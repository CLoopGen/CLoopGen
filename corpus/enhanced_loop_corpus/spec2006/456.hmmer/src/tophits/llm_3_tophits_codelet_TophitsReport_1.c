#include <stdio.h>

#include <inttypes.h>

struct fancyali_s {
    char *rfline;
    char *csline;
    char *model;
    char *mline;
    char *aseq;
    int len;
    char *query;
    char *target;
    int sqfrom;
    int sqto;
};


struct hit_s {
    double sortkey;
    float score;
    double pvalue;
    float mothersc;
    double motherp;
    char *name;
    char *acc;
    char *desc;
    int sqfrom;
    int sqto;
    int sqlen;
    int hmmfrom;
    int hmmto;
    int hmmlen;
    int domidx;
    int ndom;
    struct fancyali_s *ali;
};


struct tophit_s {
    struct hit_s **hit;
    struct hit_s *unsrt;
    int alloc;
    int num;
    int lump;
};


extern struct tophit_s *h;
extern double E;
extern int nseq;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access Pattern via Index Remapping
    // Use an auxiliary index array to access h->hit entries in reverse order
    // This changes the memory access pattern to indirect and reverses evaluation order
    int *indices = (int*)__builtin_alloca(h->num * sizeof(int));
    for (int j = 0; j < h->num; j++) {
        indices[j] = h->num - 1 - j;  // Reverse mapping
    }

    n = 0;
    for (i = 0; i < h->num; i++) {
        int idx = indices[i];  // Indirect access
        if (h->hit[idx]->pvalue * (double)nseq >= E)
            break;
        n++;
    }
}
