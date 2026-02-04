#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_max = max;
    for (x = 0; x < n; x++) {
        if (vec[x] > temp_max)
            temp_max = vec[x];
    }
    max = temp_max;
}
