#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFuture>
#include <QtConcurrent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartClicked();
    void onStopClicked();
    void onCalculationFinished(int number, int length, long long duration);
    void onErrorMessage(const QString &message);

private:
    Ui::MainWindow *ui;
    bool running;
    QFuture<void> future;
    void startCalculation(int maxNumber, int numThreads);
    void stopCalculation();
    int collatzLength(long long n);
    int findLongestCollatz(int maxNumber, int numThreads);
};

#endif // MAINWINDOW_H
