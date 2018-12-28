#ifndef SEVENCIRCLES2_H
#define SEVENCIRCLES2_H

#include "CgalComponents.h"

struct Point_hasher {
    inline size_t operator()(const Point &p) const {
        size_t h1 = std::hash<double>()(p.x());
        size_t h2 = std::hash<double>()(p.y());

        return h1 ^ h2;
    }
};

struct Point_equal {
	bool operator() (const Point & p1, const Point & p2) const {
		if (p1.x() == p2.x() && p1.y() == p2.y())
	    	return true;
        else 
		    return false;
	}
};

class SevenCircles2
{
    public:
        SevenCircles2(vector<Point> &P, vector<Point> &C);

        Point findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints);
        void coverPoint(Point point, DelunayTriangulation &delunayTriangulation, unordered_map<Point, bool, Point_hasher, Point_equal> &hashTable);
};

// struct Point_hasher {
//     inline size_t operator()(const Point &p) const {
//         size_t h1 = std::hash<double>()(p.x());
//         size_t h2 = std::hash<double>()(p.y());

//         return h1 ^ h2;
//     }
// };

// struct Point_equal {
// 	bool operator() (const Point & p1, const Point & p2) const {
// 		if (p1.x() == p2.x() && p1.y() == p2.y())
// 	    	return true;
//         else 
// 		    return false;
// 	}
// };

// class SevenCircles2
// {
//     public:
//         SevenCircles2(vector<Point> &P, vector<Point> &C);

//         Point findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints);
//         bool coverPoint(Point center, Point point, vector<Point> &unitDiscCenters, DelunayTriangulation &delunayTriangulationExternals, unordered_map<Point, bool, Point_hasher, Point_equal> &hashTable);
// };

#endif // SEVENCIRCLES2_H
