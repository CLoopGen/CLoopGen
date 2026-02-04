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
    int temp_fds[512];
    for (i = 0; i < 512; i++) {
        temp_fds[i] = -1;
    }
    for (i = 0; i < 512; i++) {
        state->pending_fds[i] = temp_fds[i];
    }
}
