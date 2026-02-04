#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static hmm_state_t* state_array;
static hmm_t h_instance;
hmm_t *h = &h_instance;
int32 n_state;
int32 i;

void init_vars() {
    n_state = 100000;  // Adjusted to achieve ~0.01 sec runtime
    
    state_array = (hmm_state_t*)calloc(n_state, sizeof(hmm_state_t));
    if (!state_array) {
        exit(1);
    }
    
    h->state = state_array;
    h->in.score = 0;
    h->in.history = 0;
    h->out.score = 0;
    h->out.history = 0;
    h->tp = NULL;
    h->bestscore = 0;
}