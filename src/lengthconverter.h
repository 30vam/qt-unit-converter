#ifndef LENGTHCONVERTER_H
#define LENGTHCONVERTER_H

#include "abstractconverter.h"

class LengthConverter : public AbstractConverter
{
public:
    explicit LengthConverter(QWidget *parent = nullptr);

private:
    void convertValues() override;
};

#endif // LENGTHCONVERTER_H
