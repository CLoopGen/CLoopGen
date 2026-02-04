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
extern int num;
extern int seqidx;
extern int alen;
extern AINFO *ainfo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (seqidx = 0; seqidx < num; seqidx++) {
    int apos, rpos_ss = 0, rpos_sa = 0;
    struct seqinfo_s *sqinfo = &ainfo->sqinfo[seqidx];

    // Eliminate loop-carried dependencies by separating the two operations
    // and using distinct indices — removes artificial WAW on `rpos`
    if (sqinfo->flags & (1 << 9)) {
        for (apos = 0; apos < alen; apos++) {
            char c = aseqs[seqidx][apos];
            if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')) {
                sqinfo->ss[rpos_ss++] = sqinfo->ss[apos];  // RAW: uses current ss value, but no WAR/WAW via split index
            }
        }
        sqinfo->ss[rpos_ss] = '\x00';
    }

    if (sqinfo->flags & (1 << 10)) {
        for (apos = 0; apos < alen; apos++) {
            char c = aseqs[seqidx][apos];
            if (!(c == ' ' || c == '.' || c == '_' || c == '-' || c == '~')) {
                sqinfo->sa[rpos_sa++] = sqinfo->sa[apos];  // Independent index avoids interference
            }
        }
        sqinfo->sa[rpos_sa] = '\x00';
    }
}
}
