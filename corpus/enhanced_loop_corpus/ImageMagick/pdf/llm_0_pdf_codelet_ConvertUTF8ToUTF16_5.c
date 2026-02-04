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
    for (ssize_t j = 0; j <= (ssize_t)*length; j++) {
        for (i = j; i <= j; i++) {
            utf16[i] = source[i];
        }
    }
}
