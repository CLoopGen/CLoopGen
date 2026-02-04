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
    // Variant 2: Indirect access via index remapping using a separate lookup table
    static const int8_t remap[] = {0,2,4,6,8,10,12,14,1,3,5,7,9,11,13,15,16};
    for (idx = 0; idx < 17 && *codeseq != iupac[remap[idx]].code; idx++)
        ;
}
