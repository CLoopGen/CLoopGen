#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int byte_abs_range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing step size
    int stride = 2;
    int limit = byte_abs_range / 2;
    for (i = stride; i < limit; i += stride) {
        int pos_index = i;
        int neg_index = -i + (limit * 2);  // Offset negative access to positive range using mirror mapping
        byte_abs[pos_index] = i;
        byte_abs[neg_index % byte_abs_range] = i;  // Simulate symmetric assignment via modulo-bound access
    }
}
