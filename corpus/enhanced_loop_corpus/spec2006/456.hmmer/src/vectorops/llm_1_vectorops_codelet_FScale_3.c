#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < n; j++) {
            vec[j] *= scale;
        }
    }
}
