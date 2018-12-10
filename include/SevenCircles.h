#ifndef SEVENCIRCLES_H
#define SEVENCIRCLES_H

#include "CgalComponents.h"


struct node{
    Point p;
    bool active;
};


class SevenCircles
{
    public:
        SevenCircles(vector<Point> &P, vector<Point> &C);

        Point findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints);
        //void coverPoint(Point point, vector<Point> &unitDiscCenters, vector<Point> &coveredPoints);
        void coverPoint(Point point, vector<Point> &unitDiscCenters, DelunayTriangulation &delunayTriangulation, vector<node> &allCircles, DelunayTriangulation &dT);
        void searchPoint(node closestNeighborNode, vector<node> &allCircles);
};

#endif // SEVENCIRCLES_H
