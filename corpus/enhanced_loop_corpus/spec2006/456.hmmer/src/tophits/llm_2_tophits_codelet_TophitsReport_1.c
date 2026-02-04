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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive hit entries, traverse with a stride of 2,
    // then handle remaining elements in a second pass to ensure all are processed.
    int stride = 2;
    n = 0;

    // First pass: strided access
    for (i = 0; i < h->num; i += stride) {
        if (h->hit[i]->pvalue * (double)nseq >= E)
            break;
        n++;
    }

    // Second pass: fill in the gaps (odd indices)
    for (i = 1; i < h->num; i += stride) {
        if (h->hit[i]->pvalue * (double)nseq >= E)
            break;
        n++;
    }
}
