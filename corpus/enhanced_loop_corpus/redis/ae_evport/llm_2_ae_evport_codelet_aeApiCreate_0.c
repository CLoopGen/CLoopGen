#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct aeApiState {
    int portfd;
    int npending;
    int pending_fds[512];
    int pending_masks[512];
} aeApiState;

extern int i;
extern aeApiState *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even and odd indices separately
    for (i = 0; i < 512; i += 2) {
        state->pending_fds[i] = -1;
        if (i + 1 < 512) {
            state->pending_fds[i + 1] = -1;
        }
    }
}
