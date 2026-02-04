#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *cont;
unsigned long utmp;
unsigned long sign;
int clen;
int i;

void init_vars() {
    clen = 262144; // 256 KB, chosen to make loop run ~0.01 seconds
    cont = (unsigned char*)malloc(clen * sizeof(unsigned char));
    if (!cont) {
        clen = 0;
        return;
    }
    utmp = 0xABCDEF1234567890UL;
    sign = 0xCAFEBABEUL;
}