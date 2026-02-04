#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = value;
    for (x = 0; x < n; x++) {
        temp += vec[x];
        vec[x] = temp;
    }
}
