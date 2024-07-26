// ==================================================
// Class LMAT: Linear Algebra Matrix Operation Tool
// ==================================================


#include <iostream>
using namespace std;
#include <vector> 
#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()


class LMAT {

public:

    // constructor - default
    LMAT();

    // constructor - passing in 1D-array to convert into
    LMAT(double* array, int size);

    // constructor - passing in 2D-array to convert into
    LMAT(vector< vector<double> > array, int r, int c);

    // Destructor
    ~LMAT();

    // creates matrix of zeros of shape (r, c)
    void zeros(int r, int c);

    // creates matrix of zeros of shape (r, c)
    void printMatrix();
    
    LMAT multiply(LMAT mat);

    vector< vector<double> > getMat();


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

LMAT::LMAT(vector< vector<double> > array, int r, int c) {
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
    rows = r;
    cols = c;
    matrix.clear();
    for (int i=0; i<rows; ++i) {
        vector<double> single_row;
        for (int j=0; j<cols; ++j) {
            single_row.push_back(0);
        }
        matrix.push_back(single_row);
    }
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

LMAT LMAT::multiply(LMAT mat) {
    if (cols != mat.rows) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for multiplication" << endl;
    }
    vector< vector<double> > matrix2 = mat.getMat();

    int m = rows; // number of rows in first matrix
    int n = cols;  // number of cols in first matrix
    int p = matrix2[0].size();  // number of cols in second matrix
    
    // init the result matrix with zeros
    vector< vector<double> > result(m, vector<double>(p, 0));
    
    // iterate number of rows in first matrix
    for (int i = 0; i < m; ++i) {
        // iterate number of cols in second matrix
        for (int j = 0; j < p; ++j) {
            // iterate number of cols in first matrix
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }
    
    return LMAT(result, m, p);

}

vector< vector<double> > LMAT::getMat() {
    return matrix;
}

// testing func
vector< vector<double> > getRandomMatrix(int r, int c) {
    vector< vector<double> > output;
    for (int i = 0; i < r; ++i) {
        vector<double> cur_row;
        for (int j = 0; j < c; ++j) {
            cur_row.push_back(rand() % 5 + 1);
        }
        output.push_back(cur_row);
    }
    return output;
}


int main() {
    // Creating 1D-array example
    cout << endl << "Creating 1D-array example:" << endl;
    double nums[] = {1.0, 2.0, 3.0, 4.0};
    LMAT lmat(nums, 4);
    lmat.printMatrix();

    // Creating 2D-array example
    cout << endl << "Creating 2D-array example:" << endl;
    vector< vector<double> > nums1 = getRandomMatrix(2, 3);
    
    LMAT mat1(nums1, 2, 3);
    mat1.printMatrix();

    // Creating matrix of zeros of shape (4, 4)
    cout << endl << "Creating matrix of zeros of shape (r, c):" << endl;
    LMAT mat2;
    mat2.zeros(4, 4);
    mat2.printMatrix();

    // Multiplying 2 matricies
    cout << endl << "Multiplying 2 matricies of shape (2,3),(3,2):" << endl;
    vector< vector<double> > nums3 = getRandomMatrix(2, 3);
    vector< vector<double> > nums4 = getRandomMatrix(3, 2);

    LMAT mat3(nums3, 2, 3);
    LMAT mat4(nums4, 3, 2);
    cout << "Matrix 1:"<<endl;
    mat3.printMatrix() ;
    cout << "Matrix 2:"<<endl;
    mat4.printMatrix();
    cout << "Product:"<<endl;
    LMAT mat5 = mat3.multiply(mat4);
    mat5.printMatrix();
    


}

