#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
float basep;
int k;

void init_vars() {
    // Allocate hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    // Set M to a value that makes the loop run for ~0.01 seconds
    // On modern CPUs, a few million iterations take ~0.01s; we choose 5M
    hmm->M = 5000000;

    // Initialize basep to a reasonable value
    basep = 0.1f;

    // Allocate end array of size M
    hmm->end = (float *)calloc(hmm->M + 1, sizeof(float)); // index from 1 to M
    if (!hmm->end) exit(1);
}

// Ensure all external symbols are defined
struct plan7_s *hmm;
float basep;
int k;