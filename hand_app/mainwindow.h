
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFuture>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QFuture<void> future_scene;
    QFuture<void> future_camera;
    int score;

private slots:
    void update_scene();
    void update_camera();
    void update_game_over();
    void update_points();
    void analyze();
    void on_restart_button_clicked();
};

#endif // MAINWINDOW_H
