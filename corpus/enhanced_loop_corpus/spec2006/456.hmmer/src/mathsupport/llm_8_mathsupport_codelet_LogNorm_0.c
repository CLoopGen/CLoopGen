#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            float val1 = vec[x];
            float val2 = vec[x + 1];
            if (val1 > max) max = val1;
            if (val2 > max) max = val2;
        } else {
            if (vec[x] > max) max = vec[x];
        }
    }
}
