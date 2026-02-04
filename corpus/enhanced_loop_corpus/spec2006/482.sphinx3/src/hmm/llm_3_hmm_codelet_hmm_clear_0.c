#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef struct {
    int32 score;
    int32 history;
} hmm_state_t;

typedef struct {
    hmm_state_t *state;
    hmm_state_t in;
    hmm_state_t out;
    int32 **tp;
    int32 bestscore;
} hmm_t;

extern hmm_t *h;
extern int32 n_state;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index map (simulating irregular access pattern)
    int32 *index_map = (int32*)__builtin_alloca(n_state * sizeof(int32));
    int32 i;
    // Create an indirect access pattern: reverse order access indices
    for (i = 0; i < n_state; i++) {
        index_map[i] = n_state - 1 - i;
    }
    for (i = 0; i < n_state; i++) {
        int32 idx = index_map[i];
        h->state[idx].score = ((int32)3355443200U);
        h->state[idx].history = -1;
    }
}
