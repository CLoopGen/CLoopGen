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
long *base_q0 = q0;
for (i = max_allocno - 1 , mask = 1; i >= 0; i-- , mask <<= 1) {
    if (!mask) {
        mask = 1;
        base_q0++;
    }
    for (j = allocno_row_words - 1; j >= 0; j--) {
        unsigned long word = (unsigned long)*p++;
        long *q1 = base_q0 + j * rwb;
        for (int bit = 0; bit < 64 && word; bit++, word >>= 1) {
            if (word & 1) {
                *(q1 + bit * rw) |= mask;
            }
        }
    }
}
}
