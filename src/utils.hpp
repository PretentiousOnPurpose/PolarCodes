#include <stdlib.h>

void displayArr(int * mat, int dim);
void displayMat(int * mat, int dimRow, int dimCol);
int * KroneckerKernel(int dim);
int * fastMatMul(int * ker, int * data, int dim);
int * randomDataBits(int dim);
int * arikanKernel();