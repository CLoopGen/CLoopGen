#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;
typedef unsigned int UINTFLOAT;

INTFLOAT (*out)[2];
INTFLOAT (*delay)[2];
INTFLOAT (*ap_delay)[37][2];
INTFLOAT phi_fract[2];
INTFLOAT (*Q_fract)[2];
INTFLOAT *transient_gain;
int len;
INTFLOAT ag[3];
int m;
int n;

static INTFLOAT out_data[200][2];
static INTFLOAT delay_data[200][2];
static INTFLOAT ap_delay_data[37][39][2];
static INTFLOAT Q_fract_data[37][2];

void init_vars() {
    len = 200;
    m = 0;
    n = 0;

    for (int i = 0; i < 2; i++) {
        phi_fract[i] = 1 << 29;
    }

    for (int i = 0; i < 3; i++) {
        ag[i] = 1 << 30;
    }

    for (int i = 0; i < 200; i++) {
        delay_data[i][0] = i;
        delay_data[i][1] = i + 1;
        out_data[i][0] = 0;
        out_data[i][1] = 0;
    }

    for (int i = 0; i < 37; i++) {
        for (int j = 0; j < 39; j++) {
            ap_delay_data[i][j][0] = (i + j) % 100;
            ap_delay_data[i][j][1] = (i + j + 1) % 100;
        }
    }

    for (int i = 0; i < 37; i++) {
        Q_fract_data[i][0] = 1 << 29;
        Q_fract_data[i][1] = 0;
    }

    static UINTFLOAT transient_gain_data[200];
    for (int i = 0; i < 200; i++) {
        transient_gain_data[i] = 1 << 15;
    }

    out = out_data;
    delay = delay_data;
    ap_delay = (INTFLOAT(*)[37][2])ap_delay_data;
    Q_fract = Q_fract_data;
    transient_gain = (INTFLOAT*)transient_gain_data;
}