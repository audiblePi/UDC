#ifndef SEVENCIRCLES2_H
#define SEVENCIRCLES2_H

#include "CgalComponents.h"

struct Node{
    Point p;
    bool active;
};

struct Node_hash {
    inline size_t operator()(const Node &n) const {
        // cout << endl << "hash: " << (n.p.x()*31+n.p.y()) * 1000 << endl;
        // return (n.p.x()*31+n.p.y()) * 1000;

        size_t h1 = std::hash<double>()(n.p.x());
        size_t h2 = std::hash<double>()(n.p.y());

        return h1 ^ h2;
    }
};

// struct Compare_node{
// 	bool operator()(const Node & n1, const Node & n2) const {
// 		if (n1.p.x() == n2.p.x()){
// 	    	return (n1.p.y() < n2.p.y());
// 	    } else {
// 		    return (n1.p.x() < n2.p.x());
// 		}
// 	}
// };

struct Compare_node{
	bool operator() (const Node & n1, const Node & n2) const {
		if (n1.p.x() == n2.p.x() && n1.p.y() == n2.p.y())
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
        void coverPoint(Point point, DelunayTriangulation &delunayTriangulation, unordered_set<Node, Node_hash, Compare_node> &hashTable);
        //void searchPoint(node closestNeighborNode, vector<node> &allCircles);
};

#endif // SEVENCIRCLES2_H
