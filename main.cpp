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

    // constructor - passing in 1D-array to convert into
    LMAT(double* array, int size);

    // constructor - passing in 2D-array to convert into
    LMAT(const double array[][3], int r, int c);

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

    vector< vector<double> > matrix; // 2D array, when given arr is 1D it is stored as [[1, 2, 3, 4]]

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

LMAT::LMAT(const double array[][3], int r, int c){
    rows = r;
    cols = c;
    dimension = 2;

    for (int i=0; i<rows; i++) {
        vector<double> single_row;
        for (int j=0; j<cols; j++) {
            single_row.push_back(array[i][j]);
        }
        matrix.push_back(single_row);
    }
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
    // Creating 1D-array example
    cout << endl << "Creating 1D-array example:" << endl;
    double nums[] = {1.0, 2.0, 3.0, 4.0};
    LMAT lmat(nums, 4);
    lmat.printMatrix();

    // Creating 2D-array example
    cout << endl << "Creating 2D-array example:" << endl;
    double nums1[2][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    LMAT mat(nums1, 2, 3);
    mat.printMatrix();
}

