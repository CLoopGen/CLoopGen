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
int apos;
int mpos;
int idx;
int i;

void init_vars() {
    const int alen = 1 << 20; // ~1M columns, adjust for ~0.01s runtime
    const int nseq = 256;
    const int ngr = 4;
    const int ngc = 3;

    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->alen = alen;
    msa->nseq = nseq;
    msa->ngr = ngr;
    msa->ngc = ngc;

    msa->nseqalloc = nseq;
    msa->aseq = (char**)calloc(nseq, sizeof(char*));
    msa->ss = (char**)calloc(nseq, sizeof(char*));
    msa->sa = (char**)calloc(nseq, sizeof(char*));
    msa->sqlen = (int*)calloc(nseq, sizeof(int));
    msa->sslen = (int*)calloc(nseq, sizeof(int));
    msa->salen = (int*)calloc(nseq, sizeof(int));

    for (int i = 0; i < nseq; i++) {
        msa->aseq[i] = (char*)calloc(alen, sizeof(char));
        msa->ss[i] = (char*)calloc(alen, sizeof(char));
        msa->sa[i] = (char*)calloc(alen, sizeof(char));
        msa->sqlen[i] = alen;
        msa->sslen[i] = alen;
        msa->salen[i] = alen;
        for (int j = 0; j < alen; j++) {
            msa->aseq[i][j] = "ACGT"[j % 4];
            msa->ss[i][j] = "()."[j % 3];
            msa->sa[i][j] = "acgt"[j % 4];
        }
    }

    msa->ss_cons = (char*)calloc(alen, sizeof(char));
    msa->sa_cons = (char*)calloc(alen, sizeof(char));
    msa->rf = (char*)calloc(alen, sizeof(char));
    for (int j = 0; j < alen; j++) {
        msa->ss_cons[j] = "()."[j % 3];
        msa->sa_cons[j] = "ACGT"[j % 4];
        msa->rf[j] = "X.-"[j % 3];
    }

    msa->gc = (char**)calloc(ngc, sizeof(char*));
    for (int i = 0; i < ngc; i++) {
        msa->gc[i] = (char*)calloc(alen, sizeof(char));
        for (int j = 0; j < alen; j++) {
            msa->gc[i][j] = "xyz"[i % 3];
        }
    }

    msa->gr = (char***)calloc(ngr, sizeof(char**));
    for (int i = 0; i < ngr; i++) {
        msa->gr[i] = (char**)calloc(nseq, sizeof(char*));
        for (int j = 0; j < nseq; j++) {
            msa->gr[i][j] = (char*)calloc(alen, sizeof(char));
            for (int k = 0; k < alen; k++) {
                msa->gr[i][j][k] = "123"[i % 3];
            }
        }
    }

    useme = (int*)calloc(alen, sizeof(int));
    for (int i = 0; i < alen; i++) {
        useme[i] = (i % 2); // roughly half positions used
    }

    apos = 0;
    mpos = 0;
    idx = 0;
    i = 0;
}