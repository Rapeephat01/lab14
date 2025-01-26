#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double matrix[][N]) {
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void findLocalMax(const double input[][N], bool output[][N]) {
    for (int i = 0; i < N; i++) {
        output[0][i] = false;
        output[N-1][i] = false;
        output[i][0] = false;
        output[i][N-1] = false;
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            double current = input[i][j];
            bool isLocalMax = current >= input[i-1][j] &&
                              current >= input[i+1][j] &&
                              current >= input[i][j-1] &&
                              current >= input[i][j+1];
            output[i][j] = isLocalMax;
        }
    }
}

void showMatrix(const bool matrix[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double A[N][N];
    bool B[N][N];
    cout << "Input the matrix.....\n";
    inputMatrix(A);
    findLocalMax(A, B);
    cout << "Result is \n";
    showMatrix(B);
    return 0;
}
