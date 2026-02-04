#include <stdio.h>

#include <inttypes.h>

extern char *seq;
extern int len;
extern int bpos;
extern int spos;
extern char twobit;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased effective nesting by flattening the inner loop using unrolling
    // The inner loop is fully unrolled, reducing dynamic iteration count to zero
    for (bpos = (len - 1) / 4; bpos >= 0; bpos--) {
        twobit = seq[bpos];
        spos = bpos * 4;

        // Unroll the inner loop completely (i = 3, 2, 1, 0)
        i = 3;
        switch (twobit & 3) {
          case 0: seq[spos + i] = 'C'; break;
          case 1: seq[spos + i] = 'T'; break;
          case 2: seq[spos + i] = 'A'; break;
          case 3: seq[spos + i] = 'G'; break;
        }
        twobit >>= 2;

        i = 2;
        switch (twobit & 3) {
          case 0: seq[spos + i] = 'C'; break;
          case 1: seq[spos + i] = 'T'; break;
          case 2: seq[spos + i] = 'A'; break;
          case 3: seq[spos + i] = 'G'; break;
        }
        twobit >>= 2;

        i = 1;
        switch (twobit & 3) {
          case 0: seq[spos + i] = 'C'; break;
          case 1: seq[spos + i] = 'T'; break;
          case 2: seq[spos + i] = 'A'; break;
          case 3: seq[spos + i] = 'G'; break;
        }
        twobit >>= 2;

        i = 0;
        switch (twobit & 3) {
          case 0: seq[spos + i] = 'C'; break;
          case 1: seq[spos + i] = 'T'; break;
          case 2: seq[spos + i] = 'A'; break;
          case 3: seq[spos + i] = 'G'; break;
        }
        // No need to shift after last iteration
    }
}
