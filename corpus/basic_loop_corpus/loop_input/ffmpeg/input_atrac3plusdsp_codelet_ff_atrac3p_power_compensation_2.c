#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

AtracGainInfo *g2;
int i;
int gain_lev;
int gcv;

void init_vars() {
    // Allocate and initialize AtracGainInfo structure
    g2 = (AtracGainInfo*)malloc(sizeof(AtracGainInfo));
    if (!g2) {
        exit(1);
    }

    // Set number of points within valid range (0 to 7, since lev_code has size 7)
    g2->num_points = 7;

    // Initialize lev_code with sample values between 0 and 15 to avoid negative adjustments
    for (int j = 0; j < 7; j++) {
        g2->lev_code[j] = (j * 19 + 43) % 16;  // pseudo-random pattern in [0,15]
    }

    // loc_code is not used in the loop, but we initialize it anyway
    for (int j = 0; j < 7; j++) {
        g2->loc_code[j] = 0;
    }

    // Initialize other variables
    i = 0;
    gain_lev = 20;
    gcv = 10;
}