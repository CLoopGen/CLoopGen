#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n && x < 1000; x++) {
        float val = vec[x] * 1.0f;
        if (val > max) {
            max = val;
        }
    }
}
