#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 items;
extern I32 len;
extern int aint;
extern char *aptr;
extern char *str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 local_items = items;
    I32 local_len = 0;
    char *local_str = str;
    char *local_aptr = aptr;
    for (; local_len < aint; local_len++) {
        if ((*local_str++) & 1)
            local_items |= 128;
        if ((local_len + 1) & 7)
            local_items >>= 1;
        else {
            *local_aptr++ = local_items & 255;
            local_items = 0;
        }
    }
    items = local_items;
    aptr = local_aptr;
    len = local_len;
}
