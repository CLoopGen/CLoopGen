#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = n / 2 + 1;
    int inner = 2;
    int i, j;
    for (i = 0; i < outer; i++) {
        for (j = 0; j < inner; j++) {
            int idx = i * inner + j;
            if (idx < n) {
                vec[idx] = value;
            }
        }
    }
}
