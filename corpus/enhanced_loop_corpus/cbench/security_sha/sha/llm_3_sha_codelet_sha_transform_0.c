#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

typedef struct {
    LONG digest[5];
    LONG count_lo;
    LONG count_hi;
    LONG data[16];
} SHA_INFO;

extern SHA_INFO *sha_info;
extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access - process array from end to beginning
    for (i = 15; i >= 0; --i) {
        W[i] = sha_info->data[i];
    }
}
