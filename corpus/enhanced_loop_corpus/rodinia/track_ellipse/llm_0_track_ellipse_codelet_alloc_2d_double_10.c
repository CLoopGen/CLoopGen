#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double *data;
extern double **pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < x; i++) {
            pointers[i] = data + (i * y);
        }
    }
}
