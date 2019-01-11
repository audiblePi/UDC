#include "SevenCirclesSpatial.h"
#include "CgalComponents.h"
#include <math.h>

//https://planet.openstreetmap.org/gps/
//https://wiki.openstreetmap.org/wiki/Planet.osm
//https://www.openstreetmap.org
//https://data.world/datasets/gps

SevenCirclesSpatial::SevenCirclesSpatial(vector<Point> &Points, vector<Point> &unitDiskCenters){
    unordered_map< Point, bool, Point_hasher2, Point_equal2> hashTable;
	bool isEmptyTriangulation = true;

    const unsigned int N = 1;   
    Tree tree;

    for( Point point : Points) {
    	if(isEmptyTriangulation) {
			coverPoint(point, hashTable, tree);
       		isEmptyTriangulation = false;
			continue;
    	}

        Neighbor_search neighbor_search(tree, point, N);       
		if (neighbor_search.begin()->second > 1) {
			coverPoint(point, hashTable, tree);
			continue;
		}

		auto hash_search = hashTable.find(neighbor_search.begin()->first);
		if( hash_search != hashTable.end()){
			hash_search->second = true;
			continue;
		}
    }

    for (auto &p : hashTable){
		if (p.second)
    		unitDiskCenters.push_back(p.first);
    }
}

void SevenCirclesSpatial::coverPoint(Point point, unordered_map<Point, bool, Point_hasher2, Point_equal2> &hashTable, Tree &tree){
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
        tree.insert(point);
		center = false;
	}
}