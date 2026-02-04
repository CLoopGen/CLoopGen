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
    // Variant 2: Strided Memory Access Pattern with stride-2 simulation using offset indexing
    // Simulate accessing state variables through a larger buffer with non-unit stride
    uint64_t state_buffer[4] = {h, 0, l, 0};  // Interleaved layout: [h][pad][l][pad]
    const int stride = 2;                     // Access every second element
    int offset = (count % 2) * stride;        // Dynamic offset based on count (stride variation)

    for (;;) {
        uint64_t* h_ptr = &state_buffer[offset];      // Strided access to h
        uint64_t* l_ptr = &state_buffer[(2 + offset) % 4];  // Strided access to l (offset + 2 mod 4)

        if ((*h_ptr >> 32) == dh)
            q = 4294967295UL;
        else
            q = *h_ptr / dh;

        th = q * dh;
        tl = dl * q;

        for (;;) {
            t = *h_ptr - th;
            if ((t & 18446744069414584320ULL) || (tl <= ((t << 32) | ((*l_ptr & 18446744069414584320ULL) >> 32))))
                break;
            q--;
            th -= dh;
            tl -= dl;
        }

        t = (tl >> 32);
        tl = (tl << 32) & 18446744069414584320ULL;
        th += t;
        if (*l_ptr < tl)
            th++;
        *l_ptr -= tl;
        if (*h_ptr < th) {
            *h_ptr += d;
            q--;
        }
        *h_ptr -= th;

        if (--count == 0)
            break;

        ret = q << 32;
        *h_ptr = ((*h_ptr << 32) | (*l_ptr >> 32)) & 18446744073709551615ULL;
        *l_ptr = (*l_ptr & 4294967295ULL) << 32;

        offset = (offset + stride) % 4;  // Advance with stride
        h = state_buffer[0];
        l = state_buffer[2];
    }
}
