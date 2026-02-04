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

extern char **aseqs;
extern AINFO *ainfo;
extern int mpos;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = ainfo->nseq - 1; j >= 0; j--) {
        aseqs[j][mpos] = '\x00';
        ainfo->sqinfo[j].start += ainfo->sqinfo[j].stop > 0 ? 1 : -1;
        ainfo->sqinfo[j].olen++;
    }
}
