#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of array 'a'
    for (i = 5; i >= 0; i--) {
        *b++ = a[i];  // Copy elements from 'a' in reverse order
    }
}
