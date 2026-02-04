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
    // Variant 2: Consecutive Memory Access Pattern with Linear Indexing
    // Flatten the indexing logic to promote consecutive memory layout interpretation.
    // We simulate consecutive assignment by treating pointers_to_data as a linearized
    // array of double*, and assign consecutive segments to pointers_to_pointers.
    double **flat_base = (double **)malloc(x * sizeof(double *));
    if (!flat_base) exit(1);
    for (i = 0; i < x; i++) {
        flat_base[i] = pointers_to_data[i * y]; // Consecutive base rows
        pointers_to_pointers[i] = &flat_base[i];
    }
    free(flat_base);
}
