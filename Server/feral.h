#include "cat.h"

#ifndef FERAL_H
#define FERAL_H

class Feral : public Cat {
public:
    Feral();

    Cat scratch(Cat attackingCat, Cat opposingCat) const override;
    Cat bite(Cat attackingCat, Cat opposingCat) const override;
    Cat headbutt(Cat attackingCat, Cat opposingCat) const override;
    Cat kick(Cat attackingCat, Cat opposingCat) const override;
};

#endif
