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
extern int apos;
extern int mpos;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (apos = 0, mpos = 0; aseqs[0][apos] != '\x00'; apos++) {
        int all_gaps = 1;
        for (idx = 0; idx < ainfo->nseq; idx++) {
            char c = aseqs[idx][apos];
            if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')) {
                all_gaps = 0;
                break;
            }
        }
        if (all_gaps) continue;
        if (mpos != apos) {
            for (idx = 0; idx < ainfo->nseq; idx++) {
                aseqs[idx][mpos] = aseqs[idx][apos];
            }
            if (ainfo->cs != ((void *)0)) {
                ainfo->cs[mpos] = ainfo->cs[apos];
            }
            if (ainfo->rf != ((void *)0)) {
                ainfo->rf[mpos] = ainfo->rf[apos];
            }
        }
        mpos++;
    }
}
