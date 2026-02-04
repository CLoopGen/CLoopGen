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
    // Allocate matassign with size to handle at least 10 million elements for ~0.01s runtime
    const int arr_size = 20000000;  // ~80MB for int array
    matassign = (int*)calloc(arr_size, sizeof(int));
    if (!matassign) exit(1);

    // Set up MSA structure
    msa = (MSA*)malloc(sizeof(MSA));
    if (!msa) exit(1);
    memset(msa, 0, sizeof(MSA));

    // Initialize alen within bounds of matassign array and loop condition
    msa->alen = arr_size - 1;  // ensures apos <= msa->alen stays in bounds

    // Ensure the loop runs long enough: set middle portion of matassign to satisfy `(matassign[apos] & (1<<3))`
    // Start from apos=1, so set bits accordingly
    for (int i = 1; i < arr_size - 1000000; i++) {
        matassign[i] |= (1 << 3);  // satisfy loop condition
    }
    // Let last part break the loop condition
}

// Force initialization before main via constructor attribute
__attribute__((constructor))
static void initialize() {
    init_vars();
}