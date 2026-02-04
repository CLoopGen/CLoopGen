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
extern float *fmp;
extern float *fip;
extern float *fdp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via array base pointer arithmetic
    float *fmp_base = fmp + 2;
    float *fip_base = fip + 2;
    float *fdp_base = fdp + 2;
    float *begin_base = hmm->begin + 2;
    float **t_ptr = hmm->t;
    int M = hmm->M;

    for (k = 2; k <= M; k++) {
        int idx = k - 2; // index into base-shifted arrays
        int prev = idx - 1; // previous element in shifted view

        if (idx > 0) {
            fmp_base[idx] = fmp_base[prev] * t_ptr[k-1][0] + 
                            fip_base[prev] + 
                            fdp_base[prev] * t_ptr[k-1][5] + 
                            begin_base[idx];
            fdp_base[idx] = fmp_base[prev] * t_ptr[k-1][2] + 
                            fdp_base[prev] * t_ptr[k-1][6];
        } else {
            // k == 2, use original indices
            fmp_base[idx] = fmp[1] * t_ptr[1][0] + fip[1] + fdp[1] * t_ptr[1][5] + begin_base[0];
            fdp_base[idx] = fmp[1] * t_ptr[1][2] + fdp[1] * t_ptr[1][6];
        }

        if (k < M) {
            fip_base[idx] = fmp_base[idx] * t_ptr[k][1];
        }

        float sum = fmp_base[idx] + fdp_base[idx];
        fmp_base[idx] /= sum;
        fdp_base[idx] /= sum;
    }
}
