#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int f0;
int Y0;
int Y1;
uint8_t Luma[16];
int mask;
int i;

void init_vars() {
    f0 = 0xFFFF;      
    Y0 = 42;          
    Y1 = 255;         
}