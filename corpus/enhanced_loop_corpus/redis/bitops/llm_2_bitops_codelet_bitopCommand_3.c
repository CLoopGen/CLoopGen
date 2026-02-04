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
for (; j < maxlen; j++) {
    ptrdiff_t stride = 2; // Strided access with step size 2
    ptrdiff_t idx = j * stride;
    if (idx >= maxlen) continue;

    output = (len[0] <= idx) ? 0 : src[0][idx];
    if (op == 3)
        output = ~output;
    disjunction = 0;
    common_bits = 0;
    for (i = 1; i < numkeys; i++) {
        int skip = 0;
        byte = (len[i] <= idx) ? 0 : src[i][idx];
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
        if (skip) {
            break;
        }
    }
    switch (op) {
      case 4:
        res[idx] = (output & ~disjunction);
        break;
      case 5:
        res[idx] = (~output & disjunction);
        break;
      case 6:
        res[idx] = (output & disjunction);
        break;
      default:
        res[idx] = output;
        break;
    }
}
}
