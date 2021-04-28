#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QIcon>
#include <QTranslator>

class Application : public QApplication{

    Q_OBJECT

public:
    Application(int &argc, char **argv);
    virtual ~Application(){}
//    QString getLocale();

private:
    QTranslator *translator;
};

#endif // APPLICATION_H
