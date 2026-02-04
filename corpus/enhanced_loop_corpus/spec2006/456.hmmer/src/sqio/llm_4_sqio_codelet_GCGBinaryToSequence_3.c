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
    for (i = 3; i >= 0; i--) {
        if ((twobit & 3) == 0) {
            seq[spos + i] = 'C';
        } else if ((twobit & 3) == 1) {
            seq[spos + i] = 'T';
        } else if ((twobit & 3) == 2) {
            seq[spos + i] = 'A';
        } else if ((twobit & 3) == 3) {
            seq[spos + i] = 'G';
        }
        twobit = twobit >> 2;
    }
}
}
