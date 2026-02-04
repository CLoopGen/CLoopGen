#include <stdio.h>

#include <inttypes.h>

extern unsigned char *data;
extern uint64_t value;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *ptr = data + len - 1;
    uint64_t val = value;
    for (size_t i = 0; i < len; i++) {
        *(ptr - i) = (unsigned char)(val & 255);
        val >>= 8;
    }
    data = ptr - len + 1;
}
