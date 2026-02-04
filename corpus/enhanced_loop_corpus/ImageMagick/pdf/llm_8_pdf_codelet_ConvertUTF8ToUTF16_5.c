#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *source;
extern size_t *length;
extern wchar_t *utf16;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (i = 0; i <= (ssize_t)*length; i += 2) {
        utf16[i] = source[i];
        j = i + 1;
        if (j <= (ssize_t)*length) {
            utf16[j] = source[j];
        }
    }
}
