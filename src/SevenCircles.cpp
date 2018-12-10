#include "SevenCircles.h"
#include "CgalComponents.h"
#include <math.h>

struct compareCircle {
	bool operator()(const Circle &c1, const Circle &c2) {
		if (c1.center().x() == c2.center().x()){
	    	return (c1.center().y() < c2.center().y());
	    } else {
		    return (c1.center().x() < c2.center().x());
		}
	}
};

SevenCircles::SevenCircles(vector<Point> &Points, vector<Point> &unitDiskCenters){
    vector<node> allCircles;

	DelunayTriangulation delunayTriangulation;
	DelunayTriangulation dT;
	bool isEmptyTriangulation = true;

    //sort(Points.begin(), Points.end(), compareCircle());

    for( Point point : Points) {
    	if(isEmptyTriangulation) {
			coverPoint(point, unitDiskCenters, delunayTriangulation, allCircles, dT);
    		isEmptyTriangulation = false;
    	} else {
	        Vertex_handle closestNeighbor = delunayTriangulation.nearest_vertex(point);
	    	int distance = squared_distance(point, closestNeighbor->point());

	    	if (distance > 2){
	    		coverPoint(point, unitDiskCenters, delunayTriangulation, allCircles, dT);
	   		}
	   		else{
                Vertex_handle closestNeighbor2 = dT.nearest_vertex(point);
                unitDiskCenters.push_back(closestNeighbor2->point());

	   		}
	   	}
    }
}

void SevenCircles::coverPoint(Point point, vector<Point> &unitDiskCenters, DelunayTriangulation &delunayTriangulation, vector<node> &allCircles,
                                DelunayTriangulation &dT){
    //right circles
    Point p2(point.x() + sqrt(3.0), point.y());
    node c2 = { p2, false };

    Point p3(point.x() + sqrt(3.0) / 2, point.y() + 1.5);
	node c3 = { p3, false };

	Point p4(point.x() + sqrt(3.0) / 2, point.y() - 1.5);
	node c4 = { p4, false };

	//left circles
	Point p5(point.x() - sqrt(3.0) / 2, point.y() + 1.5);
	node c5 = { p5, false };

    Point p6(point.x() - sqrt(3.0), point.y());
	node c6 = { p6, false };

	Point p7(point.x() - sqrt(3.0) / 2, point.y() - 1.5);
	node c7 = { p7, false };

	node pointed = {point, true};

	allCircles.push_back(pointed);
	allCircles.push_back(c2);
	allCircles.push_back(c3);
	allCircles.push_back(c4);
	allCircles.push_back(c5);
	allCircles.push_back(c6);
	allCircles.push_back(c7);

	unitDiskCenters.push_back(point);


    delunayTriangulation.insert(point);
    //dT.insert(point);
    dT.insert(p2);
    dT.insert(p3);
    dT.insert(p4);
    dT.insert(p5);
    dT.insert(p6);
    dT.insert(p7);
}
