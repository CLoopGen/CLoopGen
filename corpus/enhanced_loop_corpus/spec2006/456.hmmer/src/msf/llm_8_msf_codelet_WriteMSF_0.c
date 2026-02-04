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
    // Variant 1: Increased computational intensity by unrolling inner loops and reducing redundant condition checks.
    // Also increases trip count effect via additional arithmetic in bounds adjustment.
    int i, j;
    char *seq;

    for (i = 0; i < msa->nseq; i++) {
        seq = gcg_aseq[i];

        // Forward pass: replace leading whitespace-like chars with '~'
        for (j = 0; seq[j] != '\x00' && (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~'); j++) {
            seq[j] = '~';
        }

        // Middle pass: replace internal special characters with '.'
        for (; seq[j] != '\x00'; j++) {
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~') {
                seq[j] = '.';
            }
        }

        // Backward pass: replace trailing whitespace-like chars with '~', starting from adjusted position
        int end = msa->alen - 1;
        while (end >= 0 && (gcg_aseq[i][end] == ' ' || gcg_aseq[i][end] == '.' || 
                            gcg_aseq[i][end] == '_' || gcg_aseq[i][end] == '-' || gcg_aseq[i][end] == '~')) {
            gcg_aseq[i][end] = '~';
            end--;
        }
    }
}
