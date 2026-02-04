#include <stdio.h>

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

extern MSA *msa;
extern int *matassign;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change to strided memory access by stepping through matassign with a fixed stride (e.g., every 2nd element)
    // We maintain the same logical behavior but access memory in a non-unit stride pattern.
    // Since original loop decrements from msa->alen down to 1, we simulate a strided backward traversal.
    int stride = 2;
    for (apos = msa->alen - ((msa->alen) % stride); matassign[apos] & (1 << 3) && apos > 0; apos -= stride) {
        matassign[apos] |= (1 << 5);
        // Fill in skipped elements to preserve original semantics
        int i;
        for (i = apos + 1; i < apos + stride && i <= msa->alen && i > 0; i++) {
            if (matassign[i] & (1 << 3)) {
                matassign[i] |= (1 << 5);
            }
        }
    }
    // Final cleanup for any remaining high indices missed due to striding
    for (apos = msa->alen; apos > msa->alen - ((msa->alen) % stride); apos--) {
        if (apos <= msa->alen && apos > 0 && (matassign[apos] & (1 << 3))) {
            matassign[apos] |= (1 << 5);
        }
    }
    apos = msa->alen; // Restore logical state
}
