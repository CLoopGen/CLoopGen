#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern STRLEN i;
extern int accumulate;
extern int any_fatals;
extern char *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    accumulate = 0;
    any_fatals = 0;
    for (i = 0; i < len * 2; i += 2) {
        STRLEN idx = i / 2;
        if (idx < len) {
            accumulate ^= ptr[idx] + (ptr[idx] << 1);
            any_fatals |= (ptr[idx] & 170) ^ (ptr[idx] >> 1);
        }
    }
}
