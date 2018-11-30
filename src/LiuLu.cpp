#include "LiuLu.h"
#include "CgalComponents.h"

LiuLu::LiuLu(vector<Point> &P, vector<Point> &C) {

    unsigned answer = P.size()+1;

    //maybe storing the sorted array and copying at the start of every iteration is faster?

    for(unsigned i = 0; i < 6; i++) {
        sort(P.begin(), P.end(), [](const Point& pi, const Point& pj) { return (pi.x() < pj.x()) || ( pi.x() == pj.x() && pi.y() < pj.y());});
        unsigned current = 0;
        long double leftOfCurrentStrip = P[0].x() - std::sqrt(3) + ((i*std::sqrt(3))/6), rightOfCurrentStrip = leftOfCurrentStrip + std::sqrt(3);
        vector<Point> tempC;

        while( current < P.size() ) {
            unsigned indexOfTheFirstPointInTheCurrentStrip = current;
            while(P[current].x() < rightOfCurrentStrip && current < P.size())
                current++;

            if( current > indexOfTheFirstPointInTheCurrentStrip )
                sort(P.begin()+indexOfTheFirstPointInTheCurrentStrip, P.begin()+current, [](const Point& pi, const Point& pj) { return ( pi.y() > pj.y());});

            long double lowestYsoFar = P[indexOfTheFirstPointInTheCurrentStrip].y() + 2;

            for(unsigned j = indexOfTheFirstPointInTheCurrentStrip; j < current; j++) {
                long double xOfRestrictionline = rightOfCurrentStrip - (std::sqrt(3)/2), distanceFromRestrictionLine = P[j].x()-xOfRestrictionline;
                long double y = std::sqrt(1-(distanceFromRestrictionLine*distanceFromRestrictionLine));

                if(P[j].y()+y < lowestYsoFar) {
                    tempC.push_back(Point(xOfRestrictionline,P[j].y()-y));
                    lowestYsoFar = P[j].y()-y;
                }
            }
            leftOfCurrentStrip = rightOfCurrentStrip;
            rightOfCurrentStrip += std::sqrt(3);
       }

       if( tempC.size() < answer) {
           answer = tempC.size();
           C.clear();

           for(Point p : tempC)
                C.push_back(p);
       }
    }
}
