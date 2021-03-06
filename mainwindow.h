#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QProcess>

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
    void on_folderPushButton_clicked();
    void updateOutputTextEdit();
    void on_joinPushButton_clicked();
    void processFinished(int exitCode,
                         QProcess::ExitStatus exitStatus);
    void processError(QProcess::ProcessError error);

    void on_programLineEdit_textEdited(const QString &arg1);

    void on_typeLineEdit_textEdited(const QString &arg1);

    void on_formatLineEdit_textEdited(const QString &arg1);

    void on_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QString mkvmerge;
    QString format;
    QString type;
    QString folder;
    QFileSystemModel model;
    QStringList allFiles;
    QStringList videos;
    QStringList subtitles;
    QProcess *process;
    QString film;
    void findSubtitle();
    bool deleteOriginal;
};

#endif // MAINWINDOW_H
