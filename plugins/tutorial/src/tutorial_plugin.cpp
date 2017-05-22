#include "tutorial_plugin.h"
#include "countnonzeropixels.h"
#include "addweighted.h"
#include "compilationcount.h"
#include <qqml.h>

void TutorialPlugin::registerTypes(const char *uri){
    qmlRegisterType<CountNonZeroPixels>(uri, 1, 0, "CountNonZeroPixels");
    qmlRegisterType<AddWeighted>(       uri, 1, 0, "AddWeighted");
    qmlRegisterType<CompilationCount>(  uri, 1, 0, "CompilationCount");
}
