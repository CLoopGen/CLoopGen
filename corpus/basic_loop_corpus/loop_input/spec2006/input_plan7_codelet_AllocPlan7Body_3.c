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
int x;

void init_vars() {
    // Allocate hmm structure
    hmm = malloc(sizeof(struct plan7_s));
    if (!hmm) exit(1);

    // Initialize scalar fields
    hmm->nseq = 0;
    hmm->checksum = 0;
    hmm->ga1 = 0.0f;
    hmm->ga2 = 0.0f;
    hmm->tc1 = 0.0f;
    hmm->tc2 = 0.0f;
    hmm->nc1 = 0.0f;
    hmm->nc2 = 0.0f;
    hmm->M = 0;
    hmm->tbd1 = 0.0f;
    hmm->p1 = 0.0f;
    hmm->dna2 = 0;
    hmm->dna4 = 0;
    hmm->mu = 0.0f;
    hmm->lambda = 0.0f;
    hmm->flags = 0;

    // Initialize arrays inside struct
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            hmm->xt[i][j] = 0.0f;
            hmm->xsc[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; i++) {
        hmm->null[i] = 0.0f;
    }

    // Allocate memory for pointer arrays with sufficient size to avoid bounds issues
    // Since loop runs up to x=6, we need at least 7 elements for tsc[x][0]
    hmm->tsc_mem = calloc(7 * 1, sizeof(int));
    if (!hmm->tsc_mem) exit(1);

    // Allocate and initialize tsc as array of 7 pointers
    hmm->tsc = malloc(7 * sizeof(int*));
    if (!hmm->tsc) exit(1);
    for (int i = 0; i < 7; i++) {
        hmm->tsc[i] = hmm->tsc_mem + i * 1;
    }

    // Allocate other required pointer fields to prevent crashes
    hmm->msc_mem = calloc(7 * 1, sizeof(int));
    if (!hmm->msc_mem) exit(1);
    hmm->msc = malloc(7 * sizeof(int*));
    if (!hmm->msc) exit(1);
    for (int i = 0; i < 7; i++) {
        hmm->msc[i] = hmm->msc_mem + i * 1;
    }

    hmm->isc_mem = calloc(7 * 1, sizeof(int));
    if (!hmm->isc_mem) exit(1);
    hmm->isc = malloc(7 * sizeof(int*));
    if (!hmm->isc) exit(1);
    for (int i = 0; i < 7; i++) {
        hmm->isc[i] = hmm->isc_mem + i * 1;
    }

    hmm->bsc_mem = calloc(7, sizeof(int));
    if (!hmm->bsc_mem) exit(1);
    hmm->bsc = hmm->bsc_mem;

    hmm->esc_mem = calloc(7, sizeof(int));
    if (!hmm->esc_mem) exit(1);
    hmm->esc = hmm->esc_mem;

    // Allocate 2D arrays: dnam and dnai (size 7x4 suggested)
    hmm->dnam = malloc(7 * sizeof(int*));
    if (!hmm->dnam) exit(1);
    hmm->dnai = malloc(7 * sizeof(int*));
    if (!hmm->dnai) exit(1);

    int *dnam_data = calloc(7 * 4, sizeof(int));
    int *dnai_data = calloc(7 * 4, sizeof(int));
    if (!dnam_data || !dnai_data) exit(1);

    for (int i = 0; i < 7; i++) {
        hmm->dnam[i] = dnam_data + i * 4;
        hmm->dnai[i] = dnai_data + i * 4;
    }

    // Allocate 2D float arrays: t, mat, ins (size 7xM where M ~ 1000 to get desired data size ~1MB per array)
    int M = 1000;
    hmm->M = M;

    hmm->t = malloc(7 * sizeof(float*));
    if (!hmm->t) exit(1);
    hmm->mat = malloc(7 * sizeof(float*));
    if (!hmm->mat) exit(1);
    hmm->ins = malloc(7 * sizeof(float*));
    if (!hmm->ins) exit(1);

    float *t_data = calloc(7 * M, sizeof(float));
    float *mat_data = calloc(7 * M, sizeof(float));
    float *ins_data = calloc(7 * M, sizeof(float));
    if (!t_data || !mat_data || !ins_data) exit(1);

    for (int i = 0; i < 7; i++) {
        hmm->t[i] = t_data + i * M;
        hmm->mat[i] = mat_data + i * M;
        hmm->ins[i] = ins_data + i * M;
    }

    // Allocate begin and end arrays of size M
    hmm->begin = calloc(M, sizeof(float));
    hmm->end = calloc(M, sizeof(float));
    if (!hmm->begin || !hmm->end) exit(1);

    // Allocate map array of size M
    hmm->map = calloc(M, sizeof(int));
    if (!hmm->map) exit(1);

    // Allocate priority arrays
    hmm->tpri = calloc(M, sizeof(int));
    hmm->mpri = calloc(M, sizeof(int));
    hmm->ipri = calloc(M, sizeof(int));
    if (!hmm->tpri || !hmm->mpri || !hmm->ipri) exit(1);

    // String-like pointers can be NULL or empty
    hmm->name = NULL;
    hmm->acc = NULL;
    hmm->desc = NULL;
    hmm->rf = NULL;
    hmm->cs = NULL;
    hmm->ca = NULL;
    hmm->comlog = NULL;
    hmm->ctime = NULL;
}