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
    int apos, rpos;
    if (ainfo->sqinfo[seqidx].flags & (1 << 9)) {
        for (apos = rpos = 0; apos < alen; apos += 2) {
            if (!((aseqs[seqidx][apos]) == ' ' || (aseqs[seqidx][apos]) == '.' || (aseqs[seqidx][apos]) == '_' || (aseqs[seqidx][apos]) == '-' || (aseqs[seqidx][apos]) == '~')) {
                ainfo->sqinfo[seqidx].ss[rpos] = ainfo->sqinfo[seqidx].ss[apos];
                rpos++;
            }
            if (apos + 1 < alen && !((aseqs[seqidx][apos + 1]) == ' ' || (aseqs[seqidx][apos + 1]) == '.' || (aseqs[seqidx][apos + 1]) == '_' || (aseqs[seqidx][apos + 1]) == '-' || (aseqs[seqidx][apos + 1]) == '~')) {
                ainfo->sqinfo[seqidx].ss[rpos] = ainfo->sqinfo[seqidx].ss[apos + 1];
                rpos++;
            }
        }
        ainfo->sqinfo[seqidx].ss[rpos] = '\x00';
    }
    if (ainfo->sqinfo[seqidx].flags & (1 << 10)) {
        for (apos = rpos = 0; apos < alen; apos += 2) {
            if (!((aseqs[seqidx][apos]) == ' ' || (aseqs[seqidx][apos]) == '.' || (aseqs[seqidx][apos]) == '_' || (aseqs[seqidx][apos]) == '-' || (aseqs[seqidx][apos]) == '~')) {
                ainfo->sqinfo[seqidx].sa[rpos] = ainfo->sqinfo[seqidx].sa[apos];
                rpos++;
            }
            if (apos + 1 < alen && !((aseqs[seqidx][apos + 1]) == ' ' || (aseqs[seqidx][apos + 1]) == '.' || (aseqs[seqidx][apos + 1]) == '_' || (aseqs[seqidx][apos + 1]) == '-' || (aseqs[seqidx][apos + 1]) == '~')) {
                ainfo->sqinfo[seqidx].sa[rpos] = ainfo->sqinfo[seqidx].sa[apos + 1];
                rpos++;
            }
        }
        ainfo->sqinfo[seqidx].sa[rpos] = '\x00';
    }
}
}
