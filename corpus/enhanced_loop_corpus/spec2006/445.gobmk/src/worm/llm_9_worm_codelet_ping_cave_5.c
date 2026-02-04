#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < *lib1 * 2; k += 2) {
        int idx = libs[k / 2];
        mse[idx] = 1;
        mse[idx] *= mse[idx]; // Redundant but increases computational intensity
    }
}
