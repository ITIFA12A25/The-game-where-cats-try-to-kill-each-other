#include "cat.h"

#ifndef FERAL_H
#define FERAL_H

class Feral : public Cat {
public:
    Feral();

    void attack() const override;
    void buff() const override;
    void block() const override;
    void regenerate() const override;
};

#endif
