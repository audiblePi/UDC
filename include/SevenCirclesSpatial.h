#ifndef SEVENCIRCLESSPATIAL_H
#define SEVENCIRCLESSPATIAL_H

#include "CgalComponents.h"

struct Point_hasher2 {
    inline size_t operator()(const Point &p) const {
        size_t h1 = std::hash<double>()(p.x());
        size_t h2 = std::hash<double>()(p.y());

        return h1 ^ h2;
    }
};

struct Point_equal2 {
	bool operator() (const Point & p1, const Point & p2) const {
		if (p1.x() == p2.x() && p1.y() == p2.y())
	    	return true;
        else 
		    return false;
	}
};

class SevenCirclesSpatial
{
    public:
        SevenCirclesSpatial(vector<Point> &P, vector<Point> &C);

        Point findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints);
        void coverPoint(Point point, unordered_map<Point, bool, Point_hasher2, Point_equal2> &hashTable, Tree &tree);
};

#endif // SEVENCIRCLESSPATIAL_H
