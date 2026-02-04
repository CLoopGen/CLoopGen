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
int j;

void init_vars() {
    const int target_size = 128 * 1024 * 1024; // Aim for ~128MB of data
    msa = (MSA*)calloc(1, sizeof(MSA));
    if (!msa) exit(1);

    // Estimate number of sequences to allocate based on pointer size
    // Each sequence has several pointers; use conservative estimate
    msa->nseqalloc = target_size / (sizeof(char*) * 4); // Approx 32M elements for 128MB
    if (msa->nseqalloc == 0) msa->nseqalloc = 1000;

    msa->ss = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sslen = (int*)calloc(msa->nseqalloc, sizeof(int));
    msa->salen = (int*)calloc(msa->nseqalloc, sizeof(int));
    msa->sqlen = (int*)calloc(msa->nseqalloc, sizeof(int));

    if (!msa->ss || !msa->sslen || !msa->salen || !msa->sqlen) exit(1);

    // Initialize other fields that might be accessed indirectly
    msa->aseq = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sqname = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->wgt = (float*)calloc(msa->nseqalloc, sizeof(float));
    msa->sqacc = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sqdesc = (char**)calloc(msa->nseqalloc, sizeof(char*));
    msa->sa = (char**)calloc(msa->nseqalloc, sizeof(char*));

    // Set remaining scalar members
    msa->alen = 0;
    msa->nseq = msa->nseqalloc;
    msa->flags = 0;
    msa->type = 0;
    msa->name = NULL;
    msa->desc = NULL;
    msa->acc = NULL;
    msa->au = NULL;
    msa->ss_cons = NULL;
    msa->sa_cons = NULL;
    msa->rf = NULL;

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
    msa->nseqlump = 0;
    msa->lastidx = -1;

    // Ensure all arrays are properly initialized to avoid undefined behavior in loop
    for (int i = 0; i < msa->nseqalloc; i++) {
        msa->ss[i] = NULL;
        msa->sslen[i] = 0;
        msa->salen[i] = 0;
        msa->sqlen[i] = 0;
    }
}