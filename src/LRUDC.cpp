#include "LRUDC.h"
#include "CgalComponents.h"
#include <math.h> 

struct sortByX {
	bool operator()(const Point &p1, const Point &p2) { 
		return (p1.x() < p2.x()); 
	} 
};

struct sortByY {
	bool operator()(const Point &p1, const Point &p2) { 
		return (p1.y() > p2.y());	   
	} 
};

LRUDC::LRUDC(vector<Point> &Points, vector<Point> &unitDiskCenters){
    sort(Points.begin(), Points.end(), sortByX());

    int sliceIndex = 0;
    double sweepLine = Points[sliceIndex].x();

    // for each slice
    while (sweepLine < Points.back().x()){
		//cout << endl << ">>> sweepLine: " << sweepLine << ", sliceIndex: " << sliceIndex << endl;
    	
    	//find the points in this slice
    	for (int currentIndex = sliceIndex; Points[currentIndex].x() <= Points.back().x(); currentIndex++) {			
			//cout << "point currentIndex: " << Points[currentIndex].x() << ", " << Points[currentIndex].y() << " -> boundary: " << sweepLine + sqrt(3.0) << endl;

			if ( (Points[currentIndex].x() >= sweepLine && Points[currentIndex].x() < sweepLine + sqrt(3.0)) ) {
				//cout << " Slice Points: " << Points[currentIndex].x() << ", " << Points[currentIndex].y() << endl; 	
			} 
			else {
				if (sliceIndex != currentIndex) {
					//cout << "slice is done: " << sliceIndex << " to " << currentIndex << endl;
					
					sort(Points.begin() + sliceIndex, Points.begin() + currentIndex, sortByY());
					bool firstInSlice = true;
					double restrictionLine = sweepLine + sqrt(3.0) / 2.0;
					double nextDiscCenter;

					for(int j=sliceIndex; j < currentIndex; j++) {
						//cout << " Slice Points: " << Points[j].x() << ", " << Points[j].y() << endl; 			

						// find intersections with restrictionLine
						double y = sqrt ( 1 - pow(restrictionLine - Points[j].x(), 2.0) );

						if (firstInSlice){
							nextDiscCenter = Points[j].y() - (sqrt (1 - pow(restrictionLine - Points[sliceIndex].x(), 2.0)));
							firstInSlice = false;
						}

						//if there is no overlap, place disc at last center
						if ((Points[j].y() + y < nextDiscCenter)) {
							unitDiskCenters.push_back(Point( restrictionLine, nextDiscCenter ));
							nextDiscCenter = Points[j].y() - y;
						}

						//if this is the last point, place disc at last center
						if (j+1 == currentIndex) {
							unitDiskCenters.push_back(Point( restrictionLine, nextDiscCenter ));
						}
					}
				}
				sliceIndex = currentIndex;
				break;
			}
		}

    	sweepLine += sqrt(3.0);
    }
}