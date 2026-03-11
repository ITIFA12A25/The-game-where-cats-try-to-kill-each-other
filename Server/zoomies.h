#include "cat.h"

#ifndef ZOOMIES_H
#define ZOOMIES_H

class Zoomies : public Cat {
public:
    Zoomies();

    void attack() const override;
    void buff() const override;
    void block() const override;
    void regenerate() const override;
};

#endif
