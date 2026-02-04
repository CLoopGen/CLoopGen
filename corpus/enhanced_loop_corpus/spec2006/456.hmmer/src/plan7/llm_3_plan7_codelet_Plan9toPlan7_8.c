#include <stdio.h>

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


extern int Alphabet_size;
extern struct plan9_s *hmm;
extern struct plan7_s *plan7;
extern int k;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed stride over plan7->mat and hmm->mat
    float **mat_ptr = plan7->mat;
    struct basic_state *hmm_mat_ptr = hmm->mat;
    int m = hmm->M;
    int alpha_size = Alphabet_size;

    for (k = 1; k <= m; k++) {
        float *mat_row = mat_ptr[k];
        float *p_vec = hmm_mat_ptr[k].p;
        for (x = 0; x < alpha_size; x += 4) {
            // Unroll by 4 to create strided access pattern
            if (x + 0 < alpha_size) mat_row[x + 0] = p_vec[x + 0];
            if (x + 1 < alpha_size) mat_row[x + 1] = p_vec[x + 1];
            if (x + 2 < alpha_size) mat_row[x + 2] = p_vec[x + 2];
            if (x + 3 < alpha_size) mat_row[x + 3] = p_vec[x + 3];
        }
    }
}
