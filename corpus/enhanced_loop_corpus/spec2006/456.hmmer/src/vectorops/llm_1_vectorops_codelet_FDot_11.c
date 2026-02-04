#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern float result;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    int block_size = 16;
    for (i = 0; i < n; i += block_size) {
        for (j = i; j < n && j < i + block_size; j++) {
            x = j;
            result += vec1[x] * vec2[x];
        }
    }
}
