import QtQuick 2.3
import lcvcore 1.0
import tutorial 1.0

Rectangle{

    // This sample counts the number of compilations
    // Trigger a new compilation by changing the contents of the file
    // and see the value change

    Text{
        text : "Compilations : " + cc.compilations
        color : "#fff"
    }
    CompilationCount{
        id : cc
        Component.onCompleted : staticLoad('cc')
    }

}