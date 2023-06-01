
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QFuture>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*
 * This class manages the general layout and events of the application.
 * It handles all the signals of the app.
 *
 * @author : Matthieu d'Hoop
 */
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
    bool start;

private slots:
    // Updates the 3D scene
    void update_scene();
    // Updates the camera frame
    void update_camera();
    // Updates the game over state
    void update_game_over();
    // Updates the score of the player
    void update_points();
    // Start the hand detection
    void analyze();
    // Handles the event "restart button clicked"
    void on_restart_button_clicked();
    // Handles the event "start button clicked"
    void on_start_button_clicked();
};

#endif // MAINWINDOW_H
