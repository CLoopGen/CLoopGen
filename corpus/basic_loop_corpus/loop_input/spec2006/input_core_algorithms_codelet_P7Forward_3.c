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
int **mmx;
int **imx;
int **dmx;
int k;

void init_vars() {
    // Allocate and initialize hmm structure
    hmm = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    if (!hmm) exit(1);

    // Set M to a value that will make the loop access ~100MB of memory
    // Each matrix has M+1 columns, and we have 3 matrices, each storing int (4 bytes)
    // Total size per row: 3*(M+1)*4 bytes
    // We want total allocation to be around 100MB for good timing (~0.01s on modern CPU)
    // Let's choose M such that 3*(M+1)*sizeof(int) * number_of_rows is about 100MB
    // We'll use 1000 rows for mmx/imx/dmx -> each matrix has 1000 rows
    const int num_rows = 1000;
    hmm->M = (int)((100 * 1024 * 1024) / (3 * num_rows * sizeof(int))) - 1;
    if (hmm->M < 100) hmm->M = 100;  // ensure minimum size

    // Allocate mmx, imx, dmx: each is num_rows x (M+1)
    mmx = (int **)calloc(num_rows, sizeof(int *));
    imx = (int **)calloc(num_rows, sizeof(int *));
    dmx = (int **)calloc(num_rows, sizeof(int *));
    if (!mmx || !imx || !dmx) exit(1);

    int total_elements = num_rows * (hmm->M + 1);
    int *mmx_data = (int *)calloc(total_elements, sizeof(int));
    int *imx_data = (int *)calloc(total_elements, sizeof(int));
    int *dmx_data = (int *)calloc(total_elements, sizeof(int));
    if (!mmx_data || !imx_data || !dmx_data) exit(1);

    for (int i = 0; i < num_rows; i++) {
        mmx[i] = &mmx_data[i * (hmm->M + 1)];
        imx[i] = &imx_data[i * (hmm->M + 1)];
        dmx[i] = &dmx_data[i * (hmm->M + 1)];
    }
}