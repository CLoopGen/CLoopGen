#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern int l;
extern int w;
extern  int linesize;
extern  uint32_t *py;
extern  uint32_t *pr;
extern  uint32_t *pb;
extern uint32_t *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – write every other element, then fill in
    // Simulates non-unit stride access pattern for cache behavior exploration

    for (; py < pb; py += linesize) {
        px = (uint32_t *)py + l;
        pr = px + w;

        // First pass: write to even indices with stride 2
        uint32_t *px_even = px;
        for (; px_even < pr; px_even += 2) {
            *px_even = color;
        }

        // Second pass: write to odd indices with stride 2
        uint32_t *px_odd = px + 1;
        for (; px_odd < pr; px_odd += 2) {
            *px_odd = color;
        }
    }
}
