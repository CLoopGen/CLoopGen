#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i += 2) {
    Pm_rgQp[i] = 0;
    if (i + 1 < 20) {
        Pm_rgQp[i + 1] = 0;
    }
    Pm_rgRp[i] = 0.;
    PPictureMAD[i] = 0.;
    if (i + 1 < 20) {
        Pm_rgRp[i + 1] = 0.;
        PPictureMAD[i + 1] = 0.;
    }
}
}
