#include <stdio.h>

#include <inttypes.h>

extern int max_allocno;
extern int allocno_row_words;
extern int i;
extern int j;
extern int rw;
extern int rwb;
extern long *p;
extern long *q0;
extern long *q1;
extern long *q2;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (max_allocno >> 1) - 1, mask = 1; i >= 0; i--, mask <<= 2) {
    if (mask == 0) {
        mask = 1;
        q0 += 2;
    } else if (mask == 0x80000000UL) {
        q0++;
    }
    for (j = allocno_row_words - 1, q1 = q0; j >= 0; j--, q1 += rwb) {
        unsigned long word = (unsigned long)*p++;
        for (int k = 0; k < 2 && word; k++, q1 += rw) {
            for (int b = 0; b < 32 && word; b++, word >>= 1, q1 += rw) {
                if (word & 1)
                    *q1 |= mask;
            }
        }
    }
}
}
