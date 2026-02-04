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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            accumulate |= (ptr[i] | ptr[i+1]);
            any_fatals |= ((ptr[i] & 170) | (ptr[i+1] & 170));
        } else {
            accumulate |= ptr[i];
            any_fatals |= (ptr[i] & 170);
        }
    }
}
