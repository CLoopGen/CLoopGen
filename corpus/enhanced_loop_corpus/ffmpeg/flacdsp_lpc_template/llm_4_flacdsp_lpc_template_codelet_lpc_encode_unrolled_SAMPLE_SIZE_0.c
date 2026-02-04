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
    int s = smp[i - order];
    int32_t p0 = 0, p1 = 0;
    if (big && order >= 16) {
        switch (order) {
          case 32:
            {
                int c = coefs[31];
                p0 += c * s;
                s = smp[i - 31];
                p1 += c * s;
            }
          case 30:
            {
                int c = coefs[29];
                p0 += c * s;
                s = smp[i - 29];
                p1 += c * s;
            }
          case 28:
            {
                int c = coefs[27];
                p0 += c * s;
                s = smp[i - 27];
                p1 += c * s;
            }
          case 26:
            {
                int c = coefs[25];
                p0 += c * s;
                s = smp[i - 25];
                p1 += c * s;
            }
          case 24:
            {
                int c = coefs[23];
                p0 += c * s;
                s = smp[i - 23];
                p1 += c * s;
            }
          case 22:
            {
                int c = coefs[21];
                p0 += c * s;
                s = smp[i - 21];
                p1 += c * s;
            }
          case 20:
            {
                int c = coefs[19];
                p0 += c * s;
                s = smp[i - 19];
                p1 += c * s;
            }
          case 18:
            {
                int c = coefs[17];
                p0 += c * s;
                s = smp[i - 17];
                p1 += c * s;
            }
          case 16:
            {
                int c = coefs[15];
                p0 += c * s;
                s = smp[i - 15];
                p1 += c * s;
            }
        }
        for (int j = order - (order % 2 ? 1 : 2); j >= 15; j -= 2) {
            int c = coefs[j - 1];
            p0 += c * s;
            s = smp[i - j + 1];
            p1 += c * s;
        }
    } else {
        int start = (big) ? 16 : 8;
        for (int j = start; j >= 1; j--) {
            int c = coefs[j - 1];
            p0 += c * s;
            s = smp[i - j + 1];
            p1 += c * s;
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    if (i + 1 < len) {
        res[i + 1] = smp[i + 1] - (p1 >> shift);
    }
}
}
