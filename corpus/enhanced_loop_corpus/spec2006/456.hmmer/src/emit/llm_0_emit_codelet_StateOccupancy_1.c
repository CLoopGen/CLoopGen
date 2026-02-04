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
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops.
    // The outer loop processes chunks of size 2, and the inner loop handles individual elements within the chunk.
    int chunk_size = 2;
    int num_chunks = (hmm->M - 1) / chunk_size + 1;
    
    for (int chunk = 0; chunk < num_chunks; chunk++) {
        int start_k = 2 + chunk * chunk_size;
        int end_k = (start_k + chunk_size > hmm->M) ? hmm->M : start_k + chunk_size;
        
        for (k = start_k; k <= end_k; k++) {
            fmp[k] = fmp[k - 1] * hmm->t[k - 1][0] + fip[k - 1] + fdp[k - 1] * hmm->t[k - 1][5] + hmm->begin[k];
            fdp[k] = fmp[k - 1] * hmm->t[k - 1][2] + fdp[k - 1] * hmm->t[k - 1][6];
            if (k < hmm->M) {
                fip[k] = fmp[k] * hmm->t[k][1];
            }
            fmp[k] /= fmp[k] + fdp[k];
            fdp[k] /= fmp[k] + fdp[k];
        }
    }
}
