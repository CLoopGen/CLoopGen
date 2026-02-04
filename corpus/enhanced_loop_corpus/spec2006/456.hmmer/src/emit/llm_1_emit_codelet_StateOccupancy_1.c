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
    // Variant 2: Reduced loop nesting depth by unrolling the loop body and eliminating conditional inside the loop.
    // We assume M is at least 2. The loop now performs full iterations without branching inside.
    // Conditional assignment for fip[k] is moved after the main loop.
    if (hmm->M >= 2) {
        // Handle k=2 separately to allow forward scheduling
        fmp[2] = fmp[1] * hmm->t[1][0] + fip[1] + fdp[1] * hmm->t[1][5] + hmm->begin[2];
        fdp[2] = fmp[1] * hmm->t[1][2] + fdp[1] * hmm->t[1][6];
        float sum2 = fmp[2] + fdp[2];
        fmp[2] /= sum2;
        fdp[2] /= sum2;

        // Loop from k=3 to M with no conditionals
        for (k = 3; k <= hmm->M; k++) {
            fmp[k] = fmp[k - 1] * hmm->t[k - 1][0] + fip[k - 1] + fdp[k - 1] * hmm->t[k - 1][5] + hmm->begin[k];
            fdp[k] = fmp[k - 1] * hmm->t[k - 1][2] + fdp[k - 1] * hmm->t[k - 1][6];
            fmp[k] /= fmp[k] + fdp[k];
            fdp[k] /= fmp[k] + fdp[k];
        }

        // Post-loop: assign fip[k] values for k < M
        for (k = 2; k < hmm->M; k++) {
            fip[k] = fmp[k] * hmm->t[k][1];
        }
    }
}
