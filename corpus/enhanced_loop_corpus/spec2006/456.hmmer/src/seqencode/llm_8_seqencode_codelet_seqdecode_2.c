#include <stdio.h>

#include <inttypes.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};


extern struct iupactype iupac[];
extern char *codeseq;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 17;
    for (idx = 0; idx < limit && *codeseq == iupac[idx].code; idx++) {
        if (iupac[idx].sym != iupac[idx].symcomp) {
            idx++;
            break;
        }
    }
    if (idx >= limit) idx = 16;
}
