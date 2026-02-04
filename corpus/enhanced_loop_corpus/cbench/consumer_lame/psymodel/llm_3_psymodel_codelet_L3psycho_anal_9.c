#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

typedef struct {
    FLOAT8 l[22];
    FLOAT8 s[13][3];
} III_psy_xmin;

extern III_psy_xmin thm[4];
extern III_psy_xmin en[4];
extern FLOAT8 mld_s[12];
extern int sb;
extern int sblock;
extern FLOAT8 rside;
extern FLOAT8 rmid;
extern FLOAT8 mld;
extern int chmid;
extern int chside;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access to strided pattern: reverse the loop order to create column-major-like access on sblock first
for (sblock = 0; sblock < 3; sblock++) {
    for (sb = 0; sb < 12; sb++) {
        if (thm[0].s[sb][sblock] <= 1.5800000000000001 * thm[1].s[sb][sblock] && thm[1].s[sb][sblock] <= 1.5800000000000001 * thm[0].s[sb][sblock]) {
            mld = mld_s[sb] * en[chside].s[sb][sblock];
            rmid = ((thm[chmid].s[sb][sblock]) > (((thm[chside].s[sb][sblock]) < (mld) ? (thm[chside].s[sb][sblock]) : (mld))) ? (thm[chmid].s[sb][sblock]) : (((thm[chside].s[sb][sblock]) < (mld) ? (thm[chside].s[sb][sblock]) : (mld))));
            mld = mld_s[sb] * en[chmid].s[sb][sblock];
            rside = ((thm[chside].s[sb][sblock]) > (((thm[chmid].s[sb][sblock]) < (mld) ? (thm[chmid].s[sb][sblock]) : (mld))) ? (thm[chside].s[sb][sblock]) : (((thm[chmid].s[sb][sblock]) < (mld) ? (thm[chmid].s[sb][sblock]) : (mld))));
            thm[chmid].s[sb][sblock] = rmid;
            thm[chside].s[sb][sblock] = rside;
        }
    }
}
}
