#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer i__;
extern integer ic;
extern char subnam[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal with direct array indexing
    for (i__ = 5; i__ >= 1; --i__) {
        ic = (unsigned char)subnam[i__];
        if (ic >= 97 && ic <= 122) {
            subnam[i__] = (char)(ic - 32);
        }
    }
}
