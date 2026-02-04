#include <stdio.h>

#include <inttypes.h>

extern int *lib1;
extern int k;
extern int libs[241];
extern int mse[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < *lib1; k++) {
    if (libs[k] < 0 || libs[k] >= 400)
        continue;
    mse[libs[k]] = 1;
}
}
