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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    float *mp_ptr = mp + 1;
    float *ip_ptr = ip + 1;
    float **t_ptr = hmm->t + 1;
    int M = hmm->M;

    for (k = 1; k <= M; k++) {
        if (*mp_ptr >= 0.5)
            nmat++;
        else
            ndel++;

        if (k < M && *ip_ptr >= 0.5) {
            float denom = 1.F - (*(t_ptr))[4];
            nins += (int)(1.F / denom);
        }

        mp_ptr++;
        ip_ptr++;
        t_ptr++;
    }
}
