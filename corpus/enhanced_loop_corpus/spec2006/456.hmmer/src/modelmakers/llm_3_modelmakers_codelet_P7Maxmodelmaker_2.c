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
extern float maxgap;
extern int idx;
extern int last;
extern int ngap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to allow non-sequential traversal of sequences
    // Simulate indirect access via a permutation table (e.g., representing reordered sequence indices)
    int *seq_order = (int*)__builtin_alloca(msa->nseq * sizeof(int));
    for (int i = 0; i < msa->nseq; i++) {
        seq_order[i] = i; // Identity permutation, but allows for arbitrary reordering patterns
    }

    for (last = msa->alen; last >= 1; last--) {
        ngap = 0;
        for (int i = 0; i < msa->nseq; i++) {
            int idx = seq_order[i]; // Indirect access through index mapping
            char c = msa->aseq[idx][last - 1];
            if (c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')
                ngap++;
        }
        if ((float)ngap / (float)msa->nseq <= maxgap)
            break;
    }
}
