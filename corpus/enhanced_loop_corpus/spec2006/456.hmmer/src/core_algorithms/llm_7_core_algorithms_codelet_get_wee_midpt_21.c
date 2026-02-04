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
extern char *dsq;
extern int k1;
extern int k3;
extern int s3;
extern int **xmx;
extern int **mmx;
extern int s2;
extern int nxt;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *restrict local_esc = hmm->esc;
    int **restrict local_mmx = mmx;
    int **restrict local_msc = hmm->msc;
    char *restrict local_dsq = dsq;
    int base_score = xmx[nxt][1];
    int i;
    for (i = 0; i <= k3 - k1; i++) {
        int k_index = k3 - i;
        local_mmx[nxt][k_index] = base_score + local_esc[k_index];
        if (s3 != s2) {
            local_mmx[nxt][k_index] += local_msc[(int)local_dsq[s3]][k_index];
        }
    }
}
