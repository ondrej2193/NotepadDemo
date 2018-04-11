#include "notepaddemo.h"
#include "ui_notepaddemo.h"
#include <Qfile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

NotepadDemo::NotepadDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NotepadDemo)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

NotepadDemo::~NotepadDemo()
{
    delete ui;
}

void NotepadDemo::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");

}

void NotepadDemo::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"..","File not opened");
        return;
    }
    QTextStream in (&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    //file.close;
}

void NotepadDemo::on_actionSave_triggered()
{
    //QString file_name = QFileDialog::getSaveFileName(this,"Save the file");
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"..","File not opened");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void NotepadDemo::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Save the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"..","File not opened");
        return;
    }
    QTextStream out (&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void NotepadDemo::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void NotepadDemo::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void NotepadDemo::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void NotepadDemo::on_actionRendo_triggered()
{
    ui->textEdit->redo();
}

void NotepadDemo::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void NotepadDemo::on_actionFont_triggered()
{

}

void NotepadDemo::on_actionPrint_triggered()
{

}

void NotepadDemo::on_actionExit_triggered()
{

}

void NotepadDemo::on_actionInfo_triggered()
{

}

void NotepadDemo::on_actionNew_changed()
{

}
