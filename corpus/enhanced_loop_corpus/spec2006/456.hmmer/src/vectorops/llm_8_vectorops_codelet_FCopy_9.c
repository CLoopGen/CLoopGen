#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec1[x] = vec2[x];
            vec1[x+1] = vec2[x+1];
        } else {
            vec1[x] = vec2[x];
        }
    }
}
