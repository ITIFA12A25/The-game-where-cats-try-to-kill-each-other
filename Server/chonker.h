#include "cat.h"

#ifndef CHONKER_H
#define CHONKER_H

class Chonker : public Cat {
public:
    Chonker();

    void attack() const override;
    void buff() const override;
    void block() const override;
    void regenerate() const override;
};

#endif
