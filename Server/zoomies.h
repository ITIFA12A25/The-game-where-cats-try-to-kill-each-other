#include "cat.h"

#ifndef ZOOMIES_H
#define ZOOMIES_H

class Zoomies : public Cat {
public:
    Zoomies();

    Cat scratch(Cat attackingCat, Cat opposingCat) const override;
    Cat bite(Cat attackingCat, Cat opposingCat) const override;
    Cat headbutt(Cat attackingCat, Cat opposingCat) const override;
    Cat kick(Cat attackingCat, Cat opposingCat) const override;
};

#endif
