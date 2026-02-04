#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *s;
extern int k;
extern word msr;
extern longword ltmp;
extern word tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[160];
    for (int i = 0; i < 160; i++) {
        indices[i] = i * 4; // Strided index pattern
    }
    for (k = 0; k < 160; k++) {
        word* access_ptr = s + indices[k]; // Indirect, strided memory access
        tmp = (((((longword)(msr) * (longword)(28180) + 16384)) >> (15)));
        msr = ((ulongword)((ltmp = (longword)(*access_ptr) + (longword)(tmp)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        *access_ptr = ((ulongword)((ltmp = (longword)(msr) + (longword)(msr)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp) & 65528;
    }
}
