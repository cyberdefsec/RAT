#include "shell.h"

RemoteShell::RemoteShell(QWidget *parent) : QPlainTextEdit(parent){
//    setFont(QFont("monospace"));
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::white);
    setPalette(p);
}

void RemoteShell::scrollDown(){
    QScrollBar *vbar = verticalScrollBar();
    vbar->setValue(vbar->maximum());
}

void RemoteShell::insertPromt(){
    textCursor().insertBlock();
    textCursor().insertText(prompt);
    scrollDown();
}

void RemoteShell::offsetCursor(QTextCursor::MoveOperation pos){
    QTextCursor cur = textCursor();
    if(pos == QTextCursor::PreviousCharacter){
        if(cur.positionInBlock() > 0)
            cur.movePosition(pos);
    }
    else
        cur.movePosition(pos);
    setTextCursor(cur);
}

void RemoteShell::clearShell(){
    clear();
}

void RemoteShell::selectText(QTextCursor::MoveOperation pos){
    QTextCursor cur = textCursor();
    if(pos == QTextCursor::PreviousCharacter){
        if(cur.positionInBlock() > 0)
            cur.movePosition(pos, QTextCursor::KeepAnchor);
    }
    else
        cur.movePosition(pos, QTextCursor::KeepAnchor);
    setTextCursor(cur);
}

void RemoteShell::historyAdd(const QString &cmd){
    command.append(cmd);
    historyCount = command.length();
}

void RemoteShell::runCommand(){
    cmd = textCursor().block().text();
    historyAdd(cmd);
    if(cmd == "clear")
        clearShell();
    else{
        data.cmd = SHELL;
        qstrcpy(data.data, cmd.toStdString().c_str());
        emit send(data);
    }
    QTextCursor cur = textCursor();
    cur.movePosition(QTextCursor::EndOfBlock);
    setTextCursor(cur);
}

void RemoteShell::historyBack(){
    if(historyCount > 0){
        QTextCursor cursor = textCursor();
        cursor.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
        cursor.insertText(QString("%1").arg(command.at(historyCount - 1)));
        setTextCursor(cursor);
        historyCount--;
    }
}

void RemoteShell::historyForward(){
    if(historyCount < command.length() - 1){
        QTextCursor cursor = textCursor();
        cursor.movePosition(QTextCursor::StartOfBlock);
        cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
        cursor.removeSelectedText();
        cursor.insertText(QString("%1").arg(command.at(historyCount + 1)));
        setTextCursor(cursor);
        historyCount++;
    }
}

void RemoteShell::keyPressEvent(QKeyEvent *event){
    if(event->key() >= 0x20 && event->key() <= 0x7e && (event->modifiers() == Qt::NoModifier || event->modifiers() == Qt::ShiftModifier))
        QPlainTextEdit::keyPressEvent(event);
    if(event->key() == Qt::Key_Backspace && event->modifiers() == Qt::NoModifier){
        QTextCursor cur = textCursor();
        if(cur.positionInBlock() > 0)
            QPlainTextEdit::keyPressEvent(event);
    }
    if(event->key() == Qt::Key_Delete && event->modifiers() == Qt::NoModifier)
        QPlainTextEdit::keyPressEvent(event);
    if(event->key() == Qt::Key_Left && event->modifiers() == Qt::NoModifier)
        offsetCursor(QTextCursor::PreviousCharacter);
    if(event->key() == Qt::Key_Right && event->modifiers() == Qt::NoModifier)
        offsetCursor(QTextCursor::NextCharacter);
    if(event->key() == Qt::Key_Return && event->modifiers() == Qt::NoModifier){
        runCommand();
        QPlainTextEdit::keyPressEvent(event);
    }
    if(event->key() == Qt::Key_Left && event->modifiers() == Qt::ShiftModifier)
        selectText(QTextCursor::PreviousCharacter);
    if(event->key() == Qt::Key_Right && event->modifiers() == Qt::ShiftModifier)
        selectText(QTextCursor::NextCharacter);
    if(event->key() == Qt::Key_Up && event->modifiers() == Qt::NoModifier)
        historyBack();
    if(event->key() == Qt::Key_Down && event->modifiers() == Qt::NoModifier)
        historyForward();
}

void RemoteShell::mousePressEvent(QMouseEvent *){
    setFocus();
    QTextCursor cur = textCursor();
    cur.clearSelection();
    cur.movePosition(QTextCursor::EndOfBlock);
    setTextCursor(cur);
}

void RemoteShell::mouseDoubleClickEvent(QMouseEvent *){
    selectText(QTextCursor::StartOfLine);
}

void RemoteShell::shellData(QByteArray data){
    insertPlainText(QString::fromUtf8(data));
    scrollDown();
}
