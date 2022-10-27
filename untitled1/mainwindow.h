#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ReadData();

    void ReadError(QAbstractSocket::SocketError);

    void on_pushButton_go_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_connect_clicked();

    void on_cbb_speed_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTcpSocket  *client ;
};

#endif // MAINWINDOW_H
