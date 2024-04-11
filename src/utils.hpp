#include <stdlib.h>

void displayMat(int * mat, int dimRow, int dimCol);
int * KroneckerKernel(int N);
int * fastMatMul(int ** ker, int * data);
int * randomDataBits(int N);
int * arikanKernel();