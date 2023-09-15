#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Worker
{
public:
    Worker();
    ~Worker();

    Shovel *getEquippedShovel() const;
    void equipShovel(Shovel *shovel);
    void unequipShovel();

private:
    Position coordonnee;
    Statistic stat;
    Shovel *equippedShovel;
};

#endif