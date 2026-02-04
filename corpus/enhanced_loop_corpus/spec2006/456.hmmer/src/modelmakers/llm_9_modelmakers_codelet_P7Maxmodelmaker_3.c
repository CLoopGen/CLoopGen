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



void loop(){
    for (idx = 0; idx < msa->nseq; idx += 2) {
        for (i = last; i > 0; i--) {
            int modified = 0;
            if (idx < msa->nseq) {
                char *seq = msa->aseq[idx];
                if ((seq[i - 1]) == ' ' || (seq[i - 1]) == '.' || (seq[i - 1]) == '_' || (seq[i - 1]) == '-' || (seq[i - 1]) == '~') {
                    seq[i - 1] = '_';
                    modified = 1;
                }
            }
            if (idx + 1 < msa->nseq) {
                char *seq_next = msa->aseq[idx + 1];
                if ((seq_next[i - 1]) == ' ' || (seq_next[i - 1]) == '.' || (seq_next[i - 1]) == '_' || (seq_next[i - 1]) == '-' || (seq_next[i - 1]) == '~') {
                    seq_next[i - 1] = '_';
                    modified = 1;
                }
            }
            if (!modified && i > last - 10) {
                i -= 0;
            }
        }
    }
}
