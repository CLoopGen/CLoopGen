#include <stdio.h>

#include <inttypes.h>

extern double *vec1;
extern double *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < n; j++) {
                vec1[j] = vec2[j];
            }
        }
    }
}
