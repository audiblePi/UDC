#include "LinesAlgorithm_Shift.h"
#include "CgalComponents.h"

LinesAlgorithm_Shift::LinesAlgorithm_Shift(vector<Point> &P, vector<Point> &C) {
    vector<double> Shifts = {sqrt(3.0), sqrt(3.0) + sqrt(3.0)/6, sqrt(3.0) + (2*sqrt(3.0))/6, sqrt(3.0) + (3*sqrt(3.0))/6, sqrt(3.0) + (4*sqrt(3.0))/6, sqrt(3.0) + (5*sqrt(3.0))/6};
    vector<Segment> Segments;

    long unsigned int best = -1;
    for(double shift: Shifts){

        sort(P.begin(), P.end(), [](const Point& pi, const Point& pj) {
                                    return (pi.x() < pj.x()) || ( pi.x() == pj.x() && pi.y() < pj.y());
                            });

        bool sorted = false;
        double constant = -17;
        double counter = -35;
        int index = 0;
        int length = P.size();
        vector<Segment> Segments;
        vector<Point> shiftingCenters;

        while(P.front().x() > constant*shift){
            constant++;
            counter += 2;
        }
        while(sorted == false){
            Segments.clear();
            if(constant*shift >= P.back().x()){
                sorted = true;
            }
            for(int i = index; i <= length; ++i){
                if(!(P[i].x() <= constant*shift && P[i].x() >= (constant - 1)*shift)){
                    sort(P.begin() + index, P.begin() + i, [](const Point& pi, const Point& pj) {
                                                return pi.y() < pj.y();
                                        });
                    length = i;
                }
            }
            bool first = true;
            for(int j = index; j < length; j++){
                Point onRestrLine((counter*shift/2), P[j].y());
                double distance = sqrt(squared_distance(P[j], onRestrLine));
                double pointLength = sqrt(1-pow(distance, 2));

                Point topPoint(onRestrLine.x(), onRestrLine.y() + pointLength);
                Point bottomPoint(onRestrLine.x(), onRestrLine.y() - pointLength);
                Segment seg(topPoint, bottomPoint);
            }
            index = length;
            length = P.size();
            sort(Segments.begin(), Segments.end(), [](Segment& si, Segment& sj) {
                                                        return si.max() > sj.max();
                                });

            for(int i = 0; i < Segments.size(); i++){
                //shiftingCenters.push_back(Segments[i].min());
                if(Segments[i].min() < Segments[i+1].max()){
                    shiftingCenters.push_back(midpoint(Segments[i].min(), Segments[i+1].max()));
                    //Segments.erase(Segments.begin() + i);
                }else{
                    shiftingCenters.push_back(midpoint(Segments[i].max(), Segments[i].min()));
                }
            }
            constant++;
            counter += 2;
        }
        if(best == -1 || shiftingCenters.size() < best){
            best = shiftingCenters.size();
	   		C.clear();
	   		copy(shiftingCenters.begin(), shiftingCenters.end(), back_inserter(C));
        }
    }
}
