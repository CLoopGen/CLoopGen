#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int i;
int j;
int i1;
int M4[4][4];
int M5[4];
int M6[4];
Boolean lossless_qpprime;

void init_vars() {
    // Initialize scalar variables
    i = 0;
    j = 0;
    i1 = 0;
    lossless_qpprime = FALSE;

    // Initialize M4 with non-zero values to ensure meaningful computation
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            M4[row][col] = (row * 4 + col + 1) * 7;
        }
    }

    // Initialize M5 and M6 with default values
    for (int idx = 0; idx < 4; idx++) {
        M5[idx] = 0;
        M6[idx] = 0;
    }
}