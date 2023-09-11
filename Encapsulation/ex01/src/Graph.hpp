#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <sstream>
#include <string>
#include "Vector2.hpp"

#define SSTR(x) static_cast<std::ostringstream &>(           \
                    (std::ostringstream() << std::dec << x)) \
                    .str()

class Graph
{
public:
    Graph();
    ~Graph();

    void addPoint(float x, float y);
    void addPoint(Vector2 point);

    void display();

    friend std::ostream &operator<<(std::ostream &p_os, const Graph &graph);

private:
    std::list<Vector2> points;
    size_t size;
};

#endif