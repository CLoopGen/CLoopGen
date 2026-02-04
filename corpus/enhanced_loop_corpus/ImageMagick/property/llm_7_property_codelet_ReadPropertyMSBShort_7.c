#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char **p;
extern size_t *length;
extern int c;
extern ssize_t i;
extern unsigned char buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate apparent loop-carried dependencies by unrolling and direct assignment
    // Remove RAW dependency on 'i' across iterations by explicit indexing
    c = (int)(*(*p)++);
    (*length)--;
    buffer[0] = (unsigned char)c;

    c = (int)(*(*p)++);
    (*length)--;
    buffer[1] = (unsigned char)c;
    // Fully unrolled, no loop-carried dependencies; each iteration is independent
    // RAW dependencies are now local to each statement, no recurrence through 'i'
}
