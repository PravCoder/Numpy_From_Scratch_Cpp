// ==================================================
// Class LMAT: Linear Algebra Matrix Operation Tool
// ==================================================


#include <iostream>
using namespace std;
#include <vector> 


class LMAT {

public:

    // constructor - default
    LMAT();

    // constructor - passing in array to convert into
    LMAT(double* array, int size);

    // Destructor
    ~LMAT();

    // creates matrix of zeros of shape (r, c)
    void zeros(int r, int c);

    // creates matrix of zeros of shape (r, c)
    void printMatrix();


private:

    int rows;
    int cols;
    int dimension;

    vector< vector<double> > matrix;

};

LMAT::LMAT() {
    rows = 0;
    cols = 0;
    dimension = 0;
}

LMAT::LMAT(double* array, int size) {
    rows = 1;
    cols = size;
    dimension = 1;
    vector<double> single_row;

    for (int i=0; i<size; i++ ) {
        single_row.push_back(array[i]);
    }
    matrix.push_back(single_row);
}

LMAT::~LMAT() {
    // Empty destructor (can be used for cleanup if needed in the future)
}

void LMAT::zeros(int r, int c) {
    return;
}

void LMAT::printMatrix() {

    for (int i = 0; i < rows; ++i) {
        cout << "[";
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; // Convert 2D indices to 1D
        }
        cout << "]";
        cout << endl;
    }
    
}




int main() {
    double nums[] = {1.0, 2.0, 3.0, 4.0};
    
    LMAT lmat(nums, 4);

    lmat.printMatrix();
}

