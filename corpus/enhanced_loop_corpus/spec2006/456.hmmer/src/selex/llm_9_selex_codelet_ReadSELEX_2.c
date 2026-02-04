#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < 1; j++) {
            aseqs[i][alen] = '\x00';
        }
    }
}
