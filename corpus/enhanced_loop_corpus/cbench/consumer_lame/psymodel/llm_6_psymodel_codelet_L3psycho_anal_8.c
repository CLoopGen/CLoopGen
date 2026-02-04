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
for (sb = 0; sb < 21; sb++) {
    FLOAT8 temp_thm0 = thm[0].l[sb];
    FLOAT8 temp_thm1 = thm[1].l[sb];
    if (temp_thm0 <= 1.5800000000000001 * temp_thm1 && temp_thm1 <= 1.5800000000000001 * temp_thm0) {
        FLOAT8 mld_val_side = mld_l[sb] * en[chside].l[sb];
        FLOAT8 mld_val_mid = mld_l[sb] * en[chmid].l[sb];
        FLOAT8 candidate_mid = (thm[chside].l[sb] < mld_val_side) ? thm[chside].l[sb] : mld_val_side;
        FLOAT8 candidate_side = (thm[chmid].l[sb] < mld_val_mid) ? thm[chmid].l[sb] : mld_val_mid;
        FLOAT8 rmid_local = (thm[chmid].l[sb] > candidate_mid) ? thm[chmid].l[sb] : candidate_mid;
        FLOAT8 rside_local = (thm[chside].l[sb] > candidate_side) ? thm[chside].l[sb] : candidate_side;
        thm[chmid].l[sb] = rmid_local;
        thm[chside].l[sb] = rside_local;
    }
}
}
