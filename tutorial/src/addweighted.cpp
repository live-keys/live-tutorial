#include "addweighted.h"

AddWeighted::AddWeighted(QQuickItem *parent)
    : QMatFilter(parent)
    , m_input2(new QMat)
    , m_input2Internal(m_input2)
{
}

AddWeighted::~AddWeighted(){
    delete m_input2Internal;
}

void AddWeighted::transform(cv::Mat& in, cv::Mat& out){
    cv::Mat* in2 = m_input2->cvMat();
    if ( in.size() == in2->size() && in.channels() == in2->channels() ){
        cv::addWeighted(in, m_alpha, *in2, m_beta, m_gamma, out);
    }
 }
