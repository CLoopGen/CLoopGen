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
for (i = order; i < len; i++) {
    int32_t p = 0;
    if (big) {
        switch (order) {
          case 32: p += coefs[31] * smp[i - 32]; /* fallthrough */
          case 31: p += coefs[30] * smp[i - 31]; /* fallthrough */
          case 30: p += coefs[29] * smp[i - 30]; /* fallthrough */
          case 29: p += coefs[28] * smp[i - 29]; /* fallthrough */
          case 28: p += coefs[27] * smp[i - 28]; /* fallthrough */
          case 27: p += coefs[26] * smp[i - 27]; /* fallthrough */
          case 26: p += coefs[25] * smp[i - 26]; /* fallthrough */
          case 25: p += coefs[24] * smp[i - 25]; /* fallthrough */
          case 24: p += coefs[23] * smp[i - 24]; /* fallthrough */
          case 23: p += coefs[22] * smp[i - 23]; /* fallthrough */
          case 22: p += coefs[21] * smp[i - 22]; /* fallthrough */
          case 21: p += coefs[20] * smp[i - 21]; /* fallthrough */
          case 20: p += coefs[19] * smp[i - 20]; /* fallthrough */
          case 19: p += coefs[18] * smp[i - 19]; /* fallthrough */
          case 18: p += coefs[17] * smp[i - 18]; /* fallthrough */
          case 17: p += coefs[16] * smp[i - 17]; /* fallthrough */
          case 16: p += coefs[15] * smp[i - 16]; /* fallthrough */
          case 15: p += coefs[14] * smp[i - 15]; /* fallthrough */
          case 14: p += coefs[13] * smp[i - 14]; /* fallthrough */
          case 13: p += coefs[12] * smp[i - 13]; /* fallthrough */
          case 12: p += coefs[11] * smp[i - 12]; /* fallthrough */
          case 11: p += coefs[10] * smp[i - 11]; /* fallthrough */
          case 10: p += coefs[9]  * smp[i - 10]; /* fallthrough */
          case  9: p += coefs[8]  * smp[i -  9]; /* fallthrough */
          case  8: p += coefs[7]  * smp[i -  8]; /* fallthrough */
          case  7: p += coefs[6]  * smp[i -  7]; /* fallthrough */
          case  6: p += coefs[5]  * smp[i -  6]; /* fallthrough */
          case  5: p += coefs[4]  * smp[i -  5]; /* fallthrough */
          case  4: p += coefs[3]  * smp[i -  4]; /* fallthrough */
          case  3: p += coefs[2]  * smp[i -  3]; /* fallthrough */
          case  2: p += coefs[1]  * smp[i -  2]; /* fallthrough */
          case  1: p += coefs[0]  * smp[i -  1];
        }
    } else {
        switch (order) {
          case 8: p += coefs[7] * smp[i - 8]; /* fallthrough */
          case 7: p += coefs[6] * smp[i - 7]; /* fallthrough */
          case 6: p += coefs[5] * smp[i - 6]; /* fallthrough */
          case 5: p += coefs[4] * smp[i - 5]; /* fallthrough */
          case 4: p += coefs[3] * smp[i - 4]; /* fallthrough */
          case 3: p += coefs[2] * smp[i - 3]; /* fallthrough */
          case 2: p += coefs[1] * smp[i - 2]; /* fallthrough */
          case 1: p += coefs[0] * smp[i - 1];
        }
    }
    res[i] = smp[i] - (p >> shift);
}
}
