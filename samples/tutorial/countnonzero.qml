import QtQuick 2.3
import live 1.0
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

    Canny{
        id : canny
        input: imgSource.output
        threshold1 : 70
        threshold2 : 210
    }

    CountNonZeroPixels{
        id : count
        input : canny.output
    }

    Text{
        color : "#fff"
        text : count.nonZeroPixels
    }

}