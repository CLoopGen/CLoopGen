#include <stdio.h>
#include <stdlib.h>
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

int Alphabet_size = 20;
struct plan9_s *hmm;
struct plan7_s *plan7;
int x;

void init_vars() {
    Alphabet_size = 20;

    hmm = (struct plan9_s *)calloc(1, sizeof(struct plan9_s));
    plan7 = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));

    for (int i = 0; i < 20; i++) {
        hmm->null[i] = (float)(i + 1) / 21.0f;
        plan7->null[i] = 0.0f;
    }
}