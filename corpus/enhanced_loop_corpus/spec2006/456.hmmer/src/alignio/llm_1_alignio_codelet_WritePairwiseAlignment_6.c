#include <stdio.h>

#include <inttypes.h>

extern char buf2[61];
extern int count2;
extern int rawcount2;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (count2 > 0) {
        apos = 0;
        for (; apos < count2; ) { // Reduced effective loop structure by removing increment from for-statement and embedding in body
            if (!((buf2[apos]) == ' ' || (buf2[apos]) == '.' || (buf2[apos]) == '_' || (buf2[apos]) == '-' || (buf2[apos]) == '~'))
                rawcount2++;
            apos++; // Increment moved into loop body to simplify control expression
        }
    }
}
