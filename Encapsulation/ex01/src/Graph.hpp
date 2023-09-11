#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <sstream>
#include <string>
#include "Vector2.hpp"

class Graph
{
public:
    Graph();
    ~Graph();

    void addPoint(float x, float y);
    void addPoint(Vector2 point);

    void display();

private:
    std::list<Vector2> points;
    size_t size;
};

#endif