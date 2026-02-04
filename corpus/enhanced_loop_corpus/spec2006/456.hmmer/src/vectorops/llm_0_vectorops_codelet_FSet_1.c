#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x++) {
        for (int y = 0; y < 1; y++) {
            vec[x] = value;
        }
    }
}
