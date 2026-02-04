#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 6 - 1; i >= 0; --i) {
    raxKey[i] = (unsigned char)(bucketKey & 255);
    bucketKey >>= 8;
}

}
