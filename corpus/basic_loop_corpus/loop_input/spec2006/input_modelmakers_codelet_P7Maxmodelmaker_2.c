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
float maxgap;
int idx;
int last;
int ngap;

void init_vars() {
    maxgap = 0.8f;
    
    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->alen = 10000;
    msa->nseq = 100;
    msa->nseqalloc = msa->nseq;
    
    msa->aseq = (char**)calloc(msa->nseq, sizeof(char*));
    for (int i = 0; i < msa->nseq; i++) {
        msa->aseq[i] = (char*)calloc(msa->alen, sizeof(char));
        for (int j = 0; j < msa->alen; j++) {
            char c = 'A' + (i + j) % 20;
            if ((i + j) % 15 == 0) c = '-';
            else if ((i + j) % 23 == 0) c = '.';
            else if ((i + j) % 31 == 0) c = '_';
            else if ((i + j) % 41 == 0) c = '~';
            else if ((i + j) % 53 == 0) c = ' ';
            msa->aseq[i][j] = c;
        }
    }
    
    msa->sqname = (char**)calloc(msa->nseq, sizeof(char*));
    for (int i = 0; i < msa->nseq; i++) {
        msa->sqname[i] = (char*)calloc(32, sizeof(char));
        snprintf(msa->sqname[i], 32, "seq_%d", i);
    }
    
    msa->wgt = (float*)calloc(msa->nseq, sizeof(float));
    for (int i = 0; i < msa->nseq; i++) {
        msa->wgt[i] = 1.0f / msa->nseq;
    }
    
    msa->sqlen = (int*)calloc(msa->nseq, sizeof(int));
    msa->sslen = (int*)calloc(msa->nseq, sizeof(int));
    msa->salen = (int*)calloc(msa->nseq, sizeof(int));
    for (int i = 0; i < msa->nseq; i++) {
        msa->sqlen[i] = msa->alen;
        msa->sslen[i] = msa->alen;
        msa->salen[i] = msa->alen;
    }
    
    msa->cutoff[0] = 0.5f;
    msa->cutoff_is_set[0] = 1;
    for (int i = 1; i < 6; i++) {
        msa->cutoff[i] = 0.0f;
        msa->cutoff_is_set[i] = 0;
    }
    
    msa->ncomment = 0;
    msa->alloc_ncomment = 10;
    msa->comment = (char**)calloc(msa->alloc_ncomment, sizeof(char*));
    
    msa->ngf = 0;
    msa->alloc_ngf = 10;
    msa->gf_tag = (char**)calloc(msa->alloc_ngf, sizeof(char*));
    msa->gf = (char**)calloc(msa->alloc_ngf, sizeof(char*));
    
    msa->ngs = 0;
    msa->gs_tag = (char**)calloc(10, sizeof(char*));
    msa->gs = (char***)calloc(10, sizeof(char**));
    msa->gs_idx = NULL;
    
    msa->ngc = 0;
    msa->gc_tag = (char**)calloc(10, sizeof(char*));
    msa->gc = (char**)calloc(10, sizeof(char*));
    msa->gc_idx = NULL;
    
    msa->ngr = 0;
    msa->gr_tag = (char**)calloc(10, sizeof(char*));
    msa->gr = (char***)calloc(10, sizeof(char**));
    msa->gr_idx = NULL;
    
    msa->index = NULL;
    msa->lastidx = -1;
    
    msa->name = strdup("test_msa");
    msa->desc = strdup("benchmark alignment");
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;
    
    msa->sqacc = (char**)calloc(msa->nseq, sizeof(char*));
    msa->sqdesc = (char**)calloc(msa->nseq, sizeof(char*));
    msa->ss = (char**)calloc(msa->nseq, sizeof(char*));
    msa->sa = (char**)calloc(msa->nseq, sizeof(char*));
    for (int i = 0; i < msa->nseq; i++) {
        msa->sqacc[i] = NULL;
        msa->sqdesc[i] = NULL;
        msa->ss[i] = NULL;
        msa->sa[i] = NULL;
    }
}