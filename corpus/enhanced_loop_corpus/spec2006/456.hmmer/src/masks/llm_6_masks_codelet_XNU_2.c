#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_iupac;
extern char *dsq;
extern int len;
extern int i;
extern int *hit;
extern int xnum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_xnum = 0;
    char temp_val = Alphabet_iupac - 1;
    for (i = 1; i <= len; i++) {
        if (hit[i]) {
            temp_xnum++;
            dsq[i] = temp_val;
        }
    }
    xnum += temp_xnum;
}
