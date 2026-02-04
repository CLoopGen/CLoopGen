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
for (i = 0; i < x; i++) {
    if (i % 2 == 0) {
        pointers_to_pointers[i] = pointers_to_data + (i * y);
    } else {
        pointers_to_pointers[i] = NULL;
    }
}
}
