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
    // Variant 1: Consecutive memory access pattern using pointer arithmetic for msa->aseq
    float *sc_ptr = sc + 1;
    int seq_count = msa->nseq;
    char **aseq = msa->aseq;
    float new_score, best_score = bestsc;
    int first_idx = first;

    for (i = 1; i <= last; i++) {
        new_score = *sc_ptr++;
        const float *bm_ptr = &bm1;  // Hint-friendly access

        for (idx = 0; idx < seq_count; idx++) {
            char residue = *(aseq[idx] + i - 1);  // Base address + offset (consecutive in outer loop)
            new_score += (residue == ' ' || residue == '.' || residue == '_' || residue == '-' || residue == '~') ? bm2 : *bm_ptr;
        }

        if (new_score > best_score) {
            best_score = new_score;
            first_idx = i;
        }
    }

    bestsc = best_score;
    first = first_idx;
}
