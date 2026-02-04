#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    uchar *in_local = in;
    uchar *midp_local = midp;
    int total_size = x_size * y_size;
    
    // Process two elements per iteration for consecutive access pattern
    for (i = 0; i < total_size - 1; i += 2) {
        if (*midp_local < 8)
            *(in_local + (midp_local - mid)) = 0;
        midp_local++;
        
        if (*midp_local < 8)
            *(in_local + (midp_local - mid)) = 0;
        midp_local++;
    }
    
    // Handle remaining element if total size is odd
    if (i < total_size) {
        if (*midp_local < 8)
            *(in_local + (midp_local - mid)) = 0;
        midp_local++;
    }
}
