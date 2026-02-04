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
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride (e.g., step by 2) to simulate different cache behavior.
    // We adjust the loop increment and handle edge cases carefully.

    int stride = 2;
    int limit = L - 1;  // Ensure we don't go out of bounds when accessing i+1

    for (i = 1; i < limit; i += stride) {
        // Handle two iterations per loop body to preserve logic coverage
        // First element in stride
        if (tassign[i] == 1 && tassign[i + 1] == 1)
            tlen += kassign[i + 1] - kassign[i] - 1;
        if (tassign[i] == 5 && tassign[i + 1] == 1)
            tlen += kassign[i + 1] - 1;
        if (tassign[i] == 1 && tassign[i + 1] == 8)
            tlen += hmm->M - kassign[i];

        // Second element in stride (if within bounds)
        if (i + 1 < limit) {
            if (tassign[i + 1] == 1 && tassign[i + 2] == 1)
                tlen += kassign[i + 2] - kassign[i + 1] - 1;
            if (tassign[i + 1] == 5 && tassign[i + 2] == 1)
                tlen += kassign[i + 2] - 1;
            if (tassign[i + 1] == 1 && tassign[i + 2] == 8)
                tlen += hmm->M - kassign[i + 1];
        }
    }

    // Handle any remaining elements if L is not aligned with the stride
    for (; i < L; i++) {
        if (tassign[i] == 1 && tassign[i + 1] == 1)
            tlen += kassign[i + 1] - kassign[i] - 1;
        if (tassign[i] == 5 && tassign[i + 1] == 1)
            tlen += kassign[i + 1] - 1;
        if (tassign[i] == 1 && tassign[i + 1] == 8)
            tlen += hmm->M - kassign[i];
    }
}
