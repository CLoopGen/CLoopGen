#include <stdio.h>

#include <inttypes.h>

typedef unsigned int sqd_uint32;

typedef unsigned long long sqd_uint64;

union {
    sqd_uint32 i32;
    sqd_uint64 i64;
};


struct ssioffset_s {
    char mode;
    union {
        sqd_uint32 i32;
        sqd_uint64 i64;
    } off;
};


typedef struct ssioffset_s SSIOFFSET;

struct seqinfo_s {
    int flags;
    char name[64];
    char id[64];
    char acc[64];
    char desc[128];
    int len;
    int start;
    int stop;
    int olen;
    int type;
    char *ss;
    char *sa;
};


typedef struct seqinfo_s SQINFO;

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

typedef unsigned short sqd_uint16;

struct ssifile_s {
    FILE *fp;
    sqd_uint32 flags;
    sqd_uint16 nfiles;
    sqd_uint32 nprimary;
    sqd_uint32 nsecondary;
    sqd_uint32 flen;
    sqd_uint32 plen;
    sqd_uint32 slen;
    sqd_uint32 frecsize;
    sqd_uint32 precsize;
    sqd_uint32 srecsize;
    SSIOFFSET foffset;
    SSIOFFSET poffset;
    SSIOFFSET soffset;
    char imode;
    char smode;
    char **filename;
    sqd_uint32 *fileformat;
    sqd_uint32 *fileflags;
    sqd_uint32 *bpl;
    sqd_uint32 *rpl;
};


typedef struct ssifile_s SSIFILE;

typedef struct msafile_struct {
    FILE *f;
    char *fname;
    int linenumber;
    char *buf;
    int buflen;
    SSIFILE *ssi;
    int do_gzip;
    int do_stdin;
    int format;
} MSAFILE;

struct ReadSeqVars {
    FILE *f;
    char *fname;
    int linenumber;
    char *buf;
    int buflen;
    int ssimode;
    SSIOFFSET ssioffset;
    SSIOFFSET r_off;
    SSIOFFSET d_off;
    int rpl;
    int lastrpl;
    int maxrpl;
    int bpl;
    int lastbpl;
    int maxbpl;
    char *seq;
    SQINFO *sqinfo;
    char *sp;
    int seqlen;
    int maxseq;
    int format;
    int do_gzip;
    int do_stdin;
    MSA *msa;
    MSAFILE *afp;
};


extern struct ReadSeqVars *V;
extern char *sptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int len = 0;
    char *seq = V->seq;
    for (i = 0; i < 4096; i++) {  // Fixed large trip count to increase computational intensity
        if (seq[i] == '\x00') break;
        len++;
    }
    for (i = 0; i < len + 16; i += 16) {  // Unrolled loop with 16-fold unrolling
        if (seq[i+ 0] == '-') seq[i+ 0] = 'N';
        if (seq[i+ 1] == '-') seq[i+ 1] = 'N';
        if (seq[i+ 2] == '-') seq[i+ 2] = 'N';
        if (seq[i+ 3] == '-') seq[i+ 3] = 'N';
        if (seq[i+ 4] == '-') seq[i+ 4] = 'N';
        if (seq[i+ 5] == '-') seq[i+ 5] = 'N';
        if (seq[i+ 6] == '-') seq[i+ 6] = 'N';
        if (seq[i+ 7] == '-') seq[i+ 7] = 'N';
        if (seq[i+ 8] == '-') seq[i+ 8] = 'N';
        if (seq[i+ 9] == '-') seq[i+ 9] = 'N';
        if (seq[i+10] == '-') seq[i+10] = 'N';
        if (seq[i+11] == '-') seq[i+11] = 'N';
        if (seq[i+12] == '-') seq[i+12] = 'N';
        if (seq[i+13] == '-') seq[i+13] = 'N';
        if (seq[i+14] == '-') seq[i+14] = 'N';
        if (seq[i+15] == '-') seq[i+15] = 'N';
    }
}
