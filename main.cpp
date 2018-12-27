#include "UnitDiskCoverPrinter.h"
#include "UnitDiskCoverCenters.h"
#include "UnitDiskCoverUnitGrid.h"
#include "BiniazEtAls.h"
#include "LRUDC.h"
#include "LRUDC_Shift.h"
#include "LinesAlgorithm.h"
#include "LinesAlgorithm_Shift.h"
#include "LiuLu.h"
#include "SevenCircles.h"
#include "SevenCircles2.h"
#include "CgalComponents.h"

template<class Algorithm>
void run(vector<Point>& points, vector<Point>& centers, string filename, bool show, bool os, string name){
    clock_t begin, end;
    double elapsed_secs;

    cout << endl << "***********" << name << " STARTED*********************" << endl;
    begin = clock();
    centers.clear();
    Algorithm algorithm(points, centers);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centers.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl << endl;

    if (show) {
        UnitDiskCoverPrinter printer(points, centers, 1, filename, os);
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
    bool useFile, showOutput, osPrinter;

    cout  << endl << "Load from file (world.tsp)? (1/0): ";
    cin >> useFile;

    if (useFile){
        loadFromFile(points);
    }
    else {
        cout << "Number of points? : ";
        cin >> numPoints;
        cout << "Size of graph? : ";
        cin >> graphSize;
        loadRandom(points, numPoints, graphSize);
    }

    cout << "Point generation completed " << points.size() << endl;

    cout << "Show output? (1/0): ";
    cin >> showOutput;

    if (showOutput){
        cout << "Mac(1) or Linux(0)?: ";
        cin >> osPrinter;
    }

    //run<UnitDiskCoverCenters>(points, centersOfPlacedDisks, "output_centers", showOutput, osPrinter, "Centers");
    run<UnitDiskCoverUnitGrid>(points, centersOfPlacedDisks, "output_grid", showOutput, osPrinter, "Grids");
    run<BiniazEtAls>(points, centersOfPlacedDisks, "output_biniaz", showOutput, osPrinter, "BiniazEtAls");
    run<LRUDC>(points, centersOfPlacedDisks, "output_lrudc", showOutput, osPrinter, "LRUDC");
    run<LRUDC_Shift>(points, centersOfPlacedDisks, "output_lrudc_shift", showOutput, osPrinter, "LRUDC_Shift");
    //run<LinesAlgorithm>(points, centersOfPlacedDisks, "output_linesalgorithm", showOutput, osPrinter, "LinesAlgorithm");
    //run<LinesAlgorithm_Shift>(points, centersOfPlacedDisks, "output_linesalgorithm_shift", showOutput, osPrinter, "LinesAlgorithm_Shift");
    run<LiuLu>(points, centersOfPlacedDisks, "output_liulu", showOutput, osPrinter, "LiuLu");
    run<SevenCircles>(points, centersOfPlacedDisks, "output_sevencircles", showOutput, osPrinter, "SevenCircles");
    run<SevenCircles2>(points, centersOfPlacedDisks, "output_sevencircles2", showOutput, osPrinter, "SevenCircles2");

    return EXIT_SUCCESS;
}
