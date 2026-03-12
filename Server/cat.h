#include <string>

#ifndef CAT_H
#define CAT_H

extern std::string lastMoveMessage;
extern bool lastMoveBlock;
extern int moves;

class Cat {
protected:
    std::string name;
    int hp;
    int damage;
    int speed;

public:
    Cat(const std::string& catName, int catHP, int catDamage, int catSpeed)
        : name(catName), hp(catHP), damage(catDamage), speed(catSpeed) {}

    virtual ~Cat() {

    }

    virtual Cat scratch(Cat attackingCat, Cat opposingCat) const {
        return opposingCat;
    }

    virtual Cat bite(Cat attackingCat, Cat opposingCat) const {

    }

    virtual Cat headbutt(Cat attackingCat, Cat opposingCat) const {

    }

    virtual Cat kick(Cat attackingCat, Cat opposingCat) const {

    }

    std::string getName() const { return name; }
    int getHp() const { return hp; }
    int getDamage() const { return damage; }
    int getSpeed() const { return speed; }

    void setName(const std::string& catName) { name = catName; }
    void setHp(int catHP) { hp = catHP; }
    void setDamage(int catDamage) { damage = catDamage; }
    void setSpeed(int catSpeed) { speed = catSpeed; }
};

#endif // CAT_H
