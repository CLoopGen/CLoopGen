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
    if (op == 3) {
        output = ~output;
    }
    disjunction = 0;
    common_bits = 0;
    for (i = 1; i < numkeys; i++) {
        byte = (len[i] <= j) ? 0 : src[i][j];
        if (op < 4) {
            switch (op) {
              case 0:
                output &= byte;
                if (output == 0) goto write_result;
                break;
              case 1:
                output |= byte;
                if (output == 255) goto write_result;
                break;
              case 2:
                output ^= byte;
                break;
            }
        } else {
            switch (op) {
              case 4:
              case 5:
              case 6:
                disjunction |= byte;
                if (disjunction == 255) goto write_result;
                break;
              case 7:
                common_bits |= (output & byte);
                output ^= byte;
                output &= ~common_bits;
                if (common_bits == 255) goto write_result;
                break;
            }
        }
    }
write_result:
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
