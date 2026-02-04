#include <stdio.h>

#include <inttypes.h>

extern unsigned long value;
extern size_t i;
extern unsigned long ret;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < sizeof (value) * 8; i++) {
    ret += (value != 0);
    value >>= 1;
}

}
