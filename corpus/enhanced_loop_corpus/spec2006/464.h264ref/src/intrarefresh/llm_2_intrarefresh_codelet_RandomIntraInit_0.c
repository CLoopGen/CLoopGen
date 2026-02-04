#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, write to every 2nd element first, then handle the rest if needed.
    // For simplicity and full coverage, we use a stride of 1 but reverse the order (backward traversal).
    for (i = NumberOfMBs - 1; i >= 0; i--)
        RefreshPattern[i] = -1;
}
