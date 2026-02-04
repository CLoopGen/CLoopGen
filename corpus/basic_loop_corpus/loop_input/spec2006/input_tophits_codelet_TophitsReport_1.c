#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

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

struct tophit_s *h;
double E;
int nseq;
int i;
int n;

void init_vars() {
    nseq = 10000;
    E = 0.01;
    i = 0;
    n = 0;

    h = (struct tophit_s *)malloc(sizeof(struct tophit_s));
    h->alloc = 50000;
    h->num = 50000;
    h->lump = 0;
    h->unsrt = NULL;
    h->hit = (struct hit_s **)malloc(h->alloc * sizeof(struct hit_s *));

    for (int idx = 0; idx < h->alloc; idx++) {
        struct hit_s *hit_entry = (struct hit_s *)malloc(sizeof(struct hit_s));
        hit_entry->pvalue = ((double)rand() / RAND_MAX) * 10.0; 
        hit_entry->sortkey = 0.0;
        hit_entry->score = 0.0f;
        hit_entry->mothersc = 0.0f;
        hit_entry->motherp = 0.0;
        hit_entry->name = NULL;
        hit_entry->acc = NULL;
        hit_entry->desc = NULL;
        hit_entry->sqfrom = 0;
        hit_entry->sqto = 0;
        hit_entry->sqlen = 100;
        hit_entry->hmmfrom = 1;
        hit_entry->hmmto = 100;
        hit_entry->hmmlen = 100;
        hit_entry->domidx = 1;
        hit_entry->ndom = 1;
        hit_entry->ali = NULL;

        h->hit[idx] = hit_entry;
    }
}