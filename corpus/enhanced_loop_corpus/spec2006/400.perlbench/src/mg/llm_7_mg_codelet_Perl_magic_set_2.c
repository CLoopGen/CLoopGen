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
    STRLEN step = 2;
    STRLEN limit = (len + step - 1) / step;
    for (i = 0; i < limit; ++i) {
        STRLEN idx1 = i * step;
        STRLEN idx2 = idx1 + 1;
        int val1 = 0, val2 = 0;
        val1 = (idx1 < len) ? ptr[idx1] : 0;
        accumulate |= val1;
        any_fatals |= (val1 & 170);
        if (idx2 < len) {
            val2 = ptr[idx2];
            accumulate |= val2;
            any_fatals |= (val2 & 170);
        }
    }
}
