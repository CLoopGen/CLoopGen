#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping table (indirection array)
    int *index_map = (int*)malloc(nc * sizeof(int));
    int *values = (int*)malloc(nc * sizeof(int));
    for (i = 0; i < nc; i++) {
        index_map[i] = i;  // Establish indirect mapping
        values[i] = iroot;
    }
    for (i = 1; i < nc; i++) {
        // Use indirection: access values via index_map
        temp *= values[index_map[i]];
    }
    free(index_map);
    free(values);
}
