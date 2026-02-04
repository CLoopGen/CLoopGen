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
    int *esc_ptr = hmm->esc;
    int **msc_ptr = hmm->msc;
    int dsq_val = (int)dsq[L];
    int xmx_val = xmx[L][1];
    float **t_ptr = hmm->t;
    float **mat_ptr = hmm->mat;
    float **ins_ptr = hmm->ins;

    for (k = hmm->M; k >= 1; k--) {
        int combined_score = esc_ptr[k] + msc_ptr[dsq_val][k];
        mmx[L][k] = xmx_val + combined_score;
        imx[L][k] = -987654321;
        dmx[L][k] = -987654321;
    }

    // Introduce artificial write-after-write dependency on k (WAW-like, though k is reused safely)
    k = -1;
}
