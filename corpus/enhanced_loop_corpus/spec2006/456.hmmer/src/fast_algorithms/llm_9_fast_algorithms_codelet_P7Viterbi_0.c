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
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int upper = hmm->M + 1;
    // Unroll loop by factor of 2 to increase computational intensity per iteration
    for (k = 0; k <= upper - stride; k += stride) {
        mmx[0][k]     = imx[0][k]     = dmx[0][k]     = -987654321;
        mmx[0][k + 1] = imx[0][k + 1] = dmx[0][k + 1] = -987654321;
    }
    // Handle remaining iteration if M+1 is odd
    if (k <= hmm->M) {
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
    }
}
