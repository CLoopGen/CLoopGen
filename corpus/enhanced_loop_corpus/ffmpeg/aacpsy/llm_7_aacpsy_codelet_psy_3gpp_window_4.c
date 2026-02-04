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
    wi.window_type[0] = prev_type;
    for (i = 1; i < 3; i++)
        wi.window_type[i] = wi.window_type[i - 1];
}
