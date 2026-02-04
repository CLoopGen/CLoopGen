#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int cov[6];
extern int mu[3];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried dependency and restructure computation
    // to create a sequential data flow across iterations (RAW dependency)
    int acc_r = 0, acc_g = 0, acc_b = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int r = block[x * 4 + stride * y + 0] - mu[0];
            int g = block[x * 4 + stride * y + 1] - mu[1];
            int b = block[x * 4 + stride * y + 2] - mu[2];

            // Create loop-carried dependency using previous values
            // Simulate filtering effect: current contribution depends on accumulated past
            int dr = r + (x > 0 || y > 0 ? (acc_r >> 3) : 0); // Feedback from prior r
            int dg = g + (x > 0 || y > 0 ? (acc_g >> 3) : 0);
            int db = b + (x > 0 || y > 0 ? (acc_b >> 3) : 0);

            cov[0] += dr * dr;
            cov[1] += dr * dg;
            cov[2] += dr * db;
            cov[3] += dg * dg;
            cov[4] += dg * db;
            cov[5] += db * db;

            // Update accumulators for feedback (creates RAW dependency)
            acc_r += r;
            acc_g += g;
            acc_b += b;
        }
    }
}
