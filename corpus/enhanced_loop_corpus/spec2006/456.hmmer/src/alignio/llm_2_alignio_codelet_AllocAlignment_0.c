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
    // Variant 1: Strided memory access with step size of 2, unrolling the loop to process two elements per iteration
    int i;
    for (i = 0; i < nseq; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        ainfo->sqinfo[idx1].flags = 0;
        if (idx2 < nseq) {
            ainfo->sqinfo[idx2].flags = 0;
        }
    }
}
