#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM workspace[16];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - simulate strided reads by accessing every other row
    // and interleaving computation across two rows at a time (unrolled-like pattern)
    int next_ctr;
    JSAMPROW curr_elem, next_elem;
    DCTELEM *curr_dataptr = dataptr;
    
    for (;;) {
        curr_elem = sample_data[ctr] + start_col;
        next_ctr = ctr + 1;
        if (next_ctr >= 10) next_ctr = ctr; // Avoid overflow, repeat current if out of bounds
        
        next_elem = sample_data[next_ctr] + start_col;

        // Use alternating elements from current and next row to create strided access
        tmp0 = ((int)(curr_elem[0])) + ((int)(next_elem[4]));  // Mix rows
        tmp1 = ((int)(curr_elem[1])) + ((int)(next_elem[3]));
        tmp2 = ((int)(curr_elem[2]));
        
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        
        tmp0 = ((int)(curr_elem[0])) - ((int)(next_elem[4]));
        tmp1 = ((int)(curr_elem[1])) - ((int)(next_elem[3]));
        
        curr_dataptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << 2);
        
        tmp11 = ((tmp11) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        tmp10 -= tmp2 << 2;
        tmp10 = ((tmp10) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
        
        curr_dataptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        curr_dataptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        tmp10 = ((tmp0 + tmp1) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        curr_dataptr[1] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        curr_dataptr[3] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        ctr++;
        if (ctr != 8) {
            if (ctr == 10)
                break;
            curr_dataptr += 8;
        } else
            curr_dataptr = workspace;
    }
}
