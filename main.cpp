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

    vector<double> matrix;

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
    for (int i=0; i<size; i++ ) {
        matrix.push_back(array[i]);
    }
}

LMAT::~LMAT() {
    // Empty destructor (can be used for cleanup if needed in the future)
}

void LMAT::zeros(int r, int c) {
    return;
}

void LMAT::printMatrix() {
    if (dimension == 1) {
        for (int i = 0; i < cols; ++i) {
            cout << matrix[i] << " ";
        }
        cout << endl;
    } else if (dimension == 2) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i * cols + j] << " "; // Convert 2D indices to 1D
            }
            cout << endl;
        }
    }
}




int main() {
    double nums[] = {1.0, 2.0, 3.0, 4.0};
    
    LMAT lmat(nums, 4);

    lmat.printMatrix();
}

