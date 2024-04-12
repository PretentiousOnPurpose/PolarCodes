#include <iostream>
#include <vector>
#include "utils.hpp"
using namespace std;

int main() {
    vector<int> data = randomDataBits(4);
    vector<int> modData = BPSK_modulation(data, 4);

    double noiseVar = 0.0001;

    vector<double> corr_sig = AWGN(modData, 4, noiseVar);
    vector<double> logLLR = BPSK_logLLR(corr_sig, 4, noiseVar);

    displayArr(data, 4);
    cout << endl;
    displayArr(modData, 4);
    cout << endl;
    displayArr(corr_sig, 4);
    cout << endl;
    displayArr(logLLR, 4);
    cout << endl;
    
    return 0;
}