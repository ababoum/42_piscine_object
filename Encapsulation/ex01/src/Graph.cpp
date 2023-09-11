#include "Graph.hpp"

Graph::Graph() : size(0) {}

Graph::~Graph() {}

void Graph::addPoint(float x, float y)
{
    points.push_back(Vector2(x, y));
}

void Graph::addPoint(Vector2 point)
{
    points.push_back(point);
}

void Graph::display()
{
    int y_max, x_max, y_min, x_min = 0;

    for (std::list<Vector2>::iterator it = points.begin(); it != points.end(); ++it)
    {
        if (y_max < it->getY())
            y_max = std::ceil(it->getY());

        if (y_min > it->getY())
            y_min = std::floor(it->getY());

        if (x_max < it->getX())
            x_max = std::ceil(it->getX());

        if (x_min > it->getX())
            x_min = std::floor(it->getX());
    }

    size_t height = y_max - y_min + 2;
    size_t width = x_max - x_min + 2;

    std::vector<std::string> lines;

    for (size_t i = 0; i < height; ++i)
    {
        lines.push_back(std::string(""));

        if (i == height - 1)
        {
            lines.front().append(" ");
            for (size_t j = 0; j < width - 1; ++j)
            {
                std::ostringstream last_line;
                last_line << x_min - j;
                lines.front().append(" ");
                lines.front().append(last_line.str());
            }
            return ;
        }

        std::ostringstream str;
        str << y_max - i;

        lines.front().append(std::string(str.str()));

        for (size_t j = 0; j < width - 1; ++j)
        {
            lines.front().append(" .");
        }
    }

    for (size_t l = 0; l < lines.size(); ++l)
    {
        std::cout << lines[l] << std::endl;
    }
}