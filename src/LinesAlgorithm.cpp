#include "LinesAlgorithm.h"
#include "CgalComponents.h"

LinesAlgorithm::LinesAlgorithm(vector<Point> &P, vector<Point> &C) {
    vector<Segment> Segments;

    sort(P.begin(), P.end(), [](const Point& pi, const Point& pj) {
                                    return (pi.x() < pj.x()) || ( pi.x() == pj.x() && pi.y() < pj.y());
                            });
    bool sorted = false;
    double constant = -17;
    double counter = -35;
    int index = 0;
    int length = P.size();
    while(P.front().x() > constant*sqrt(3.0)){
        constant++;
        counter += 2;
    }
    while(!(constant+1*sqrt(3.0) >= P.back().x())){
        Segments.clear();
        for(int i = index; i <= length; ++i){
            if(!(P[i].x() <= constant*sqrt(3.0) && P[i].x() >= (constant - 1)*sqrt(3.0))){
                sort(P.begin() + index, P.begin() + i, [](const Point& pi, const Point& pj) {
                                            return pi.y() < pj.y();
                                    });
                length = i;
            }
        }
        for(int j = index; j < length; j++){
            Point onRestrLine((counter*sqrt(3.0)/2), P[j].y());
            double distance = sqrt(squared_distance(P[j], onRestrLine));
            double pointLength = sqrt(1-pow(distance, 2));

            Point topPoint(onRestrLine.x(), onRestrLine.y() + pointLength);
            Point bottomPoint(onRestrLine.x(), onRestrLine.y() - pointLength);
            Segment seg(topPoint, bottomPoint);
            Segments.push_back(seg);
        }
        index = length;
        length = P.size();
        sort(Segments.begin(), Segments.end(), [](Segment& si, Segment& sj) {
                                                    return si.max() > sj.max();
                            });

        for(int i = 0; i < Segments.size(); i++){
            if(Segments[i].min() < Segments[i+1].max()){
                C.push_back(midpoint(Segments[i].min(), Segments[i+1].max()));
                Segments.erase(Segments.begin() + i+1);
                i--;
            }else{
                C.push_back(midpoint(Segments[i].max(), Segments[i].min()));
            }
        }
        constant++;
        counter += 2;
    }
}
