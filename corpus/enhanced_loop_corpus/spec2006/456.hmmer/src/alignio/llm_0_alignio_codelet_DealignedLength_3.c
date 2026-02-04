#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rlen = 0; *aseq; aseq++) {
        if (!((*aseq) == ' ' || (*aseq) == '.' || (*aseq) == '_' || (*aseq) == '-' || (*aseq) == '~')) {
            rlen++;
        }
    }
}
