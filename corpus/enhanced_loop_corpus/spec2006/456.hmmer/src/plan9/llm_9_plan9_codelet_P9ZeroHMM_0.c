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
        float val_t = 0.0f;
        hmm->mat[k].t[ts] = val_t;
        hmm->ins[k].t[ts] = val_t;
        hmm->del[k].t[ts] = val_t;
    }
    for (idx = 0; idx < Alphabet_size; idx += 4) {
        float val_p = 0.0f;
        if (idx < Alphabet_size) {
            hmm->mat[k].p[idx] = val_p;
            hmm->ins[k].p[idx] = val_p;
            hmm->del[k].p[idx] = val_p;
        }
        if (idx + 1 < Alphabet_size) {
            hmm->mat[k].p[idx+1] = val_p;
            hmm->ins[k].p[idx+1] = val_p;
            hmm->del[k].p[idx+1] = val_p;
        }
        if (idx + 2 < Alphabet_size) {
            hmm->mat[k].p[idx+2] = val_p;
            hmm->ins[k].p[idx+2] = val_p;
            hmm->del[k].p[idx+2] = val_p;
        }
        if (idx + 3 < Alphabet_size) {
            hmm->mat[k].p[idx+3] = val_p;
            hmm->ins[k].p[idx+3] = val_p;
            hmm->del[k].p[idx+3] = val_p;
        }
    }
}
}
