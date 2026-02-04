#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern size_t mtop;
extern unsigned long carry;
extern unsigned long *rp;
extern unsigned long *tp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < 2; j++) {
        for (i = 0; i < mtop; i++) {
            rp[i] = (carry & tp[i]) | (~carry & rp[i]);
            ((volatile unsigned long *)tp)[i] = 0;
        }
    }
}
