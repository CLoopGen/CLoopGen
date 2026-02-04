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
    ts = 0;
    do {
        hmm->mat[k].t[ts] = 0.;
        hmm->ins[k].t[ts] = 0.;
        hmm->del[k].t[ts] = 0.;
        if (ts == 0) {
            for (idx = 0; idx < Alphabet_size; idx++) {
                hmm->mat[k].p[idx] = 0.;
                hmm->ins[k].p[idx] = 0.;
                hmm->del[k].p[idx] = 0.;
            }
        }
        ts++;
    } while (ts < 3);
}
}
