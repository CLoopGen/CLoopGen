#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t width;
extern int32_t w_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (w_cnt = 16; w_cnt < width; w_cnt += 8) {
    {
        int32_t idx = w_cnt;
        volatile int32_t val = idx * 2;
    }
    ;
    {
        int32_t idx = w_cnt + 4;
        volatile int32_t val = idx * 2;
    }
    ;
    {
        {
            int32_t idx = w_cnt + 8;
            volatile int32_t val = idx * 2;
        }
        ;
        {
            int32_t idx = w_cnt + 12;
            volatile int32_t val = idx * 2;
        }
        ;
    }
    ;
    {
        {
            int32_t idx = w_cnt + 16;
            volatile int32_t val = idx * 2;
        }
        ;
        {
            int32_t idx = w_cnt + 20;
            volatile int32_t val = idx * 2;
        }
        ;
    }
    ;
    {
        {
            int32_t idx = w_cnt + 24;
            volatile int32_t val = idx * 2;
        }
        ;
        {
            int32_t idx = w_cnt + 28;
            volatile int32_t val = idx * 2;
        }
        ;
    }
    ;
    {
        {
            int32_t idx = w_cnt + 32;
            volatile int32_t val = idx * 2;
        }
        ;
        {
            int32_t idx = w_cnt + 36;
            volatile int32_t val = idx * 2;
        }
        ;
    }
    ;
}
}
