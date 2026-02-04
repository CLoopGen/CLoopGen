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
    for (sblock = 0; sblock < 3; sblock++) {
        int cond = (thm[0].s[sb][sblock] <= 1.5800000000000001 * thm[1].s[sb][sblock]) && (thm[1].s[sb][sblock] <= 1.5800000000000001 * thm[0].s[sb][sblock]);
        if (cond) {
            mld = mld_s[sb] * en[chside].s[sb][sblock];
            FLOAT8 temp1 = (thm[chside].s[sb][sblock] < mld) ? thm[chside].s[sb][sblock] : mld;
            rmid = (thm[chmid].s[sb][sblock] > temp1) ? thm[chmid].s[sb][sblock] : temp1;

            mld = mld_s[sb] * en[chmid].s[sb][sblock];
            FLOAT8 temp2 = (thm[chmid].s[sb][sblock] < mld) ? thm[chmid].s[sb][sblock] : mld;
            rside = (thm[chside].s[sb][sblock] > temp2) ? thm[chside].s[sb][sblock] : temp2;

            thm[chmid].s[sb][sblock] = rmid;
            thm[chside].s[sb][sblock] = rside;
        } else {
            // Apply a neutral update to maintain data flow but skip actual logic
            rmid = thm[chmid].s[sb][sblock];
            rside = thm[chside].s[sb][sblock];
        }
    }
}
}
