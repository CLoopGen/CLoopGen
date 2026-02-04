#include <stdio.h>

#include <inttypes.h>

extern char **aseqs;
extern int num;
extern int seqidx;
extern int alen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < num; i++)
    for (int j = 0; j <= alen; j++)
        if (j == alen)
            aseqs[i][j] = '\x00';
}
