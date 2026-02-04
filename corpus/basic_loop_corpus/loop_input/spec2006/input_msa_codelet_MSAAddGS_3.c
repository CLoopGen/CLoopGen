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
int i;

void init_vars() {
    msa = (MSA *)calloc(1, sizeof(MSA));
    msa->nseqalloc = 131072;  // ~1MB of pointers (assuming 8-byte per pointer on 64-bit)

    msa->gs_tag = (char **)calloc(msa->nseqalloc, sizeof(char *));
    msa->gs = (char ***)calloc(1, sizeof(char **));
    msa->gs[0] = (char **)calloc(msa->nseqalloc, sizeof(char *));

    msa->gs_idx = (GKI *)calloc(1, sizeof(GKI));
    msa->gs_idx->table = NULL;
    msa->gs_idx->primelevel = 0;
    msa->gs_idx->nhash = 0;
    msa->gs_idx->nkeys = 0;

    msa->ngs = 0;

    msa->sqlen = (int *)calloc(msa->nseqalloc, sizeof(int));
    msa->sslen = (int *)calloc(msa->nseqalloc, sizeof(int));
    msa->salen = (int *)calloc(msa->nseqalloc, sizeof(int));
}