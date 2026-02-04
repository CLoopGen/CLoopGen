#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nsegs;
extern int size;
extern uint8_t segments[255];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {4, 1, 3, 0, 2, 5}; // example indirect access pattern
    int num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < num_indices && i < nsegs; i++)
        size += segments[indices[i]];
}
