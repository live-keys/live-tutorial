#ifndef COMPILATIONCOUNT_H
#define COMPILATIONCOUNT_H

#include <QQuickItem>

class CompilationCountState;
class CompilationCount : public QQuickItem{

    Q_OBJECT
    Q_PROPERTY(int compilations READ compilations NOTIFY compilationsChanged)

 public:
    explicit CompilationCount(QQuickItem *parent = 0);

    int compilations() const;

public slots:
    void staticLoad(const QString& id);

signals:
    void compilationsChanged();

private:
    CompilationCountState* m_state;
};

#endif // COMPILATIONCOUNT_H
