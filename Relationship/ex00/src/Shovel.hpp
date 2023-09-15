#ifndef SHOVEL_HPP
#define SHOVEL_HPP

class Worker;

class Shovel
{
public:
    Shovel();
    ~Shovel();

    void use();
    Worker *getHolder();
    void setHolder(Worker *worker);

private:
    int numberOfUses;
    Worker *holder;
};

#endif