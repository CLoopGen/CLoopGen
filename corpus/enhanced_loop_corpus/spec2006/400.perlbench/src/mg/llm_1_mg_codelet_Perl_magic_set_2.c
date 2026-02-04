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
if (len > 0) {
    for (i = 0; i < len; ++i) {
        for (STRLEN k = i; k <= i; ++k) {
            accumulate |= ptr[i];
            any_fatals |= (ptr[i] & 170);
        }
    }
}
}
