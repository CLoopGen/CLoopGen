#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_value = value;
    for (x = 0; x < n; x += 4) {
        vec[x]     = local_value;
        if (x+1 < n) vec[x+1] = local_value;
        if (x+2 < n) vec[x+2] = local_value;
        if (x+3 < n) vec[x+3] = local_value;
    }
}
