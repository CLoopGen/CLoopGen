#include <stdint.h>

long Bit_Buffer[10000];
unsigned long total_frame_buffer = 10000;
unsigned long TotalRate = 0;
unsigned long iFrame = 0;

void init_vars() {
    for (int i = 0; i < 10000; i++) {
        Bit_Buffer[i] = (long)(i * 31);
    }
    total_frame_buffer = 10000;
    TotalRate = 0;
}