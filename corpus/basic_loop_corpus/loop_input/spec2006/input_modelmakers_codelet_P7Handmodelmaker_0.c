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
int *matassign;
int apos;

void init_vars() {
    const int alen = 10000000; // ~10M to make loop take ~0.01s

    msa = (MSA*)calloc(1, sizeof(MSA));
    matassign = (int*)calloc(alen + 2, sizeof(int));

    msa->alen = alen;
    msa->rf = (char*)malloc(alen * sizeof(char));
    
    for (int i = 0; i < alen; ++i) {
        msa->rf[i] = (i % 7 == 0) ? ' ' : 'x';
    }

    msa->aseq = NULL;
    msa->sqname = NULL;
    msa->wgt = NULL;
    msa->nseq = 0;
    msa->flags = 0;
    msa->type = 0;
    msa->name = NULL;
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;
    for (int i = 0; i < 6; ++i) {
        msa->cutoff[i] = 0.0f;
        msa->cutoff_is_set[i] = 0;
    }
    msa->comment = NULL;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;
    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->ngf = 0;
    msa->alloc_ngf = 0;
    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->gs_idx = NULL;
    msa->ngs = 0;
    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->gc_idx = NULL;
    msa->ngc = 0;
    msa->gr_tag = NULL;
    msa->gr = NULL;
    msa->gr_idx = NULL;
    msa->ngr = 0;
    msa->index = NULL;
    msa->nseqalloc = 0;
    msa->nseqlump = 0;
    msa->sqlen = NULL;
    msa->sslen = NULL;
    msa->salen = NULL;
    msa->lastidx = -1;
}