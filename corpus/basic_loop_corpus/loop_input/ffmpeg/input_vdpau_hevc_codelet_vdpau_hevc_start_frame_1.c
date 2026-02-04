#include <stdint.h>
#include <stddef.h>

const uint8_t ff_hevc_diag_scan4x4_x[16] = {
    0, 1, 0, 2, 1, 0, 3, 2,
    1, 0, 3, 2, 1, 2, 3, 3
};

const uint8_t ff_hevc_diag_scan4x4_y[16] = {
    0, 0, 1, 0, 1, 2, 0, 1,
    2, 3, 1, 2, 3, 3, 2, 3
};

const uint8_t ff_hevc_diag_scan8x8_x[64] = {
     0, 1, 0, 2, 1, 0, 3, 2,
     1, 0, 4, 3, 2, 1, 0, 5,
     4, 3, 2, 1, 0, 6, 5, 4,
     3, 2, 1, 0, 7, 6, 5, 4,
     3, 2, 1, 7, 6, 5, 4, 3,
     2, 7, 6, 5, 4, 3, 7, 6,
     5, 4, 7, 6, 5, 7, 6, 7
};

const uint8_t ff_hevc_diag_scan8x8_y[64] = {
     0, 0, 1, 0, 1, 2, 0, 1,
     2, 3, 0, 1, 2, 3, 4, 0,
     1, 2, 3, 4, 5, 0, 1, 2,
     3, 4, 5, 6, 0, 1, 2, 3,
     4, 5, 6, 1, 2, 3, 4, 5,
     6, 2, 3, 4, 5, 6, 3, 4,
     5, 6, 4, 5, 6, 5, 6, 6
};

void init_vars(void)
{
    // All arrays are statically initialized; no runtime initialization needed
}