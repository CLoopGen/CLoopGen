#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        x = 0;
        for (int i = 0; i < 1; i++) {
            do {
                vec[x] = 1. / (double)n;
                x++;
            } while (x < n);
        }
    }
}
