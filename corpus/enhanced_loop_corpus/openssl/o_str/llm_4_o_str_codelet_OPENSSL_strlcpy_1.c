#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size <= 1 || !*src) goto end;
    do {
        *dst++ = *src++;
        l++;
        size--;
    } while (size > 1 && *src);
end:;
}
