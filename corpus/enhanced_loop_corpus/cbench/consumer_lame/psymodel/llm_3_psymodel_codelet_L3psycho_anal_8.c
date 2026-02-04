#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

typedef struct {
    FLOAT8 l[22];
    FLOAT8 s[13][3];
} III_psy_xmin;

extern III_psy_xmin thm[4];
extern III_psy_xmin en[4];
extern FLOAT8 mld_l[21];
extern int sb;
extern FLOAT8 rside;
extern FLOAT8 rmid;
extern FLOAT8 mld;
extern int chmid;
extern int chside;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int access_pattern[21];
for (int i = 0; i < 21; ++i) {
    access_pattern[i] = (17 * i + 13) % 21; // Strided indirect access via linear congruential sequence
}
for (int p = 0; p < 21; ++p) {
    int sb = access_pattern[p];
    if (thm[0].l[sb] <= 1.5800000000000001 * thm[1].l[sb] && thm[1].l[sb] <= 1.5800000000000001 * thm[0].l[sb]) {
        mld = mld_l[sb] * en[chside].l[sb];
        rmid = ((thm[chmid].l[sb]) > (((thm[chside].l[sb]) < (mld) ? (thm[chside].l[sb]) : (mld))) ? (thm[chmid].l[sb]) : (((thm[chside].l[sb]) < (mld) ? (thm[chside].l[sb]) : (mld))));
        mld = mld_l[sb] * en[chmid].l[sb];
        rside = ((thm[chside].l[sb]) > (((thm[chmid].l[sb]) < (mld) ? (thm[chmid].l[sb]) : (mld))) ? (thm[chside].l[sb]) : (((thm[chmid].l[sb]) < (mld) ? (thm[chmid].l[sb]) : (mld))));
        thm[chmid].l[sb] = rmid;
        thm[chside].l[sb] = rside;
    }
}
}
