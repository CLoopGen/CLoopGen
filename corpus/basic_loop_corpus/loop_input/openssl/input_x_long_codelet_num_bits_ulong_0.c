#include <stdio.h>
#include <inttypes.h>
#include <string.h>

unsigned long value;
size_t i;
unsigned long ret;

void init_vars() {
    value = 0xABCDEF1234567890UL;
    i = 0;
    ret = 0;
}