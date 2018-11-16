#include "LRUDC.h"
#include "CgalComponents.h"
#include <math.h> 

/**
Sort By X
sweepLine SL = P(0) - Something
endingPoint E = P.end()
While i < E
	Slice [ SL : SL + i * sqrt(3) ]
	Restriction Line L = SL + sqrt(3) / 2 
	Sort Points in Slice by Y
	For Each Point in Slice
		If Uncovered
			Place a Unit Circle U with center P
			Find Intersection Points of U with SL
			Place Unit Circle U at Lowest Intersection Point
	i += SL + i * sqrt(3)	
**/

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
    // resort by y
    sort(Points.begin(), Points.end(), sortByX());

    int sliceIndex = 0;
    double sweepLine = Points[sliceIndex].x();
    double endingPoint = Points.back().x();

    //build slices
    //sort each sub array strip

    // for each slice
    while ( sweepLine < endingPoint ) {
    	vector<Point> slice;
		
    	//build slice
    	for ( long unsigned int i = 0; i < Points.size(); i++ ) {			
			if ( Points[i].x() >= sweepLine && Points[i].x() < sweepLine + sqrt(3.0) ) {
				slice.push_back(Points[i]);
			}
		}

		// sort then process
		// if we use python dont need individual objects
		if (slice.size() > 0){
   			Point p(sweepLine + sqrt(3.0) / 2.0, 1000000);
   			Point q(sweepLine + sqrt(3.0) / 2.0, -1000000);
   			Line restrictionLine( p, q );

   			sort(Points.begin(), Points.end(), sortByY());

			for (Point p : slice) {
				Circle tempDisc(p, 1, CGAL::COUNTERCLOCKWISE);
				
			    vector<IntersectionResult> result;
			    CGAL::intersection(restrictionLine, tempDisc, std::back_inserter(result));

				//unitDiskCenters.push_back(c);
			}
		}

		slice.clear();
    	sweepLine += sqrt(3.0);
    }
}




