PLUGIN_NAME = tutorial
PLUGIN_PATH = $$PWD

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVECV_DIR/config/is_plugin.pri)

uri = plugins.tutorial

DEFINES += Q_LCV

## Dependencies

linkPlugin(dependencies/livecv, live,    live)
linkPlugin(dependencies/livecv, lcvcore, lcvcore)

## Deploying qml is handled by the is_plugin configuration

## Source

include($$PWD/src/tutorial.pri)
include($$LIVECV_DIR/3rdparty/opencvconfig.pro)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir
