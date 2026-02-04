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


extern int L;
extern struct plan7_s *hmm;
extern int *kassign;
extern char *tassign;
extern int tlen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < L; i++) {
    if (!(tassign[i] == 1 || tassign[i] == 5)) continue;
    if (tassign[i + 1] == 1) {
        if (tassign[i] == 1)
            tlen += kassign[i + 1] - kassign[i] - 1;
        else if (tassign[i] == 5)
            tlen += kassign[i + 1] - 1;
    }
    else if (tassign[i] == 1 && tassign[i + 1] == 8)
        tlen += hmm->M - kassign[i];
}
}
