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
int stride = 4;
for (i = 1; i < L; i++) {
    int cond1 = (tassign[i] == 1);
    int cond5 = (tassign[i] == 5);
    int cond8_next = (i + 1 < L && tassign[i + 1] == 8);
    int cond1_next = (i + 1 < L && tassign[i + 1] == 1);
    
    if (cond1 && cond1_next)
        tlen += kassign[i + 1] - kassign[i] - 1;
    else if (cond5 && cond1_next)
        tlen += kassign[i + 1] - 1;
    else if (cond1 && cond8_next)
        tlen += hmm->M - kassign[i];
        
    if (i % stride == 0) {
        tlen += (hmm->checksum > 0) ? hmm->checksum % 3 : 0;
        for (int j = 0; j < 2; j++) {
            tlen -= (hmm->xt[0][j] < 0.0f) ? 1 : 0;
        }
    }
}
}
