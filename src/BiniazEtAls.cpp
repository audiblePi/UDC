#include "BiniazEtAls.h"
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

BiniazEtAls::BiniazEtAls(vector<Point> &P, vector<Point> &unitDiskCenters){
	vector<Point> coveredPoints;
	vector<Point> points = P;

    sort(points.begin(), points.end(), compareCircle());

    //first point, so cover and pop
    coverPoint(points.front(), unitDiskCenters, coveredPoints);
    points.erase(points.begin());

    while (points.size() > 0){    	
    	//find the closest point in coveredPoints to point
    	Point closestNeightbor = findClosestNeighbor(points.front(), coveredPoints);
    	//cout << " Closest Point: " << closestNeightbor.x() << ", " << closestNeightbor.y() << endl; 

    	//find the distance between point and closest covered point
    	int distance = squared_distance(points.front(), closestNeightbor);
    	//cout << " Closest Distance: " << distance << endl; 

    	//if distance is greater than 2, cover(p)
    	if (distance > 2){
    		coverPoint(points.front(), unitDiskCenters, coveredPoints);
    	}

    	//remove the first point
    	points.erase(points.begin());
    }
}

//brute force
Point BiniazEtAls::findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints){	
	Point closest;
	int minDistance = -1;

   	//calculate distance to each point
	for ( Point coveredPoint : coveredPoints ) {
		int tmpDistance = squared_distance(testPoint, coveredPoint);
		
		if (tmpDistance < minDistance || minDistance == -1){
			minDistance = tmpDistance;
			closest = coveredPoint;
		}
	}

	return closest;
}

void BiniazEtAls::coverPoint(Point point, vector<Point> &unitDiskCenters, vector<Point> &coveredPoints){
	Point c2(point.x() + sqrt(3.0), point.y());
	Point c3(point.x() + sqrt(3.0) / 2, point.y() + 1.5);
	Point c4(point.x() + sqrt(3.0) / 2, point.y() - 1.5);

	unitDiskCenters.push_back(point);
	unitDiskCenters.push_back(c2);
	unitDiskCenters.push_back(c3);
	unitDiskCenters.push_back(c4);

    coveredPoints.push_back(point);
}



