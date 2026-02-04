#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double Pm_rgQp[20];
extern double Pm_rgRp[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW and RAW dependencies
    // We introduce a dependency where each iteration depends on the previous one
    // by making PPictureMAD[i] depend on PPictureMAD[i-1], creating a loop-carried RAW.
    // Also, we reorder writes to create WAW on Pm_rgQp and Pm_rgRp across iterations.

    if (20 > 0) {
        Pm_rgQp[0] = 0;
        Pm_rgRp[0] = 0.;
        PPictureMAD[0] = 0.;
    }
    for (i = 1; i < 20; i++) {
        PPictureMAD[i] = PPictureMAD[i-1] + 0.;  // Loop-carried RAW and WAW dependency
        Pm_rgQp[i] = Pm_rgQp[i-1] + 0;          // Artificially chain writes (WAW)
        Pm_rgRp[i] = Pm_rgRp[i-1] + 0.;         // Same for Rp
    }
}
