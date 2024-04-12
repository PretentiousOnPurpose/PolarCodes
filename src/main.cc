#include <iostream>
#include "utils.hpp"
using namespace std;

int main() {
    int * data = randomDataBits(30);
    displayArr(data, 30);

    return 0;
}