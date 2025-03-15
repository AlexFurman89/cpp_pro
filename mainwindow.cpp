#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), running(false) {
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::onStopClicked);

    ui->stopButton->setEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartClicked() {
    int maxNumber = ui->limitSpinBox->value();
    int numThreads = ui->threadSlider->value();

    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
    ui->resultText->clear();

    startCalculation(maxNumber, numThreads);
}

void MainWindow::onStopClicked() {
    stopCalculation();
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

void MainWindow::startCalculation(int maxNumber, int numThreads) {
    running = true;
    auto start = std::chrono::high_resolution_clock::now();
    int result = findLongestCollatz(maxNumber, numThreads);
    auto end = std::chrono::high_resolution_clock::now();
    long long duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    if (result != -1)
        onCalculationFinished(result, collatzLength(result), duration);
    else
        onErrorMessage("Calculation was stopped.");
}

void MainWindow::stopCalculation() {
    running = false;
}

int MainWindow::collatzLength(long long n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        length++;
    }
    return length;
}

int MainWindow::findLongestCollatz(int maxNumber, int numThreads) {
    int bestNumber = 1, maxLength = 0;
    QVector<QFuture<std::pair<int, int>>> futures;

    int chunkSize = maxNumber / numThreads;

    for (int t = 0; t < numThreads; ++t) {
        int start = t * chunkSize + 1;
        int end = (t == numThreads - 1) ? maxNumber : start + chunkSize;

        futures.append(QtConcurrent::run([this, start, end]() {
            int localBest = 1, localMaxLength = 0;
            for (int i = start; i <= end; i++) {
                if (!running) return std::make_pair(-1, -1);
                int len = collatzLength(i);
                if (len > localMaxLength) {
                    localBest = i;
                    localMaxLength = len;
                }
            }
            return std::make_pair(localBest, localMaxLength);
        }));
    }

    for (auto &fut : futures) {
        auto result = fut.result();
        if (result.second > maxLength) {
            bestNumber = result.first;
            maxLength = result.second;
        }
    }
    return bestNumber;
}

void MainWindow::onCalculationFinished(int number, int length, long long duration) {
    ui->resultText->setText(QString("Number: %1\nLength: %2\nTime: %3 ms")
                                .arg(number).arg(length).arg(duration));
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

void MainWindow::onErrorMessage(const QString &message) {
    QMessageBox::warning(this, "Error", message);
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}
