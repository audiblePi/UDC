#include "BiniazEtAls.h"
#include "CgalComponents.h"
#include <math.h> 

//sort the points
//find the closest point in coveredPoints to point
//find the distance between point and closest covered point
//if distance is greater than 2, cover(p)
//remove the first point

struct compareCircle {
	bool operator()(const Circle &c1, const Circle &c2) { 
		if (c1.center().x() == c2.center().x()){
	    	return (c1.center().y() < c2.center().y()); 
	    } else {
		    return (c1.center().x() < c2.center().x()); 
		}
	} 
};




// BiniazEtAls::BiniazEtAls(vector<Point> &Points, vector<Point> &unitDiskCenters){
// 	vector<Point> coveredPoints;
//     cout << coveredPoints.size() << endl;

//     sort(Points.begin(), Points.end(), compareCircle());

//     for( Point point : Points) {
//     	if ( coveredPoints.size() == 0 ){
// 		    coverPoint(point, unitDiskCenters, coveredPoints);
//     	} else {
// 	    	Point closestNeightbor = findClosestNeighbor(point, coveredPoints);
// 	    	int distance = squared_distance(point, closestNeightbor);

// 	    	if (distance > 2){
// 	    		coverPoint(point, unitDiskCenters, coveredPoints);
// 	   		}
// 	   	}
//     }
// }

// Point BiniazEtAls::findClosestNeighbor(Point &testPoint, vector<Point> &coveredPoints){	
// 	Point closest;
// 	int minDistance = -1;

//    	//calculate distance to each point
// 	for ( Point coveredPoint : coveredPoints ) {
// 		int tmpDistance = squared_distance(testPoint, coveredPoint);
		
// 		if (tmpDistance < minDistance || minDistance == -1){
// 			minDistance = tmpDistance;
// 			closest = coveredPoint;
// 		}
// 	}

// 	return closest;
// }

// void BiniazEtAls::coverPoint(Point point, vector<Point> &unitDiskCenters, vector<Point> &coveredPoints){
// 	Point c2(point.x() + sqrt(3.0), point.y());
// 	Point c3(point.x() + sqrt(3.0) / 2, point.y() + 1.5);
// 	Point c4(point.x() + sqrt(3.0) / 2, point.y() - 1.5);

// 	unitDiskCenters.push_back(point);
// 	unitDiskCenters.push_back(c2);
// 	unitDiskCenters.push_back(c3);
// 	unitDiskCenters.push_back(c4);

//    coveredPoints.push_back(point);
// }










BiniazEtAls::BiniazEtAls(vector<Point> &Points, vector<Point> &unitDiskCenters){
	DelunayTriangulation delunayTriangulation;
	bool isEmptyTriangulation = true;

    sort(Points.begin(), Points.end(), compareCircle());

    for( Point point : Points) {
    	if(isEmptyTriangulation) {
			coverPoint(point, unitDiskCenters, delunayTriangulation);
    		isEmptyTriangulation = false;
    	} else {
	        Vertex_handle closestNeightbor = delunayTriangulation.nearest_vertex(point);
	    	int distance = squared_distance(point, closestNeightbor->point());

	    	if (distance > 2){
	    		coverPoint(point, unitDiskCenters, delunayTriangulation);
	   		}
	   	}
    }
}

void BiniazEtAls::coverPoint(Point point, vector<Point> &unitDiskCenters, DelunayTriangulation &delunayTriangulation){
	Point c2(point.x() + sqrt(3.0), point.y());
	Point c3(point.x() + sqrt(3.0) / 2, point.y() + 1.5);
	Point c4(point.x() + sqrt(3.0) / 2, point.y() - 1.5);

	unitDiskCenters.push_back(point);
	unitDiskCenters.push_back(c2);
	unitDiskCenters.push_back(c3);
	unitDiskCenters.push_back(c4);

   delunayTriangulation.insert(point);
}









// BiniazEtAls::BiniazEtAls(vector<Point> &P, vector<Point> &C){
//     vector<Point> I;

//     DelunayTriangulation T;
//     bool isEmptyTriangulation = true;

//     sort(P.begin(), P.end(), [](const Point& pi, const Point& pj) {
//                                     return (pi.x() < pj.x()) || ( pi.x() == pj.x() && pi.y() < pj.y());
//                             });

//     for( Point p : P) {
//         if(isEmptyTriangulation) {
//           isEmptyTriangulation = false;
//           C.push_back(p);
//           C.push_back( Point( p.x() + std::sqrt(3), p.y() ) );
//           C.push_back( Point( p.x() + std::sqrt(3)/2, p.y() - 1.5 ) );
//           C.push_back( Point( p.x() + std::sqrt(3)/2, p.y() + 1.5 ) );

//           T.insert(p);
//         }
//         else {
//           Vertex_handle handleToTheNearestPoint = T.nearest_vertex(p);
//           if(squared_distance(p,handleToTheNearestPoint->point()) > 2) {
//             C.push_back(p);
//             C.push_back( Point( p.x() + std::sqrt(3), p.y() ) );
//             C.push_back( Point( p.x() + std::sqrt(3)/2, p.y() - 1.5 ) );
//             C.push_back( Point( p.x() + std::sqrt(3)/2, p.y() + 1.5 ) );

//             T.insert(p);
//           }
//         }
//     }
// }





