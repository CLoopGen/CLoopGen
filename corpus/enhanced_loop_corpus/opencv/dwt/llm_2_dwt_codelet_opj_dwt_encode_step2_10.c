#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_FLOAT32 *fw;
extern OPJ_FLOAT32 c;
extern OPJ_UINT32 i;
extern OPJ_UINT32 imax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_FLOAT32 *fw_local = fw;
    for (; i + 3 < imax; i += 4) {
        OPJ_FLOAT32 temp0 = (fw_local[-2] + fw_local[0]) * c;
        OPJ_FLOAT32 temp1 = (fw_local[0] + fw_local[2]) * c;
        OPJ_FLOAT32 temp2 = (fw_local[2] + fw_local[4]) * c;
        OPJ_FLOAT32 temp3 = (fw_local[4] + fw_local[6]) * c;
        
        fw_local[-1] += temp0;
        fw_local[1]  += temp1;
        fw_local[3]  += temp2;
        fw_local[5]  += temp3;
        
        fw_local += 8;
    }
    fw = fw_local;
}
