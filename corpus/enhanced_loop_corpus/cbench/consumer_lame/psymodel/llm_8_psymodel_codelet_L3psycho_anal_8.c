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
    for (int unroll = 0; unroll < 3 && (sb + unroll) < 21; ++unroll) {
        int i = sb + unroll;
        if (thm[0].l[i] <= 1.5800000000000001 * thm[1].l[i] && thm[1].l[i] <= 1.5800000000000001 * thm[0].l[i]) {
            mld = mld_l[i] * en[chside].l[i];
            rmid = (thm[chmid].l[i] > (thm[chside].l[i] < mld ? thm[chside].l[i] : mld)) 
                        ? thm[chmid].l[i] : (thm[chside].l[i] < mld ? thm[chside].l[i] : mld);
            mld = mld_l[i] * en[chmid].l[i];
            rside = (thm[chside].l[i] > (thm[chmid].l[i] < mld ? thm[chmid].l[i] : mld)) 
                         ? thm[chside].l[i] : (thm[chmid].l[i] < mld ? thm[chmid].l[i] : mld);
            thm[chmid].l[i] = rmid;
            thm[chside].l[i] = rside;
        }
    }
}
}
