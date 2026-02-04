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


struct plan7_s {
    char *name;
    char *acc;
    char *desc;
    char *rf;
    char *cs;
    char *ca;
    char *comlog;
    int nseq;
    char *ctime;
    int *map;
    int checksum;
    int *tpri;
    int *mpri;
    int *ipri;
    float ga1;
    float ga2;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    int M;
    float **t;
    float **mat;
    float **ins;
    float tbd1;
    float xt[4][2];
    float *begin;
    float *end;
    float null[20];
    float p1;
    int **tsc;
    int **msc;
    int **isc;
    int xsc[4][2];
    int *bsc;
    int *esc;
    int *tsc_mem;
    int *msc_mem;
    int *isc_mem;
    int *bsc_mem;
    int *esc_mem;
    int **dnam;
    int **dnai;
    int dna2;
    int dna4;
    float mu;
    float lambda;
    int flags;
};


extern struct plan9_s *hmm;
extern struct plan7_s *plan7;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k < hmm->M; k++) {
    if (hmm->mat[k].t[0] <= 0.0f) continue;
    plan7->t[k][0] = hmm->mat[k].t[0];
    plan7->t[k][2] = hmm->mat[k].t[2];
    plan7->t[k][1] = hmm->mat[k].t[1];
    plan7->t[k][5] = hmm->del[k].t[0];
    plan7->t[k][6] = hmm->del[k].t[2];
    plan7->t[k][3] = hmm->ins[k].t[0];
    plan7->t[k][4] = hmm->ins[k].t[1];
}
}
