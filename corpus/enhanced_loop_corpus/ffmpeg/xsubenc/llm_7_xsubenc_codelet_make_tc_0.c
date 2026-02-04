#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t ms;
extern int *tc;
extern  int tc_divs[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t local_ms_vals[3];
    local_ms_vals[0] = ms;
    for (i = 0; i < 3; i++) {
        if (i > 0) {
            local_ms_vals[i] = local_ms_vals[i-1] / tc_divs[i-1];
        }
        tc[i] = local_ms_vals[i] % tc_divs[i];
    }
    ms = local_ms_vals[2] / tc_divs[2];
}
