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
extern char **gcg_aseq;
extern int idx;
extern char *s;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by merging character classification into a helper macro,
    // decreasing loop trip count through early termination and eliminating redundant pointer dereferences.
    #define IS_SPECIAL(c) ((c) == ' ' || (c) == '.' || (c) == '_' || (c) == '-' || (c) == '~')

    int i;
    char *seq;
    int len;

    for (i = 0; i < msa->nseq; i++) {
        seq = gcg_aseq[i];
        len = msa->alen;

        // Process forward: convert leading special chars to '~'
        int pos = 0;
        while (pos < len && seq[pos] != '\x00' && IS_SPECIAL(seq[pos])) {
            seq[pos++] = '~';
        }

        // Process middle: convert remaining special chars (non-leading) to '.'
        while (pos < len && seq[pos] != '\x00') {
            if (IS_SPECIAL(seq[pos])) {
                seq[pos] = '.';
            }
            pos++;
        }

        // Process backward: clean up trailing special chars to '~'
        int last_valid = len - 1;
        while (last_valid >= 0 && IS_SPECIAL(gcg_aseq[i][last_valid])) {
            gcg_aseq[i][last_valid] = '~';
            last_valid--;
        }
    }

    #undef IS_SPECIAL
}
