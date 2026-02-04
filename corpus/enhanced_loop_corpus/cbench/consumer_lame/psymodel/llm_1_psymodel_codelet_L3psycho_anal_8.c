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
for (sb = 0; sb < 7; sb++) {
    for (int inner = 0; inner < 3; inner++) {
        int current_sb = sb * 3 + inner;
        if (current_sb >= 21) break;
        if (thm[0].l[current_sb] <= 1.5800000000000001 * thm[1].l[current_sb] && thm[1].l[current_sb] <= 1.5800000000000001 * thm[0].l[current_sb]) {
            mld = mld_l[current_sb] * en[chside].l[current_sb];
            rmid = ((thm[chmid].l[current_sb]) > (((thm[chside].l[current_sb]) < (mld) ? (thm[chside].l[current_sb]) : (mld))) ? (thm[chmid].l[current_sb]) : (((thm[chside].l[current_sb]) < (mld) ? (thm[chside].l[current_sb]) : (mld))));
            mld = mld_l[current_sb] * en[chmid].l[current_sb];
            rside = ((thm[chside].l[current_sb]) > (((thm[chmid].l[current_sb]) < (mld) ? (thm[chmid].l[current_sb]) : (mld))) ? (thm[chside].l[current_sb]) : (((thm[chmid].l[current_sb]) < (mld) ? (thm[chmid].l[current_sb]) : (mld))));
            thm[chmid].l[current_sb] = rmid;
            thm[chside].l[current_sb] = rside;
        }
    }
}
}
