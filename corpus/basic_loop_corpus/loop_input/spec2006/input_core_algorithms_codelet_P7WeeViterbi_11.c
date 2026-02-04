#include <stdio.h>
#include <stdlib.h>
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

struct plan7_s *hmm;
int *kassign;
char *tassign;
int s2;
int s3;

void init_vars() {
    // Allocate and initialize hmm
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    hmm->M = 100;  // Set M to a reasonable value

    // Set loop bounds so that the loop runs for approximately 0.01 seconds
    // Assume modern CPU can do ~1e9 iterations/sec -> 1e7 iterations in 0.01 sec
    s2 = 0;
    s3 = 9999999;  // 10 million iterations

    // Allocate kassign and tassign arrays of size s3+1
    kassign = (int *)calloc(s3 + 1, sizeof(int));
    if (!kassign) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    tassign = (char *)calloc(s3 + 1, sizeof(char));
    if (!tassign) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

// End of file