
# --- Version Check ---

# Some linux distributions have qt version 4 already installed. Sometimes this
# can lead to running the wrong qmake version. Notify the user:

#!qtVersionCheck(5, 6)::error( \
#    This project requires at least Qt version 5.6. \
#    Make sure you have Qt 5.6 installed and running the correct qmake. \
#)

# --- Project structure ---

TEMPLATE = subdirs

SUBDIRS += \
    dependencies \
    plugins

# --- Subdir configurations ---
dependencies.subdir = $$PWD/dependencies
plugins.subdir      = $$PWD/plugins

# --- Dependency configuration ---
plugins.depends = dependencies


# Include the global configuration files since otherwise they would never show
# up in your project
OTHER_FILES += \
    .qmake.conf \

OTHER_FILES += \
    $$LIVECV_DIR/config/is_plugin.pri \
    $$LIVECV_DIR/config/config_functions.pri
