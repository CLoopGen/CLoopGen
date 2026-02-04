#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (*lib1 > 0) {
        k = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; k < *lib1; k++) {
                mse[libs[k]] = 1;
            }
        }
    }
}
