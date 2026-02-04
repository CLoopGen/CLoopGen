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
    char *seq = V->seq;
    size_t i = 0;
    while (1) {
        char c = *(seq + i);
        if (c == '\x00') break;
        if (c == '-') *(seq + i) = 'N';
        i += 1;
    }
}
