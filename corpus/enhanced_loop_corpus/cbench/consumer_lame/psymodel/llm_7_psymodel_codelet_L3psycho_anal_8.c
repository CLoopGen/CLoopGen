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
FLOAT8 temp_rmid[21], temp_rside[21];
for (sb = 0; sb < 21; sb++) {
    temp_rmid[sb] = thm[chmid].l[sb];
    temp_rside[sb] = thm[chside].l[sb];
}
for (sb = 0; sb < 21; sb++) {
    if (thm[0].l[sb] <= 1.5800000000000001 * thm[1].l[sb] && thm[1].l[sb] <= 1.5800000000000001 * thm[0].l[sb]) {
        mld = mld_l[sb] * en[chside].l[sb];
        rmid = ((temp_rmid[sb]) > (((temp_rside[sb]) < (mld) ? (temp_rside[sb]) : (mld))) ? (temp_rmid[sb]) : (((temp_rside[sb]) < (mld) ? (temp_rside[sb]) : (mld))));
        mld = mld_l[sb] * en[chmid].l[sb];
        rside = ((temp_rside[sb]) > (((temp_rmid[sb]) < (mld) ? (temp_rmid[sb]) : (mld))) ? (temp_rside[sb]) : (((temp_rmid[sb]) < (mld) ? (temp_rmid[sb]) : (mld))));
        thm[chmid].l[sb] = rmid;
        thm[chside].l[sb] = rside;
    }
}
}
