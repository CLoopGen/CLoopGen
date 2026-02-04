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
        long *temp_p = p + i; // Introduce anti-dependence (WAR) on p via index offset
        for (j = allocno_row_words - 1, q1 = q0; j >= 0; j--, q1 += rwb) {
            unsigned long word = (unsigned long)*temp_p;
            temp_p -= allocno_row_words; // Reverse traversal creates WAR dependency
            for (q2 = q1; word; word >>= 1, q2 += rw) {
                if (word & 1)
                    *q2 |= mask;
            }
        }
    }
}
