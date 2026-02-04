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
    if (big) {
        switch (order) {
          case 32:
            {
                int c = coefs[(32) - 1];
                p0 += ((c) * (s));
                s = smp[i - (32) + 1];
                p1 += ((c) * (s));
            }
          case 31:
            {
                int c = coefs[(31) - 1];
                p0 += ((c) * (s));
                s = smp[i - (31) + 1];
                p1 += ((c) * (s));
            }
          case 30:
            {
                int c = coefs[(30) - 1];
                p0 += ((c) * (s));
                s = smp[i - (30) + 1];
                p1 += ((c) * (s));
            }
          case 29:
            {
                int c = coefs[(29) - 1];
                p0 += ((c) * (s));
                s = smp[i - (29) + 1];
                p1 += ((c) * (s));
            }
          case 28:
            {
                int c = coefs[(28) - 1];
                p0 += ((c) * (s));
                s = smp[i - (28) + 1];
                p1 += ((c) * (s));
            }
          case 27:
            {
                int c = coefs[(27) - 1];
                p0 += ((c) * (s));
                s = smp[i - (27) + 1];
                p1 += ((c) * (s));
            }
          case 26:
            {
                int c = coefs[(26) - 1];
                p0 += ((c) * (s));
                s = smp[i - (26) + 1];
                p1 += ((c) * (s));
            }
          case 25:
            {
                int c = coefs[(25) - 1];
                p0 += ((c) * (s));
                s = smp[i - (25) + 1];
                p1 += ((c) * (s));
            }
          case 24:
            {
                int c = coefs[(24) - 1];
                p0 += ((c) * (s));
                s = smp[i - (24) + 1];
                p1 += ((c) * (s));
            }
          case 23:
            {
                int c = coefs[(23) - 1];
                p0 += ((c) * (s));
                s = smp[i - (23) + 1];
                p1 += ((c) * (s));
            }
          case 22:
            {
                int c = coefs[(22) - 1];
                p0 += ((c) * (s));
                s = smp[i - (22) + 1];
                p1 += ((c) * (s));
            }
          case 21:
            {
                int c = coefs[(21) - 1];
                p0 += ((c) * (s));
                s = smp[i - (21) + 1];
                p1 += ((c) * (s));
            }
          case 20:
            {
                int c = coefs[(20) - 1];
                p0 += ((c) * (s));
                s = smp[i - (20) + 1];
                p1 += ((c) * (s));
            }
          case 19:
            {
                int c = coefs[(19) - 1];
                p0 += ((c) * (s));
                s = smp[i - (19) + 1];
                p1 += ((c) * (s));
            }
          case 18:
            {
                int c = coefs[(18) - 1];
                p0 += ((c) * (s));
                s = smp[i - (18) + 1];
                p1 += ((c) * (s));
            }
          case 17:
            {
                int c = coefs[(17) - 1];
                p0 += ((c) * (s));
                s = smp[i - (17) + 1];
                p1 += ((c) * (s));
            }
          case 16:
            {
                int c = coefs[(16) - 1];
                p0 += ((c) * (s));
                s = smp[i - (16) + 1];
                p1 += ((c) * (s));
            }
          case 15:
            {
                int c = coefs[(15) - 1];
                p0 += ((c) * (s));
                s = smp[i - (15) + 1];
                p1 += ((c) * (s));
            }
          case 14:
            {
                int c = coefs[(14) - 1];
                p0 += ((c) * (s));
                s = smp[i - (14) + 1];
                p1 += ((c) * (s));
            }
          case 13:
            {
                int c = coefs[(13) - 1];
                p0 += ((c) * (s));
                s = smp[i - (13) + 1];
                p1 += ((c) * (s));
            }
          case 12:
            {
                int c = coefs[(12) - 1];
                p0 += ((c) * (s));
                s = smp[i - (12) + 1];
                p1 += ((c) * (s));
            }
          case 11:
            {
                int c = coefs[(11) - 1];
                p0 += ((c) * (s));
                s = smp[i - (11) + 1];
                p1 += ((c) * (s));
            }
          case 10:
            {
                int c = coefs[(10) - 1];
                p0 += ((c) * (s));
                s = smp[i - (10) + 1];
                p1 += ((c) * (s));
            }
          case 9:
            {
                int c = coefs[(9) - 1];
                p0 += ((c) * (s));
                s = smp[i - (9) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(8) - 1];
                p0 += ((c) * (s));
                s = smp[i - (8) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(7) - 1];
                p0 += ((c) * (s));
                s = smp[i - (7) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(6) - 1];
                p0 += ((c) * (s));
                s = smp[i - (6) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(5) - 1];
                p0 += ((c) * (s));
                s = smp[i - (5) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(4) - 1];
                p0 += ((c) * (s));
                s = smp[i - (4) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(3) - 1];
                p0 += ((c) * (s));
                s = smp[i - (3) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(2) - 1];
                p0 += ((c) * (s));
                s = smp[i - (2) + 1];
                p1 += ((c) * (s));
            }
            {
                int c = coefs[(1) - 1];
                p0 += ((c) * (s));
                s = smp[i - (1) + 1];
                p1 += ((c) * (s));
            }
        }
    } else {
        switch (order) {
          case 8:
            {
                int c = coefs[(8) - 1];
                p0 += ((c) * (s));
                s = smp[i - (8) + 1];
                p1 += ((c) * (s));
            }
          case 7:
            {
                int c = coefs[(7) - 1];
                p0 += ((c) * (s));
                s = smp[i - (7) + 1];
                p1 += ((c) * (s));
            }
          case 6:
            {
                int c = coefs[(6) - 1];
                p0 += ((c) * (s));
                s = smp[i - (6) + 1];
                p1 += ((c) * (s));
            }
          case 5:
            {
                int c = coefs[(5) - 1];
                p0 += ((c) * (s));
                s = smp[i - (5) + 1];
                p1 += ((c) * (s));
            }
          case 4:
            {
                int c = coefs[(4) - 1];
                p0 += ((c) * (s));
                s = smp[i - (4) + 1];
                p1 += ((c) * (s));
            }
          case 3:
            {
                int c = coefs[(3) - 1];
                p0 += ((c) * (s));
                s = smp[i - (3) + 1];
                p1 += ((c) * (s));
            }
          case 2:
            {
                int c = coefs[(2) - 1];
                p0 += ((c) * (s));
                s = smp[i - (2) + 1];
                p1 += ((c) * (s));
            }
          case 1:
            {
                int c = coefs[(1) - 1];
                p0 += ((c) * (s));
                s = smp[i - (1) + 1];
                p1 += ((c) * (s));
            }
        }
    }
    res[i] = smp[i] - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
}

}
