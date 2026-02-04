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
    i = 3;
    while (i >= 0) {
        switch (twobit & 3) {
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
        twobit >>= 2;
        i--;
    }
}
}
