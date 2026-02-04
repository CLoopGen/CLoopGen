#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char basis_64[];
extern char *str;
extern ssize_t len;
extern char *eol;
extern STRLEN eollen;
extern char *r;
extern unsigned char c1;
extern unsigned char c2;
extern unsigned char c3;
extern int chunk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increased computational intensity with unrolled inner operations and reduced control flow
    int remaining = len;
    len = 0; // Temporarily zero to prevent outer interference

    for (chunk = 0; remaining > 0; ) {
        if (chunk == (76 / 4)) {
            for (int i = 0; i < eollen; i++)
                *r++ = eol[i];
            chunk = 0;
        }

        // Unroll processing: handle up to 3 bytes with fully expanded logic and extra arithmetic masking
        unsigned char data[3] = {0};
        int fetch = (remaining >= 3) ? 3 : remaining;

        data[0] = *str++;
        if (fetch > 1) data[1] = *str++;
        if (fetch > 2) data[2] = *str++;

        // Heavier arithmetic: split shifts and mask across multiple steps
        uint8_t part1_low = data[0] & 0x03;
        uint8_t part2_high = data[1] & 0xF0;
        uint8_t part2_low = data[1] & 0x0F;
        uint8_t part3_high = data[2] & 0xC0;

        *r++ = basis_64[data[0] >> 2];
        *r++ = basis_64[(part1_low << 4) | (part2_high >> 4)];

        if (fetch == 3) {
            *r++ = basis_64[(part2_low << 2) | (part3_high >> 6)];
            *r++ = basis_64[data[2] & 0x3F];
        } else if (fetch == 2) {
            *r++ = basis_64[part2_low << 2];
            *r++ = '=';
        } else {
            *r++ = '=';
            *r++ = '=';
        }

        remaining -= fetch;
        chunk++;
    }
}
