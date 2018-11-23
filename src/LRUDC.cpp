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
    int stripIndex = 0;
    double sweepLine = Points[stripIndex].x();

    while (sweepLine < Points.back().x()){
       	for (int currentIndex = stripIndex; Points[currentIndex].x() <= Points.back().x(); currentIndex++) {			
			if ( !(Points[currentIndex].x() >= sweepLine && Points[currentIndex].x() < sweepLine + sqrt(3.0)) ) {
				if (stripIndex != currentIndex) {					
					sort(Points.begin() + stripIndex, Points.begin() + currentIndex, sortByY());
					bool firstInStrip = true;
					double restrictionLine = sweepLine + sqrt(3.0) / 2.0;
					double nextDiscCenter;

					for(int j=stripIndex; j < currentIndex; j++) {
						double y = sqrt ( 1 - pow(restrictionLine - Points[j].x(), 2.0) );

						if (firstInStrip){
							nextDiscCenter = Points[j].y() - (sqrt (1 - pow(restrictionLine - Points[stripIndex].x(), 2.0)));
							firstInStrip = false;
						}

						if ((Points[j].y() + y < nextDiscCenter)) {
							unitDiskCenters.push_back(Point( restrictionLine, nextDiscCenter ));
							nextDiscCenter = Points[j].y() - y;
						}

						if (j+1 == currentIndex) {
							unitDiskCenters.push_back(Point( restrictionLine, nextDiscCenter ));
						}
					}
				}
				stripIndex = currentIndex;
				break;
			}
		}
    	sweepLine += sqrt(3.0);
    }
}