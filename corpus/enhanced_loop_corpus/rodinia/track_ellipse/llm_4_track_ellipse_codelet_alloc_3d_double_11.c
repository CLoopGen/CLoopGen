#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern int z;
extern double *data;
extern double **pointers_to_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (x <= 0 || y <= 0) return;
    for (i = 0; i < x * y; i++) {
        pointers_to_data[i] = data + (i * z);
    }
}
