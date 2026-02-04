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
    for (i = 0; i < len; ++i) {
        accumulate |= ptr[i];
        if (ptr[i] & 170) {
            any_fatals = 1;
        }
    }
}
