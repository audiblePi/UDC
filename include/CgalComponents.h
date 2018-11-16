#ifndef CGALCOMPONENTS_H
#define CGALCOMPONENTS_H

#include <vector>
#include <algorithm>
#include <ctime>
#include <unordered_set>

#include <iterator>
#include <boost/bind.hpp>

/**********************CGAL headers files**************************/
#include <CGAL/point_generators_2.h>
#include <CGAL/algorithm.h>
#include <CGAL/random_selection.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include <CGAL/Exact_circular_kernel_2.h>
#include <CGAL/Circular_kernel_intersections.h>
#include <CGAL/Exact_circular_kernel_2.h>
#include <CGAL/Circular_kernel_intersections.h>
#include <CGAL/intersections.h>
#include <CGAL/result_of.h>
#include <CGAL/iterator.h>
#include <CGAL/point_generators_2.h>
/******************************************************************/

using namespace CGAL;

typedef Exact_predicates_inexact_constructions_kernel K;
typedef Delaunay_triangulation_2<K>			DelunayTriangulation;
typedef K::Point_2                      	Point;
typedef K::Line_2                      		Line;
typedef Creator_uniform_2<double,Point> 	Creator;
typedef DelunayTriangulation::Vertex_handle Vertex_handle;
typedef Circle_2<K> 						Circle;

typedef CGAL::Exact_circular_kernel_2        CircK;
typedef CGAL::Point_2<CircK>                 Point_K;
typedef CGAL::Circle_2<CircK>                Circle_K;
typedef CGAL::Line_arc_2<CircK>              LineArc_K;
typedef boost::variant<std::pair<CGAL::Circular_arc_point_2<CircK>, unsigned> > IntersectionResult;
typedef CGAL::cpp11::result_of<CircK::Intersect_2(Circle_K,LineArc_K,std::back_insert_iterator<std::vector<IntersectionResult> >)>::type Res;

using namespace std;

#endif

