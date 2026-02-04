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
    idx = 0;
    char found = 0;
    for (int i = 0; i < 17 && !found; i++) {
        idx = i;
        found = (iupac[i].code == *codeseq);
    }
}
