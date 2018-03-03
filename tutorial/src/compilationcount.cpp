#include "compilationcount.h"

#include "qstaticloader.h"
#include "qstaticcontainer.h"

class CompilationCountState{
public:
    CompilationCountState():compilations(0){}

    int compilations;
};

CompilationCount::CompilationCount(QQuickItem *parent)
    : QQuickItem(parent)
    , m_state(0)
{
}

void CompilationCount::staticLoad(const QString &id){
    QStaticContainer* container = QStaticContainer::grabFromContext(this);
    m_state = container->get<CompilationCountState>(id);
    if ( !m_state ){ // create it if it doesn't exist
        m_state = new CompilationCountState;
        container->set<CompilationCountState>(id, m_state);
    }

    m_state->compilations++;

    emit compilationsChanged();
}

int CompilationCount::compilations() const{
    if ( m_state )
        return m_state->compilations;
    return 0;
 }
