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
extern int k1;
extern int k3;
extern int **mmx;
extern int **dmx;
extern int cur;
extern int k;
extern int sc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_k = k1;
    if (k1 < k3) {
        for (k = k1 + 1; k <= k3; k++) {
            int mmx_val = mmx[cur][k - 1];
            int dmx_prev = dmx[cur][prev_k];
            int tsc2_val = hmm->tsc[2][k - 1];
            int tsc6_val = hmm->tsc[6][k - 1];

            sc = mmx_val + tsc2_val;
            dmx[cur][k] = (sc > -987654321) ? sc : -987654321;

            sc = dmx_prev + tsc6_val;
            if (sc > dmx[cur][k])
                dmx[cur][k] = sc;

            prev_k = k;
        }
    }
}
