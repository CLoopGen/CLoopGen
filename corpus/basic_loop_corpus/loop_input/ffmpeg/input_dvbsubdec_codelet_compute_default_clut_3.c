#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int (*counttab2)[256];
int i;

void init_vars() {
    // Allocate a 2D array of dimensions [257][256] to safely allow access up to counttab2[256][255]
    // This ensures that counttab2[i+1][i] for i from 0 to 255 is valid (max index: counttab2[256][255])
    counttab2 = calloc(257, sizeof(int[256]));
    if (!counttab2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}