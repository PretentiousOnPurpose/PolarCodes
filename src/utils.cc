#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <vector>
#include <numeric>
#include <random>
#include "utils.hpp"
using namespace std;

vector<int> fastMatMul(vector<int> ker, vector<int> data, int dim) {
    vector<int> cwd;

    for (int iter_n = 0; iter_n < dim; iter_n++) {
        cwd.push_back(inner_product(&ker[iter_n * dim], &ker[(iter_n + 1) * dim], &data[0], 0) % 2);
    }

    return cwd;
}

void displayArr(vector<double> mat, int dim) {

    for (int iter_r = 0; iter_r < dim; iter_r++) {
        cout << mat[iter_r] << " ";            
    }

    cout << endl;
}

void displayArr(vector<int> mat, int dim) {

    for (int iter_r = 0; iter_r < dim; iter_r++) {
        cout << mat[iter_r] << " ";            
    }

    cout << endl;
}

void displayMat(vector<int> mat, int dimRow, int dimCol) {
    int numel = dimCol * dimRow;

    for (int iter_r = 0; iter_r < dimRow; iter_r++) {
        for (int iter_c = 0; iter_c < dimCol; iter_c++) {
            cout << mat[iter_r * dimRow + iter_c] << " ";            
        }
        cout << endl;
    }
}

vector<int> KroneckerKernel(int N) {
    // My super lazy way of performing Kronecker Product. Maybe ChatGPT can do better?

    vector<int> ker1 = arikanKernel();

    if (N == 0) {
        return ker1;
    }

    vector<int> ker2 = arikanKernel();
    vector<int> kronKer;
    int tmpRowDim;

    for (int iter_n = 1; iter_n <= N; iter_n++) {
        tmpRowDim = sqrt(pow(4, iter_n + 1));
        vector<int> tmpKer(tmpRowDim * tmpRowDim, 0);

        for (int iter_row = 0; iter_row < (int)tmpRowDim / 2; iter_row++) {
            for (int iter_col = 0; iter_col < (int)tmpRowDim / 2; iter_col++) {
                if (ker1[iter_row * (int)tmpRowDim / 2 + iter_col] == 1) {
                    tmpKer[iter_row * 2 * tmpRowDim + iter_col * 2] = ker2[0];
                    tmpKer[iter_row * 2 * tmpRowDim + iter_col * 2 + 1] = ker2[1];
                    tmpKer[(iter_row * 2 + 1) * tmpRowDim + iter_col * 2] = ker2[2];
                    tmpKer[(iter_row * 2 + 1) * tmpRowDim + iter_col * 2 + 1] = ker2[3];
                }
            }
        }

        ker1 = tmpKer;
    }

    return ker1;
}

vector<int> randomDataBits(int N) {
    srand(time(NULL));
    vector<int> data;

    for (int iter_n = 0; iter_n < N; iter_n++) {
        data.push_back((int)(rand() * 100 / RAND_MAX) > 50 ? 1: 0); 
    }

    return data;
}

vector<int> arikanKernel() {
    vector<int> ker;
    
    // Constructing the Arikan Kernel
    // X = [[1 1]
    //      [0 1]]

    ker.push_back(1);
    ker.push_back(1);
    ker.push_back(0);
    ker.push_back(1);

    return ker;
}

vector<int> BPSK_modulation(vector<int> cwd, int dim) {
    vector<int> modData(dim, 0);

    for (int iter_n = 0; iter_n < dim; iter_n++) {
        modData[iter_n] = 1 - 2 * cwd[iter_n];
    }

    return modData;
}

vector<double> AWGN(vector<int> data, int dim, double noiseVar) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<float> noiseDist(0, 1);

    vector<double> corr_sig(dim, 0.0);

    for (int iter_n = 0; iter_n < dim; iter_n++) {
        corr_sig[iter_n] = data[iter_n] + sqrt(noiseVar) * noiseDist(gen);
    }

    return corr_sig;
}

vector<double> BPSK_logLLR(vector<double> corr_sig, int dim, double noiseVar) {
    vector<double> logLLR(dim, 0);

    for (int iter_n = 0; iter_n < dim; iter_n++) {
        logLLR[iter_n] = (corr_sig[iter_n] * corr_sig[iter_n] - (corr_sig[iter_n] - 1) * (corr_sig[iter_n] - 1)) / noiseVar;
    }

    return logLLR;
}