#include <stdio.h>

#include <inttypes.h>

extern  char *m1;
extern  char *m2;
extern char bdiff[81];
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t k = 0; k < j; k++) {
        i = k;
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
    }
}
