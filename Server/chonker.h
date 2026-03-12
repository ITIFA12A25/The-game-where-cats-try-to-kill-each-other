#include "cat.h"

#ifndef CHONKER_H
#define CHONKER_H

class Chonker : public Cat {
public:
    Chonker();

    Cat scratch(Cat attackingCat, Cat opposingCat) const override;
    Cat bite(Cat attackingCat, Cat opposingCat) const override;
    Cat headbutt(Cat attackingCat, Cat opposingCat) const override;
    Cat kick(Cat attackingCat, Cat opposingCat) const override;
};

#endif
