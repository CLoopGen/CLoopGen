#include <stdio.h>
#include <inttypes.h>

double PPictureMAD[21];
double Pm_rgQp[20];
double Pm_rgRp[20];
int i;

void init_vars() {
    for (int j = 0; j < 21; j++) {
        PPictureMAD[j] = 0.0;
    }
    for (int j = 0; j < 20; j++) {
        Pm_rgQp[j] = 0.0;
        Pm_rgRp[j] = 0.0;
    }
    i = 0;
}