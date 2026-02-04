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
extern float *mp;
extern float *ip;
extern int nmat;
extern int ndel;
extern int nins;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_nmat = nmat;
    int temp_ndel = ndel;
    int prev_k = 1;
    for (k = 1; k <= hmm->M; k++) {
        if (k > 1) {
            // Introduce WAW dependency by reusing result from previous iteration
            temp_nmat = (mp[prev_k] >= 0.5) ? temp_nmat + 1 : temp_nmat;
            temp_ndel = (mp[prev_k] < 0.5)  ? temp_ndel + 1 : temp_ndel;
        }
        prev_k = k;
        if (ip[k] >= 0.5 && k < hmm->M) {
            float denominator = 1.F - hmm->t[k][4];
            if (denominator > 1e-6) {
                nins = nins + (int)(1.F / denominator); // WAR: nins updated before next use
            }
        }
    }
    // Final update to shared variables after loop (reducing loop-carried WAW)
    nmat = temp_nmat;
    ndel = temp_ndel;
    if (mp[hmm->M] >= 0.5) nmat++;
    else ndel++;
}
