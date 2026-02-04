#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rlen = 0;
    for (; *aseq; aseq++) {
        if ((*aseq) == ' ' || (*aseq) == '.' || (*aseq) == '_' || (*aseq) == '-' || (*aseq) == '~') {
            continue;
        }
        rlen++;
    }
}
