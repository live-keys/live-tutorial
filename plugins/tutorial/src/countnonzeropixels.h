#ifndef COUNTNONZEROPIXELS_H
#define COUNTNONZEROPIXELS_H

#include <QQuickItem>

#include <QQuickItem>
#include "qmat.h"

class CountNonZeroPixels : public QQuickItem{

    Q_OBJECT
    Q_DISABLE_COPY(CountNonZeroPixels)
    Q_PROPERTY(QMat* input         READ input         WRITE setInput NOTIFY inputChanged)
    Q_PROPERTY(int   nonZeroPixels READ nonZeroPixels NOTIFY nonZeroPixelsChanged)

public:
    CountNonZeroPixels(QQuickItem *parent = 0) : QQuickItem(parent){}
    ~CountNonZeroPixels(){}

    QMat* input();
    void setInput(QMat* input);

    int nonZeroPixels() const;

signals:
    void inputChanged();
    void nonZeroPixelsChanged();

private:
    QMat* m_input;
    int   m_nonZeroPixels;
};

inline int CountNonZeroPixels::nonZeroPixels() const{
    return m_nonZeroPixels;
}

inline QMat*CountNonZeroPixels::input(){
    return m_input;
}

inline void CountNonZeroPixels::setInput(QMat* input){
    m_input = input;
    emit inputChanged();
    m_nonZeroPixels = cv::countNonZero(*m_input->cvMat());
    emit nonZeroPixelsChanged();
}

#endif // COUNTNONZEROPIXELS_H
