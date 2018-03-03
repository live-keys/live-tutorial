PLUGIN_NAME = tutorial
PLUGIN_PATH = tutorial

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVECV_DEV_PATH/project/plugin.pri)

uri = tutorial

DEFINES += Q_LCV

## Dependencies

linkPlugin(live,    live)
linkPlugin(lcvcore, lcvcore)

message($$LIBS)

## Deploying qml is handled by the plugin.pri configuration

## Source

include($$PWD/src/tutorial.pri)
include($$LIVECV_DEV_PATH/project/3rdparty/opencv.pri)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir
