#include <stdio.h>

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


extern struct plan7_s *hmm;
extern float basep;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access with stride of 2, processing even indices only
    for (k = 2; k < hmm->M; k += 2) {
        hmm->end[k] = basep / (1. - basep * (float)(k - 1));
    }
    // Handle odd index if M is odd, to maintain correctness
    if (hmm->M > 1 && (hmm->M - 1) % 2 == 1) {
        hmm->end[hmm->M - 1] = basep / (1. - basep * (float)((hmm->M - 1) - 1));
    }
}
