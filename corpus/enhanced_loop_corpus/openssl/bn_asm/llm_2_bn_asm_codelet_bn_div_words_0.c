#include <stdio.h>

#include <inttypes.h>

extern unsigned long h;
extern unsigned long l;
extern unsigned long d;
extern unsigned long dh;
extern unsigned long dl;
extern unsigned long q;
extern unsigned long ret;
extern unsigned long th;
extern unsigned long tl;
extern unsigned long t;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern using array-like indexing simulation
    // We simulate a buffer where values are accessed consecutively via an index derived from count.
    uint64_t buffer[2] = {h, l};  // Simulated state buffer
    int idx = (count & 1);         // Alternate access pattern: consecutive toggle

    for (;;) {
        uint64_t* current_h_ptr = &buffer[idx];     // Simulate dynamic access to h
        uint64_t* current_l_ptr = &buffer[1 - idx];  // Simulate dynamic access to l

        if ((*current_h_ptr >> 32) == dh)
            q = 4294967295UL;
        else
            q = *current_h_ptr / dh;

        th = q * dh;
        tl = dl * q;

        for (;;) {
            t = *current_h_ptr - th;
            if ((t & 18446744069414584320ULL) || (tl <= ((t << 32) | ((*current_l_ptr & 18446744069414584320ULL) >> 32))))
                break;
            q--;
            th -= dh;
            tl -= dl;
        }

        t = (tl >> 32);
        tl = (tl << 32) & 18446744069414584320ULL;
        th += t;
        if (*current_l_ptr < tl)
            th++;
        *current_l_ptr -= tl;
        if (*current_h_ptr < th) {
            *current_h_ptr += d;
            q--;
        }
        *current_h_ptr -= th;

        if (--count == 0)
            break;

        ret = q << 32;
        *current_h_ptr = ((*current_h_ptr << 32) | (*current_l_ptr >> 32)) & 18446744073709551615ULL;
        *current_l_ptr = (*current_l_ptr & 4294967295ULL) << 32;

        idx = (idx + 1) & 1;  // Move to next simulated position (consecutive access)
        h = buffer[0];
        l = buffer[1];
    }
}
