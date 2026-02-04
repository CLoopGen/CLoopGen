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
    double **temp_pointers = pointers;
    double *temp_data = data;
    int temp_y = y;
    for (i = 0; i < x; i++) {
        temp_pointers[i] = temp_data + (i * temp_y);
    }
}
