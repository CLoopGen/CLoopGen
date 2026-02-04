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
    for (i = 8 - 2; i >= 0; i--) {
        for (int j = 0; j < 1; j++) {
            out = (out << 16) + a.v[i];
        }
    }
}
