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
    unsigned char temp_output = output;
    for (i = 1; i < numkeys; i++) {
        int skip = 0;
        byte = (len[i] <= j) ? 0 : src[i][j];
        switch (op) {
          case 0:
            temp_output &= byte;
            skip = (temp_output == 0);
            break;
          case 1:
            temp_output |= byte;
            skip = (temp_output == 255);
            break;
          case 2:
            temp_output ^= byte;
            break;
          case 4:
          case 5:
          case 6:
            disjunction |= byte;
            skip = (disjunction == 255);
            break;
          case 7:
            common_bits |= (temp_output & byte);
            temp_output ^= byte;
            temp_output &= ~common_bits;
            skip = (common_bits == 255);
            break;
          default:
            break;
        }
        if (skip) {
            break;
        }
    }
    output = temp_output;
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
