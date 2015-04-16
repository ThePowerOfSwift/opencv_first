

#ifndef __opencv_first__Container__
#define __opencv_first__Container__

#include <stdio.h>
#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, int> stringVect;

class Document {
    
private:
    stringVect _documentVect;
    std::string _document;
    
    
public:
    Document(std::string* str):_document(*str) {};
    void createVector();
    double Dist( Document& );
    stringVect& getVector();
    void printVect();
    double magnitude();
    double scalarProduct(stringVect& v2);
};
#endif /* defined(__opencv_first__Container__) */
