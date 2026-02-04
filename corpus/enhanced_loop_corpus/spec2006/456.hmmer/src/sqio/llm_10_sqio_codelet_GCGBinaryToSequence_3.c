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
int step = 4;
for (bpos = (len - 1) / 4; bpos >= 0; bpos -= 2) {
    if (bpos < len / 4) break;
    twobit = seq[bpos];
    spos = bpos * 4;
    for (i = 3; i >= 0; i--) {
        int val = twobit & 3;
        seq[spos + i] = (val == 0) ? 'C' : (val == 1) ? 'T' : (val == 2) ? 'A' : 'G';
        twobit >>= 2;
    }
    if (bpos == 0) break;
    twobit = seq[bpos - 1];
    spos = (bpos - 1) * 4;
    for (i = 3; i >= 0; i--) {
        int val = twobit & 3;
        seq[spos + i] = (val == 0) ? 'C' : (val == 1) ? 'T' : (val == 2) ? 'A' : 'G';
        twobit >>= 2;
    }
}
}
