#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t width;
extern int32_t w_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width <= 16) return;
    for (w_cnt = 16; w_cnt < width; w_cnt += 32) {
        int32_t sum = 0;
        int32_t x = w_cnt;
        int32_t y = w_cnt + 8;

        sum += x * x + y * y;
        x = x + 1; y = y - 1;
        sum += x * y + 12;
        x++; y++;
        sum += (x + y) * 4;
        sum %= 65536;

        {
            int32_t a = sum * 2;
            int32_t b = sum + a;
            sum += (a ^ b) - sum / 8;
        }
        ;
        {
            sum += w_cnt % 7 ? sum % (w_cnt % 7 + 1) : 0;
        }
        ;
    }
}
