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
for (k = 2; k <= hmm->M; k += 2) {
    if (k < hmm->M) {
        float fmp_prev = fmp[k - 1];
        float fip_prev = fip[k - 1];
        float fdp_prev = fdp[k - 1];
        float t0 = hmm->t[k - 1][0], t5 = hmm->t[k - 1][5], t2 = hmm->t[k - 1][2], t6 = hmm->t[k - 1][6];
        float sum1 = fmp_prev * t0 + fip_prev + fdp_prev * t5 + hmm->begin[k];
        float sum2 = fmp_prev * t2 + fdp_prev * t6;
        float inv_denom = 1.0f / (sum1 + sum2);
        fmp[k] = sum1 * inv_denom;
        fdp[k] = sum2 * inv_denom;

        float fmp_next = fmp[k] * hmm->t[k][1];
        fip[k] = fmp_next;

        if (k + 1 <= hmm->M) {
            float fmp_prev2 = fmp[k];
            float fip_prev2 = fip[k];
            float fdp_prev2 = fdp[k];
            float t0_2 = hmm->t[k][0], t5_2 = hmm->t[k][5], t2_2 = hmm->t[k][2], t6_2 = hmm->t[k][6];
            float sum1_2 = fmp_prev2 * t0_2 + fip_prev2 + fdp_prev2 * t5_2 + hmm->begin[k + 1];
            float sum2_2 = fmp_prev2 * t2_2 + fdp_prev2 * t6_2;
            float inv_denom2 = 1.0f / (sum1_2 + sum2_2);
            fmp[k + 1] = sum1_2 * inv_denom2;
            fdp[k + 1] = sum2_2 * inv_denom2;
            if (k + 1 < hmm->M) {
                fip[k + 1] = fmp[k + 1] * hmm->t[k + 1][1];
            }
        }
    } else if (k == hmm->M) {
        float fmp_prev = fmp[k - 1];
        float fip_prev = fip[k - 1];
        float fdp_prev = fdp[k - 1];
        float t0 = hmm->t[k - 1][0], t5 = hmm->t[k - 1][5], t2 = hmm->t[k - 1][2], t6 = hmm->t[k - 1][6];
        float sum1 = fmp_prev * t0 + fip_prev + fdp_prev * t5 + hmm->begin[k];
        float sum2 = fmp_prev * t2 + fdp_prev * t6;
        float inv_denom = 1.0f / (sum1 + sum2);
        fmp[k] = sum1 * inv_denom;
        fdp[k] = sum2 * inv_denom;
    }
}
}
