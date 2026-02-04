#include <stdio.h>
#include <inttypes.h>
#include <math.h>

double MADPictureC1 = 1.5;
double MADPictureC2 = 0.8;
double PictureMAD[21] = {0};
double ReferenceMAD[21] = {0};
int n_windowSize = 20;
int i = 0;
double error[20] = {0};
double std = 0.0;

void init_vars() {
    n_windowSize = 20;

    MADPictureC1 = 1.5;
    MADPictureC2 = 0.8;
    std = 0.0;

    for (int idx = 0; idx < 21; idx++) {
        PictureMAD[idx] = idx * 0.5 + 1.0;
        if (idx < 20) {
            ReferenceMAD[idx] = idx * 0.3 + 0.5;
        }
    }

    for (int idx = 0; idx < 20; idx++) {
        error[idx] = 0.0;
    }
}