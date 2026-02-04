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
int idx;
int i;
int last;

void init_vars() {
    msa = (MSA *)calloc(1, sizeof(MSA));
    if (!msa) exit(1);

    msa->nseq = 4000;
    msa->alen = 256;
    last = msa->alen;

    msa->aseq = (char **)calloc(msa->nseq, sizeof(char *));
    if (!msa->aseq) exit(1);

    for (int seq_idx = 0; seq_idx < msa->nseq; seq_idx++) {
        msa->aseq[seq_idx] = (char *)malloc(msa->alen * sizeof(char));
        if (!msa->aseq[seq_idx]) exit(1);
        for (int pos = 0; pos < msa->alen - 1; pos++) {
            msa->aseq[seq_idx][pos] = ' ';
        }
        msa->aseq[seq_idx][msa->alen - 1] = '-';
    }

    msa->sqname = (char **)calloc(msa->nseq, sizeof(char *));
    msa->wgt = (float *)calloc(msa->nseq, sizeof(float));
    msa->sqlen = (int *)calloc(msa->nseq, sizeof(int));
    msa->sslen = (int *)calloc(msa->nseq, sizeof(int));
    msa->salen = (int *)calloc(msa->nseq, sizeof(int));

    for (int j = 0; j < msa->nseq; j++) {
        msa->sqlen[j] = msa->alen;
        msa->sslen[j] = msa->alen;
        msa->salen[j] = msa->alen;
    }

    msa->flags = 0;
    msa->type = 1;
    msa->name = strdup("test_msa");
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;

    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;

    for (int k = 0; k < 6; k++) {
        msa->cutoff[k] = 0.0f;
        msa->cutoff_is_set[k] = 0;
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
    msa->nseqalloc = msa->nseq;
    msa->nseqlump = 0;
    msa->lastidx = -1;
}