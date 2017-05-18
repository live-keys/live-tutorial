#include "tutorial_plugin.h"
#include "countnonzeropixels.h"
#include <qqml.h>

void TutorialPlugin::registerTypes(const char *uri){
    qmlRegisterType<CountNonZeroPixels>(uri, 1, 0, "CountNonZeroPixels");
}
