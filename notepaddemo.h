#ifndef NOTEPADDEMO_H
#define NOTEPADDEMO_H

#include <QMainWindow>

namespace Ui {
class NotepadDemo;
}

class NotepadDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotepadDemo(QWidget *parent = 0);
    ~NotepadDemo();

private slots:
    void on_actionNew_changed();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRendo_triggered();

    void on_actionUndo_triggered();

    void on_actionFont_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionInfo_triggered();

private:
    Ui::NotepadDemo *ui;
    QString file_path;
};

#endif // NOTEPADDEMO_H
