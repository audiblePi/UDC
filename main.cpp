#include "UnitDiskCoverPrinter.h"
#include "UnitDiskCoverCenters.h"
#include "UnitDiskCoverUnitGrid.h"
#include "BiniazEtAls.h"
#include "LRUDC.h"
#include "LRUDC_Shift.h"
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

void loadFromFile(vector<Point> &points){
    int count = 0;
    int a;
    double b, c;
    ifstream inFile, runFile;
    
    inFile.open("data/world.tsp");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> a >> b >> c) {
        count = count + 1;
    }

    inFile.close();

    points.reserve(count);

    inFile.open("data/world.tsp");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> a >> b >> c) {
        //cout << "Line = " << a << ": " << b << ", " << c << endl; 
        Point p(b, c);
        points.push_back(p);
    }
    
    inFile.close();
}

void loadRandom(vector<Point> &points, int numPoints, int graphSize){
    points.reserve(numPoints);

    Random_points_in_square_2<Point,Creator> g1(graphSize);
    std::copy_n(g1, numPoints/2, back_inserter(points));

    Random_points_in_disc_2<Point,Creator> g2(30.0);
    std::copy_n(g2, numPoints/2, back_inserter(points));
}

int main() {
    vector<Point> points, centersOfPlacedDisks;
    int numPoints, graphSize;
    bool useFile, showOutput;

    cout << "Load from file (world.tsp)? (1/0): ";
    cin >> useFile;

    if (useFile){
        loadFromFile(points);
    }
    else {
        cout << endl << "Number of points? : ";
        cin >> numPoints;
        cout << "Size of graph? : ";
        cin >> graphSize;
        loadRandom(points, numPoints, graphSize);
    }

    cout << endl << "Point generation completed" << points.size() << endl;

    cout << "Show output? (1/0): ";
    cin >> showOutput;


    run<UnitDiskCoverCenters>(points, centersOfPlacedDisks, "output_centers", showOutput, "Centers");
    run<UnitDiskCoverUnitGrid>(points, centersOfPlacedDisks, "output_grid", showOutput, "Grids");
    run<BiniazEtAls>(points, centersOfPlacedDisks, "output_biniaz", showOutput, "BiniazEtAls");
    run<LRUDC>(points, centersOfPlacedDisks, "output_lrudc", showOutput, "LRUDC");
    run<LRUDC_Shift>(points, centersOfPlacedDisks, "output_lrudc_shift", showOutput, "LRUDC_Shift");

    return EXIT_SUCCESS;
}
