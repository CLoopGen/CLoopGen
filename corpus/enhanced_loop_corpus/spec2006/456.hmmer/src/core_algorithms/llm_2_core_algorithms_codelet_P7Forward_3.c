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
    // Variant 1: Consecutive memory access with loop unrolling for better spatial locality
    int k;
    int m = hmm->M;
    // Align to multiple of 4 for unrolling, handle remainder separately
    int unroll_factor = 4;
    int limit = (m + 1) / unroll_factor * unroll_factor;

    for (k = 0; k < limit; k += unroll_factor) {
        int idx0 = k;
        int idx1 = k + 1;
        int idx2 = k + 2;
        int idx3 = k + 3;

        if (idx0 <= m) {
            mmx[0][idx0] = imx[0][idx0] = dmx[0][idx0] = -987654321;
        }
        if (idx1 <= m) {
            mmx[0][idx1] = imx[0][idx1] = dmx[0][idx1] = -987654321;
        }
        if (idx2 <= m) {
            mmx[0][idx2] = imx[0][idx2] = dmx[0][idx2] = -987654321;
        }
        if (idx3 <= m) {
            mmx[0][idx3] = imx[0][idx3] = dmx[0][idx3] = -987654321;
        }
    }
}
