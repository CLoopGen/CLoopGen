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
for (i = order; i < len; i += 4) {
    int s = smp[i - order];
    int32_t p0 = 0, p1 = 0, p2 = 0, p3 = 0;
    if (big) {
        switch (order) {
          case 32:
            {
                int c = coefs[31];
                p0 += c * s;
                p1 += c * smp[i - 31];
                p2 += c * smp[i - 30];
                p3 += c * smp[i - 29];
                s = smp[i - 31 + 1];
            }
          case 31:
            {
                int c = coefs[30];
                p0 += c * s;
                p1 += c * smp[i - 30];
                p2 += c * smp[i - 29];
                p3 += c * smp[i - 28];
                s = smp[i - 30 + 1];
            }
          case 30:
            {
                int c = coefs[29];
                p0 += c * s;
                p1 += c * smp[i - 29];
                p2 += c * smp[i - 28];
                p3 += c * smp[i - 27];
                s = smp[i - 29 + 1];
            }
          case 29:
            {
                int c = coefs[28];
                p0 += c * s;
                p1 += c * smp[i - 28];
                p2 += c * smp[i - 27];
                p3 += c * smp[i - 26];
                s = smp[i - 28 + 1];
            }
          case 28:
            {
                int c = coefs[27];
                p0 += c * s;
                p1 += c * smp[i - 27];
                p2 += c * smp[i - 26];
                p3 += c * smp[i - 25];
                s = smp[i - 27 + 1];
            }
          case 27:
            {
                int c = coefs[26];
                p0 += c * s;
                p1 += c * smp[i - 26];
                p2 += c * smp[i - 25];
                p3 += c * smp[i - 24];
                s = smp[i - 26 + 1];
            }
          case 26:
            {
                int c = coefs[25];
                p0 += c * s;
                p1 += c * smp[i - 25];
                p2 += c * smp[i - 24];
                p3 += c * smp[i - 23];
                s = smp[i - 25 + 1];
            }
          case 25:
            {
                int c = coefs[24];
                p0 += c * s;
                p1 += c * smp[i - 24];
                p2 += c * smp[i - 23];
                p3 += c * smp[i - 22];
                s = smp[i - 24 + 1];
            }
          case 24:
            {
                int c = coefs[23];
                p0 += c * s;
                p1 += c * smp[i - 23];
                p2 += c * smp[i - 22];
                p3 += c * smp[i - 21];
                s = smp[i - 23 + 1];
            }
          case 23:
            {
                int c = coefs[22];
                p0 += c * s;
                p1 += c * smp[i - 22];
                p2 += c * smp[i - 21];
                p3 += c * smp[i - 20];
                s = smp[i - 22 + 1];
            }
          case 22:
            {
                int c = coefs[21];
                p0 += c * s;
                p1 += c * smp[i - 21];
                p2 += c * smp[i - 20];
                p3 += c * smp[i - 19];
                s = smp[i - 21 + 1];
            }
          case 21:
            {
                int c = coefs[20];
                p0 += c * s;
                p1 += c * smp[i - 20];
                p2 += c * smp[i - 19];
                p3 += c * smp[i - 18];
                s = smp[i - 20 + 1];
            }
          case 20:
            {
                int c = coefs[19];
                p0 += c * s;
                p1 += c * smp[i - 19];
                p2 += c * smp[i - 18];
                p3 += c * smp[i - 17];
                s = smp[i - 19 + 1];
            }
          case 19:
            {
                int c = coefs[18];
                p0 += c * s;
                p1 += c * smp[i - 18];
                p2 += c * smp[i - 17];
                p3 += c * smp[i - 16];
                s = smp[i - 18 + 1];
            }
          case 18:
            {
                int c = coefs[17];
                p0 += c * s;
                p1 += c * smp[i - 17];
                p2 += c * smp[i - 16];
                p3 += c * smp[i - 15];
                s = smp[i - 17 + 1];
            }
          case 17:
            {
                int c = coefs[16];
                p0 += c * s;
                p1 += c * smp[i - 16];
                p2 += c * smp[i - 15];
                p3 += c * smp[i - 14];
                s = smp[i - 16 + 1];
            }
          case 16:
            {
                int c = coefs[15];
                p0 += c * s;
                p1 += c * smp[i - 15];
                p2 += c * smp[i - 14];
                p3 += c * smp[i - 13];
                s = smp[i - 15 + 1];
            }
          case 15:
            {
                int c = coefs[14];
                p0 += c * s;
                p1 += c * smp[i - 14];
                p2 += c * smp[i - 13];
                p3 += c * smp[i - 12];
                s = smp[i - 14 + 1];
            }
          case 14:
            {
                int c = coefs[13];
                p0 += c * s;
                p1 += c * smp[i - 13];
                p2 += c * smp[i - 12];
                p3 += c * smp[i - 11];
                s = smp[i - 13 + 1];
            }
          case 13:
            {
                int c = coefs[12];
                p0 += c * s;
                p1 += c * smp[i - 12];
                p2 += c * smp[i - 11];
                p3 += c * smp[i - 10];
                s = smp[i - 12 + 1];
            }
          case 12:
            {
                int c = coefs[11];
                p0 += c * s;
                p1 += c * smp[i - 11];
                p2 += c * smp[i - 10];
                p3 += c * smp[i - 9];
                s = smp[i - 11 + 1];
            }
          case 11:
            {
                int c = coefs[10];
                p0 += c * s;
                p1 += c * smp[i - 10];
                p2 += c * smp[i - 9];
                p3 += c * smp[i - 8];
                s = smp[i - 10 + 1];
            }
          case 10:
            {
                int c = coefs[9];
                p0 += c * s;
                p1 += c * smp[i - 9];
                p2 += c * smp[i - 8];
                p3 += c * smp[i - 7];
                s = smp[i - 9 + 1];
            }
          case 9:
            {
                int c = coefs[8];
                p0 += c * s;
                p1 += c * smp[i - 8];
                p2 += c * smp[i - 7];
                p3 += c * smp[i - 6];
                s = smp[i - 8 + 1];
            }
          case 8:
            {
                int c = coefs[7];
                p0 += c * s;
                p1 += c * smp[i - 7];
                p2 += c * smp[i - 6];
                p3 += c * smp[i - 5];
                s = smp[i - 7 + 1];
            }
          case 7:
            {
                int c = coefs[6];
                p0 += c * s;
                p1 += c * smp[i - 6];
                p2 += c * smp[i - 5];
                p3 += c * smp[i - 4];
                s = smp[i - 6 + 1];
            }
          case 6:
            {
                int c = coefs[5];
                p0 += c * s;
                p1 += c * smp[i - 5];
                p2 += c * smp[i - 4];
                p3 += c * smp[i - 3];
                s = smp[i - 5 + 1];
            }
          case 5:
            {
                int c = coefs[4];
                p0 += c * s;
                p1 += c * smp[i - 4];
                p2 += c * smp[i - 3];
                p3 += c * smp[i - 2];
                s = smp[i - 4 + 1];
            }
          case 4:
            {
                int c = coefs[3];
                p0 += c * s;
                p1 += c * smp[i - 3];
                p2 += c * smp[i - 2];
                p3 += c * smp[i - 1];
                s = smp[i - 3 + 1];
            }
          case 3:
            {
                int c = coefs[2];
                p0 += c * s;
                p1 += c * smp[i - 2];
                p2 += c * smp[i - 1];
                p3 += c * smp[i];
                s = smp[i - 2 + 1];
            }
          case 2:
            {
                int c = coefs[1];
                p0 += c * s;
                p1 += c * smp[i - 1];
                p2 += c * smp[i];
                p3 += c * smp[i + 1];
                s = smp[i - 1 + 1];
            }
          case 1:
            {
                int c = coefs[0];
                p0 += c * s;
                p1 += c * smp[i];
                p2 += c * smp[i + 1];
                p3 += c * smp[i + 2];
            }
        }
    } else {
        switch (order) {
          case 8:
            {
                int c = coefs[7];
                p0 += c * s;
                p1 += c * smp[i - 7];
                p2 += c * smp[i - 6];
                p3 += c * smp[i - 5];
                s = smp[i - 7 + 1];
            }
          case 7:
            {
                int c = coefs[6];
                p0 += c * s;
                p1 += c * smp[i - 6];
                p2 += c * smp[i - 5];
                p3 += c * smp[i - 4];
                s = smp[i - 6 + 1];
            }
          case 6:
            {
                int c = coefs[5];
                p0 += c * s;
                p1 += c * smp[i - 5];
                p2 += c * smp[i - 4];
                p3 += c * smp[i - 3];
                s = smp[i - 5 + 1];
            }
          case 5:
            {
                int c = coefs[4];
                p0 += c * s;
                p1 += c * smp[i - 4];
                p2 += c * smp[i - 3];
                p3 += c * smp[i - 2];
                s = smp[i - 4 + 1];
            }
          case 4:
            {
                int c = coefs[3];
                p0 += c * s;
                p1 += c * smp[i - 3];
                p2 += c * smp[i - 2];
                p3 += c * smp[i - 1];
                s = smp[i - 3 + 1];
            }
          case 3:
            {
                int c = coefs[2];
                p0 += c * s;
                p1 += c * smp[i - 2];
                p2 += c * smp[i - 1];
                p3 += c * smp[i];
                s = smp[i - 2 + 1];
            }
          case 2:
            {
                int c = coefs[1];
                p0 += c * s;
                p1 += c * smp[i - 1];
                p2 += c * smp[i];
                p3 += c * smp[i + 1];
                s = smp[i - 1 + 1];
            }
          case 1:
            {
                int c = coefs[0];
                p0 += c * s;
                p1 += c * smp[i];
                p2 += c * smp[i + 1];
                p3 += c * smp[i + 2];
            }
        }
    }
    res[i]     = smp[i]     - (p0 >> shift);
    res[i + 1] = smp[i + 1] - (p1 >> shift);
    res[i + 2] = smp[i + 2] - (p2 >> shift);
    res[i + 3] = smp[i + 3] - (p3 >> shift);
}
}
