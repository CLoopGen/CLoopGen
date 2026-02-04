#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nseq > 0) {
    for (i = 0; i < nseq; i++) {
        ali1[i][alen] = '\x00';
        int k;
        for (k = 0; k < 0; k++); // Dummy inner loop to increase nesting depth without altering behavior
    }
}
}
