#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t value = 0x12345678;
int len = 20000000;  // ~20 million iterations to target ~0.01 sec runtime
char bits[65] = {0};
int i = 0;

void init_vars() {
    value = 0x12345678;
    len = 20000000;
    for (int j = 0; j < 65; j++) {
        bits[j] = '0';
    }
    bits[64] = '\0';
    
    // Ensure bits array is large enough for the loop: indices up to len + len
    // But original declaration is fixed at 65, so we must constrain len accordingly
    // Correction: len must be small enough so that len + i + 1 < 65
    // Since i goes from 0 to len-1, maximum index is len + (len-1) + 1 = 2*len
    // So we require 2*len + 1 <= 65 -> len <= 32
    len = 32;
    for (int j = 0; j < 65; j++) {
        bits[j] = '0';
    }
    bits[64] = '\0';
    value = 0x12345678;
}