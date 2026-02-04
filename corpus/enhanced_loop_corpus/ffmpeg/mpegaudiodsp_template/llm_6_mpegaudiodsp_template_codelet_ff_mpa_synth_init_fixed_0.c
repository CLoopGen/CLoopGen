#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern const int32_t ff_mpa_enwindow[257];
extern MPA_INT *window;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    MPA_INT temp[513]; // Local buffer to reorganize write operations
    for (i = 0; i < 257; i++) {
        int v = ff_mpa_enwindow[i];
        temp[i] = v;
        if ((i & 63) != 0)
            v = -v;
        if (i != 0)
            temp[512 - i] = v;
    }
    // Eliminate loop-carried dependence by separating read/write from final store
    for (i = 0; i < 513; i++) {
        if (i < 257)
            window[i] = temp[i];
        if (i > 0 && i <= 512 && i >= 256)
            window[i] = temp[i];
    }
}
