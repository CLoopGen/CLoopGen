#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_max = max;
for (int block = 0; block < n; block += 1) {
    for (x = block; x < block + 1 && x < n; x++) {
        if (vec[x] > temp_max)
            temp_max = vec[x];
    }
}
max = temp_max;
}
