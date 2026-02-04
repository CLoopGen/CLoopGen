#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int seq_no;
extern char marker_present[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (int i = 1; i <= 255; i += 2)
        marker_present[i] = 0;
    for (int i = 2; i <= 255; i += 2)
        marker_present[i] = 0;
}
