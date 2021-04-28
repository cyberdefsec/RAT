#include "application.h"

Application::Application(int &argc, char **argv) : QApplication(argc, argv){
    setApplicationName(tr("Administration"));
    setApplicationDisplayName(tr("Administration"));
    setWindowIcon(QIcon(":/ico/title.ico"));

    /*translator = new QTranslator(this);
    translator->load(getLocale());
    installTranslator(translator);*/
}

/*QString Application::getLocale(){
    if(QLocale::system().name() == "ru_RU")
        return QString(":/translations/ru_RU.qm");
    return QString(":/translations/en_EN.qm");
}*/
