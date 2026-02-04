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
int i;

void init_vars() {
    msa = (MSA *)calloc(1, sizeof(MSA));
    
    if (!msa) return;

    msa->alen = 0;
    msa->nseq = 0;
    msa->flags = 0;
    msa->type = 0;
    msa->name = NULL;
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;
    msa->ngf = 0;
    msa->alloc_ngf = 0;
    msa->ngs = 0;
    msa->ngc = 0;
    msa->ngr = 0;
    msa->nseqalloc = 0;
    msa->nseqlump = 0;
    msa->lastidx = 0;

    msa->aseq = NULL;
    msa->sqname = NULL;
    msa->wgt = NULL;
    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;
    msa->comment = NULL;
    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->gs_idx = NULL;
    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->gc_idx = NULL;
    msa->gr_tag = NULL;
    msa->gr = NULL;
    msa->index = NULL;
    msa->sqlen = NULL;
    msa->sslen = NULL;
    msa->salen = NULL;

    for (int j = 0; j < 6; j++) {
        msa->cutoff[j] = 0.0;
        msa->cutoff_is_set[j] = 0;
    }
}