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
    int32 temp_score = (int32)3355443200U;
    for (i = 0; i < n_state; i++) {
        h->state[i].score = temp_score;
        h->state[i].history = -1;
    }
}
