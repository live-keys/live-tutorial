import QtQuick 2.3
import lcvcore 1.0
import lcvimgproc 1.0
import tutorial 1.0

Grid{

    columns : 2

    property string imagePath : project.dir() + '/tutorial.jpg'

    ImRead{
        id : imgSource
        file : parent.imagePath
    }

    MatEmpty{
        id : imgE
        matSize : imgSource.output.dataSize()
        channels : 3
        color : "#997822"
    }

    AddWeighted{
        input : imgSource.output
        input2 : imgE.output
        alpha : 0.6
        beta : 0.4
        gamma : 0
    }

}
