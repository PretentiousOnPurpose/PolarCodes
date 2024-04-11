#include <iostream>
#include "utils.hpp"
using namespace std;

int main() {
    int * kronKer = KroneckerKernel(3);
    displayMat(kronKer, 16, 16);

    return 0;
}