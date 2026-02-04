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
    int i, j;
    char **aseq = msa->aseq; // Local alias to potentially reduce repeated struct access

    for (i = 0; i < msa->nseq; i++) {
        char *seq = gcg_aseq[i];
        // First pass: replace leading whitespace and special chars with '~'
        for (j = 0; seq[j] != '\x00' && (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~'); j++) {
            seq[j] = '~';
        }
        // Second pass: from first non-special char, replace any special char with '.'
        for (; seq[j] != '\x00'; j++) {
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~') {
                seq[j] = '.';
            }
        }
        // Third pass: trailing cleanup — remove trailing special chars by overwriting with '~'
        for (j = msa->alen - 1; j > 0 && (gcg_aseq[i][j] == ' ' || gcg_aseq[i][j] == '.' || 
             gcg_aseq[i][j] == '_' || gcg_aseq[i][j] == '-' || gcg_aseq[i][j] == '~'); j--) {
            gcg_aseq[i][j] = '~';
        }
    }
}
