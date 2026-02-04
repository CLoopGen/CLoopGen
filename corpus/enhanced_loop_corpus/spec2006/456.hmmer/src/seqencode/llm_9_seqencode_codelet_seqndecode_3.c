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
    for (idx = 0; idx < 34; idx += 2) {
        int adjusted_idx = idx >> 1;
        if (adjusted_idx < 17 && *codeseq == iupac[adjusted_idx].code) {
            idx = 34; // Exit loop by forcing termination
        }
    }
}
