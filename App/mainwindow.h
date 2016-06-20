#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include <TPFile/tpfile.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    /*!
     * Inicializa la ventana
     */
    void setup();

    /*!
      Realiza las conexiones
      */

    void connectApp();

private slots:

    void selectFileOrigen();
    void selectFileDestino();
    void transform();
};

#endif // MAINWINDOW_H
