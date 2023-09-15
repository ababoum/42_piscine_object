#include "Shovel.hpp"

Shovel::Shovel(): numberOfUses(0), holder(0)
{
}

Shovel::~Shovel()
{
}

void Shovel::use()
{
    ++numberOfUses;
}

Worker *Shovel::getHolder()
{
    return holder;
}

void Shovel::setHolder(Worker *worker)
{
    holder = worker;
}