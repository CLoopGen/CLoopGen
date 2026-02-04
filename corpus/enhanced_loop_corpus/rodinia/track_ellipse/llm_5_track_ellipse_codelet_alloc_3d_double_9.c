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
    for (i = 0; i < x * y && x > 0 && y > 0; i++) {
        if (pointers_to_data != NULL && data != NULL) {
            pointers_to_data[i] = data + (i * z);
        }
    }
}
