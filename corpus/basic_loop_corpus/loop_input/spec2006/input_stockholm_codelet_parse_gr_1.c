#include <stdio.h>
#include <stdlib.h>
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
int j;

void init_vars() {
    msa = (MSA *)calloc(1, sizeof(MSA));
    if (!msa) exit(1);

    msa->nseqalloc = 131072;

    msa->sa = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->sa) exit(1);

    msa->salen = (int *)calloc(msa->nseqalloc, sizeof(int));
    if (!msa->salen) exit(1);

    msa->sqlen = (int *)calloc(msa->nseqalloc, sizeof(int));
    if (!msa->sqlen) exit(1);

    msa->sslen = (int *)calloc(msa->nseqalloc, sizeof(int));
    if (!msa->sslen) exit(1);

    for (int i = 0; i < 6; i++) {
        msa->cutoff[i] = 0.0f;
        msa->cutoff_is_set[i] = 0;
    }

    msa->aseq = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->aseq) exit(1);

    msa->sqname = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->sqname) exit(1);

    msa->wgt = (float *)calloc(msa->nseqalloc, sizeof(float));
    if (!msa->wgt) exit(1);

    msa->ss = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->ss) exit(1);

    msa->sqacc = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->sqacc) exit(1);

    msa->sqdesc = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->sqdesc) exit(1);

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
    msa->nseqlump = 0;
    msa->lastidx = -1;

    msa->name = NULL;
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;
}