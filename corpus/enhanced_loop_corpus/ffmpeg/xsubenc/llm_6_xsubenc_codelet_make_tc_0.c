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
    uint64_t temp_ms = ms;
    for (i = 0; i < 3; i++) {
        tc[i] = temp_ms % tc_divs[i];
        temp_ms = temp_ms / tc_divs[i];
    }
    ms = temp_ms;
}
