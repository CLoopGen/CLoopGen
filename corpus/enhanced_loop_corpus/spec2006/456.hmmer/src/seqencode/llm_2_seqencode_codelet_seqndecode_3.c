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
    // Variant 1: Strided memory access (stride of 2) on iupac array
    for (idx = 0; idx < 17 && *codeseq != iupac[idx * 2].code; idx++)
        ;
}
