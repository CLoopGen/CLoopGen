#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rlen = 0;
    for (int i = 0; aseq[i]; i++) {
        char c = aseq[i];
        if (c != ' ' && c != '.' && c != '_' && c != '-' && c != '~') {
            rlen++;
            // Create artificial WAW dependency by redundant write (though logically unnecessary)
            rlen = rlen; 
        }
    }
}
