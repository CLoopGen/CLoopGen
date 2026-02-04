#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 6; k++) {
    for (i = 0; i < 8; i++) {
        for (j = 0; j < number_of_slices * 2; j++) {
            initialized[k % 3][i % 4][j % number_of_slices] = 0;
            initialized[k % 3][i % 4][j % number_of_slices] += k + i + j;
        }
    }
}
}
