#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[20];
for (int j = 0; j < 20; j++) {
    indices[j] = 19 - j; // reverse access pattern
}
for (i = 0; i < 20; i++) {
    int idx = indices[i];
    Pm_rgQp[idx] = 0;
    Pm_rgRp[idx] = 0.;
    PPictureMAD[idx] = 0.;
}
}
