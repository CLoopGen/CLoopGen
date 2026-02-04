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
    // Allocate MSA structure
    msa = (MSA *)calloc(1, sizeof(MSA));
    if (!msa) exit(1);

    // Set nseqalloc to a value that makes the loop take ~0.01 seconds.
    // Assuming simple pointer assignment takes about 1-2 ns per iteration on modern CPU,
    // we need about 5e6 to 1e7 iterations for 0.01 sec. But to be safe and portable,
    // let's use ~8M which is within 1MB-256MB data range when considering pointers.
    msa->nseqalloc = 8000000;  // ~8 million elements

    // Ensure ngs is within bounds and gs is allocated
    msa->ngs = 0;  // We'll use index 0 in gs[msa->ngs][i]

    // Allocate gs array: msa->gs[msa->ngs] must be valid
    msa->gs = (char ***)calloc(msa->ngs + 1, sizeof(char **));
    if (!msa->gs) exit(1);

    // Allocate second dimension: gs[ngs] points to array of char*
    msa->gs[msa->ngs] = (char **)calloc(msa->nseqalloc, sizeof(char *));
    if (!msa->gs[msa->ngs]) exit(1);

    // Initialize other required fields to avoid undefined behavior
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
    for (int j = 0; j < 6; j++) {
        msa->cutoff[j] = 0.0f;
        msa->cutoff_is_set[j] = 0;
    }
    msa->comment = NULL;
    msa->ncomment = 0;
    msa->alloc_ncomment = 0;
    msa->gf_tag = NULL;
    msa->gf = NULL;
    msa->ngf = 0;
    msa->alloc_ngf = 0;
    msa->gs_tag = NULL;
    msa->gs_idx = NULL;
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
    msa->sqlen = NULL;
    msa->sslen = NULL;
    msa->salen = NULL;
    msa->lastidx = -1;
}