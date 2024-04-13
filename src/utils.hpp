#include <stdlib.h>
#include <vector>
using namespace std;

void displayArr(vector<int> mat, int dim);
void displayArr(vector<double> mat, int dim);
void displayMat(vector<int> mat, int dimRow, int dimCol);
vector<int> KroneckerKernel(int dim);
vector<int> fastMatMul(vector<int> ker, vector<int> data, int dim);
vector<int> randomDataBits(int dim);
vector<int> arikanKernel();
vector<double> BPSK_logLLR(vector<double> corr_sig, int dim, double noiseVar);
vector<double> AWGN(vector<int> data, int dim, double noiseVar);
vector<int> BPSK_modulation(vector<int> cwd, int dim);
vector<int> BEC(vector<int> data, int dim, double erasureProb);
vector<int> BSC(vector<int> data, int dim, double flipProb);
