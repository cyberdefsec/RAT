#ifndef SHELL_H
#define SHELL_H

#include <QPlainTextEdit>
#include <QKeyEvent>
#include <QScrollBar>
#include <QDebug>
#include <QTextBlock>

#include "common.h"

class RemoteShell : public QPlainTextEdit{

    Q_OBJECT

public:
    RemoteShell(QWidget *parent = nullptr);
    virtual ~RemoteShell() override {}

private:    
    void scrollDown();
    void insertPromt();
    void offsetCursor(QTextCursor::MoveOperation pos);
    void clearShell();
    void selectText(QTextCursor::MoveOperation pos);
    void historyAdd(const QString &cmd);
    void runCommand();
    void historyBack();
    void historyForward();

    QString prompt = "SHELL#";
    QString cmd;
    QStringList command;
    int historyCount = 0;
    DATA data;

protected:
    void keyPressEvent(QKeyEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseDoubleClickEvent(QMouseEvent *) override;
//    void contextMenuEvent(QContextMenuEvent *) override {}

public slots:
    void shellData(QByteArray data);

signals:
    void send(DATA &data);
};

#endif
