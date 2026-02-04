#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 items;
extern I32 len;
extern int aint;
extern char *aptr;
extern char *str;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    I32 local_items = 0;
    I32 even_phase = 0;
    for (len = 0; len++ < aint;) {
        char c = *str++;
        I32 shifted_value = 0;
        if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            shifted_value = (((c & 15) + 9) & 15) << 4;
        } else {
            shifted_value = (c & 15) << 4;
        }
        local_items |= shifted_value;
        even_phase = len & 1;
        if (!even_phase) {
            aptr[(len >> 1) - 1] = local_items & 255;
            local_items = 0;
        }
    }
    if ((aint & 1) == 0) {
        items = 0;
    } else {
        items = local_items; // Introduce loop-carried dependency: final value depends on all iterations
    }
}
