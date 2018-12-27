#include "SevenCircles2.h"
#include "CgalComponents.h"
#include <math.h>

SevenCircles2::SevenCircles2(vector<Point> &Points, vector<Point> &unitDiskCenters){
    unordered_map< Node, Node, Node_hash, Compare_node> hashTable;
	DelunayTriangulation delunayTriangulation;
	bool isEmptyTriangulation = true;

    for( Point point : Points) {
    	if(isEmptyTriangulation) {
			coverPoint(point, delunayTriangulation, hashTable);
       		isEmptyTriangulation = false;
			continue;
    	}

		Vertex_handle closestNeighbor = delunayTriangulation.nearest_vertex(point);
		double distance = squared_distance(point, closestNeighbor->point());

		if (distance > 1) {
			coverPoint(point, delunayTriangulation, hashTable);
			continue;
		}

		Node key = {closestNeighbor->point(), true};
		auto search = hashTable.find(key);
		if( search != hashTable.end()){
			search->second.active = true;
			continue;
		}
    }

    for (auto &node : hashTable){
		if (node.second.active)
    		unitDiskCenters.push_back(node.second.p);
    }
}

void SevenCircles2::coverPoint(Point point, DelunayTriangulation &delunayTriangulation, unordered_map<Node, Node, Node_hash, Compare_node> &hashTable){
	vector<Point> newPoints;
    bool center = true;

	newPoints.push_back(point);
	newPoints.push_back(Point(point.x() + sqrt(3.0), point.y()));
	newPoints.push_back(Point(point.x() + sqrt(3.0) / 2, point.y() + 1.5));
	newPoints.push_back(Point(point.x() + sqrt(3.0) / 2, point.y() - 1.5));
	newPoints.push_back(Point(point.x() - sqrt(3.0) / 2, point.y() + 1.5));
	newPoints.push_back(Point(point.x() - sqrt(3.0), point.y()));
	newPoints.push_back(Point(point.x() - sqrt(3.0) / 2, point.y() - 1.5));
   
	for (Point point : newPoints) {
		Node node = {point, false};

		if (center){
			node = {point, true};
			center = false;
		}
		
		hashTable.emplace(node, node);
		delunayTriangulation.insert(point);
	}
}
