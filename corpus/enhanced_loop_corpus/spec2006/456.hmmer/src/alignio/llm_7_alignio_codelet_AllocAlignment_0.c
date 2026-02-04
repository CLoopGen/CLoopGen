#include <stdio.h>

#include <inttypes.h>

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


struct aliinfo_s {
    int flags;
    int alen;
    int nseq;
    float *wgt;
    char *cs;
    char *rf;
    struct seqinfo_s *sqinfo;
    char *name;
    char *desc;
    char *acc;
    char *au;
    float tc1;
    float tc2;
    float nc1;
    float nc2;
    float ga1;
    float ga2;
};


typedef struct aliinfo_s AINFO;

extern int nseq;
extern AINFO *ainfo;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    // Eliminate loop-carried dependencies entirely; make all iterations independent
    // Unroll and vectorization-friendly version with no data flow between iterations
    #pragma GCC unroll 4
    for (i = 0; i < nseq; i++) {
        struct seqinfo_s *si = &ainfo->sqinfo[i];
        si->flags = 0;
        si->start = si->len > 0 ? si->start : 0; // Use current values only, no inter-iteration refs
        si->olen = si->len; // Independent assignment
        si->type = (si->len > 100) ? 1 : 0;     // Local decision based only on per-element data
    }
}
