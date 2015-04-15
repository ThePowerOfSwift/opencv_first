#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main( /*int argc, const char** argv*/ )
{
    std::vector<std::vector<int>> twoDvec;
    
    for(int i =0 ; i< 5 ; i++ ){
        std::vector<int> row;
        
        for(int j = 0 ; j < 5 ; j++){
            row.push_back(0);
        }
        twoDvec.push_back(row);
    }
    cout <<  "The size of vector is " <<  twoDvec.size() << " X " << twoDvec[1].size();
    
    return 0;
}
