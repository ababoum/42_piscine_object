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
    // Identify the graph size

    int y_max = 0;
    int x_max = 0;
    int y_min = 0;
    int x_min = 0;

    for (std::list<Vector2>::iterator it = points.begin(); it != points.end(); ++it)
    {
        if (y_max < it->getY())
            y_max = std::ceil(it->getY()) + 1;

        if (y_min > it->getY())
            y_min = std::floor(it->getY());

        if (x_max < it->getX())
            x_max = std::ceil(it->getX()) + 1;

        if (x_min > it->getX())
            x_min = std::floor(it->getX());
    }

    int height = y_max - y_min + 2;
    int width = x_max - x_min + 2;

    // Create the lines without the points

    std::vector<std::string> lines;

    for (int i = 0; i < height; ++i)
    {
        lines.push_back(std::string(""));

        if (i == height - 1)
        {
            lines.front().append(" ");
            for (int j = 0; j < width - 1; ++j)
            {
                std::ostringstream last_line;
                lines.front().append(" ");
                std::string s = SSTR(x_min + j);
                lines.front().append(s);
            }
            lines.front().append("\n");
            break;
        }

        std::ostringstream str;
        str << y_max - i;

        lines.front().append(std::string(str.str()));

        for (int j = 0; j < width - 1; ++j)
        {
            lines.front().append(" .");
        }
        lines.front().append("\n");
    }

    // Fill the map/lines

    for (std::list<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it)
    {
        Vector2 point = *it;
        lines[y_max - point.getY()][2 * (point.getX() - x_min + 1)] = 'X';
    }

    // Display the graph

    for (size_t l = 0; l < lines.size(); ++l)
    {
        std::cout << lines[l];
    }
}

std::ostream &operator<<(std::ostream &p_os, const Graph &graph)
{
    p_os << "The graph is composed of:" << '\n';

    for (std::list<Vector2>::const_iterator it = graph.points.begin(); it != graph.points.end(); ++it)
    {
        Vector2 vec = *it;
        p_os << "(" << vec.getX() << ", " << vec.getY() << ")\n";
    }
    return (p_os);
}