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

int i;
aeApiState *state;

void init_vars() {
    state = (aeApiState*)calloc(1, sizeof(aeApiState));
    if (!state) {
        exit(1);
    }
    state->portfd = -1;
    state->npending = 0;
    for (int j = 0; j < 512; j++) {
        state->pending_fds[j] = -1;
        state->pending_masks[j] = 0;
    }
}