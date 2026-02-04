#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int L = 10000000;
struct plan7_s *hmm;
int *kassign;
char *tassign;
int tlen;
int i;

void init_vars() {
    // Allocate and initialize hmm
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = 500;

    // Set L to desired size for ~0.01 sec runtime
    L = 10000000;  // Adjust as needed based on target performance

    // Allocate tassign and kassign with padding to prevent out-of-bounds access
    tassign = (char *)calloc(L + 2, sizeof(char));
    kassign = (int *)calloc(L + 2, sizeof(int));

    // Initialize tassign and kassign with sample data
    for (int idx = 0; idx < L + 1; idx++) {
        kassign[idx] = rand() % hmm->M;
        tassign[idx] = (rand() % 8) + 1;  // values from 1 to 8
    }

    // Ensure last element is safe for i+1 indexing when i = L-1
    tassign[L] = 1;
    kassign[L] = hmm->M / 2;
    tassign[L+1] = 1;
    kassign[L+1] = hmm->M - 1;

    // Initialize tlen
    tlen = 0;
}