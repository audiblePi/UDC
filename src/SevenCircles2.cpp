#include "SevenCircles2.h"
#include "CgalComponents.h"
#include <math.h>

SevenCircles2::SevenCircles2(vector<Point> &Points, vector<Point> &unitDiskCenters){
    unordered_map< Point, bool, Point_hasher, Point_equal> hashTable;
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

		auto search = hashTable.find(closestNeighbor->point());
		if( search != hashTable.end()){
			search->second = true;
			continue;
		}
    }

    for (auto &p : hashTable){
		if (p.second)
    		unitDiskCenters.push_back(p.first);
    }
}

void SevenCircles2::coverPoint(Point point, DelunayTriangulation &delunayTriangulation, unordered_map<Point, bool, Point_hasher, Point_equal> &hashTable){
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
		hashTable.emplace(point, center);
		delunayTriangulation.insert(point);
		center = false;
	}
}







/*
SevenCircles2::SevenCircles2(vector<Point> &Points, vector<Point> &unitDiskCenters){
   	unordered_map< Point, bool, Point_hasher, Point_equal> hashTable;
	DelunayTriangulation delunayTriangulationCenters;
	DelunayTriangulation delunayTriangulationExternals;
	bool isEmptyTriangulation = true;
	double test = 1 + sqrt(3.0);

    for( Point point : Points) {
    	if(isEmptyTriangulation) {
			unitDiskCenters.push_back(point);
			delunayTriangulationCenters.insert(point);
       		isEmptyTriangulation = false;
			continue;
    	}

		Vertex_handle closestNeighbor = delunayTriangulationCenters.nearest_vertex(point);
		double distance = sqrt(squared_distance(point, closestNeighbor->point()));

		if (distance > test) {
			unitDiskCenters.push_back(point);
			delunayTriangulationCenters.insert(point);
			continue;
		}

		if (distance > 1 && distance <= test) {
			bool covered = coverPoint(closestNeighbor->point(), point, unitDiskCenters, delunayTriangulationExternals, hashTable);
			if (!covered){
				unitDiskCenters.push_back(point);
				delunayTriangulationCenters.insert(point);
			}
			continue;
		}
    }
}

bool SevenCircles2::coverPoint(Point center, Point point, vector<Point> &unitDiscCenters, DelunayTriangulation &delunayTriangulationExternals, unordered_map<Point, bool, Point_hasher, Point_equal> &hashTable){
	vector<Point> newPoints;

	newPoints.push_back(Point(point.x() + sqrt(3.0), point.y()));
	newPoints.push_back(Point(point.x() + sqrt(3.0) / 2, point.y() + 1.5));
	newPoints.push_back(Point(point.x() + sqrt(3.0) / 2, point.y() - 1.5));
	newPoints.push_back(Point(point.x() - sqrt(3.0) / 2, point.y() + 1.5));
	newPoints.push_back(Point(point.x() - sqrt(3.0), point.y()));
	newPoints.push_back(Point(point.x() - sqrt(3.0) / 2, point.y() - 1.5));
   
	for (Point p : newPoints) {
		hashTable.emplace(p, false);
		delunayTriangulationExternals.insert(p);
	}

	Vertex_handle closest = delunayTriangulationExternals.nearest_vertex(point);
	double distance = sqrt(squared_distance(point, closest->point()));

	if (distance <= 1){		
		auto search = hashTable.find(closest->point());
		if( search != hashTable.end()){
			if (!search->second){
				unitDiscCenters.push_back(closest->point());
				search->second = true;
			}
			return true;
		}
	}
	return false;
}
*/