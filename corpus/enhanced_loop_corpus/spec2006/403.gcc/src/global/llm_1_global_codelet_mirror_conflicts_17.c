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
for (i = max_allocno - 1, mask = 1; i >= 0; i--, mask <<= 1) {
    if (!mask) {
        mask = 1;
        q0++;
    }
    j = allocno_row_words - 1;
    q1 = q0;
    for (; j >= 0; ) {
        unsigned long word = (unsigned long)*p++;
        q2 = q1;
        for (int sub_iter = 0; sub_iter < 1 && word; sub_iter++, word >>= 1, q2 += rw) {
            if (word & 1)
                *q2 |= mask;
        }
        j--;
        q1 += rwb;
    }
}
}
