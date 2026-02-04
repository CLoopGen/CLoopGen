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
int *dmx_row = dmx[cur];
int *mmx_row = mmx[cur];
int k_start = k1 + 1;
int k_end = k3;
for (int i = k_start; i <= k_end; i++) {
    int prev = i - 1;
    dmx_row[i] = -987654321;
    if ((sc = mmx_row[prev] + hmm->tsc[2][prev]) > -987654321)
        dmx_row[i] = sc;
    if ((sc = dmx_row[prev] + hmm->tsc[6][prev]) > dmx_row[i])
        dmx_row[i] = sc;
}
}
