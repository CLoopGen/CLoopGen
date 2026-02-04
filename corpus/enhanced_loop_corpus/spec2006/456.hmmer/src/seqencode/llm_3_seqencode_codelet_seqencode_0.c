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
    // Variant 2: Indirect array access using an index mapping table (simulates irregular access pattern)
    static const int index_map[] = {0,2,4,6,8,10,12,14,16,1,3,5,7,9,11,13,15,17}; // even indices first, then odd
    for (idx = 0; idx < 18; idx++) {
        int mapped_idx = index_map[idx];
        if (*str == iupac[mapped_idx].sym)
            break;
    }
    // Remap final index to original ordering
    idx = index_map[idx]; // now idx refers to the correct position in original iupac[]
}
