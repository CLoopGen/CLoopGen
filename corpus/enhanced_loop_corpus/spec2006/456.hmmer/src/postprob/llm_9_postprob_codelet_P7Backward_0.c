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
int step = 2;
for (k = hmm->M; k >= 2; k -= step) {
    int k1 = k;
    int k2 = k - 1;

    mmx[L][k1] = xmx[L][1] + hmm->esc[k1] + hmm->msc[(int)dsq[L]][k1];
    mmx[L][k2] = xmx[L][1] + hmm->esc[k2] + hmm->msc[(int)dsq[L]][k2];

    imx[L][k1] = dmx[L][k1] = -987654321;
    imx[L][k2] = dmx[L][k2] = -987654321;
}
if (k == 1) {
    mmx[L][1] = xmx[L][1] + hmm->esc[1] + hmm->msc[(int)dsq[L]][1];
    imx[L][1] = dmx[L][1] = -987654321;
}
}
