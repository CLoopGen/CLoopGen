#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

double MADPictureC1 = 0.85;
double MADPictureC2 = 0.15;
int NumberofBasicUnit = 131072;
int TotalNumberofBasicUnit = 131072;
double CurrentBUMAD = 0.0;
double TotalBUMAD = 0.0;
double *FCBUPFMAD = NULL;
int i = 0;

void init_vars() {
    FCBUPFMAD = (double *)calloc(TotalNumberofBasicUnit, sizeof(double));
    if (FCBUPFMAD == NULL) {
        exit(1);
    }
    for (int idx = 0; idx < TotalNumberofBasicUnit; idx++) {
        FCBUPFMAD[idx] = 1.0 + 0.01 * idx;
    }
}