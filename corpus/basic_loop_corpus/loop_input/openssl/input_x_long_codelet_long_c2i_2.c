#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *cont;
int len = 524288; // ~512KB data size for ~0.01 sec runtime estimate
int i;
unsigned long utmp;
unsigned long sign = 0xABCDEF00UL;

void init_vars() {
    cont = (unsigned char *)malloc(len);
    if (!cont) {
        exit(1);
    }
    for (int j = 0; j < len; j++) {
        cont[j] = (unsigned char)(j & 0xFF);
    }
}