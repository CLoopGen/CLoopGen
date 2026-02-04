#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int I32;
typedef unsigned char U8;

const unsigned char PL_utf8skip[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x00 - 0x0F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x10 - 0x1F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x20 - 0x2F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x30 - 0x3F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x40 - 0x4F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x50 - 0x5F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x60 - 0x6F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x70 - 0x7F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // 0x80 - 0x8F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // 0x90 - 0x9F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // 0xA0 - 0xAF
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // 0xB0 - 0xBF
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 0xC0 - 0xCF
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 0xD0 - 0xDF
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0xE0 - 0xEF
    4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 0, 0  // 0xF0 - 0xFF
};

I32 i;
I32 len;
I32 odd;
signed char *s;

signed char *data_buffer = NULL;

void init_vars() {
    const size_t data_size = 134217728; // 128MB to target ~0.01 sec on modern CPU

    if (data_buffer) return; // Prevent reinitialization

    data_buffer = (signed char*)malloc(data_size);
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate data buffer\n");
        exit(1);
    }

    // Initialize with mixed UTF-8 and control characters
    for (size_t idx = 0; idx < data_size; idx++) {
        switch (idx % 16) {
            case 0:  data_buffer[idx] = 'A';                    break;
            case 1:  data_buffer[idx] = 'z';                    break;
            case 2:  data_buffer[idx] = '\n';                   break;
            case 3:  data_buffer[idx] = '\r';                   break;
            case 4:  data_buffer[idx] = '\b';                   break;
            case 5:  data_buffer[idx] = '\t';                   break;
            case 6:  data_buffer[idx] = '\f';                   break;
            case 7:  data_buffer[idx] = 27;                     break;
            case 8:  data_buffer[idx] = 31;                     break; // Control char
            case 9:  data_buffer[idx] = (signed char)0xC2;      break; // Start of 2-byte UTF-8
            case 10: data_buffer[idx] = (signed char)0xA9;      break; // Continuation byte
            case 11: data_buffer[idx] = (signed char)0xE2;      break; // Start of 3-byte UTF-8
            case 12: data_buffer[idx] = (signed char)0x82;       break; // Continuation
            case 13: data_buffer[idx] = (signed char)0xAC;      break; // Continuation
            case 14: data_buffer[idx] = (signed char)0xF0;      break; // Start of 4-byte UTF-8
            case 15: data_buffer[idx] = (signed char)0x9F;       break; // Continuation
        }
    }

    // Set global variables
    s = data_buffer;
    len = data_size;
    i = 0;
    odd = 0;
}