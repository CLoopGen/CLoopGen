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
for (i = 0; i < 257; i++) {
    int v;
    v = ff_mpa_enwindow[i];
    window[i] = v;
    if ((i & 63) != 0)
        v = -v;
    if (i != 0)
        window[512 - i] = v;
}

}
