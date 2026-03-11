#include <string>

#ifndef CAT_H
#define CAT_H

class Cat {
protected:
    std::string name;
    int hp;
    int damage;

public:
    Cat(const std::string& catName, int catHP, int catDamage)
        : name(catName), hp(catHP), damage(catDamage) {}

    virtual ~Cat() {

    }

    virtual void attack() const {

    }

    virtual void buff() const {

    }

    virtual void block() const {

    }

    virtual void regenerate() const {

    }

    std::string getName() const { return name; }
    int getHp() const { return hp; }
    int getDamage() const { return damage; }

};

#endif // CAT_H
