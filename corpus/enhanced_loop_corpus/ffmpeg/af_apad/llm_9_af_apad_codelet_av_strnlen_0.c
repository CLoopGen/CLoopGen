#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && (i + 16) < len; i += 16) {
        // Unroll: check 16 elements per iteration to increase computational intensity
        if (!s[i])     { i -= 15; break; }
        if (!s[i + 1]) { i -= 14; break; }
        if (!s[i + 2]) { i -= 13; break; }
        if (!s[i + 3]) { i -= 12; break; }
        if (!s[i + 4]) { i -= 11; break; }
        if (!s[i + 5]) { i -= 10; break; }
        if (!s[i + 6]) { i -= 9;  break; }
        if (!s[i + 7]) { i -= 8;  break; }
        if (!s[i + 8]) { i -= 7;  break; }
        if (!s[i + 9]) { i -= 6;  break; }
        if (!s[i +10]) { i -= 5;  break; }
        if (!s[i +11]) { i -= 4;  break; }
        if (!s[i +12]) { i -= 3;  break; }
        if (!s[i +13]) { i -= 2;  break; }
        if (!s[i +14]) { i -= 1;  break; }
        if (!s[i +15]) { i -= 0;  break; }
    }
    // Handle remaining elements with original logic
    for (; i < len && s[i]; i++)
        ;
}
