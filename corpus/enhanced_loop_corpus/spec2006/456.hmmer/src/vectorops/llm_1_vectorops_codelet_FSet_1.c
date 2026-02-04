#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        vec[x] = value;
        if (x + 1 < n) {
            vec[x + 1] = value;
        }
    }
}
