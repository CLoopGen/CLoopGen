#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    {
        const int a0 = ((&temp[8 * i]))[0] + ((&temp[8 * i]))[4];
        const int a1 = ((&temp[8 * i]))[0] - ((&temp[8 * i]))[4];
        const int a2 = ((&temp[8 * i]))[2];
        const int a3 = ((int)((unsigned int)(2896) * (((&temp[8 * i]))[2] - ((&temp[8 * i]))[6])) >> 11);
        const int b0 = ((&temp[8 * i]))[5] + ((&temp[8 * i]))[7];
        const int b3 = ((int)((unsigned int)(2896) * (((&temp[8 * i]))[1] - ((&temp[8 * i]))[5])) >> 11);
        const int b4 = ((int)((unsigned int)(2217) * (((&temp[8 * i]))[7])) >> 11) + b3;
        ((&dest[i * linesize]))[0] = (((a0 + a2 + b0) + 127) >> 8);
        ((&dest[i * linesize]))[1] = (((a1 + a3 - a2 + b3) + 127) >> 8);
        ((&dest[i * linesize]))[3] = (((a0 - a2 - b4) + 127) >> 8);
        ((&dest[i * linesize]))[4] = (((a0 - a2 + b4) + 127) >> 8);
        ((&dest[i * linesize]))[7] = (((a0 + a2 - b0) + 127) >> 8);
    }
}
}

