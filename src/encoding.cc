#include <iostream>
#include <vector>
#include <cmath>
#include "utils.hpp"
#include "polar.hpp"
using namespace std;

vector<int> setFrozenDataBits(int * data, int K, int N) {
    vector<int> fData(N, 0);

    for (int iter_n = 0; iter_n < N; iter_n++) {
        fData[MASTER_REL_SEQ[iter_n]] = data[iter_n];
    }

    return fData;
}

vector<int> polarEncoding(vector<int> fData, int N) {
    int kronDeg = log2(N) - 1;
    vector<int> polarGenMat = KroneckerKernel(kronDeg);

    return fastMatMul(polarGenMat, fData, N);
}