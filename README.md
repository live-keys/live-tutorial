# Live CV Plugin Tutorial

You can use this as a starting point for developing Live CV plugins.

 * **Version**: 1.0.0
 * **Requires**:
    * **Live CV**: 1.4 or higher
    * **Qt**: 5.6 or higher
    * **Open CV**: 3.1 or higher

## Compiling

There are 3 ways to compile the code, depending on your preferences:

### 1. Compiling together with Live CV

Use this mode if you want to debug your plugin alongside Live CV or simply want to have
access to Live CV's source while you are developing your plugin.

To build, clone the dev branch(currently only the dev branch is at version 1.4) from livecv in the dependencies directory:

```
git clone -b dev https://github.com/livecv/livecv.git dependencies/livecv
```

Use the *livetutorial.pro* to build.

Please note that the plugin is configured to be deployed into the build directory of Live
CV so it can be located as soon as it's build. If you compile manually:

```
cd build
qmake -r ..
make (or nmake)
```

Then Live CV will be build in *build/dependencies/livecv/bin*, and the plugin in
*build/depdendencies/livecv/bin/plugins/tutorial*

### 2. Compiling with a Live CV manual build

If you've already build Live CV in another location, and want to deploy the plugin there,
you can configure ```LIVECV_BIN_PATH``` and ```LIVECV_DEV_PATH``` variables from *.qmake.conf* file.

 * ```LIVECV_BIN_PATH``` points to the *bin* directory of your Live CV build
 * ```LIVECV_DEV_PATH``` points to the source code directory of Live CV (this is mostly used to
   include project files and setup include paths)

The plugin will be deployed in Live CV's *bin/plugins* directory, so it will be automatically
discovered by Live CV.

### 3. Compiling with a Live CV package

This is simplest mode since it doesn't require you to build Live CV. By obtaining an already
build version from Live CV's website, configure the 2 variables from *.qmake.conf* to point to
it:

 * ```LIVECV_BIN_PATH``` points to the downloaded live cv application (*.../livecv*)
 * ```LIVECV_DEV_PATH``` points to the downloaded live cv application dev directory (*.../livecv/dev*)

Like the above step, the plugin will be deployed in Live CV's *bin/plugins* directory.

> Note: If you want to keep your git branch clean, instead of modifying the *.qmake.conf* file,
> you can create a file *config.pri* in your source root where you can overwrite the
> configuration paths. The file is ignored by git and is automatically included in the project
> if it exists.

## Project files

This section describes some of the files that are part of the project.

### .qmake.conf

*.qmake.conf* is the starting point and a key file in the project. The
file is included automatically into all project files, so any variables or functions defined
here will be available everywhere. As a Live CV plugin, we want to obtain most of the
functionality already provided by the application (linking to plugins, deployment structure, etc), it's why within *.qmake.conf* we include the *package.pri* file from Live CV's dev path, which removes the need to write a lot of it ourselves:

```
include($$LIVECV_DEV_PATH/project/package.pri)
```

### livetutorial.pro

This is the main file used to build the project. It includes the *dependencies* and
*plugins* dirs. The *dependencies* are optional and can be controlled by the `BUILD_DEPENDENCIES` variable.

```
TEMPLATE = subdirs
SUBDIRS += plugins

plugins.subdir = $$PWD/plugins

!isEmpty(BUILD_DEPENDENCIES){
    SUBDIRS += dependencies
    dependencies.subdir = $$PWD/dependencies
    plugins.depends = dependencies
}
```

The *dependencies/dependencies.pro* file includes Live CV's source code only if its available.
This is only used if you are compiling this plugin together with Live CV.

### plugins/plugins.pro

This file adds the *tutorial* plugin to the build.

### plugins/tutorial/tutorial.pro

In *tutorial.pro* we configure ```PLUGIN_NAME``` and ```PLUGIN_PATH```:

```
PLUGIN_NAME = tutorial
PLUGIN_PATH = $$PWD
```

Then include *plugin.pri* from Live CV to handle a lot of boilerplate code:

```
include($$LIVECV_DEV_PATH/project/plugin.pri)
```

We link to the plugins we are dependent on, in this case ```lcvcore``` and ```live```.
This will solve include paths and link the plugin libraries to our plugin.

```
linkPlugin(live,    live)
linkPlugin(lcvcore, lcvcore)
```

And finally we include our source and opencv configuration:

```
include($$LIVECV_DEV_PATH/3rdparty/opencvconfig.pro)
```

The *qmldir* file together with any other *\*.qml* files in the *qml* dir be deployed automatically (handled in *plugins.pri*).
