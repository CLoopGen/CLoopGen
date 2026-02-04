#include <stdio.h>
#include <inttypes.h>

double MADPictureC1 = 0.9;
double MADPictureC2 = 0.1;
int NumberofBasicUnit = 1000000;
int TotalNumberofBasicUnit = 1000000;
double CurrentBUMAD = 0.0;
double TotalBUMAD = 0.0;

double *BUPFMAD;
int i;

void init_vars() {
    BUPFMAD = (double*)__builtin_malloc(TotalNumberofBasicUnit * sizeof(double));
    for (int idx = 0; idx < TotalNumberofBasicUnit; idx++) {
        BUPFMAD[idx] = (double)(idx % 100) / 100.0;
    }
    i = 0;
    TotalBUMAD = 0.0;
}