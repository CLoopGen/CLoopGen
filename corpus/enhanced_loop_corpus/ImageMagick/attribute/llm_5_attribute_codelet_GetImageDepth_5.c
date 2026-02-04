#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
depth = current_depth[0];
for (i = 1; i < (ssize_t)number_threads; i++)
    depth = (current_depth[i] > depth) ? current_depth[i] : depth;
}
