#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (!msa) exit(1);

    msa->nseqalloc = 10000000; // ~10M iterations to target ~0.01 sec runtime

    msa->gr_tag = (char **)calloc(1, sizeof(char *));
    if (!msa->gr_tag) exit(1);
    msa->gr_tag[0] = strdup("gr_data");

    msa->gr = (char ***)calloc(1, sizeof(char **));
    if (!msa->gr) exit(1);
    msa->gr[0] = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->gr[0]) exit(1);

    msa->ngr = 1;
    msa->nseqlump = 0;
    msa->lastidx = -1;

    msa->sqlen = (int *)calloc(msa->nseqalloc, sizeof(int));
    msa->sslen = (int *)calloc(msa->nseqalloc, sizeof(int));
    msa->salen = (int *)calloc(msa->nseqalloc, sizeof(int));
    if (!msa->sqlen || !msa->sslen || !msa->salen) exit(1);

    msa->gs_idx = (GKI *)calloc(1, sizeof(GKI));
    msa->gc_idx = (GKI *)calloc(1, sizeof(GKI));
    msa->gr_idx = (GKI *)calloc(1, sizeof(GKI));
    msa->index = (GKI *)calloc(1, sizeof(GKI));
    if (!msa->gs_idx || !msa->gc_idx || !msa->gr_idx || !msa->index) exit(1);

    msa->gs_idx->table = NULL;
    msa->gc_idx->table = NULL;
    msa->gr_idx->table = NULL;
    msa->index->table = NULL;

    msa->gs_idx->primelevel = msa->gc_idx->primelevel = 
    msa->gr_idx->primelevel = msa->index->primelevel = 0;
    msa->gs_idx->nhash = msa->gc_idx->nhash = 
    msa->gr_idx->nhash = msa->index->nhash = 0;
    msa->gs_idx->nkeys = msa->gc_idx->nkeys = 
    msa->gr_idx->nkeys = msa->index->nkeys = 0;

    for (int j = 0; j < 6; j++) {
        msa->cutoff[j] = 0.0f;
        msa->cutoff_is_set[j] = 0;
    }

    msa->aseq = NULL;
    msa->sqname = NULL;
    msa->wgt = NULL;
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

    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;

    msa->comment = NULL;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;

    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->ngf = 0;
    msa->alloc_ngf = 0;

    msa->gs_tag = NULL;
    msa->gs = NULL;
    msa->ngs = 0;

    msa->gc_tag = NULL;
    msa->gc = NULL;
    msa->ngc = 0;

    msa->name = strdup("test_msa");
    msa->desc = strdup("benchmark description");
}