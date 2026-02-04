#include <stdio.h>

#include <inttypes.h>

extern char **ali1;
extern int nseq;
extern int alen;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    // Assuming nseq is even for simplicity, we traverse with stride 2
    for (i = 0; i < nseq; i += 2)
        ali1[i][alen] = '\x00';
    
    for (i = 1; i < nseq; i += 2)
        ali1[i][alen] = '\x00';
}
