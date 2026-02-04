#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate all loop-carried dependencies entirely
    // Unroll the loop manually to remove any potential WAW, WAR, RAW dependencies
    // Each statement is independent and can be reordered freely by the compiler

    Pm_rgQp[0] = 0;   Pm_rgRp[0] = 0.;   PPictureMAD[0] = 0.;
    Pm_rgQp[1] = 0;   Pm_rgRp[1] = 0.;   PPictureMAD[1] = 0.;
    Pm_rgQp[2] = 0;   Pm_rgRp[2] = 0.;   PPictureMAD[2] = 0.;
    Pm_rgQp[3] = 0;   Pm_rgRp[3] = 0.;   PPictureMAD[3] = 0.;
    Pm_rgQp[4] = 0;   Pm_rgRp[4] = 0.;   PPictureMAD[4] = 0.;
    Pm_rgQp[5] = 0;   Pm_rgRp[5] = 0.;   PPictureMAD[5] = 0.;
    Pm_rgQp[6] = 0;   Pm_rgRp[6] = 0.;   PPictureMAD[6] = 0.;
    Pm_rgQp[7] = 0;   Pm_rgRp[7] = 0.;   PPictureMAD[7] = 0.;
    Pm_rgQp[8] = 0;   Pm_rgRp[8] = 0.;   PPictureMAD[8] = 0.;
    Pm_rgQp[9] = 0;   Pm_rgRp[9] = 0.;   PPictureMAD[9] = 0.;
    Pm_rgQp[10] = 0;  Pm_rgRp[10] = 0.;  PPictureMAD[10] = 0.;
    Pm_rgQp[11] = 0;  Pm_rgRp[11] = 0.;  PPictureMAD[11] = 0.;
    Pm_rgQp[12] = 0;  Pm_rgRp[12] = 0.;  PPictureMAD[12] = 0.;
    Pm_rgQp[13] = 0;  Pm_rgRp[13] = 0.;  PPictureMAD[13] = 0.;
    Pm_rgQp[14] = 0;  Pm_rgRp[14] = 0.;  PPictureMAD[14] = 0.;
    Pm_rgQp[15] = 0;  Pm_rgRp[15] = 0.;  PPictureMAD[15] = 0.;
    Pm_rgQp[16] = 0;  Pm_rgRp[16] = 0.;  PPictureMAD[16] = 0.;
    Pm_rgQp[17] = 0;  Pm_rgRp[17] = 0.;  PPictureMAD[17] = 0.;
    Pm_rgQp[18] = 0;  Pm_rgRp[18] = 0.;  PPictureMAD[18] = 0.;
    Pm_rgQp[19] = 0;  Pm_rgRp[19] = 0.;  PPictureMAD[19] = 0.;
}
