#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup();
    connectApp();
}

void MainWindow::setup()
{
    //Preparamos el comboBox de formatos

    TPFile::initGDAL();

    vector<string> nombres=TPFile::driverNames();

    for(auto it=nombres.begin();it!=nombres.end();it++) {
        ui->formatComboBox->addItem(QString((*it).c_str()));
    }
}

void MainWindow::connectApp()
{
    connect(ui->origenToolButton,SIGNAL(clicked(bool)),this,SLOT(selectFileOrigen()));
    connect(ui->salidaToolButton,SIGNAL(clicked(bool)),this,SLOT(selectFileDestino()));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(transform()));
}

void MainWindow::selectFileDestino()
{
    QString destino=QFileDialog::getSaveFileName(this,tr("TPTranslate - Archivo de destino"));

    if(destino.isEmpty() || destino.isNull())
        return;

    ui->salidaLine->setText(destino);
}

void MainWindow::selectFileOrigen()
{
    QString origen=QFileDialog::getOpenFileName(this,tr("TPTranslate - Archivo de origen"));
    if(origen.isEmpty() || origen.isNull())
        return;

    ui->origenLine->setText(origen);
}

void MainWindow::transform()
{
    TPFile archivoOrigen(ui->origenLine->text().toStdString().c_str());

    if(!archivoOrigen.isOpen())
        return;

    archivoOrigen.saveToFileFormat(ui->salidaLine->text().toStdString(),
                                   ui->formatComboBox->currentText().toStdString().c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
