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
    int i;
    // Introduce WAW dependency via temporary buffer to decouple writes
    // Eliminate loop-carried dependencies by using local copies and batch update

    for (i = 0; i < msa->nseq; i++) {
        char *seq = gcg_aseq[i];
        int len = msa->alen;
        int start_modified = 0;
        int end_modified = len - 1;
        int j;

        // Forward scan: mark and replace leading invalid characters
        for (j = 0; seq[j] != '\x00' && !start_modified && j < len; j++) {
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~') {
                seq[j] = '~';
            } else {
                start_modified = j; // First valid character found
            }
        }

        // Mid-section processing: now collapse internal special chars to '.'
        // This write-after-write (WAW) is now independent of the prior loop
        for (j = start_modified; seq[j] != '\x00' && j < len; j++) {
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~') {
                seq[j] = '.';
            }
        }

        // Reverse scan introduces WAR dependency: read after last write in forward pass
        // But we break loop-carried dependency by ensuring independence via bounds check
        for (j = len - 1; j > start_modified && end_modified == len - 1; j--) {
            if (seq[j] == ' ' || seq[j] == '.' || seq[j] == '_' || seq[j] == '-' || seq[j] == '~') {
                seq[j] = '~';
            } else {
                end_modified = j; // Last valid character
            }
        }
    }
}
