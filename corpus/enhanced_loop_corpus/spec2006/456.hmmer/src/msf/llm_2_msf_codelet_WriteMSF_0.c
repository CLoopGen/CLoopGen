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
    // Variant 1: Memory Access Pattern Modification using strided access with step size of 2 (forward and backward)
    for (idx = 0; idx < msa->nseq; idx++) {
        char *seq = gcg_aseq[idx];
        int len = 0;
        while (seq[len] != '\x00') len++;

        // First pass: forward strided write (step 2) for leading special chars
        for (s = seq; *s != '\x00' && ((*s) == ' ' || (*s) == '.' || (*s) == '_' || (*s) == '-' || (*s) == '~'); s += 2) {
            if (*(s+1) != '\x00' && (*(s+1) == ' ' || *(s+1) == '.' || *(s+1) == '_' || *(s+1) == '-' || *(s+1) == '~'))
                *(s+1) = '~';
            *s = '~';
        }

        // Second pass: full sequential scan to replace internal special chars with '.'
        for (s = seq; *s != '\x00'; s++) {
            if ((*s) == ' ' || (*s) == '.' || (*s) == '_' || (*s) == '-' || (*s) == '~')
                *s = '.';
        }

        // Third pass: backward strided clean-up from end (step 2)
        for (pos = msa->alen - 1; pos > 1; pos -= 2) {
            char *p1 = &gcg_aseq[idx][pos];
            char *p2 = &gcg_aseq[idx][pos-1];
            if (*p1 != '\x00' && (*p1) == ' ' || (*p1) == '.' || (*p1) == '_' || (*p1) == '-' || (*p1) == '~')
                *p1 = '~';
            if (*p2 != '\x00' && (*p2) == ' ' || (*p2) == '.' || (*p2) == '_' || (*p2) == '-' || (*p2) == '~')
                *p2 = '~';
        }
    }
}
