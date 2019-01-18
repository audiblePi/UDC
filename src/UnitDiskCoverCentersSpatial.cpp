#include "UnitDiskCoverCentersSpatial.h"
#include "CgalComponents.h"

UnitDiskCoverCentersSpatial::UnitDiskCoverCentersSpatial(vector<Point> &P, vector<Point> &C) {
  bool isEmptyTriangulation = true;
  const unsigned int N = 1;   
  Tree tree;

  for( Point p : P ) {
        if(isEmptyTriangulation) {
          isEmptyTriangulation = false;
          C.push_back(p);
          tree.insert(p);
        }
        else {
          Neighbor_search neighbor_search(tree, p, N);       
		      if (neighbor_search.begin()->second > 1) {
            C.push_back(p);
            tree.insert(p);
          }
        }
  }
}