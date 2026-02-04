#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern U8 *s;
extern U8 *win32_send;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    U8 temp[64];
    size_t offset = 0;
    size_t chunk_size = sizeof(temp);

    for (; s + chunk_size <= win32_send; s += chunk_size) {
        for (size_t i = 0; i < chunk_size; i++) {
            U8 val = s[i];
            temp[i] = (val >= 'a' && val <= 'z') ? val - ('a' - 'A') : val;
        }
        for (size_t i = 0; i < chunk_size; i++) {
            s[i] = temp[i];
        }
    }

    for (; s < win32_send; s++) {
        *s = (*s >= 'a' && *s <= 'z') ? *s - ('a' - 'A') : *s;
    }
}
