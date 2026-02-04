#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *index_map = malloc(ni * sizeof(int));
    for (int temp_i = 0; temp_i < ni; ++temp_i) {
        index_map[temp_i] = ni - 1 - temp_i;
    }
    for (i = 0; i < ni; ++i) {
        left[i] = q[index_map[i]];
    }
    free(index_map);
}
