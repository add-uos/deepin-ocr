#ifndef RESULTTEXTVIEW_H
#define RESULTTEXTVIEW_H

#include <QObject>
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QGestureEvent>

class ResultTextView : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ResultTextView(QWidget *parent = nullptr);

protected:
    void contextMenuEvent(QContextMenuEvent *e) override;
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;

    bool event(QEvent *event) override;
    //触摸屏功能函数
    bool gestureEvent(QGestureEvent *event);
    void tapGestureTriggered(QTapGesture *tap);

    //add for single refers to the sliding
    void slideGestureY(qreal diff);
    void slideGestureX(qreal diff);
signals:
    void sigChangeSize();
private:
    QMenu *m_Menu{nullptr};
    QAction *m_actCopy{nullptr};
    QAction *m_actCut{nullptr};
    QAction *m_actPaste{nullptr};
    QAction *m_actSelectAll{nullptr};

    bool m_slideContinue = false;

    //触摸屏
    enum GestureAction {
        GA_null,
        GA_tap,
        GA_slide,
        GA_pinch,
        GA_hold,
        GA_pan,
        GA_swipe
    };
    GestureAction m_gestureAction = GA_null;

    qint64 m_tapBeginTime = 0;
    ulong m_lastMouseTime;
    int m_lastMouseYpos;
    int m_lastMouseXpos;
    qreal m_stepSpeedY = 0;
    qreal m_stepSpeedX = 0;
    qreal durationY = {0.0};
    qreal durationX = {0.0};
    qreal changeY = {0.0};
    qreal changeX = {0.0};
    ulong m_lastMouseTimeX;
    ulong m_lastMouseTimeY;

};

#endif // RESULTTEXTVIEW_H
