#include "labeltext.h"

LabelText::LabelText()
{
    //setStyleSheet("background-color:yellow;");
}

void LabelText::mousePressEvent(QMouseEvent *ev)
{
    emit signalLabelClicked(positon);
}

void LabelText::setTextLabel(QString text,int posText)
{
    setText(text);
    positon = posText;

}

void LabelText::updatePosition(int newPos)
{
    positon = newPos;
}
