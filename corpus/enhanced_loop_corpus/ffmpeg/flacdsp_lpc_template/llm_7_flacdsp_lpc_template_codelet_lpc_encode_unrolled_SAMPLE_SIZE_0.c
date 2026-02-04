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



void loop(){
for (i = order; i < len; i += 2) {
    int32_t p0 = 0, p1 = 0;
    int offset = i - order;
    if (big) {
        switch (order) {
          case 32: p0 += coefs[31] * smp[offset + 0]; p1 += coefs[31] * smp[offset + 1];
          case 31: p0 += coefs[30] * smp[offset + 1]; p1 += coefs[30] * smp[offset + 2];
          case 30: p0 += coefs[29] * smp[offset + 2]; p1 += coefs[29] * smp[offset + 3];
          case 29: p0 += coefs[28] * smp[offset + 3]; p1 += coefs[28] * smp[offset + 4];
          case 28: p0 += coefs[27] * smp[offset + 4]; p1 += coefs[27] * smp[offset + 5];
          case 27: p0 += coefs[26] * smp[offset + 5]; p1 += coefs[26] * smp[offset + 6];
          case 26: p0 += coefs[25] * smp[offset + 6]; p1 += coefs[25] * smp[offset + 7];
          case 25: p0 += coefs[24] * smp[offset + 7]; p1 += coefs[24] * smp[offset + 8];
          case 24: p0 += coefs[23] * smp[offset + 8]; p1 += coefs[23] * smp[offset + 9];
          case 23: p0 += coefs[22] * smp[offset + 9]; p1 += coefs[22] * smp[offset + 10];
          case 22: p0 += coefs[21] * smp[offset + 10]; p1 += coefs[21] * smp[offset + 11];
          case 21: p0 += coefs[20] * smp[offset + 11]; p1 += coefs[20] * smp[offset + 12];
          case 20: p0 += coefs[19] * smp[offset + 12]; p1 += coefs[19] * smp[offset + 13];
          case 19: p0 += coefs[18] * smp[offset + 13]; p1 += coefs[18] * smp[offset + 14];
          case 18: p0 += coefs[17] * smp[offset + 14]; p1 += coefs[17] * smp[offset + 15];
          case 17: p0 += coefs[16] * smp[offset + 15]; p1 += coefs[16] * smp[offset + 16];
          case 16: p0 += coefs[15] * smp[offset + 16]; p1 += coefs[15] * smp[offset + 17];
          case 15: p0 += coefs[14] * smp[offset + 17]; p1 += coefs[14] * smp[offset + 18];
          case 14: p0 += coefs[13] * smp[offset + 18]; p1 += coefs[13] * smp[offset + 19];
          case 13: p0 += coefs[12] * smp[offset + 19]; p1 += coefs[12] * smp[offset + 20];
          case 12: p0 += coefs[11] * smp[offset + 20]; p1 += coefs[11] * smp[offset + 21];
          case 11: p0 += coefs[10] * smp[offset + 21]; p1 += coefs[10] * smp[offset + 22];
          case 10: p0 += coefs[9] * smp[offset + 22]; p1 += coefs[9] * smp[offset + 23];
          case 9:  p0 += coefs[8] * smp[offset + 23]; p1 += coefs[8] * smp[offset + 24];
          case 8:  p0 += coefs[7] * smp[offset + 24]; p1 += coefs[7] * smp[offset + 25];
          case 7:  p0 += coefs[6] * smp[offset + 25]; p1 += coefs[6] * smp[offset + 26];
          case 6:  p0 += coefs[5] * smp[offset + 26]; p1 += coefs[5] * smp[offset + 27];
          case 5:  p0 += coefs[4] * smp[offset + 27]; p1 += coefs[4] * smp[offset + 28];
          case 4:  p0 += coefs[3] * smp[offset + 28]; p1 += coefs[3] * smp[offset + 29];
          case 3:  p0 += coefs[2] * smp[offset + 29]; p1 += coefs[2] * smp[offset + 30];
          case 2:  p0 += coefs[1] * smp[offset + 30]; p1 += coefs[1] * smp[offset + 31];
          case 1:  p0 += coefs[0] * smp[offset + 31]; p1 += coefs[0] * smp[offset + 32];
        }
    } else {
        switch (order) {
          case 8:  p0 += coefs[7] * smp[offset + 0]; p1 += coefs[7] * smp[offset + 1];
          case 7:  p0 += coefs[6] * smp[offset + 1]; p1 += coefs[6] * smp[offset + 2];
          case 6:  p0 += coefs[5] * smp[offset + 2]; p1 += coefs[5] * smp[offset + 3];
          case 5:  p0 += coefs[4] * smp[offset + 3]; p1 += coefs[4] * smp[offset + 4];
          case 4:  p0 += coefs[3] * smp[offset + 4]; p1 += coefs[3] * smp[offset + 5];
          case 3:  p0 += coefs[2] * smp[offset + 5]; p1 += coefs[2] * smp[offset + 6];
          case 2:  p0 += coefs[1] * smp[offset + 6]; p1 += coefs[1] * smp[offset + 7];
          case 1:  p0 += coefs[0] * smp[offset + 7]; p1 += coefs[0] * smp[offset + 8];
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}
}
