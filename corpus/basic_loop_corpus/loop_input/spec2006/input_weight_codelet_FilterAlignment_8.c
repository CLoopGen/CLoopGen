#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

struct gki_elem {
    char *key;
    int idx;
    struct gki_elem *nxt;
};

typedef struct {
    struct gki_elem **table;
    int primelevel;
    int nhash;
    int nkeys;
} GKI;

typedef struct msa_struct {
    char **aseq;
    char **sqname;
    float *wgt;
    int alen;
    int nseq;
    int flags;
    int type;
    char *name;
    char *desc;
    char *acc;
    char *au;
    char *ss_cons;
    char *sa_cons;
    char *rf;
    char **sqacc;
    char **sqdesc;
    char **ss;
    char **sa;
    float cutoff[6];
    int cutoff_is_set[6];
    char **comment;
    int ncomment;
    int alloc_ncomment;
    char **gf_tag;
    char **gf;
    int ngf;
    int alloc_ngf;
    char **gs_tag;
    char ***gs;
    GKI *gs_idx;
    int ngs;
    char **gc_tag;
    char **gc;
    GKI *gc_idx;
    int ngc;
    char **gr_tag;
    char ***gr;
    GKI *gr_idx;
    int ngr;
    GKI *index;
    int nseqalloc;
    int nseqlump;
    int *sqlen;
    int *sslen;
    int *salen;
    int lastidx;
} MSA;

MSA *msa;
int *useme;
int i;

void init_vars() {
    const int target_time_ns = 10000000; // ~10ms target
    const long long mem_size = 64 * 1024 * 1024; // 64MB as base size

    msa = (MSA*)calloc(1, sizeof(MSA));
    if (!msa) exit(1);

    msa->nseqalloc = (mem_size / sizeof(int)) / 2;
    msa->nseq = msa->nseqalloc;
    msa->nseqlump = 0;
    msa->lastidx = -1;

    useme = (int*)calloc(msa->nseqalloc, sizeof(int));
    if (!useme) exit(1);

    msa->sqlen = (int*)calloc(msa->nseqalloc, sizeof(int));
    msa->sslen = (int*)calloc(msa->nseqalloc, sizeof(int));
    msa->salen = (int*)calloc(msa->nseqalloc, sizeof(int));
    if (!msa->sqlen || !msa->sslen || !msa->salen) exit(1);

    for (int j = 0; j < msa->nseqalloc; j++) {
        msa->sqlen[j] = 100;
        msa->sslen[j] = 100;
        msa->salen[j] = 100;
    }

    msa->aseq = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sqname = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->wgt = (float*)calloc(msa->nseqalloc, sizeof(float));
    msa->sqacc = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sqdesc = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->ss = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sa = (char**)calloc(msa->nseqalloc, sizeof(char*));
    if (!msa->aseq || !msa->sqname || !msa->wgt || !msa->sqacc || !msa->sqdesc || !msa->ss || !msa->sa) exit(1);

    for (int j = 0; j < msa->nseqalloc; j++) {
        msa->aseq[j] = (char*)calloc(101, sizeof(char));
        msa->sqname[j] = (char*)calloc(32, sizeof(char));
        msa->wgt[j] = 1.0f;
        msa->sqacc[j] = (char*)calloc(32, sizeof(char));
        msa->sqdesc[j] = (char*)calloc(64, sizeof(char));
        msa->ss[j] = (char*)calloc(101, sizeof(char));
        msa->sa[j] = (char*)calloc(101, sizeof(char));
        strcpy(msa->sqname[j], "seq_name");
        strcpy(msa->sqacc[j], "acc");
        strcpy(msa->sqdesc[j], "description");
    }

    msa->name = strdup("msa_name");
    msa->desc = strdup("multiple sequence alignment");
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = (char*)calloc(101, sizeof(char));
    msa->sa_cons = (char*)calloc(101, sizeof(char));
    msa->rf = NULL;

    for (int j = 0; j < 6; j++) {
        msa->cutoff[j] = 0.5f;
        msa->cutoff_is_set[j] = 0;
    }

    msa->ncomment = 0;
    msa->alloc_ncomment = 8;
    msa->comment = (char**)calloc(msa->alloc_ncomment, sizeof(char*));

    msa->ngf = 0;
    msa->alloc_ngf = 8;
    msa->gf_tag = (char**)calloc(msa->alloc_ngf, sizeof(char*));
    msa->gf = (char**)calloc(msa->alloc_ngf, sizeof(char*));

    msa->ngs = 0;
    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->gs_idx = NULL;

    msa->ngc = 0;
    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->gc_idx = NULL;

    msa->ngr = 0;
    msa->gr_tag = NULL;
    msa->gr = NULL;
    msa->gr_idx = NULL;

    msa->index = (GKI*)calloc(1, sizeof(GKI));
    if (!msa->index) exit(1);
    msa->index->nhash = 1024;
    msa->index->nkeys = 0;
    msa->index->primelevel = 0;
    msa->index->table = (struct gki_elem**)calloc(1024, sizeof(struct gki_elem*));
    if (!msa->index->table) exit(1);

    i = 0;
}