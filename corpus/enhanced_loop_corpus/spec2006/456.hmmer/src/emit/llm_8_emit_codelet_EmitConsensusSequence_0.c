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
    int k_start = 1;
    int k_step = 1;
    int k_limit = hmm->M;

    for (k = k_start; k <= k_limit; k += k_step) {
        float inv_term = 1.0F / (1.0F - hmm->t[k][4]);
        if (mp[k] >= 0.5) {
            nmat++;
            if (k < hmm->M && ip[k] >= 0.5) {
                nins += (int)inv_term;
            }
        } else {
            ndel++;
            if (k < hmm->M && ip[k] >= 0.5) {
                nins += (int)(inv_term * 0.5F); // Reduced contribution in this path
            }
        }
    }
}
