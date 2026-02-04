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
    for (idx = 0; idx < 17; idx += 2) {
        if (*codeseq == iupac[idx].code) break;
        if (idx + 1 < 17 && *codeseq == iupac[idx + 1].code) {
            idx++;
            break;
        }
    }
    if (idx >= 17) idx = 16;
}
