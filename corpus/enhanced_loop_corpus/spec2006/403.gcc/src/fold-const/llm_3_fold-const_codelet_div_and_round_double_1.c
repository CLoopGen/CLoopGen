#include <stdio.h>

#include <inttypes.h>

extern long num[5];
extern long quo[4];
extern int i;
extern unsigned long work;
extern unsigned long carry;
extern unsigned long lden;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (reverse order traversal via lookup)
    int index_map[4] = {3, 2, 1, 0};  // Reverse mapping
    for (i = 0; i < 4; i++) {
        int mapped_idx = index_map[i];
        work = num[mapped_idx] + carry * ((unsigned long)1 << (8 * 8) / 2);
        quo[mapped_idx] = work / lden;
        carry = work % lden;
    }
}
