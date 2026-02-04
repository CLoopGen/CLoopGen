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
for (j = 0; j < maxlen; j += 2) {
    for (int offset = 0; offset < 2 && (j + offset) < maxlen; offset++) {
        unsigned long pos = j + offset;
        output = (len[0] <= pos) ? 0 : src[0][pos];
        if (op == 3)
            output = ~output;
        disjunction = 0;
        common_bits = 0;
        int early_exit = 0;
        for (i = 1; i < numkeys && !early_exit; i++) {
            int skip = 0;
            byte = (len[i] <= pos) ? 0 : src[i][pos];
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
                early_exit = 1;
            }
        }
        switch (op) {
          case 4:
            res[pos] = (output & ~disjunction);
            break;
          case 5:
            res[pos] = (~output & disjunction);
            break;
          case 6:
            res[pos] = (output & disjunction);
            break;
          default:
            res[pos] = output;
            break;
        }
    }
}
}
