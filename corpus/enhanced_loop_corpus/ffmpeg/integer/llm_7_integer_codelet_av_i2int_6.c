#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern int i;
extern int64_t out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_out = out;
    for (i = 0; i <= 8 - 2; i++) {
        local_out = (local_out << 16) + a.v[6 - i];
    }
    out = local_out;
}
