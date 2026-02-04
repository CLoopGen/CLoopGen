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
    for (bpos = (len - 1) / 4; bpos >= 0; bpos--) {
        twobit = seq[bpos];
        spos = bpos * 4;
        // Eliminate loop-carried dependency on loop index `i` by unrolling
        // This introduces WAW independence and removes inner loop control dependency
        switch (twobit & 3) {
          case 0: seq[spos + 3] = 'C'; break;
          case 1: seq[spos + 3] = 'T'; break;
          case 2: seq[spos + 3] = 'A'; break;
          case 3: seq[spos + 3] = 'G'; break;
        }
        twobit >>= 2;

        switch (twobit & 3) {
          case 0: seq[spos + 2] = 'C'; break;
          case 1: seq[spos + 2] = 'T'; break;
          case 2: seq[spos + 2] = 'A'; break;
          case 3: seq[spos + 2] = 'G'; break;
        }
        twobit >>= 2;

        switch (twobit & 3) {
          case 0: seq[spos + 1] = 'C'; break;
          case 1: seq[spos + 1] = 'T'; break;
          case 2: seq[spos + 1] = 'A'; break;
          case 3: seq[spos + 1] = 'G'; break;
        }
        twobit >>= 2;

        switch (twobit & 3) {
          case 0: seq[spos + 0] = 'C'; break;
          case 1: seq[spos + 0] = 'T'; break;
          case 2: seq[spos + 0] = 'A'; break;
          case 3: seq[spos + 0] = 'G'; break;
        }
    }
}
