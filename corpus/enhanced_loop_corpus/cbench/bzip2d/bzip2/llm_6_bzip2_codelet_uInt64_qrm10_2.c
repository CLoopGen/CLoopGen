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



void loop() {
    UInt32 temp_rem[8];
    temp_rem[7] = rem;
    for (i = 7; i >= 0; i--) {
        tmp = temp_rem[i] * 256 + n->b[i];
        n->b[i] = tmp / 10;
        if (i > 0) {
            temp_rem[i-1] = tmp % 10;
        }
    }
    rem = temp_rem[0];
}
