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
    // Variant 2: Memory Access Pattern Modification using indirect access via index array
    int *indices = (int*)__builtin_alloca(msa->alen * sizeof(int));
    for (idx = 0; idx < msa->nseq; idx++) {
        char *seq = gcg_aseq[idx];

        // Precompute valid indices (indirect addressing pattern)
        int len = 0;
        while (seq[len] != '\x00') {
            indices[len] = len;
            len++;
        }

        // First pass: indirect access for leading cleanup
        for (int i = 0; i < len; i++) {
            int j = indices[i];
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~')
                seq[j] = '~';
            else
                break;
        }

        // Second pass: indirect full scan to replace internal special chars
        for (int i = 0; i < len; i++) {
            int j = indices[i];
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~')
                seq[j] = '.';
        }

        // Third pass: reverse indirect traversal for trailing cleanup
        for (int i = len - 1; i >= 0; i--) {
            int j = indices[i];
            if (j >= msa->alen) continue;
            if (gcg_aseq[idx][j] == ' ' || gcg_aseq[idx][j] == '.' || 
                gcg_aseq[idx][j] == '_' || gcg_aseq[idx][j] == '-' || gcg_aseq[idx][j] == '~')
                gcg_aseq[idx][j] = '~';
            else
                break;
        }
    }
}
