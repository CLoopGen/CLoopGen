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
char *dsq;
int k1;
int k3;
int s3;
int **xmx;
int **mmx;
int s2;
int nxt;
int k;

void init_vars() {
    // Allocate hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    // Set M to a reasonable size (~1024), and use it for array dimensions
    hmm->M = 1024;

    // Allocate esc array of size M
    hmm->esc = (int *)calloc(hmm->M, sizeof(int));
    if (!hmm->esc) exit(1);

    // Allocate msc as a 5xM matrix (assuming dsq values are in range 0-4)
    hmm->msc = (int **)calloc(5, sizeof(int *));
    if (!hmm->msc) exit(1);
    for (int i = 0; i < 5; i++) {
        hmm->msc[i] = (int *)calloc(hmm->M, sizeof(int));
        if (!hmm->msc[i]) exit(1);
    }

    // Allocate dsq with ~64MB to ensure sufficient runtime
    dsq = (char *)calloc(64 * 1024 * 1024, sizeof(char));
    if (!dsq) exit(1);

    // Initialize loop indices
    k1 = 0;
    k3 = hmm->M - 1;  // so k goes from M-1 down to 0
    s3 = 100;         // within bounds of dsq
    s2 = 99;          // different from s3 to trigger conditional
    nxt = 0;

    // Allocate xmx and mmx as 2D arrays: [1][2] minimum, but make it larger if needed
    xmx = (int **)calloc(1, sizeof(int *));
    if (!xmx) exit(1);
    xmx[0] = (int *)calloc(2, sizeof(int));
    if (!xmx[0]) exit(1);

    mmx = (int **)calloc(1, sizeof(int *));
    if (!mmx) exit(1);
    mmx[0] = (int *)calloc(hmm->M, sizeof(int));
    if (!mmx[0]) exit(1);

    // Ensure xmx[nxt][1] is initialized
    xmx[0][1] = 100;
}