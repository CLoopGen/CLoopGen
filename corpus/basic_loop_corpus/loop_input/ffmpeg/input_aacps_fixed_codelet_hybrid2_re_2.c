#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;
typedef int64_t INT64FLOAT;

INTFLOAT filter[8] = {1, 2, 3, 4, 5, 6, 7, 8};

int len = 262144;
int reverse = 0;
int i = 0;
int j = 0;

static INTFLOAT in_data[12][2];
static INTFLOAT out_data[2][262144][32][2];

INTFLOAT (*in)[2] = in_data;
INTFLOAT (*out)[32][2] = out_data[0];

void init_vars() {
    for (int idx = 0; idx < 12; ++idx) {
        in_data[idx][0] = idx;
        in_data[idx][1] = idx + 1;
    }
    for (int r = 0; r < 2; ++r) {
        for (int l = 0; l < 262144; ++l) {
            for (int s = 0; s < 32; ++s) {
                out_data[r][l][s][0] = 0;
                out_data[r][l][s][1] = 0;
            }
        }
    }
}