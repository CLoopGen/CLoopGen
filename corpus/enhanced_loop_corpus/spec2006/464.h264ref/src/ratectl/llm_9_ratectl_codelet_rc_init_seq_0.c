#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double sum_Qp = 0.0, sum_Rp = 0.0, sum_MAD = 0.0;
for (i = 0; i < 20; i++) {
    Pm_rgQp[i] = sum_Qp;
    Pm_rgRp[i] = sum_Rp;
    PPictureMAD[i] = sum_MAD;
    sum_Qp += i * 0.5;
    sum_Rp += i * 1.2;
    sum_MAD += i * 0.1 + 0.3;
}
PPictureMAD[20] = sum_MAD;
}
