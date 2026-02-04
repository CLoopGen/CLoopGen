#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

typedef struct {
    FLOAT8 l[22];
    FLOAT8 s[13][3];
} III_psy_xmin;

III_psy_xmin thm[4];
III_psy_xmin en[4];
FLOAT8 mld_l[21];
int sb;
FLOAT8 rside;
FLOAT8 rmid;
FLOAT8 mld;
int chmid;
int chside;

void init_vars() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 22; j++) {
            thm[i].l[j] = (FLOAT8)(i + 1) * (1.0 + j * 0.05);
            en[i].l[j] = (FLOAT8)(i + 1) * (0.8 + j * 0.04);
        }
        for (int j = 0; j < 13; j++) {
            for (int k = 0; k < 3; k++) {
                thm[i].s[j][k] = (FLOAT8)(i * 13 + j * 3 + k) * 0.1;
            }
        }
    }

    for (int i = 0; i < 21; i++) {
        mld_l[i] = 1.2 + i * 0.03;
    }

    chmid = 0;
    chside = 1;
}