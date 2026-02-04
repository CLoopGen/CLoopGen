#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum CodingMode {
    CODING_MODE_RICE = 4,
    CODING_MODE_RICE2 = 5
};

typedef struct RiceContext {
    enum CodingMode coding_mode;
    int porder;
    int params[256];
} RiceContext;

typedef struct FlacSubframe {
    int type;
    int type_code;
    int obits;
    int wasted;
    int order;
    int32_t coefs[32];
    int shift;
    RiceContext rc;
    uint32_t rc_udata[65535];
    uint64_t rc_sums[32][256];
    int32_t samples[65535];
    int32_t residual[65546];
} FlacSubframe;

int i;
FlacSubframe *sub;
int32_t coefs[32][32];

void init_vars() {
    sub = (FlacSubframe*)malloc(sizeof(FlacSubframe));
    if (!sub) exit(1);

    sub->order = 32;

    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 32; k++) {
            coefs[j][k] = (j + 1) * (k + 1);
        }
    }

    for (int j = 0; j < 32; j++) {
        sub->coefs[j] = 0;
    }

    sub->rc.coding_mode = CODING_MODE_RICE;
    sub->rc.porder = 0;
    for (int j = 0; j < 256; j++) {
        sub->rc.params[j] = j;
    }

    for (int j = 0; j < 65535; j++) {
        sub->rc_udata[j] = j * 2;
        sub->samples[j] = j * 3;
    }

    for (int j = 0; j < 65546; j++) {
        sub->residual[j] = j * 4;
    }

    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 256; k++) {
            sub->rc_sums[j][k] = ((uint64_t)j) * k;
        }
    }

    sub->type = 0;
    sub->type_code = 0;
    sub->obits = 16;
    sub->wasted = 0;
    sub->shift = 0;
}