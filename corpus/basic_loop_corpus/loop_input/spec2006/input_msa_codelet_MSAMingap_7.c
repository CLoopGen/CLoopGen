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
int idx;

void init_vars() {
    const int target_data_size = 16 * 1024 * 1024; // ~16MB for ~0.01s runtime estimate
    const int approx_avg_seq_len = 256;
    msa = (MSA*)calloc(1, sizeof(MSA));
    msa->nseq = target_data_size / approx_avg_seq_len;
    if (msa->nseq == 0) msa->nseq = 1;
    msa->alen = target_data_size / msa->nseq;
    if (msa->alen == 0) msa->alen = 1;

    msa->aseq = (char**)calloc(msa->nseq, sizeof(char*));
    for (int i = 0; i < msa->nseq; i++) {
        msa->aseq[i] = (char*)calloc(msa->alen + 1, sizeof(char));
        for (int j = 0; j < msa->alen; j++) {
            // Fill with mostly gaps and some residues to ensure realistic loop behavior
            if ((i * msa->alen + j) % 7 == 0)
                msa->aseq[i][j] = 'A';
            else
                msa->aseq[i][j] = '-';
        }
    }

    msa->sqname = (char**)calloc(msa->nseq, sizeof(char*));
    for (int i = 0; i < msa->nseq; i++) {
        msa->sqname[i] = (char*)calloc(16, sizeof(char));
        sprintf(msa->sqname[i], "seq%d", i);
    }

    msa->wgt = (float*)calloc(msa->nseq, sizeof(float));
    for (int i = 0; i < msa->nseq; i++)
        msa->wgt[i] = 1.0f;

    msa->flags = 0;
    msa->type = 0;
    msa->name = strdup("test_msa");
    msa->desc = strdup("benchmark alignment");
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;

    msa->sqacc = NULL;
    msa->sqdesc = NULL;
    msa->ss = NULL;
    msa->sa = NULL;

    for (int i = 0; i < 6; i++) {
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
    msa->nseqalloc = msa->nseq;
    msa->nseqlump = 0;

    msa->sqlen = (int*)calloc(msa->nseq, sizeof(int));
    msa->sslen = (int*)calloc(msa->nseq, sizeof(int));
    msa->salen = (int*)calloc(msa->nseq, sizeof(int));
    for (int i = 0; i < msa->nseq; i++) {
        msa->sqlen[i] = msa->alen;
        msa->sslen[i] = msa->alen;
        msa->salen[i] = msa->alen;
    }

    msa->lastidx = -1;

    useme = (int*)calloc(msa->alen, sizeof(int));
}