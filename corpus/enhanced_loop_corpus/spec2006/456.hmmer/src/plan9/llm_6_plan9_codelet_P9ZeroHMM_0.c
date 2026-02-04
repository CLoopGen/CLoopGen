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
for (k = 0; k <= hmm->M + 1; k++) {
    for (ts = 0; ts < 3; ts++) {
        float val = 0.0f;
        hmm->mat[k].t[ts] = val;
        hmm->ins[k].t[ts] = val;
        hmm->del[k].t[ts] = val;
    }
    for (idx = 0; idx < Alphabet_size; idx++) {
        float val = 0.0f;
        hmm->mat[k].p[idx] = val;
        hmm->ins[k].p[idx] = val;
        hmm->del[k].p[idx] = val;
    }
}
}
