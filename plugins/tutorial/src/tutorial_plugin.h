#ifndef TUTORIAL_PLUGIN_H
#define TUTORIAL_PLUGIN_H

#include <QQmlExtensionPlugin>

class TutorialPlugin : public QQmlExtensionPlugin{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // TUTORIAL_PLUGIN_H
