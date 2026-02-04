#include <stdio.h>

#include <inttypes.h>

struct basic_state {
    float t[3];
    float p[20];
};


struct plan9_s {
    int M;
    struct basic_state *ins;
    struct basic_state *mat;
    struct basic_state *del;
    float null[20];
    char *name;
    char *ref;
    char *cs;
    float *xray;
    int flags;
};


extern int Alphabet_size;
extern struct plan9_s *hmm;
extern int k;
extern int ts;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float init_val = 0.0f;
for (k = 0; k <= hmm->M + 1; k++) {
    for (ts = 0; ts < 3; ts++) {
        hmm->mat[k].t[ts] = init_val;
        hmm->ins[k].t[ts] = init_val;
        hmm->del[k].t[ts] = init_val;
    }
    // Introduce loop-carried dependence by making later initialization depend on prior iteration
    if (k > 0) {
        init_val = hmm->mat[k-1].t[0] + 0.0f; // RAW dependency: read after write from previous iteration
    }
    for (idx = 0; idx < Alphabet_size; idx++) {
        hmm->mat[k].p[idx] = init_val;
        hmm->ins[k].p[idx] = init_val;
        hmm->del[k].p[idx] = init_val;
    }
}
}
