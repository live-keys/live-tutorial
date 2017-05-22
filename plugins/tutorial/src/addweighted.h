#ifndef ADDWEIGHTED_H
#define ADDWEIGHTED_H

#include "qmatfilter.h"

class AddWeighted : public QMatFilter{

    Q_OBJECT
    Q_PROPERTY(QMat* input2 READ input2 WRITE setInput2 NOTIFY input2Changed)
    Q_PROPERTY(qreal alpha  READ alpha  WRITE setAlpha  NOTIFY alphaChanged)
    Q_PROPERTY(qreal beta   READ beta   WRITE setBeta   NOTIFY betaChanged)
    Q_PROPERTY(qreal gamma  READ gamma  WRITE setGamma  NOTIFY gammaChanged)

public:
    explicit AddWeighted(QQuickItem *parent = 0);
    ~AddWeighted();

    void transform(cv::Mat& in, cv::Mat& out);

    QMat* input2();
    void setInput2(QMat* input2);

    qreal alpha() const;
    void setAlpha(qreal alpha);

    qreal beta() const;
    void setBeta(qreal beta);

    qreal gamma() const;
    void setGamma(qreal gamma);

signals:
    void input2Changed();
    void alphaChanged();
    void betaChanged();
    void gammaChanged();

private:
    QMat* m_input2;
    QMat* m_input2Internal;
    qreal m_alpha;
    qreal m_beta;
    qreal m_gamma;
};

inline QMat* AddWeighted::input2(){
    return m_input2;
}

inline void AddWeighted::setInput2(QMat* input2){
    m_input2 = input2;
    emit input2Changed();

    QMatFilter::transform();
}

inline qreal AddWeighted::alpha() const{
    return m_alpha;
}

inline void AddWeighted::setAlpha(qreal alpha){
    if ( m_alpha != alpha ){
        m_alpha = alpha;
        emit alphaChanged();

        QMatFilter::transform();
    }
}

inline qreal AddWeighted::beta() const{
    return m_beta;
}

inline void AddWeighted::setBeta(qreal beta){
    if ( m_beta != beta ){
        m_beta = beta;
        emit betaChanged();

        QMatFilter::transform();
    }
}

inline qreal AddWeighted::gamma() const{
    return m_gamma;
}

inline void AddWeighted::setGamma(qreal gamma){
    if ( gamma != m_gamma ){
        m_gamma = gamma;
        emit gammaChanged();

        QMatFilter::transform();
    }
}


#endif // ADDWEIGHTED_H
