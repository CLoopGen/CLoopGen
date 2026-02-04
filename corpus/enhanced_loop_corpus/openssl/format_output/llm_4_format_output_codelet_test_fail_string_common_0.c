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
    for (; i < j; i++) {
        char eq = (m1[i] == m2[i]);
        bdiff[i] = eq ? ' ' : '^';
        if (!eq) diff = 1;
    }
}
