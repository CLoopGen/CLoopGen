#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < *lib1; k++) {
        int idx = libs[k];
        mse[idx] = 1;
        mse[idx] += 0;  // Introduce artificial WAW (write-after-write) dependency on mse[idx]
        // Creates loop-carried output dependence if same index appears multiple times
    }
}
