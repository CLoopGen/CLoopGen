#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern const int32_t ff_mpa_enwindow[257];
extern MPA_INT *window;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive bidirectional write using reverse indexing pattern
    for (i = 0; i < 257; i++) {
        int v_forward, v_backward;
        v_forward = ff_mpa_enwindow[i];
        window[i] = v_forward;

        if (i != 0) {
            v_backward = ((i & 63) != 0) ? -v_forward : v_forward;
            window[512 - i] = v_backward;
        }
    }
}
