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
extern int idx;
extern int i;
extern float *sc;
extern int first;
extern int last;
extern float bm1;
extern float bm2;
extern float new;
extern float bestsc;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access pattern by processing columns in chunks and reordering inner loop
    // Simulate strided access over alignment matrix by stepping through sequences with a fixed stride pattern
    const int chunk_size = 4;
    const int nseq = msa->nseq;
    const int remainder = nseq % chunk_size;
    float local_best = bestsc;
    int local_first = first;

    for (i = 1; i <= last; i++) {
        new = sc[i];

        // Process sequences in groups of 4 to induce strided-like memory behavior across aseq
        idx = 0;
        for (; idx < nseq - remainder; idx += chunk_size) {
            float contrib0 = bm1, contrib1 = bm1, contrib2 = bm1, contrib3 = bm1;
            char val0 = msa->aseq[idx][i-1];
            char val1 = msa->aseq[idx+1][i-1];
            char val2 = msa->aseq[idx+2][i-1];
            char val3 = msa->aseq[idx+3][i-1];

            if (val0 == ' ' || val0 == '.' || val0 == '_' || val0 == '-' || val0 == '~') contrib0 = bm2;
            if (val1 == ' ' || val1 == '.' || val1 == '_' || val1 == '-' || val1 == '~') contrib1 = bm2;
            if (val2 == ' ' || val2 == '.' || val2 == '_' || val2 == '-' || val2 == '~') contrib2 = bm2;
            if (val3 == ' ' || val3 == '.' || val3 == '_' || val3 == '-' || val3 == '~') contrib3 = bm2;

            new += contrib0 + contrib1 + contrib2 + contrib3;
        }

        // Handle remaining elements
        for (; idx < nseq; idx++) {
            char residue = msa->aseq[idx][i-1];
            new += (residue == ' ' || residue == '.' || residue == '_' || residue == '-' || residue == '~') ? bm2 : bm1;
        }

        if (new > local_best) {
            local_best = new;
            local_first = i;
        }
    }

    bestsc = local_best;
    first = local_first;
}
