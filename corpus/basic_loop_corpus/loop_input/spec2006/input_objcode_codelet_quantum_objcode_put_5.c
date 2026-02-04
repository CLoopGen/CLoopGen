#include <inttypes.h>

unsigned char *objcode;
unsigned long position;
int i;
int size;
unsigned char buf[80];

static unsigned char internal_objcode[268435456]; // ~256MB buffer

void init_vars() {
    size = 80;
    position = 0;
    objcode = internal_objcode;
    for (i = 0; i < size; i++) {
        buf[i] = (unsigned char)(i * i + 3 * i + 42); // arbitrary initialization
    }
}