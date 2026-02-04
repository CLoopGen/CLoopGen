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
    // Variant 1: Increased loop nesting depth by splitting the inner loop logic into two levels
    // The original inner loop is now split: one loop handles bit extraction, another handles mapping
    for (bpos = (len - 1) / 4; bpos >= 0; bpos--) {
        twobit = seq[bpos];
        spos = bpos * 4;
        // First inner loop: extract bits and store in a temporary array
        char temp[4];
        for (i = 0; i < 4; i++) {
            temp[i] = twobit & 3;
            twobit = twobit >> 2;
        }
        // Second inner loop: map each value to corresponding character
        for (i = 3; i >= 0; i--) {
            switch (temp[3 - i]) {
              case 0:
                seq[spos + i] = 'C';
                break;
              case 1:
                seq[spos + i] = 'T';
                break;
              case 2:
                seq[spos + i] = 'A';
                break;
              case 3:
                seq[spos + i] = 'G';
                break;
            }
        }
    }
}
