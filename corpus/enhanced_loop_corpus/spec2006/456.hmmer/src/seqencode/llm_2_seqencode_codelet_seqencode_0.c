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
    // Variant 1: Strided memory access (access every 2nd element initially, then adjust)
    int stride = 2;
    for (idx = 0; idx <= 17; idx += stride) {
        if (*str == iupac[idx].sym)
            break;
    }
    // Handle case where we might have skipped the match due to stride
    if (idx > 17 || *str != iupac[idx].sym) {
        idx = (idx == 18) ? 17 : idx - 1; // step back to check odd index
        for (; idx <= 17; idx++) {
            if (*str == iupac[idx].sym)
                break;
        }
    }
}
