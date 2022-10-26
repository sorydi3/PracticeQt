#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    //TODO IMPLEMENT
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:white;");

    resize(750, 500);
    ui->pushButton->setText(QString(">>"));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(writeText()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->guardar, SIGNAL(clicked()), this, SLOT(guardar()));
    //connect(ui->bo, SIGNAL(clicked()), this, SLOT(guardar()));

    ui->widget->setLayout(new QVBoxLayout());
}

MainWindow::~MainWindow()
{
    foreach (QLabel * label, labels) {
        delete label;
    }
    delete ui;
}

void MainWindow::writeText()
{
    LabelText *label = new LabelText();
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    if(!ui->text1->toPlainText().isEmpty()){
        labels.push_back(label);
        label->setTextLabel(ui->text1->toPlainText(),labels.length());
        ui->widget->layout()->addWidget(label);
        ui->widget->show();
        connect(label,SIGNAL(signalLabelClicked(int)),this,SLOT(undoText(int)));
    }

}




void MainWindow::clear()
{

    ui->text1->clear();
    deleteAllQlabels();
}

void MainWindow::guardar()
{

    QTextDocument documento;
    // QString html ="<p>"+ui->text2->toPlainText()+"</p>";
    QString html = "";
    QPrinter impresora(QPrinter::HighResolution);
    impresora.setOutputFormat(QPrinter::PdfFormat);
    impresora.setOutputFileName(QFileDialog::getSaveFileName(this, "Exportar a PDF", "C:\\Users\\ibrah\\Documents", "*.pdf"));
    impresora.setPageMargins(QMargins(20, 30, 20, 15));

    documento.setHtml(html);
    documento.print(&impresora);
}

void MainWindow::undoText(int posText)
{
    selectedLabels.insert(posText);
    QLabel * label = labels.at(posText-1);
    if(label) delete label;
    QLayoutItem *child = ui->widget->layout()->takeAt(posText);
    if(child) delete child;
    ui->widget->show();
    updateLabelsPos();
    qDebug() << QString::number(posText);
}

void MainWindow::updateLabelsPos()
{
    for (int label = 0; label < labels.length(); ++label) {
        labels[label]->updatePosition(label+1);
    }
}




void MainWindow::deleteAllQlabels()
{
    QLayoutItem *child;
    while ((child = ui->widget->layout()->takeAt(0)) != 0) {
      delete child->widget();
      delete child;
    }
    ui->widget->show();
}
