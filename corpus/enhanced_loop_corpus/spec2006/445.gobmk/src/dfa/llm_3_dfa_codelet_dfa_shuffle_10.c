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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with indirect indexing using a fixed stride pattern
    // Simulate non-unit stride access by stepping through states in reverse with stride of 1
    // This changes access pattern from forward sequential to backward sequential (strided -1)
    for (i = pdfa->last_state; i >= 1; i--) {
        const state_t *src = &pdfa->states[i];
        state_t *dst = &old_states[i];
        for (j = 0; j < 4; j += 1) {
            // Access elements in normal order within each state, but states are processed in reverse
            dst->next[j] = src->next[j];
        }
        dst->att = src->att;
    }
}
