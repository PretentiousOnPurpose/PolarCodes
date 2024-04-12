#include <stdlib.h>
#include <vector>
using namespace std;

void displayArr(vector<int> mat, int dim);
void displayMat(vector<int> mat, int dimRow, int dimCol);
vector<int> KroneckerKernel(int dim);
vector<int> fastMatMul(vector<int> ker, vector<int> data, int dim);
vector<int> randomDataBits(int dim);
vector<int> arikanKernel();