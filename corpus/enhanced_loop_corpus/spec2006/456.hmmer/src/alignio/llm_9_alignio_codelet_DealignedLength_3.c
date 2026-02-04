#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rlen = 0;
    int i;
    for (i = 0; aseq[i] && aseq[i+1]; i += 2) { // Process two characters per iteration
        char c1 = aseq[i];
        char c2 = aseq[i+1];
        int inc1 = !(c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~');
        int inc2 = !(c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~');
        rlen += inc1 + inc2;
    }
    // Handle last character if string length is odd
    if (aseq[i] && !((aseq[i]) == ' ' || (aseq[i]) == '.' || (aseq[i]) == '_' || (aseq[i]) == '-' || (aseq[i]) == '~'))
        rlen++;
}
