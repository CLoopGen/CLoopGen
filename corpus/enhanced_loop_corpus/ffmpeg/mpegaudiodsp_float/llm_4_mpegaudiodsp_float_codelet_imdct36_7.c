#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float icos36[9];
extern  float icos36h[9];
extern float *out;
extern float *buf;
extern float *win;
extern int i;
extern int j;
extern float t0;
extern float t1;
extern float t2;
extern float t3;
extern float s0;
extern float s1;
extern float s2;
extern float s3;
extern float tmp[18];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        t0 = tmp[i];
        t1 = tmp[i + 2];
        s0 = t1 + t0;
        s2 = t1 - t0;
        t2 = tmp[i + 1];
        t3 = tmp[i + 3];
        s1 = ((2) * (icos36h[j]) * (t3 + t2));
        s3 = ((icos36[8 - j]) * (t3 - t2));
        
        // Introduce conditional path based on j value: split behavior for first half vs second half
        if (j < 2) {
            t0 = s0 + s1;
            t1 = s0 - s1;
            out[(9 + j) * 32] = ((1) * (win[9 + j]) * (t1)) + buf[4 * (9 + j)];
            out[(8 - j) * 32] = ((1) * (win[8 - j]) * (t1)) + buf[4 * (8 - j)];
            buf[4 * (9 + j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + j]) * (t0));
            buf[4 * (8 - j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 8 - j]) * (t0));
        } else {
            // Alternate computation path: swap roles of s0/s2 and modify scaling
            t0 = s2 + s3;
            t1 = s2 - s3;
            out[(9 + j) * 32] = ((1) * (win[9 + j]) * (t0)) + buf[4 * (9 + j)];
            out[(8 - j) * 32] = ((1) * (win[8 - j]) * (t1)) + buf[4 * (8 - j)];
            buf[4 * (9 + j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + j]) * (t1));
            buf[4 * (8 - j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 8 - j]) * (t0));
        }

        t0 = s0 + s1;
        t1 = s2 - s3;
        out[(9 + 8 - j) * 32] = ((1) * (win[9 + 8 - j]) * (t1)) + buf[4 * (9 + 8 - j)];
        out[j * 32] = ((1) * (win[j]) * (t1)) + buf[4 * (j)];
        buf[4 * (9 + 8 - j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + 8 - j]) * (t0));
        buf[4 * (j)] = ((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + j]) * (t0));
        
        i += 4;
    }
}
