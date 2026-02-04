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
for (sb = 0; sb < 12; sb++) {
    for (int offset = 0; offset < 3; offset++) {
        sblock = offset;
        FLOAT8 temp_thm0 = thm[0].s[sb][sblock];
        FLOAT8 temp_thm1 = thm[1].s[sb][sblock];
        if (temp_thm0 <= 1.7 * temp_thm1 && temp_thm1 <= 1.7 * temp_thm0) {
            FLOAT8 mld_side = mld_s[sb] * en[chside].s[sb][sblock];
            FLOAT8 mld_mid = mld_s[sb] * en[chmid].s[sb][sblock];
            FLOAT8 comp_mid = (thm[chside].s[sb][sblock] < mld_side) ? thm[chside].s[sb][sblock] : mld_side;
            FLOAT8 comp_side = (thm[chmid].s[sb][sblock] < mld_mid) ? thm[chmid].s[sb][sblock] : mld_mid;
            rmid = (thm[chmid].s[sb][sblock] > comp_mid) ? thm[chmid].s[sb][sblock] : comp_mid;
            rside = (thm[chside].s[sb][sblock] > comp_side) ? thm[chside].s[sb][sblock] : comp_side;
            thm[chmid].s[sb][sblock] = rmid;
            thm[chside].s[sb][sblock] = rside;
        }
        sblock = (offset + 1) % 3;
        temp_thm0 = thm[0].s[sb][sblock];
        temp_thm1 = thm[1].s[sb][sblock];
        if (temp_thm0 <= 1.7 * temp_thm1 && temp_thm1 <= 1.7 * temp_thm0) {
            FLOAT8 mld_side = mld_s[sb] * en[chside].s[sb][sblock];
            FLOAT8 mld_mid = mld_s[sb] * en[chmid].s[sb][sblock];
            FLOAT8 comp_mid = (thm[chside].s[sb][sblock] < mld_side) ? thm[chside].s[sb][sblock] : mld_side;
            FLOAT8 comp_side = (thm[chmid].s[sb][sblock] < mld_mid) ? thm[chmid].s[sb][sblock] : mld_mid;
            rmid = (thm[chmid].s[sb][sblock] > comp_mid) ? thm[chmid].s[sb][sblock] : comp_mid;
            rside = (thm[chside].s[sb][sblock] > comp_side) ? thm[chside].s[sb][sblock] : comp_side;
            thm[chmid].s[sb][sblock] = rmid;
            thm[chside].s[sb][sblock] = rside;
        }
    }
}
}
