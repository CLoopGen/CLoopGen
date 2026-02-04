#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT local_out[1024]; // Local accumulation to break WAW and RAW dependencies
    if (n4 > 1024) return; // Prevent buffer overflow, assume reasonable n4

    for (i = 0; i < n4; i++) {
        int64_t sum = 0;
        sum += (int64_t)(buf[i + n2]) * window[i + n - n4];
        sum += (int64_t)(-saved[n2 - 1 - i]) * window[i + 2 * n - n4];
        sum += (int64_t)(-saved[n + n2 + i]) * window[i + 3 * n - n4];
        local_out[i] = (int)((sum + 1073741824) >> 31); // Combined shift after sum
    }

    // Final write with reduced dependencies (no per-element read of out)
    for (i = 0; i < n4; i++) {
        out[n2 + n4 + i] = local_out[i];
    }
}
