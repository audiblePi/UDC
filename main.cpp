#include "UnitDiskCoverPrinter.h"
#include "UnitDiskCoverCenters.h"
#include "UnitDiskCoverUnitGrid.h"
#include "BiniazEtAls.h"
#include "LRUDC.h"
#include "CgalComponents.h"

template<class Algorithm>
void run(vector<Point>& points, vector<Point>& centers, string filename, bool show, string name){
    clock_t begin, end;
    double elapsed_secs;

    cout << "***********" << name << " STARTED*********************" << endl;
    begin = clock();
    centers.clear();
    Algorithm algorithm(points, centers);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centers.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl;
    
    if (show) {
        UnitDiskCoverPrinter printer(points, centers, 1, filename);
        printer.displayPDF();
    }
}

int main() {
    vector<Point> points, centersOfPlacedDisks;
    int numPoints, graphSize;
    bool showOutput;

    cout << endl << "Number of points? : ";
    cin >> numPoints;
    cout << "Size of graph? : ";
    cin >> graphSize;
    cout << "Show output? (1/0): ";
    cin >> showOutput;

    points.reserve(numPoints);

    Random_points_in_square_2<Point,Creator> g1(graphSize);
    std::copy_n(g1, numPoints/2, back_inserter(points));

    Random_points_in_disc_2<Point,Creator> g2(30.0);
    std::copy_n(g2, numPoints/2, back_inserter(points));

    cout << endl << "Point generation completed" << endl << endl;

    //run<UnitDiskCoverCenters>(points, centersOfPlacedDisks, "output_centers", showOutput, "Centers");
    //run<UnitDiskCoverUnitGrid>(points, centersOfPlacedDisks, "output_grid", showOutput, "Grids");
    //run<BiniazEtAls>(points, centersOfPlacedDisks, "output_biniaz", showOutput, "BiniazEtAls");
    run<LRUDC>(points, centersOfPlacedDisks, "output_lrudc", showOutput, "LRUDC");

    return EXIT_SUCCESS;
}
