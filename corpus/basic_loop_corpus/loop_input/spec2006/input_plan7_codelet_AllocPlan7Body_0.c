#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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

struct plan7_s *hmm;
int M = 10000;  // Chosen to make loop run ~0.01 seconds with reasonable memory (~1.6MB)
int k;

void init_vars() {
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    hmm->M = M;

    // Allocate t[0], mat[0], ins[0] as base arrays
    hmm->mat = (float **)calloc(M + 1, sizeof(float *));
    hmm->ins = (float **)calloc(M + 1, sizeof(float *));
    hmm->t   = (float **)calloc(M + 1, sizeof(float *));

    if (!hmm->mat || !hmm->ins || !hmm->t) exit(1);

    // Allocate base storage: mat[0] and ins[0] need M*20 elements, t[0] needs M*7
    float *mat_base = (float *)calloc((M + 1) * 20, sizeof(float));
    float *ins_base = (float *)calloc((M + 1) * 20, sizeof(float));
    float *t_base   = (float *)calloc((M + 1) * 7,   sizeof(float));

    if (!mat_base || !ins_base || !t_base) exit(1);

    // Assign base pointers
    hmm->mat[0] = mat_base;
    hmm->ins[0] = ins_base;
    hmm->t[0]   = t_base;

    // Initialize begin/end pointers
    hmm->begin = (float *)calloc(M + 1, sizeof(float));
    hmm->end   = (float *)calloc(M + 1, sizeof(float));
    if (!hmm->begin || !hmm->end) exit(1);
}