#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QLabel>
#include <labeltext.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void writeText();
    void clear();
    void guardar();
    void undoText(int posText);
    void updateLabelsPos();

private:
    void deleteAllQlabels();
    Ui::MainWindow *ui;
    QVector<LabelText *> labels;
};
#endif // MAINWINDOW_H
