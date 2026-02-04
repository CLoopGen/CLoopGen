#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size; i++) {
    buf[i] = j / (1 << ((size - i - 1) * 8));
    j %= (1 << ((size - i - 1) * 8));
}

}
