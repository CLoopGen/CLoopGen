#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct basic_state {
    float t[3];
    float p[20];
};

struct plan9_s {
    int M;
    struct basic_state *ins;
    struct basic_state *mat;
    struct basic_state *del;
    float null[20];
    char *name;
    char *ref;
    char *cs;
    float *xray;
    int flags;
};

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

int Alphabet_size;
struct plan9_s *hmm;
struct plan7_s *plan7;
int k;
int x;

void init_vars() {
    // Set Alphabet_size to a value that will make the loop take ~0.01 seconds
    // The loop runs for hmm->M * Alphabet_size iterations
    // To get around 10-20 million operations (typical for 0.01s on modern CPU), set parameters accordingly
    Alphabet_size = 20;  // Typical alphabet size (e.g., amino acids)

    // Allocate and initialize hmm
    hmm = (struct plan9_s *)calloc(1, sizeof(struct plan9_s));
    hmm->M = 500000 / Alphabet_size;  // Total about 500k iterations
    if (hmm->M == 0) hmm->M = 1;

    // Allocate mat array of basic_state structs
    hmm->mat = (struct basic_state *)calloc(hmm->M + 1, sizeof(struct basic_state));  // 1-indexed

    // Allocate plan7
    plan7 = (struct plan7_s *)calloc(1, sizeof(struct plan7_s));
    plan7->M = hmm->M;

    // Allocate 2D arrays: mat[k][x] for k in [1..M], x in [0..Alphabet_size)
    plan7->mat = (float **)calloc(plan7->M + 1, sizeof(float *));
    for (int i = 1; i <= plan7->M; i++) {
        plan7->mat[i] = (float *)calloc(Alphabet_size, sizeof(float));
    }

    // Initialize all other needed pointers to avoid crashes (even if unused)
    plan7->t = (float **)calloc(plan7->M + 1, sizeof(float *));
    plan7->ins = (float **)calloc(plan7->M + 1, sizeof(float *));
    for (int i = 1; i <= plan7->M; i++) {
        plan7->t[i] = (float *)calloc(2, sizeof(float));
        plan7->ins[i] = (float *)calloc(Alphabet_size, sizeof(float));
    }

    // Initialize begin/end arrays
    plan7->begin = (float *)calloc(plan7->M + 1, sizeof(float));
    plan7->end = (float *)calloc(plan7->M + 1, sizeof(float));

    // Initialize integer 2D arrays just in case
    plan7->tsc = (int **)calloc(plan7->M + 1, sizeof(int *));
    plan7->msc = (int **)calloc(plan7->M + 1, sizeof(int *));
    plan7->isc = (int **)calloc(plan7->M + 1, sizeof(int *));
    for (int i = 1; i <= plan7->M; i++) {
        plan7->tsc[i] = (int *)calloc(2, sizeof(int));
        plan7->msc[i] = (int *)calloc(Alphabet_size, sizeof(int));
        plan7->isc[i] = (int *)calloc(Alphabet_size, sizeof(int));
    }

    // Allocate memory pools
    plan7->tsc_mem = (int *)calloc((plan7->M + 1) * 2, sizeof(int));
    plan7->msc_mem = (int *)calloc((plan7->M + 1) * Alphabet_size, sizeof(int));
    plan7->isc_mem = (int *)calloc((plan7->M + 1) * Alphabet_size, sizeof(int));
    plan7->bsc_mem = (int *)calloc(plan7->M + 1, sizeof(int));
    plan7->esc_mem = (int *)calloc(plan7->M + 1, sizeof(int));

    plan7->bsc = plan7->bsc_mem;
    plan7->esc = plan7->esc_mem;

    // Initialize string fields to empty strings to prevent null dereference
    char *empty_str = "";
    plan7->name = empty_str;
    plan7->acc = empty_str;
    plan7->desc = empty_str;
    plan7->rf = empty_str;
    plan7->cs = empty_str;
    plan7->ca = empty_str;
    plan7->comlog = empty_str;
    plan7->ctime = empty_str;

    // Initialize pointer arrays in plan9 if needed
    hmm->ins = (struct basic_state *)calloc(hmm->M + 1, sizeof(struct basic_state));
    hmm->del = (struct basic_state *)calloc(hmm->M + 1, sizeof(struct basic_state));
    hmm->xray = (float *)calloc(Alphabet_size, sizeof(float));
    hmm->name = empty_str;
    hmm->ref = empty_str;
    hmm->cs = empty_str;

    // Initialize p arrays in mat, ins, del with dummy data
    for (int i = 1; i <= hmm->M; i++) {
        for (int j = 0; j < Alphabet_size; j++) {
            hmm->mat[i].p[j] = (float)(i * 0.1 + j * 0.01);
        }
    }

    // Ensure plan7->mat is zeroed initially
    for (int i = 1; i <= plan7->M; i++) {
        for (int j = 0; j < Alphabet_size; j++) {
            plan7->mat[i][j] = 0.0f;
        }
    }
}