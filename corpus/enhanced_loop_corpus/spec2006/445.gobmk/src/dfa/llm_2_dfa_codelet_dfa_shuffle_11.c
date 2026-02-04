#include <stdio.h>

#include <inttypes.h>

typedef struct state {
    int att;
    int next[4];
} state_t;

typedef struct attrib {
    int val;
    int next;
} attrib_t;

typedef struct dfa {
    char name[80];
    int pre_rotated;
    state_t *states;
    int max_states;
    int last_state;
    attrib_t *indexes;
    int max_indexes;
    int last_index;
} dfa_t;

extern dfa_t *pdfa;
extern struct state *old_states;
extern int *state_to;
extern int *state_from;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing state_from[i] repeatedly, we precompute a base pointer and use stride-based indexing.
    // This changes the access pattern to have more predictable strides in memory.

    int *base_state_from = &state_from[1];  // Start from index 1 as loop starts at i=1
    state_t *base_old_states = old_states;
    state_t *target_states = pdfa->states;
    
    for (i = 0; i < pdfa->last_state; i++) {
        int mapped_index = base_state_from[i];
        const state_t *src_state = &base_old_states[mapped_index];
        state_t *dst_state = &target_states[i + 1];

        // Unroll the inner loop slightly to emphasize strided access
        dst_state->next[0] = state_to[src_state->next[0]];
        dst_state->next[1] = state_to[src_state->next[1]];
        dst_state->next[2] = state_to[src_state->next[2]];
        dst_state->next[3] = state_to[src_state->next[3]];

        dst_state->att = src_state->att;
    }
}
