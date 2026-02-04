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
    idx = 0;
    char target = *str;
    for (; idx <= 17 && iupac[idx].sym != target; idx += 2) {
        if (idx + 1 <= 17 && iupac[idx + 1].sym == target) {
            idx++;
            break;
        }
    }
}
