#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern  char *src;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; size > 1 && *src; size--) {
    *dst++ = *src++;
    l++;
}

}
