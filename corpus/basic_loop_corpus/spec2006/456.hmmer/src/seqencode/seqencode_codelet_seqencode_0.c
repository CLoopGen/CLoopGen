#include <stdio.h>

#include <inttypes.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};


extern struct iupactype iupac[];
extern char *str;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (idx = 0; *str != iupac[idx].sym && idx <= 17; idx++)
    ;

}
