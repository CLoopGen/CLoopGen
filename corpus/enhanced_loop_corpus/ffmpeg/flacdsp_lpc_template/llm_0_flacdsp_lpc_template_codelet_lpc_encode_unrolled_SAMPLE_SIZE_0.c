#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int len;
extern int order;
extern  int32_t *coefs;
extern int shift;
extern int big;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops.
    // Outer loop handles block processing, inner loop processes individual elements within the block.
    int block_size = 4;
    for (i = order; i < len; i += block_size * 2) {
        for (int j = 0; j < block_size && (i + j * 2) < len; j++) {
            int idx = i + j * 2;
            int s = smp[idx - order];
            int32_t p0 = 0, p1 = 0;
            if (big) {
                switch (order) {
                  case 32:
                    {
                        int c = coefs[31];
                        p0 += c * s;
                        s = smp[idx - 31];
                        p1 += c * s;
                    }
                  case 31:
                    {
                        int c = coefs[30];
                        p0 += c * s;
                        s = smp[idx - 30];
                        p1 += c * s;
                    }
                  case 30:
                    {
                        int c = coefs[29];
                        p0 += c * s;
                        s = smp[idx - 29];
                        p1 += c * s;
                    }
                  case 29:
                    {
                        int c = coefs[28];
                        p0 += c * s;
                        s = smp[idx - 28];
                        p1 += c * s;
                    }
                  case 28:
                    {
                        int c = coefs[27];
                        p0 += c * s;
                        s = smp[idx - 27];
                        p1 += c * s;
                    }
                  case 27:
                    {
                        int c = coefs[26];
                        p0 += c * s;
                        s = smp[idx - 26];
                        p1 += c * s;
                    }
                  case 26:
                    {
                        int c = coefs[25];
                        p0 += c * s;
                        s = smp[idx - 25];
                        p1 += c * s;
                    }
                  case 25:
                    {
                        int c = coefs[24];
                        p0 += c * s;
                        s = smp[idx - 24];
                        p1 += c * s;
                    }
                  case 24:
                    {
                        int c = coefs[23];
                        p0 += c * s;
                        s = smp[idx - 23];
                        p1 += c * s;
                    }
                  case 23:
                    {
                        int c = coefs[22];
                        p0 += c * s;
                        s = smp[idx - 22];
                        p1 += c * s;
                    }
                  case 22:
                    {
                        int c = coefs[21];
                        p0 += c * s;
                        s = smp[idx - 21];
                        p1 += c * s;
                    }
                  case 21:
                    {
                        int c = coefs[20];
                        p0 += c * s;
                        s = smp[idx - 20];
                        p1 += c * s;
                    }
                  case 20:
                    {
                        int c = coefs[19];
                        p0 += c * s;
                        s = smp[idx - 19];
                        p1 += c * s;
                    }
                  case 19:
                    {
                        int c = coefs[18];
                        p0 += c * s;
                        s = smp[idx - 18];
                        p1 += c * s;
                    }
                  case 18:
                    {
                        int c = coefs[17];
                        p0 += c * s;
                        s = smp[idx - 17];
                        p1 += c * s;
                    }
                  case 17:
                    {
                        int c = coefs[16];
                        p0 += c * s;
                        s = smp[idx - 16];
                        p1 += c * s;
                    }
                  case 16:
                    {
                        int c = coefs[15];
                        p0 += c * s;
                        s = smp[idx - 15];
                        p1 += c * s;
                    }
                  case 15:
                    {
                        int c = coefs[14];
                        p0 += c * s;
                        s = smp[idx - 14];
                        p1 += c * s;
                    }
                  case 14:
                    {
                        int c = coefs[13];
                        p0 += c * s;
                        s = smp[idx - 13];
                        p1 += c * s;
                    }
                  case 13:
                    {
                        int c = coefs[12];
                        p0 += c * s;
                        s = smp[idx - 12];
                        p1 += c * s;
                    }
                  case 12:
                    {
                        int c = coefs[11];
                        p0 += c * s;
                        s = smp[idx - 11];
                        p1 += c * s;
                    }
                  case 11:
                    {
                        int c = coefs[10];
                        p0 += c * s;
                        s = smp[idx - 10];
                        p1 += c * s;
                    }
                  case 10:
                    {
                        int c = coefs[9];
                        p0 += c * s;
                        s = smp[idx - 9];
                        p1 += c * s;
                    }
                  case 9:
                    {
                        int c = coefs[8];
                        p0 += c * s;
                        s = smp[idx - 8];
                        p1 += c * s;
                    }
                  case 8:
                    {
                        int c = coefs[7];
                        p0 += c * s;
                        s = smp[idx - 7];
                        p1 += c * s;
                    }
                  case 7:
                    {
                        int c = coefs[6];
                        p0 += c * s;
                        s = smp[idx - 6];
                        p1 += c * s;
                    }
                  case 6:
                    {
                        int c = coefs[5];
                        p0 += c * s;
                        s = smp[idx - 5];
                        p1 += c * s;
                    }
                  case 5:
                    {
                        int c = coefs[4];
                        p0 += c * s;
                        s = smp[idx - 4];
                        p1 += c * s;
                    }
                  case 4:
                    {
                        int c = coefs[3];
                        p0 += c * s;
                        s = smp[idx - 3];
                        p1 += c * s;
                    }
                  case 3:
                    {
                        int c = coefs[2];
                        p0 += c * s;
                        s = smp[idx - 2];
                        p1 += c * s;
                    }
                  case 2:
                    {
                        int c = coefs[1];
                        p0 += c * s;
                        s = smp[idx - 1];
                        p1 += c * s;
                    }
                  case 1:
                    {
                        int c = coefs[0];
                        p0 += c * s;
                        s = smp[idx];
                        p1 += c * s;
                    }
                }
            } else {
                switch (order) {
                  case 8:
                    {
                        int c = coefs[7];
                        p0 += c * s;
                        s = smp[idx - 7];
                        p1 += c * s;
                    }
                  case 7:
                    {
                        int c = coefs[6];
                        p0 += c * s;
                        s = smp[idx - 6];
                        p1 += c * s;
                    }
                  case 6:
                    {
                        int c = coefs[5];
                        p0 += c * s;
                        s = smp[idx - 5];
                        p1 += c * s;
                    }
                  case 5:
                    {
                        int c = coefs[4];
                        p0 += c * s;
                        s = smp[idx - 4];
                        p1 += c * s;
                    }
                  case 4:
                    {
                        int c = coefs[3];
                        p0 += c * s;
                        s = smp[idx - 3];
                        p1 += c * s;
                    }
                  case 3:
                    {
                        int c = coefs[2];
                        p0 += c * s;
                        s = smp[idx - 2];
                        p1 += c * s;
                    }
                  case 2:
                    {
                        int c = coefs[1];
                        p0 += c * s;
                        s = smp[idx - 1];
                        p1 += c * s;
                    }
                  case 1:
                    {
                        int c = coefs[0];
                        p0 += c * s;
                        s = smp[idx];
                        p1 += c * s;
                    }
                }
            }
            res[idx] = smp[idx] - (p0 >> shift);
            if (idx + 1 < len) {
                res[idx + 1] = smp[idx + 1] - (p1 >> shift);
            }
        }
    }
}
