#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

typedef struct {
    FLOAT8 l[22];
    FLOAT8 s[13][3];
} III_psy_xmin;

III_psy_xmin thm[4];
III_psy_xmin en[4];
FLOAT8 mld_s[12];
int sb;
int sblock;
FLOAT8 rside;
FLOAT8 rmid;
FLOAT8 mld;
int chmid;
int chside;

void init_vars() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 22; j++) {
            thm[i].l[j] = (FLOAT8)(i * 22 + j + 1) * 0.01;
            if (j < 13) {
                en[i].l[j] = (FLOAT8)(i * 22 + j + 1) * 0.02;
            }
            if (j < 13 && i < 4) {
                for (int k = 0; k < 3; k++) {
                    thm[i].s[j][k] = (FLOAT8)(i * 39 + j * 3 + k + 1) * 0.03;
                    en[i].s[j][k] = (FLOAT8)(i * 39 + j * 3 + k + 1) * 0.04;
                }
            }
        }
        for (int j = 13; j < 22; j++) {
            en[i].l[j] = (FLOAT8)(i * 22 + j + 1) * 0.02;
        }
    }

    for (int i = 0; i < 12; i++) {
        mld_s[i] = (FLOAT8)(i + 1) * 0.05;
    }

    sb = 0;
    sblock = 0;
    rside = 1.0;
    rmid = 1.0;
    mld = 1.0;
    chmid = 0;
    chside = 1;
}