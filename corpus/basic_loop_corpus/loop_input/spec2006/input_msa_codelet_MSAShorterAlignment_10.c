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
int mpos;
int idx;
int i;

void init_vars() {
    const int nseq = 8192;
    const int alen = 16384;
    const int ngr = 8;
    const int data_size_mb = (nseq * alen * (1 + ngr)) / (1024 * 1024);
    
    if (data_size_mb < 1) {
        msa = NULL;
        return;
    }

    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->nseq = nseq;
    msa->alen = alen;
    msa->ngr = ngr;
    msa->nseqalloc = nseq;

    msa->aseq = (char**)calloc(nseq, sizeof(char*));
    for (int j = 0; j < nseq; j++) {
        msa->aseq[j] = (char*)calloc(alen, sizeof(char));
        memset(msa->aseq[j], 'A', alen - 1);
    }

    msa->ss = (char**)calloc(nseq, sizeof(char*));
    for (int j = 0; j < nseq; j++) {
        msa->ss[j] = (char*)calloc(alen, sizeof(char));
        memset(msa->ss[j], 'H', alen - 1);
    }

    msa->sa = (char**)calloc(nseq, sizeof(char*));
    for (int j = 0; j < nseq; j++) {
        msa->sa[j] = (char*)calloc(alen, sizeof(char));
        memset(msa->sa[j], 'C', alen - 1);
    }

    msa->gr = (char***)calloc(ngr, sizeof(char**));
    for (int k = 0; k < ngr; k++) {
        msa->gr[k] = (char**)calloc(nseq, sizeof(char*));
        for (int j = 0; j < nseq; j++) {
            msa->gr[k][j] = (char*)calloc(alen, sizeof(char));
            memset(msa->gr[k][j], 'X', alen - 1);
        }
    }

    msa->sqlen = (int*)calloc(nseq, sizeof(int));
    msa->sslen = (int*)calloc(nseq, sizeof(int));
    msa->salen = (int*)calloc(nseq, sizeof(int));
    for (int j = 0; j < nseq; j++) {
        msa->sqlen[j] = alen;
        msa->sslen[j] = alen;
        msa->salen[j] = alen;
    }

    mpos = alen - 1;

    for (int c = 0; c < 6; c++) {
        msa->cutoff[c] = 0.5f;
        msa->cutoff_is_set[c] = 1;
    }
}