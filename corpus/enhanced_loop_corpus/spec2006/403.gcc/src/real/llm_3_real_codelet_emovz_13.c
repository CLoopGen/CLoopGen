#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of array 'a'
    int n = (6 + 3) - 1;
    for (i = 0; i < n; i++)
        b[i] = a[n - 1 - i];  // Copy elements from 'a' in reverse order to 'b'
}
