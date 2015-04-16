#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include "Container.h"

using namespace cv;
using namespace std;

#define PI 3.14159265

int distanceMetric(Document* d1, Document* d2) {
    
    double docDist = 0.0 , scalarProd = 0.0 , M1 = 0.0 , M2 = 0.0;
    
    cout << "Vectorising Document : " << endl;
    d1->createVector();
    d2->createVector();
    
    M1 = d1->magnitude();
    M2 = d2->magnitude();
    
    if (M1 < 1) M1 = 1;
    if (M2 < 1) M2 = 1;
    
    scalarProd = d1->scalarProduct(d2->getVector());
    
    cout << " Scalar magnitude of Document 1:  "  << M1 << endl ;
    cout << " Scalar magnitude of Document 2:  "  << M2 << endl ;
    
    cout << "Scalar Product of two vectors : " << scalarProd << endl;
    
    docDist = (( scalarProd )/(M1*M2));
    
    return int(acos (docDist) * (180.0 / PI));
    
}

int main( /*int argc, const char** argv*/ )
{
    double docDist;
    std::string s1 = "quick brown brown brown fox jumped over lazy fence";
    std::string s2 = "quick brown brown brown fox jumped over lazy fence";
    
    Document * d1 = new Document(&s1);
    Document * d2 = new Document(&s2);
    
    docDist = distanceMetric(d1, d2);
    
    cout << " Calculated Document Distance : " << docDist << endl;
    
}
