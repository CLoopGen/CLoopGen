#include <stdint.h>
#include <string.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

AVInteger a;
int s;
AVInteger out;
int i;

void init_vars() {
    // Initialize 'a' with non-zero test data
    for (int j = 0; j < 8; j++) {
        a.v[j] = (uint16_t)(0xABCD ^ (j * 0x123));
    }
    // Ensure s is in a valid range so that index = i + (s >> 4) stays within bounds
    // i goes from 0 to 7, so we need index + 1 < 8 => i + (s >> 4) + 1 <= 7
    // maximum i is 7, so: 7 + (s >> 4) + 1 <= 7 -> (s >> 4) <= -1 -> not possible
    // instead, we choose s such that (s >> 4) is 0, so index = i
    // then index + 1 = i + 1, which for i=7 would be 8 -> out of bounds
    // so we must avoid accessing a.v[8], thus condition checks are critical
    // set s so that (s >> 4) = 0 and (s & 15) is reasonable
    s = 7; // then s>>4 = 0, s&15 = 7
    // This makes index = i, and shift by 7 bits
    // Accesses a.v[i] and a.v[i+1] only when i+1 < 8, so safe for i from 0 to 6
    // For i=7, only a.v[7] is accessed
    memset(&out, 0, sizeof(out));
}