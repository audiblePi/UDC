#include "UnitDiskCoverPrinter.h"
#include "UnitDiskCoverCenters.h"
#include "UnitDiskCoverCentersSpatial.h"
#include "UnitDiskCoverUnitGrid.h"
#include "UnitDiskCoverExperimental.h"
#include "BiniazEtAls.h"
#include "LRUDC.h"
#include "LRUDC_Shift.h"
#include "LinesAlgorithm.h"
#include "LinesAlgorithm_Shift.h"
#include "LiuLu.h"
#include "SevenCircles.h"
#include "SevenCircles2.h"
#include "SevenCirclesSpatial.h"
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
    cout << "Time taken: " << elapsed_secs << endl;

    if (show) {
        UnitDiskCoverPrinter printer(points, centers, 1, filename, os);
        printer.displayPDF();
    }

    cout << "Running Test... ";
    
    int covered = 0;

    for (Point p: points) {
        for (Point c: centers) {
            double distance = squared_distance(p, c);
            if (sqrt(distance) <= 1.0){
                covered = covered + 1;
                break;
            }
        }
    }

    double percent_covered = ( (double)covered / (double)points.size() ) * 100.0;
    cout << setprecision(4) << covered << " of " << points.size() << ", " << percent_covered << "% covered" << endl;
}

void loadFromFile(vector<Point> &points){
    int count = 0;
    int menuChoice;
    double a, b;
    string fileName;

    ifstream inFile, runFile;

    cout << "Choose File" << endl;
    cout << " 1. world" << endl;
    cout << " 2. usa" << endl;
    cout << " 3. places" << endl;
    cout << " 4. metro_areas" << endl;
    cout << " 5. meteorite_landings" << endl;
    cout << " 6. locations" << endl;
    cout << " 7. open_street_map" << endl;
    cout << " Enter your choice : ";
    cin >> menuChoice;

    switch(menuChoice){
        case 1 :
            fileName = "world.txt";
            break;
        case 2 :
            fileName = "usa.txt";
            break;           
        case 3 :
            fileName = "places.txt";
            break;
        case 4 :
            fileName = "metro_areas.txt";
            break;
        case 5 :
            fileName = "meteorite_landings.txt";
            break;
        case 6 :
            fileName = "locations.txt";
            break;
        case 7 :
            fileName = "open_street_map.txt";
            break;
        default :
            return;
    }

    cout << fileName;

    inFile.open("data/" + fileName);
    if (!inFile) {
        cout << "Unable to open file data/" + fileName;
        exit(1); // terminate with error
    }

    while (inFile >> a >> b) {
        count = count + 1;
    }

    inFile.close();

    points.reserve(count);

    inFile.open("data/" + fileName);
    if (!inFile) {
        cout << "Unable to open file data/" + fileName;
        exit(1); // terminate with error
    }

    while (inFile >> a >> b) {
        //cout << "Line = " << a << ", " << b << endl;
        Point p(a, b);
        points.push_back(p);
    }

    inFile.close();

    // ofstream newfile ("world-new.txt");
    // if (newfile.is_open())
    // {
    //     for (Point p : points){
    //         newfile << p.x() << " " << p.y() << "\n";
    //     }
    //     newfile.close();
    // }
    // else cout << "Unable to open file";
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

    cout  << endl << "Load from file? (1/0): ";
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

    // run<UnitDiskCoverCenters>(points, centersOfPlacedDisks, "output_centers", showOutput, osPrinter, "Centers");
    // run<UnitDiskCoverCentersSpatial>(points, centersOfPlacedDisks, "output_centers_spatial", showOutput, osPrinter, "CentersSpatial");
    // run<UnitDiskCoverUnitGrid>(points, centersOfPlacedDisks, "output_grid", showOutput, osPrinter, "Grids");
    // run<BiniazEtAls>(points, centersOfPlacedDisks, "output_biniaz", showOutput, osPrinter, "BiniazEtAls");
    // run<LRUDC>(points, centersOfPlacedDisks, "output_lrudc", showOutput, osPrinter, "LRUDC");
    // run<LRUDC_Shift>(points, centersOfPlacedDisks, "output_lrudc_shift", showOutput, osPrinter, "LRUDC_Shift");
    // //run<LinesAlgorithm>(points, centersOfPlacedDisks, "output_linesalgorithm", showOutput, osPrinter, "LinesAlgorithm");
    // //run<LinesAlgorithm_Shift>(points, centersOfPlacedDisks, "output_linesalgorithm_shift", showOutput, osPrinter, "LinesAlgorithm_Shift");
    // run<LiuLu>(points, centersOfPlacedDisks, "output_liulu", showOutput, osPrinter, "LiuLu");
    // //run<SevenCircles>(points, centersOfPlacedDisks, "output_sevencircles", showOutput, osPrinter, "SevenCircles");
    // run<SevenCircles2>(points, centersOfPlacedDisks, "output_sevencircles2", showOutput, osPrinter, "SevenCircles2");
    // run<SevenCirclesSpatial>(points, centersOfPlacedDisks, "output_sevencircles_spatial", showOutput, osPrinter, "SevenCirclesSpatial");
    run<UnitDiskCoverExperimental>(points, centersOfPlacedDisks, "output_experimental", showOutput, osPrinter, "UnitDiskCoverExperimental");

    return EXIT_SUCCESS;
}
