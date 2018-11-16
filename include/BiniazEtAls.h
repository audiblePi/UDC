#ifndef BINIAZETALS_H
#define BINIAZETALS_H

#include "CgalComponents.h"


class BiniazEtAls
{
    public:
        BiniazEtAls(vector<Point> &P, vector<Point> &C);

        Point findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints);
        //void coverPoint(Point point, vector<Point> &unitDiscCenters, vector<Point> &coveredPoints);
        void coverPoint(Point point, vector<Point> &unitDiscCenters, DelunayTriangulation &delunayTriangulation);
};

#endif // BINIAZETALS_H
