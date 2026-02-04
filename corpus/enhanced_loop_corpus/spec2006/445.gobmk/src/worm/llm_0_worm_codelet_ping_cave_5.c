#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < *lib1; i++) {
        for (k = 0; k <= i; k++) {
            mse[libs[k]] = 1;
        }
    }
}
