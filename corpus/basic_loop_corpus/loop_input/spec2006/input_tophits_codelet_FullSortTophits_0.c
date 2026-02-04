#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int i;

static char *create_string(int size) {
    char *str = (char *)malloc(size);
    if (str) {
        memset(str, 'A', size - 1);
        str[size - 1] = '\0';
    }
    return str;
}

void init_vars() {
    const int num_hits = 50000;  // Adjusted for ~0.01 sec runtime

    h = (struct tophit_s *)malloc(sizeof(struct tophit_s));
    h->alloc = num_hits;
    h->num = num_hits;
    h->lump = 1;

    h->hit = (struct hit_s **)calloc(num_hits, sizeof(struct hit_s *));
    h->unsrt = (struct hit_s *)calloc(num_hits, sizeof(struct hit_s));

    for (int idx = 0; idx < num_hits; idx++) {
        struct hit_s *hit_ptr = &(h->unsrt[idx]);
        hit_ptr->sortkey = 1000.0 - idx * 0.01;
        hit_ptr->score = 80.0f + (idx % 20);
        hit_ptr->pvalue = 1e-5;
        hit_ptr->mothersc = 75.0f;
        hit_ptr->motherp = 1e-4;
        hit_ptr->name = create_string(16);
        hit_ptr->acc = create_string(12);
        hit_ptr->desc = create_string(64);
        hit_ptr->sqfrom = 10 + idx;
        hit_ptr->sqto = 100 + idx;
        hit_ptr->sqlen = 500;
        hit_ptr->hmmfrom = 5 + idx;
        hit_ptr->hmmto = 90 + idx;
        hit_ptr->hmmlen = 450;
        hit_ptr->domidx = 1;
        hit_ptr->ndom = 1;

        hit_ptr->ali = (struct fancyali_s *)malloc(sizeof(struct fancyali_s));
        hit_ptr->ali->rfline = create_string(80);
        hit_ptr->ali->csline = create_string(80);
        hit_ptr->ali->model = create_string(80);
        hit_ptr->ali->mline = create_string(80);
        hit_ptr->ali->aseq = create_string(80);
        hit_ptr->ali->len = 80;
        hit_ptr->ali->query = create_string(80);
        hit_ptr->ali->target = create_string(80);
        hit_ptr->ali->sqfrom = 1;
        hit_ptr->ali->sqto = 80;
    }

    i = 0;
}