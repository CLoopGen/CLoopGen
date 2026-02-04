#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int final_num_colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *color_array = (int*)malloc(4 * final_num_colors * sizeof(int));
    for (i = 0; i < 4 * final_num_colors; i += 2) {
        color_array[i] = i;
    }
    free(color_array);
}
