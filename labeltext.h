#ifndef LABELTEXT_H
#define LABELTEXT_H

#include <QLabel>
#include <QEvent>
#include <QMouseEvent>
#include <QString>

class LabelText : public QLabel
{

Q_OBJECT
private:
    int positon;
public:
    LabelText();

    void mousePressEvent(QMouseEvent *ev);

    void setTextLabel(QString text, int pos);

    void updatePosition(int newPos);



signals:
    void signalLabelClicked(int pos);
};

#endif // LABELTEXT_H
