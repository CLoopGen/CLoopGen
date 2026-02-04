#include <stdint.h>
#include <stdlib.h>

int f1;
int Y0;
int Y1;
uint8_t Luma[16];
int mask;
int i;

void init_vars() {
    f1 = 0xFF;        
    Y0 = 0x55;        
    Y1 = 0xAA;        
    mask = 128;       
    i = 8;            
}