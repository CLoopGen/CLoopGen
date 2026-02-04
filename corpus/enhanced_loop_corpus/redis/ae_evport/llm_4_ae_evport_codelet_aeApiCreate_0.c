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
    for (i = 0; i < 512; i++) {
        if (i % 2 == 0) {
            state->pending_fds[i] = -1;
        } else {
            state->pending_fds[i] = -1;
        }
    }
}
