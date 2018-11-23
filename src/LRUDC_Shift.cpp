#include "LRUDC_Shift.h"
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

LRUDC_Shift::LRUDC_Shift(vector<Point> &Points, vector<Point> &unitDiskCenters){
    sort(Points.begin(), Points.end(), sortByX());
    
    double base = sqrt(3.0)/6.0;
    vector<double> shift = {0, 1.0*base, 2.0*base, 3.0*base, 4.0*base, 5.0*base};
	double baseSweepLine = Points[0].x() - shift[5];
	long unsigned int best = -1;

    for (double alpha : shift) {
    	double sweepLine = baseSweepLine + alpha;
    	double stripIndex = 0;
    	vector<Point> shiftCenters;

    	sort(Points.begin(), Points.end(), sortByX());

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
								shiftCenters.push_back(Point( restrictionLine, nextDiscCenter ));
								nextDiscCenter = Points[j].y() - y;
							}

							if (j+1 == currentIndex) {
								shiftCenters.push_back(Point( restrictionLine, nextDiscCenter ));
							}
						}
					}
					stripIndex = currentIndex;
					break;
				}
			}
	  		sweepLine += sqrt(3.0);
	   	}

		if (best == -1 || shiftCenters.size() <  best){
	   		best = shiftCenters.size();
	   		unitDiskCenters.clear();
	   		copy(shiftCenters.begin(), shiftCenters.end(), back_inserter(unitDiskCenters)); 
	   	}
	}
}