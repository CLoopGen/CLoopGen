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
    int limit = 18;
    int stride = 1;
    char found = 0;
    for (int i = 0; i < limit && !found; i++) {
        idx = i * stride;
        if (iupac[idx].sym == *str) {
            found = 1;
        }
    }
}
