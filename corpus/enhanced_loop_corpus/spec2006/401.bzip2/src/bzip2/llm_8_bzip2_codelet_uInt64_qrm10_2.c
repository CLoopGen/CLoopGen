#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef unsigned int UInt32;

typedef int Int32;

extern UInt64 *n;
extern UInt32 rem;
extern UInt32 tmp;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i -= 2) {
        if (i >= 1) {
            tmp = rem * 65536 + n->b[i] * 256 + n->b[i-1];
            n->b[i] = tmp / 10;
            n->b[i-1] = (tmp % 10) * 256;
            rem = (tmp / 10) % 10;
        } else {
            tmp = rem * 256 + n->b[i];
            n->b[i] = tmp / 10;
            rem = tmp % 10;
        }
    }
}
