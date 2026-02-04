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
    struct basic_state *mat_ptr = &hmm->mat[k];
    struct basic_state *ins_ptr = &hmm->ins[k];
    struct basic_state *del_ptr = &hmm->del[k];
    for (ts = 0; ts < 3; ts += 1) {
        mat_ptr->t[ts] = 0.;
        ins_ptr->t[ts] = 0.;
        del_ptr->t[ts] = 0.;
    }
    for (idx = 0; idx < Alphabet_size; idx += 1) {
        mat_ptr->p[idx] = 0.;
        ins_ptr->p[idx] = 0.;
        del_ptr->p[idx] = 0.;
    }
}
}
