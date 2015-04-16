

#include "Container.h"
#include <boost/tokenizer.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace boost;
 
void Document :: createVector(){
    char_separator<char> sep(" ");
    tokenizer<char_separator<char>> tokens(this->_document, sep);
    
    for ( const auto t : tokens) {
        this->_documentVect[t]++;
    }
}

void Document::printVect() {
    vector<int>::iterator i;
    for ( auto it = this->_documentVect.begin(); it!= this->_documentVect.end(); ++it ){
        cout << " " << it->first << ":" << it->second;
        cout << endl;
    }
}

double Document::magnitude(){
    double sqrMag = 0.0;
    
    for(auto it = this->_documentVect.begin(); it != this->_documentVect.end() ; ++it) {
        sqrMag = sqrMag + (it->second * it->second);
    }
    sqrMag = sqrt(sqrMag);
    
    return sqrMag;
}

stringVect& Document :: getVector() {
    return this->_documentVect;
}

double findProduct(stringVect& v1, stringVect& v2) {
    double prod = 0.0;

    for(auto it1 = v1.begin() ; it1 != v1.end() ; ++it1) {
        auto it2 = v2.find(it1->first);
            if(it2 == v2.end()) {
                continue;
            } else {
                prod = prod + (it1->second*it2->second);
            }
    }
    return prod;
}

double Document::scalarProduct(stringVect& v2) {
    double prod = 0.0;
    stringVect v1 = this->_documentVect;
    if(v1.size() > v2.size()) {
        prod = findProduct(v2,v1);
    } else {
        prod = findProduct(v1,v2);
    }
    
    return prod;
    
}

double Document:: Dist( Document& doc ){
    
    
    return 0.0;
}

