#include <iostream>
#include <vector>
#include <limits> 

using namespace std;

class Logging {
public:
    static void debug(const string& message) {
        cout << "[DEBUG] " << message << endl;
    }

    static void info(const string& message) {
        cout << "[INFO] " << message << endl;
    }

    static void error(const string& message) {
        cerr << "[ERROR] " << message << endl;
    }
};

class Matrix {
private:
    vector<vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<int>(cols, 0));
    }

    void inputMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                while (!(cin >> data[i][j])) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    Logging::error("Vui long nhap so nguyen.");
                    cout << "[" << i + 1 << "][" << j + 1 << "]: ";
                }
            }
        }
        Logging::info("Ma tran da duoc nhap.");
    }

    void displayMatrix() const {
        for (const auto& row : data) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
        Logging::info("Ma tran da duoc hien thi.");
    }

    Matrix operator+(const Matrix& other) const {
        Logging::debug("Dang thuc hien phep cong hai ma tran.");
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        Logging::info("Phep cong hai ma tran da hoan thanh.");
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Logging::debug("Dang thuc hien phep tru hai ma tran.");
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        Logging::info("Phep tru hai ma tran da hoan thanh.");
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Logging::debug("Dang thuc hien phep nhan hai ma tran.");
        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        Logging::info("Phep nhan hai ma tran da hoan thanh.");
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        Logging::debug("Dang thuc hien phep chia hai ma tran.");
        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }

        Logging::info("Phep chia hai ma tran da hoan thanh.");
        return result;
    }
};

int main() {
    int rows, cols;

    cout << "Nhap so hang cua ma tran: ";
    while (!(cin >> rows) || rows <= 0) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Logging::error("Vui long nhap so nguyen duong.");
        cout << "Nhap so hang cua ma tran: ";
    }

    cout << "Nhap so cot cua ma tran: ";
    while (!(cin >> cols) || cols <= 0) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Logging::error("Vui long nhap so nguyen duong.");
        cout << "Nhap so cot cua ma tran: ";
    }

    Matrix matrixA(rows, cols);
    cout << "Nhap ma tran A:" << endl;
    matrixA.inputMatrix();

    cout << "Ma tran A:" << endl;
    matrixA.displayMatrix();

    Matrix matrixB(rows, cols);
    cout << "Nhap ma tran B:" << endl;
    matrixB.inputMatrix();

    cout << "Ma tran B:" << endl;
    matrixB.displayMatrix();

    Logging logger;

    cout << "Tong cua 2 ma tran la: " << endl;
    Matrix sum = matrixA + matrixB;
    sum.displayMatrix();

    cout << "Hieu cua 2 ma tran la: " << endl;
    Matrix hieu1 = matrixA - matrixB;
    hieu1.displayMatrix();

    cout << "Tich cua 2 ma tran la: " << endl;
    Matrix tich = matrixA * matrixB;
    tich.displayMatrix();

    cout << "Thuong cua 2 ma tran la: " << endl;
    Matrix thuong = matrixA / matrixB;
    thuong.displayMatrix();

    return 0;
}

