#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FFPsyWindowInfo {
    int window_type[3];
    int window_shape;
    int num_windows;
    int grouping[8];
    float clipping[8];
    int *window_sizes;
} FFPsyWindowInfo;

extern int prev_type;
extern int i;
extern FFPsyWindowInfo wi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using pointer arithmetic
    int *ptr = wi.window_type;
    for (i = 0; i < 3; i++)
        *(ptr + i) = prev_type;
}
