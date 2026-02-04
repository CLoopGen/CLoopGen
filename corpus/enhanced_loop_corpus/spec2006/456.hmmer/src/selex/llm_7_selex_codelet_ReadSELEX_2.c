#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = num - 1; i >= 0; i--) {
        aseqs[i][alen] = '\x00';
    }
}
