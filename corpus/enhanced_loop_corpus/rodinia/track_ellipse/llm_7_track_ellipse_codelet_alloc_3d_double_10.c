#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double **pointers_to_data;
extern double ***pointers_to_pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double **temp_ptr = pointers_to_data;
    for (i = 0; i < x; i++) {
        pointers_to_pointers[i] = temp_ptr;
        temp_ptr += y;
    }
}
