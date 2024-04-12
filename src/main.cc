#include <iostream>
#include <vector>
#include "utils.hpp"
using namespace std;

int main() {
    vector<int> data = randomDataBits(4);
    vector<int> kronKer = KroneckerKernel(1);
    vector<int> codeword = fastMatMul(kronKer, data, 4);

    displayArr(data, 4);
    cout << endl;
    displayMat(kronKer, 4, 4);
    cout << endl;
    displayArr(codeword, 4);

    return 0;
}