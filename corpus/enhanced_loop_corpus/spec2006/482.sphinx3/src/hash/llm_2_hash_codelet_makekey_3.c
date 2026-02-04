#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uint8;

typedef int int32;

extern uint8 *data;
extern int32 len;
extern char *key;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Reversed Traversal
    // Instead of forward strided write to 'key', traverse 'data' backwards and write consecutively to 'key'
    // This changes access pattern to reverse sequential on input and simple sequential on output.
    int32 idx = 0;
    for (i = len - 1; i >= 0; i--, idx += 2) {
        key[idx]     = 'A' + (data[i] & 15);
        key[idx + 1] = 'J' + ((data[i] >> 4) & 15);
    }
}
