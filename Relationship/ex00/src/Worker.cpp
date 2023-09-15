#include "Worker.hpp"

Worker::Worker() : equippedShovel(0)
{
}

Worker::~Worker() {}

Shovel *Worker::getEquippedShovel() const
{
    return equippedShovel;
}

void Worker::equipShovel(Shovel *shovel)
{
    shovel->getHolder()->unequipShovel();
    equippedShovel = shovel;
}

void Worker::unequipShovel()
{
    equippedShovel = 0;
}