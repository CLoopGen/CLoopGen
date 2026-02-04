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

typedef struct FlacFrame {
    FlacSubframe subframes[8];
    int blocksize;
    int bs_code[2];
    uint8_t crc8;
    int ch_mode;
    int verbatim_only;
} FlacFrame;

const int32_t ff_flac_blocksize_table[16] = {
    192, 576, 1152, 2304, 4608, 256, 512, 1024,
    2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144
};

int nb_samples = 2304;
int i;
FlacFrame *frame;

void init_vars() {
    frame = (FlacFrame*)calloc(1, sizeof(FlacFrame));
    if (!frame) exit(1);

    for (int s = 0; s < 8; s++) {
        FlacSubframe* sub = &frame->subframes[s];
        sub->type = 0;
        sub->type_code = 0;
        sub->obits = 0;
        sub->wasted = 0;
        sub->order = 0;
        sub->shift = 0;
        sub->rc.coding_mode = CODING_MODE_RICE;
        sub->rc.porder = 0;
        for (int j = 0; j < 32; j++) {
            sub->coefs[j] = 0;
            for (int k = 0; k < 256; k++) {
                sub->rc_sums[j][k] = 0;
            }
        }
        for (int j = 0; j < 256; j++) {
            sub->rc.params[j] = 0;
        }
        for (int j = 0; j < 65535; j++) {
            sub->rc_udata[j] = 0;
            sub->samples[j] = 0;
        }
        for (int j = 0; j < 65546; j++) {
            sub->residual[j] = 0;
        }
    }

    frame->blocksize = 0;
    frame->bs_code[0] = 0;
    frame->bs_code[1] = 0;
    frame->crc8 = 0;
    frame->ch_mode = 0;
    frame->verbatim_only = 0;
}