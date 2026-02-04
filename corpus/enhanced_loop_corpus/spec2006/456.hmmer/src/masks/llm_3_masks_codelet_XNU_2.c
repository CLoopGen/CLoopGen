#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_iupac;
extern char *dsq;
extern int len;
extern int i;
extern int *hit;
extern int xnum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with pre-increment
    int *hit_ptr = hit + 1;
    char *dsq_ptr = dsq + 1;
    for (i = 1; i <= len; i++) {
        if (*(hit_ptr++)) {
            xnum++;
            *(dsq_ptr++) = Alphabet_iupac - 1;
        }
    }
}
