#include "UnitDiskCoverExperimental.h"
#include "CgalComponents.h"

struct pair_hash {
    inline size_t operator()(const pair<int,int> &v) const {
        return v.first*31+v.second;
    }
};

UnitDiskCoverExperimental::UnitDiskCoverExperimental(vector<Point> &P,vector<Point> &C) {
    C.clear();

    unordered_set< pair<int,int>, pair_hash> hashTableForDiskCenters;

    for( Point p : P ) {
            int col = floor(p.y()/sqrt(3.0)), row = floor(p.x());

            if( row % 2 == 0) {
                if( col % 2 != 0) {

                    Circle c1(Point(row+1,col*sqrt(3.0)),1), c2(Point(row,(col+1)*sqrt(3.0),1));

                    /* p belongs to c1 but not to c2*/
                    if( !c1.has_on_unbounded_side(p) && c2.has_on_unbounded_side(p)) {
                        auto search = hashTableForDiskCenters.find(make_pair(row+1,col*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row+1,col*sqrt(3.0)));
                             C.push_back(Point(row+1,col*sqrt(3.0)));
                        }
                    }
                    /* p belongs to c2 but not to c1*/
                    else if(c1.has_on_unbounded_side(p) && !c2.has_on_unbounded_side(p) ){
                        auto search = hashTableForDiskCenters.find(make_pair(row,(col+1)*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row,(col+1)*sqrt(3.0)));
                             C.push_back(Point(row,(col+1)*sqrt(3.0)));
                        }
                    }
                }
                else {
                    
                    Circle c1(Point(row,col*sqrt(3.0)),1), c2(Point(row+1,(col+1)*sqrt(3.0)),1);

                    /* p belongs to c1 but not to c2*/
                    if( !c1.has_on_unbounded_side(p) && c2.has_on_unbounded_side(p)) {
                        auto search = hashTableForDiskCenters.find(make_pair(row,col*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row,col*sqrt(3.0)));
                             C.push_back(Point(row,col*sqrt(3.0)));
                        }
                    }
                    /* p belongs to c2 but not to c1*/
                    else if(c1.has_on_unbounded_side(p) && !c2.has_on_unbounded_side(p) ){
                        auto search = hashTableForDiskCenters.find(make_pair(row+1,(col+1)*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row+1,(col+1)*sqrt(3.0)));
                             C.push_back(Point(row+1,(col+1)*sqrt(3.0)));
                        }
                    }
                }
            }
            else {
                if( col % 2 != 0) {
                    
                   Circle c1(Point(row,col*sqrt(3.0)),1), c2(Point(row+1,(col+1)*sqrt(3.0)),1);

                    /* p belongs to c1 but not to c2*/
                    if( !c1.has_on_unbounded_side(p) && c2.has_on_unbounded_side(p)) {
                        auto search = hashTableForDiskCenters.find(make_pair(row,col*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row,col*sqrt(3.0)));
                             C.push_back(Point(row,col*sqrt(3.0)));
                        }
                    }
                    /* p belongs to c2 but not to c1*/
                    else if(c1.has_on_unbounded_side(p) && !c2.has_on_unbounded_side(p) ){
                        auto search = hashTableForDiskCenters.find(make_pair(row+1,(col+1)*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row+1,(col+1)*sqrt(3.0)));
                             C.push_back(Point(row+1,(col+1)*sqrt(3.0)));
                        }
                    }
                }
                else {

                    Circle c1(Point(row,(col+1)*sqrt(3.0)),1), c2(Point(row+1,col*sqrt(3.0)),1);

                    /* p belongs to c1 but not to c2*/
                    if( !c1.has_on_unbounded_side(p) && c2.has_on_unbounded_side(p)) {
                        auto search = hashTableForDiskCenters.find(make_pair(row,(col+1)*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row,(col+1)*sqrt(3.0)));
                             C.push_back(Point(row,(col+1)*sqrt(3.0)));
                        }

                    }
                    /* p belongs to c2 but not to c1*/
                    else if(c1.has_on_unbounded_side(p) && !c2.has_on_unbounded_side(p) ){
                        auto search = hashTableForDiskCenters.find(make_pair(row+1,col*sqrt(3.0)));
                        if( search == hashTableForDiskCenters.end()) {
                             hashTableForDiskCenters.emplace(pair<int,int>(row+1,col*sqrt(3.0)));
                             C.push_back(Point(row+1,col*sqrt(3.0)));
                        }
                    }

                }
            }
    }
    hashTableForDiskCenters.clear();
}
