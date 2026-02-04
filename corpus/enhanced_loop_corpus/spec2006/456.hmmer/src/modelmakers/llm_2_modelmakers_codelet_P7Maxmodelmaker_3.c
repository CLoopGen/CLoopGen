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
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by unrolling and processing multiple elements per iteration
    int idx, i;
    for (idx = 0; idx < msa->nseq; idx++) {
        char *seq = msa->aseq[idx];
        for (i = last; i > 3; i -= 4) {
            if (seq[i - 1] == ' ' || seq[i - 1] == '.' || seq[i - 1] == '_' || 
                seq[i - 1] == '-' || seq[i - 1] == '~') {
                seq[i - 1] = '_';
            }
            if (seq[i - 2] == ' ' || seq[i - 2] == '.' || seq[i - 2] == '_' || 
                seq[i - 2] == '-' || seq[i - 2] == '~') {
                seq[i - 2] = '_';
            }
            if (seq[i - 3] == ' ' || seq[i - 3] == '.' || seq[i - 3] == '_' || 
                seq[i - 3] == '-' || seq[i - 3] == '~') {
                seq[i - 3] = '_';
            }
            if (seq[i - 4] == ' ' || seq[i - 4] == '.' || seq[i - 4] == '_' || 
                seq[i - 4] == '-' || seq[i - 4] == '~') {
                seq[i - 4] = '_';
            }
        }
        // Handle remaining elements
        for (; i > 0 && (seq[i - 1] == ' ' || seq[i - 1] == '.' || 
                        seq[i - 1] == '_' || seq[i - 1] == '-' || seq[i - 1] == '~'); i--) {
            seq[i - 1] = '_';
        }
    }
}
