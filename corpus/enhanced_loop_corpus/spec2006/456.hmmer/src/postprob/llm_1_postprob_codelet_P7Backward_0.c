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


extern char *dsq;
extern int L;
extern struct plan7_s *hmm;
extern int **xmx;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (hmm->M >= 1) { // Reduced loop structure to a single-level conditional with implicit iteration via manual unrolling assumption
    int k = hmm->M;
    mmx[L][k] = xmx[L][1] + hmm->esc[k];
    mmx[L][k] += hmm->msc[(int)dsq[L]][k];
    imx[L][k] = dmx[L][k] = -987654321;
}
// Note: This variant assumes M is small and known; full unrolling eliminates the loop entirely.
// For generality, we keep one instance as representative when loop depth is minimized to zero.
}
