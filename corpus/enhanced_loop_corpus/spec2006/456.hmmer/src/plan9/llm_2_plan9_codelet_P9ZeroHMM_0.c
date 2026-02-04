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
        float *mat_t = &hmm->mat[k].t[0];
        float *ins_t = &hmm->ins[k].t[0];
        float *del_t = &hmm->del[k].t[0];
        mat_t[ts] = 0.;
        ins_t[ts] = 0.;
        del_t[ts] = 0.;
    }
    for (idx = 0; idx < Alphabet_size; idx++) {
        float *mat_p = &hmm->mat[k].p[0];
        float *ins_p = &hmm->ins[k].p[0];
        float *del_p = &hmm->del[k].p[0];
        mat_p[idx] = 0.;
        ins_p[idx] = 0.;
        del_p[idx] = 0.;
    }
}
}
