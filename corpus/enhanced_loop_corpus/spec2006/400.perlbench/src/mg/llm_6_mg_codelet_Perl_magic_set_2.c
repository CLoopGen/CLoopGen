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
    STRLEN j;
    for (j = 0; j < len; ++j) {
        int val = ptr[j];
        accumulate |= val;
        any_fatals |= (val & 170);
    }
}
