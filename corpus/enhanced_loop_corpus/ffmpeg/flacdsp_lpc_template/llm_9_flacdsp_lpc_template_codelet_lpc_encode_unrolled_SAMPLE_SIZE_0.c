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
    int s = smp[i - order];
    int32_t p = 0;
    if (big && order >= 16) {
        for (int j = order; j > 0; j--) {
            int c = coefs[j - 1];
            p += c * s;
            s = smp[i - j + 1];
        }
    } else {
        switch (order) {
          case 8:
            p += coefs[7] * s; s = smp[i - 7]; 
          case 7:
            p += coefs[6] * s; s = smp[i - 6]; 
          case 6:
            p += coefs[5] * s; s = smp[i - 5]; 
          case 5:
            p += coefs[4] * s; s = smp[i - 4]; 
          case 4:
            p += coefs[3] * s; s = smp[i - 3]; 
          case 3:
            p += coefs[2] * s; s = smp[i - 2]; 
          case 2:
            p += coefs[1] * s; s = smp[i - 1]; 
          case 1:
            p += coefs[0] * s;
        }
    }
    res[i] = smp[i] - (p >> shift);
}
}
