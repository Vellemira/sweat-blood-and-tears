#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_brightness_valueChanged(int value);

    void on_step_valueChanged(int value);

    void on_speed_valueChanged(int value);

    void on_endis_clicked();

    void onConnected();

    void onDisconnected();

    void onReceive(const QString &message);

private:
    Ui::MainWindow *ui;
    QWebSocket *ws;
};
#endif // MAINWINDOW_H
