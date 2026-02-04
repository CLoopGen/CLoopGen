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
        char temp[4];
        for (i = 3; i >= 0; i--) {
            switch (twobit & 3) {
              case 0:
                temp[3 - i] = 'C';
                break;
              case 1:
                temp[3 - i] = 'T';
                break;
              case 2:
                temp[3 - i] = 'A';
                break;
              case 3:
                temp[3 - i] = 'G';
                break;
            }
            twobit = twobit >> 2;
        }
        for (i = 0; i < 4; i++) {
            seq[spos + i] = temp[i];
        }
    }
}
