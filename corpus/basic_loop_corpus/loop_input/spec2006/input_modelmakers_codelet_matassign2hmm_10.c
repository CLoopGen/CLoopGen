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
int *matassign;
int apos;

void init_vars() {
    // Allocate and initialize matassign with size large enough to support ~100MB of data access
    // Each int is 4 bytes, so 25M elements gives 100MB
    const int arr_size = 25000000;
    matassign = (int*)calloc(arr_size, sizeof(int));
    
    // Initialize msa structure
    msa = (MSA*)malloc(sizeof(MSA));
    memset(msa, 0, sizeof(MSA));

    // Set alen to near the end of valid range to allow loop to run many iterations
    msa->alen = arr_size - 1;

    // Fill part of matassign with values that satisfy the loop condition initially
    // We want: matassign[apos] & (1 << 3) to be true for many positions
    // That means bit 3 (value 8) must be set
    for (int i = msa->alen - 1000000; i <= msa->alen; i++) {
        matassign[i] = (1 << 3); // Only bit 3 set initially
    }

    // Ensure the first element checked doesn't terminate loop immediately due to apos > 0
    // The loop stops when either apos == 0 or the condition fails
    // This setup ensures it stops due to condition rather than bounds

    // Initialize other fields to plausible values
    msa->nseq = 0;
    msa->flags = 0;
    msa->type = 0;
    msa->lastidx = -1;
}