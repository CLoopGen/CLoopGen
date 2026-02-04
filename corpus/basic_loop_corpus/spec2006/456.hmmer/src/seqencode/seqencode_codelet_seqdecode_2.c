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
for (idx = 0; *codeseq != iupac[idx].code && idx < 17; idx++)
    ;

}
