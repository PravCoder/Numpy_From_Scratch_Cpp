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

    LMAT add(LMAT mat);
    LMAT subtract(LMAT mat);
    LMAT divide(LMAT mat);

    double sum();
    double mean();

    void transpose();

    LMAT log();

    LMAT element_wise_prod(LMAT mat);

    void multiply(int scalar);

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

void LMAT::multiply(int scalar) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}   

LMAT LMAT::add(LMAT mat) {
    if (rows != mat.rows || cols != mat.cols) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for addition" << endl;
        return LMAT();
    }

    vector< vector<double> > result(rows, vector<double>(cols, 0));
    vector< vector<double> > matrix2 = mat.getMat();
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i][j] += matrix[i][j] + matrix2[i][j];
        }
    }
    return LMAT(result, rows, cols);
}

LMAT LMAT::subtract(LMAT mat) {
    if (rows != mat.rows || cols != mat.cols) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for substraction" << endl;
        return LMAT();
    }

    vector< vector<double> > result(rows, vector<double>(cols, 0));
    vector< vector<double> > matrix2 = mat.getMat();
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i][j] += (matrix[i][j] - matrix2[i][j]);
        }
    }
    return LMAT(result, rows, cols);
}

LMAT LMAT::divide(LMAT mat) {  // element-wise division
    if (rows != mat.rows || cols != mat.cols) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for element-wise division" << endl;
        return LMAT();
    }

    vector< vector<double> > result(rows, vector<double>(cols, 0));
    vector< vector<double> > matrix2 = mat.getMat();
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            result[i][j] += (matrix[i][j] / matrix2[i][j]);
        }
    }
    return LMAT(result, rows, cols);
}

double LMAT::sum() {
    int total = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            total += matrix[i][j];
        }
    }
    
    return total;
}

double LMAT::mean() {
    double total = 0;
    int num = rows*cols;  // number of elements
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            total += matrix[i][j];
        }
    }
    
    return total / num;
}

void LMAT::transpose() {
    int new_rows = cols;
    int new_cols = rows;
    vector< vector<double> > result(new_rows, vector<double>(new_cols, 0)); // switch rows/cols rows=cols cols=rows

    // iterate each row in original matrix
    for (int i=0; i<rows; i++) {
        // for each row in og-matrix, iterate rows in new-matrix or cols in og-matrix, can replace this with new_rows
        for (int k=0; k<cols; k++) {
            // helps to visualize
            result[k][i] = matrix[i][k];  // element in old matrix (i,j) is found in (j,i) in transposed matrix
        }
    }
    rows = new_rows;
    cols = new_cols;
    matrix = result;
}

LMAT LMAT::log() {
    vector< vector<double> > result(rows, vector<double>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > 0) {
                result[i][j] = std::log(matrix[i][j]);
            } else {
                cerr << "Warning: Non-positive value encountered in log computation." << endl;
                result[i][j] = NAN; // Not a Number
            }
        }
    }

    return LMAT(result, rows, cols);
}


LMAT LMAT::multiply(LMAT mat) {
    // only possible when cols of first mat equals rows of second mat
    if (cols != mat.rows) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for multiplication" << endl;
        return LMAT();
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
                // matrix[i][k]: loops through ith row
                // matrix2[k][j]: loops through jth col, and mutiplying row in first and column in second
                result[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }
    
    return LMAT(result, m, p);

}

LMAT LMAT::element_wise_prod(LMAT mat) {
    if (rows != mat.rows || cols != mat.cols) {
        cout << "Error: shapes (" << rows << ", " << cols << "), (" << mat.rows << ", " << mat.cols << ") do not match for element-wise multiplication" << endl;
        return LMAT();
    }

    vector< vector<double> > matrix2 = mat.getMat();
    vector< vector<double> > result(rows, vector<double>(cols, 0));  // ouptut-matrix

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            // cout << matrix[i][j] << " " <<matrix2[i][j];
            result[i][j] += matrix[i][j] * matrix2[i][j];
        }
    }
    return LMAT(result, rows, cols);


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

    // Multiplying 2 matricies: only works where mat1.cols == mat2.rows
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

    // Element-wise multiplication: only works with matricies of same shape
    cout << endl << "Element-wise multiplying 2 matricies of shape (2,2),(2,2):" << endl;
    vector< vector<double> > nums5 = getRandomMatrix(2, 2);
    vector< vector<double> > nums6 = getRandomMatrix(2, 2);
    LMAT mat6(nums5, 2, 2);
    LMAT mat7(nums6, 2, 2);
    cout << "Matrix 1:"<<endl;
    mat6.printMatrix() ;
    cout << "Matrix 2:"<<endl;
    mat7.printMatrix();
    cout << "Element-wise Product:"<<endl;
    LMAT mat8 = mat6.element_wise_prod(mat7);
    mat8.printMatrix();

    // Constant multiplication
    cout << endl << "Constant multiplication by 5:" << endl;
    nums1 = getRandomMatrix(2, 2);
    mat6 = LMAT(nums1, 2, 2);

    cout << "Matrix 1:"<<endl;
    mat6.printMatrix();
    mat6.multiply(5);
    cout << "Product 5:"<<endl;
    mat6.printMatrix();  // deosnt return new LMAT object


    // Addition/Subtraction/Division: dimensions have to be same
    cout << endl << "Addition:" << endl;
    nums1 = getRandomMatrix(3, 3);
    nums3 = getRandomMatrix(3, 3);
    mat1 = LMAT(nums1, 3, 3);
    mat2 = LMAT(nums3, 3, 3);
    cout << "Matrix 1:"<<endl;
    mat1.printMatrix() ;
    cout << "Matrix 2:"<<endl;
    mat2.printMatrix();
    cout << "Sum:"<<endl;
    mat3 = mat1.add(mat2);
    mat3.printMatrix();
    cout << "Subtract:"<<endl;
    mat3 = mat1.subtract(mat2);
    mat3.printMatrix();
    cout << "Divide:"<<endl;
    mat3 = mat1.divide(mat2);
    mat3.printMatrix();

    // Sum & Mean of matrix
    cout << endl << "Sum of matrix:" << endl;
    nums1 = getRandomMatrix(2, 2);
    mat1 = LMAT(nums1, 2, 2);
    mat1.printMatrix();
    cout << "Sum: "<< mat1.sum() <<endl;
    cout << "Mean: "<< mat1.mean() <<endl;

    // Transpose
    cout << endl << "Transpose of matrix:" << endl;
    nums1 = getRandomMatrix(2, 3);
    mat1 = LMAT(nums1, 2, 3);
    mat1.printMatrix();
    cout << "after tranpose: " <<endl;
    mat1.transpose();
    mat1.printMatrix();

    // Log
    cout << endl << "Log of matrix:" << endl;
    nums1 = getRandomMatrix(2, 2);
    mat1 = LMAT(nums1, 2, 2);
    mat1.printMatrix();
    cout << "after log: " <<endl;
    mat2 = mat1.log();
    mat2.printMatrix();

}

