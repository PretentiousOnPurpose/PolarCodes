#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <cmath>
#include "utils.hpp"
using namespace std;

void displayMat(int * mat, int dimRow, int dimCol) {
    int numel = dimCol * dimRow;

    for (int iter_r = 0; iter_r < dimRow; iter_r++) {
        for (int iter_c = 0; iter_c < dimCol; iter_c++) {
            cout << mat[iter_r * dimRow + iter_c] << " ";            
        }
        cout << endl;
    }
}

int * KroneckerKernel(int N) {
    // Super lazy way of performing Kronecker Product. Maybe ChatGPT can do better?

    int * ker1 = arikanKernel();
    int * ker2 = arikanKernel();
    int * kronKer = nullptr;
    int * tmpKer = nullptr;
    int tmpRowDim;

    for (int iter_n = 1; iter_n <= N; iter_n++) {
        tmpRowDim = sqrt(pow(4, iter_n + 1));
        tmpKer = (int *)calloc(tmpRowDim * tmpRowDim, sizeof(int));

        for (int iter_row = 0; iter_row < (int)tmpRowDim / 2; iter_row++) {
            for (int iter_col = 0; iter_col < (int)tmpRowDim / 2; iter_col++) {
                if (ker1[iter_row * (int)tmpRowDim / 2 + iter_col] == 1) {
                    tmpKer[iter_row * 2 * tmpRowDim + iter_col * 2] = ker2[0];
                    tmpKer[iter_row * 2 * tmpRowDim + iter_col * 2 + 1] = ker2[1];
                    tmpKer[iter_row * 2 * tmpRowDim + tmpRowDim + iter_col * 2] = ker2[2];
                    tmpKer[iter_row * 2 * tmpRowDim + tmpRowDim + iter_col * 2 + 1] = ker2[3];
                }
            }
        }

        ker1 = tmpKer;
        tmpKer = nullptr;
    }

    return ker1;
}

int * randomDataBits(int N) {
    int * data = (int *)calloc(N, sizeof(int));

    for (int iter_n = 0; iter_n < N; iter_n++) {
        data[iter_n] = rand() > 0.5 ? 1: 0; 
    }

    return data;
}

int * arikanKernel() {
    int * ker = (int *)calloc(4, sizeof(int));
    
    // Constructing the Arikan Kernel
    // X = [[1 1]
    //      [0 1]]

    ker[0] = 1;
    ker[1] = 1;
    ker[2] = 0;
    ker[3] = 1;

    return ker;
}
