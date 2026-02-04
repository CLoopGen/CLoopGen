#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int final_num_colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(final_num_colors * sizeof(int));
    for (int j = 0; j < final_num_colors; ++j) {
        indices[j] = 4 * j;
    }
    for (int j = 0; j < final_num_colors; ++j) {
        i = indices[j];
    }
    free(indices);
}
