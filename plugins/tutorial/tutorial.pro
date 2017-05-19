PLUGIN_NAME = tutorial
PLUGIN_PATH = $$PWD

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVECV_DEV_DIR/project/plugin.pri)

uri = plugins.tutorial

DEFINES += Q_LCV

## Dependencies

linkPlugin(live,    live)
linkPlugin(lcvcore, lcvcore)

## Deploying qml is handled by the is_plugin configuration

## Source

include($$PWD/src/tutorial.pri)
include($$LIVECV_DEV_DIR/3rdparty/opencvconfig.pro)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir
