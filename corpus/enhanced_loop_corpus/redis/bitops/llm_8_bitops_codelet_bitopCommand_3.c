#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long op;
extern unsigned long j;
extern unsigned long numkeys;
extern unsigned char **src;
extern unsigned long *len;
extern unsigned long maxlen;
extern unsigned char *res;
extern unsigned char output;
extern unsigned char byte;
extern unsigned char disjunction;
extern unsigned char common_bits;
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < maxlen && numkeys > 0; j++) {
    output = (len[0] <= j) ? 0 : src[0][j];
    if (op == 3)
        output = ~output;
    disjunction = 0;
    common_bits = 0;
    unsigned long unroll_factor = 4;
    for (i = 1; i + 3 < numkeys; i += 4) {
        unsigned char bytes[4];
        int skips[4] = {0};
        for (int k = 0; k < 4; k++) {
            bytes[k] = (len[i + k] <= j) ? 0 : src[i + k][j];
        }
        switch (op) {
          case 0:
            for (int k = 0; k < 4; k++) {
                output &= bytes[k];
                skips[k] = (output == 0);
                if (skips[k]) break;
            }
            if (skips[0] || skips[1] || skips[2] || skips[3]) goto skip_remaining;
            break;
          case 1:
            for (int k = 0; k < 4; k++) {
                output |= bytes[k];
                skips[k] = (output == 255);
                if (skips[k]) break;
            }
            if (skips[0] || skips[1] || skips[2] || skips[3]) goto skip_remaining;
            break;
          case 2:
            for (int k = 0; k < 4; k++) {
                output ^= bytes[k];
            }
            break;
          case 4:
          case 5:
          case 6:
            for (int k = 0; k < 4; k++) {
                disjunction |= bytes[k];
                skips[k] = (disjunction == 255);
                if (skips[k]) break;
            }
            if (skips[0] || skips[1] || skips[2] || skips[3]) goto skip_remaining;
            break;
          case 7:
            for (int k = 0; k < 4; k++) {
                common_bits |= (output & bytes[k]);
                output ^= bytes[k];
                output &= ~common_bits;
                skips[k] = (common_bits == 255);
                if (skips[k]) break;
            }
            if (skips[0] || skips[1] || skips[2] || skips[3]) goto skip_remaining;
            break;
          default:
            break;
        }
    }
    for (; i < numkeys; i++) {
        int skip = 0;
        byte = (len[i] <= j) ? 0 : src[i][j];
        switch (op) {
          case 0:
            output &= byte;
            skip = (output == 0);
            break;
          case 1:
            output |= byte;
            skip = (output == 255);
            break;
          case 2:
            output ^= byte;
            break;
          case 4:
          case 5:
          case 6:
            disjunction |= byte;
            skip = (disjunction == 255);
            break;
          case 7:
            common_bits |= (output & byte);
            output ^= byte;
            output &= ~common_bits;
            skip = (common_bits == 255);
            break;
          default:
            break;
        }
        if (skip) break;
    }
skip_remaining:
    switch (op) {
      case 4:
        res[j] = (output & ~disjunction);
        break;
      case 5:
        res[j] = (~output & disjunction);
        break;
      case 6:
        res[j] = (output & disjunction);
        break;
      default:
        res[j] = output;
        break;
    }
}
}
