#include "UnitDiskCoverPrinter.h"
#include "UnitDiskCoverCenters.h"
#include "UnitDiskCoverUnitGrid.h"
#include "BiniazEtAls.h"
#include "LinesAlgorithm.h"
#include "CgalComponents.h"

int main() {

    vector<Point> points;
    points.reserve(1000);

    Random_points_in_square_2<Point,Creator> g1(30.0);
    std::copy_n(g1, 500, back_inserter(points));

    Random_points_in_disc_2<Point,Creator> g2(30.0);
    std::copy_n(g2, 500, back_inserter(points));

    cout << "Point generation completed" << endl;

    //cout << CLOCKS_PER_SEC<< endl;

    vector<Point> centersOfPlacedDisks;

    clock_t begin, end;
    double elapsed_secs;

    cout << "***********CENTERS STARTED*********************" << endl;
    begin = clock();
    UnitDiskCoverCenters objectCenters(points,centersOfPlacedDisks);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //UnitDiskCoverPrinter newPrinter1(points, centersOfPlacedDisks, 1, "output");
    //newPrinter1.displayPDF();
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centersOfPlacedDisks.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl;

    cout << "***********GRIDS STARTED*********************" << endl;
    centersOfPlacedDisks.clear();

    begin = clock();
    UnitDiskCoverUnitGrid objectGrids(points,centersOfPlacedDisks);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //UnitDiskCoverPrinter newPrinter2(points, centersOfPlacedDisks, 1, "output2");
    //newPrinter2.displayPDF();
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centersOfPlacedDisks.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl;

    cout << "***********BINIAZ STARTED*********************" << endl;
    centersOfPlacedDisks.clear();

    begin = clock();
    BiniazEtAls objectBini(points, centersOfPlacedDisks);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //UnitDiskCoverPrinter newPrinter3(points, centersOfPlacedDisks, 1, "output3");
    //newPrinter3.displayPDF();
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centersOfPlacedDisks.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl;

    cout << "***********LIULU STARTED*********************" << endl;
    centersOfPlacedDisks.clear();

    begin = clock();
    LinesAlgorithm objectLines(points, centersOfPlacedDisks, sqrt(3.0));

    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //UnitDiskCoverPrinter newPrinter4(points, centersOfPlacedDisks, 1, "output4");
    //newPrinter4.displayPDF();
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << centersOfPlacedDisks.size() << endl;
    cout << "Time taken: " << elapsed_secs << endl;

    cout << "***********LIULU (SHIFTS) STARTED*********************" << endl;
    centersOfPlacedDisks.clear();
    vector<int> tests;

    begin = clock();
    LinesAlgorithm objectLines1(points, centersOfPlacedDisks, sqrt(3.0));
    tests.push_back(centersOfPlacedDisks.size());
    centersOfPlacedDisks.clear();

    LinesAlgorithm objectLines2(points, centersOfPlacedDisks, sqrt(3.0) + sqrt(3.0)/6);
    tests.push_back(centersOfPlacedDisks.size());
    centersOfPlacedDisks.clear();

    LinesAlgorithm objectLines3(points, centersOfPlacedDisks, sqrt(3.0) + (2*sqrt(3.0))/6);
    tests.push_back(centersOfPlacedDisks.size());
    centersOfPlacedDisks.clear();

    LinesAlgorithm objectLines4(points, centersOfPlacedDisks, sqrt(3.0) + (3*sqrt(3.0))/6);
    tests.push_back(centersOfPlacedDisks.size());
    centersOfPlacedDisks.clear();

    LinesAlgorithm objectLines5(points, centersOfPlacedDisks, sqrt(3.0) + (4*sqrt(3.0))/6);
    tests.push_back(centersOfPlacedDisks.size());
    centersOfPlacedDisks.clear();

    LinesAlgorithm objectLines6(points, centersOfPlacedDisks, sqrt(3.0) + (5*sqrt(3.0))/6);
    tests.push_back(centersOfPlacedDisks.size());

    int testNum = 1;
    for(int t: tests){
        cout << "Test " << testNum++ << ": " << t << endl;
    }

    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //UnitDiskCoverPrinter newPrinter4(points, centersOfPlacedDisks, 1, "output4");
    //newPrinter4.displayPDF();
    cout << "|P|: " << points.size() << endl << "Number of disks placed: " << *min_element(tests.begin(), tests.end()) << endl;
    cout << "Time taken: " << elapsed_secs << endl;

    cout << "*********************************************" << endl;


    return EXIT_SUCCESS;
}
