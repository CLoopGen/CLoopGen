#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < *lib1 && k < 241; k++) {
        mse[libs[k]] = 1;
        if (k % 2 == 0) {
            mse[libs[k]] += 1;
        }
    }
}
