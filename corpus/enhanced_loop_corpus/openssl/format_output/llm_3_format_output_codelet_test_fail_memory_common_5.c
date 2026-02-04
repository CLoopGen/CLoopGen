#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with pointer arithmetic instead of indexing
    // Replace array index operations with direct pointer traversal to enhance locality
    unsigned char *ptr_m1 = m1 + i;
    unsigned char *ptr_m2 = m2 + i;
    size_t idx = i;

    for (; idx < j; idx++) {
        if (*ptr_m1 == *ptr_m2) {
            *p++ = ' ';
            *p++ = ' ';
        } else {
            *p++ = '^';
            *p++ = '^';
            diff = 1;
        }
        ptr_m1++;
        ptr_m2++;

        if (idx % 8 == 7 && idx != j - 1)
            *p++ = ' ';
    }
}
