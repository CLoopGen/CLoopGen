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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of random access, we process elements in a more sequential pattern by pre-resolving indices.
    int prev_tassign = tassign[0];
    int prev_kassign = kassign[0];
    
    for (i = 1; i < L; i++) {
        int curr_tassign = tassign[i];
        int next_tassign = tassign[i + 1];
        int curr_kassign = kassign[i];
        int next_kassign = kassign[i + 1];

        if (curr_tassign == 1 && next_tassign == 1)
            tlen += next_kassign - curr_kassign - 1;
        if (curr_tassign == 5 && next_tassign == 1)
            tlen += next_kassign - 1;
        if (curr_tassign == 1 && next_tassign == 8)
            tlen += hmm->M - curr_kassign;

        // Update previous values for potential use in further patterns
        prev_tassign = curr_tassign;
        prev_kassign = curr_kassign;
    }
}
