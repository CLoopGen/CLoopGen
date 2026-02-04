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
    output = (len[0] <= j) ? 0 : src[0][j];
    if (op == 3)
        output = ~output;
    disjunction = 0;
    common_bits = 0;
    for (i = 1; i < numkeys && !(op == 0 && output == 0) && !(op == 1 && output == 255); i++) {
        byte = (len[i] <= j) ? 0 : src[i][j];
        switch (op) {
          case 0:
            output &= byte;
            break;
          case 1:
            output |= byte;
            break;
          case 2:
            output ^= byte;
            break;
          case 4:
          case 5:
          case 6:
            disjunction |= byte;
            break;
          case 7:
            common_bits |= (output & byte);
            output ^= byte;
            output &= ~common_bits;
            break;
          default:
            break;
        }
    }
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
