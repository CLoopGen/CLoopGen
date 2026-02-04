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
    int i0 = sb;
    int i1 = sb + 7;
    int i2 = sb + 14;

    if (thm[0].l[i0] <= 1.5800000000000001 * thm[1].l[i0] && thm[1].l[i0] <= 1.5800000000000001 * thm[0].l[i0]) {
        mld = mld_l[i0] * en[chside].l[i0];
        rmid = (thm[chmid].l[i0] > (thm[chside].l[i0] < mld ? thm[chside].l[i0] : mld)) 
                    ? thm[chmid].l[i0] : (thm[chside].l[i0] < mld ? thm[chside].l[i0] : mld);
        mld = mld_l[i0] * en[chmid].l[i0];
        rside = (thm[chside].l[i0] > (thm[chmid].l[i0] < mld ? thm[chmid].l[i0] : mld)) 
                     ? thm[chside].l[i0] : (thm[chmid].l[i0] < mld ? thm[chmid].l[i0] : mld);
        thm[chmid].l[i0] = rmid;
        thm[chside].l[i0] = rside;
    }

    if (thm[0].l[i1] <= 1.5800000000000001 * thm[1].l[i1] && thm[1].l[i1] <= 1.5800000000000001 * thm[0].l[i1]) {
        mld = mld_l[i1] * en[chside].l[i1];
        rmid = (thm[chmid].l[i1] > (thm[chside].l[i1] < mld ? thm[chside].l[i1] : mld)) 
                    ? thm[chmid].l[i1] : (thm[chside].l[i1] < mld ? thm[chside].l[i1] : mld);
        mld = mld_l[i1] * en[chmid].l[i1];
        rside = (thm[chside].l[i1] > (thm[chmid].l[i1] < mld ? thm[chmid].l[i1] : mld)) 
                     ? thm[chside].l[i1] : (thm[chmid].l[i1] < mld ? thm[chmid].l[i1] : mld);
        thm[chmid].l[i1] = rmid;
        thm[chside].l[i1] = rside;
    }

    if (thm[0].l[i2] <= 1.5800000000000001 * thm[1].l[i2] && thm[1].l[i2] <= 1.5800000000000001 * thm[0].l[i2]) {
        mld = mld_l[i2] * en[chside].l[i2];
        rmid = (thm[chmid].l[i2] > (thm[chside].l[i2] < mld ? thm[chside].l[i2] : mld)) 
                    ? thm[chmid].l[i2] : (thm[chside].l[i2] < mld ? thm[chside].l[i2] : mld);
        mld = mld_l[i2] * en[chmid].l[i2];
        rside = (thm[chside].l[i2] > (thm[chmid].l[i2] < mld ? thm[chmid].l[i2] : mld)) 
                     ? thm[chside].l[i2] : (thm[chmid].l[i2] < mld ? thm[chmid].l[i2] : mld);
        thm[chmid].l[i2] = rmid;
        thm[chside].l[i2] = rside;
    }
}
}
