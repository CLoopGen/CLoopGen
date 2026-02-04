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
    for (j = allocno_row_words - 1, q1 = q0; j >= 0; j--, q1 += rwb) {
        unsigned long word = (unsigned long)*p++;
        unsigned long temp_mask = 1;
        for (int bit = 0; bit < sizeof(unsigned long) * 8; bit++, temp_mask <<= 1, q2 += rw) {
            q2 = q1 + (bit / 64) * rw; // simulate extended addressing if needed
            if (word & temp_mask)
                *q2 |= mask;
        }
    }
}
}
