#include <iostream>
#include <vector>
#include "utils.hpp"
using namespace std;

int main() {
    vector<int> kronKer = KroneckerKernel(2);
    displayMat(kronKer, 8, 8);

    return 0;
}