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
for (sb = 0; sb < 21; sb += 3) {
    for (int offset = 0; offset < 3 && (sb + offset) < 21; ++offset) {
        int idx = sb + offset;
        if (thm[0].l[idx] <= 1.5800000000000001 * thm[1].l[idx] && thm[1].l[idx] <= 1.5800000000000001 * thm[0].l[idx]) {
            mld = mld_l[idx] * en[chside].l[idx];
            rmid = ((thm[chmid].l[idx]) > (((thm[chside].l[idx]) < (mld) ? (thm[chside].l[idx]) : (mld))) ? (thm[chmid].l[idx]) : (((thm[chside].l[idx]) < (mld) ? (thm[chside].l[idx]) : (mld))));
            mld = mld_l[idx] * en[chmid].l[idx];
            rside = ((thm[chside].l[idx]) > (((thm[chmid].l[idx]) < (mld) ? (thm[chmid].l[idx]) : (mld))) ? (thm[chside].l[idx]) : (((thm[chmid].l[idx]) < (mld) ? (thm[chmid].l[idx]) : (mld))));
            thm[chmid].l[idx] = rmid;
            thm[chside].l[idx] = rside;
        }
    }
}
}
