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
extern char **mtb;
extern char **itb;
extern char **dtb;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride to simulate non-contiguous pattern
    int stride = 2;
    int k;
    // Access elements with a stride of 2, assuming M allows it
    for (k = 0; k <= hmm->M; k += stride) {
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
        mtb[0][k] = itb[0][k] = dtb[0][k] = 0;
        // Handle next index in stride if within bounds
        if (k + 1 <= hmm->M) {
            mmx[0][k+1] = imx[0][k+1] = dmx[0][k+1] = -987654321;
            mtb[0][k+1] = itb[0][k+1] = dtb[0][k+1] = 0;
        }
    }
    // Final cleanup pass for any missed indices due to stride alignment
    for (k = 1; k <= hmm->M; k += 2) {
        // Reinitialize any potentially skipped entries (alternative: use single forward pass)
        if (mmx[0][k] == -987654321) continue; // already set
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
        mtb[0][k] = itb[0][k] = dtb[0][k] = 0;
    }
}
