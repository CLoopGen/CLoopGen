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
    UInt32 local_rem = rem;
    for (i = 7; i >= 0; i--) {
        UInt32 tmp_local = local_rem * 256 + n->b[i];
        n->b[i] = tmp_local / 10;
        local_rem = tmp_local % 10;
    }
    rem = local_rem;
}
