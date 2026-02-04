#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char **temp_ali1 = ali1;
    int temp_alen = alen;
    for (i = 0; i < nseq; i++) {
        temp_ali1[i][temp_alen] = '\x00';
    }
}
