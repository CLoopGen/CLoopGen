#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int32_t local_max = 0;
    for (i = 0; i < len + 4; i++) {
        int32_t val = in[i];
        int32_t abs_val = (val >= 0) ? val : -val;
        local_max |= abs_val;
        in[i] = abs_val;  // WAW dependency: modifies input array (simulated side effect)
    }
    max |= local_max;
}
