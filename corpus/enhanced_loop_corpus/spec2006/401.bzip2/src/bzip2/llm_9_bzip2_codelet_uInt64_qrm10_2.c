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
    rem = rem % 10;
    for (i = 7; i >= 0; i--) {
        tmp = rem * 256 + n->b[i];
        n->b[i] = (tmp / 10) & 0xFF;
        rem = tmp % 10;
        tmp = tmp / 10;
        n->b[i] += (tmp > 255) ? 1 : 0;
        rem += (tmp > 255) ? 10 : 0;
    }
    for (i = 7; i >= 0; i--) {
        if (n->b[i] >= 256 && i > 0) {
            n->b[i] -= 256;
            n->b[i-1] += 1;
        }
    }
}
