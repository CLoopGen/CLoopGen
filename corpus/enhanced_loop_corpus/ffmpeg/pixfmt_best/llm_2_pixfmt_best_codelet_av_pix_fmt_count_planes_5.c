#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int planes[4];
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, forward and backward pass to cover all)
    int n = sizeof(planes) / sizeof(planes[0]);
    // Process even indices first with stride 2
    for (i = 0; i < n; i += 2)
        ret += planes[i];
    // Then process odd indices with stride 2
    for (i = 1; i < n; i += 2)
        ret += planes[i];
}
