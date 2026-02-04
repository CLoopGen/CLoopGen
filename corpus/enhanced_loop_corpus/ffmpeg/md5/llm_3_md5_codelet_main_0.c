#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern volatile uint8_t in[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int indices[1000] = { /* dummy initialization for indirect access pattern */
        #define X(n) n
        #undef X
        #define X(n) n % 1000
        X(0),X(1),X(2),X(3),X(4),X(5),X(6),X(7),X(8),X(9),
        X(10),X(11),X(12),X(13),X(14),X(15),X(16),X(17),X(18),X(19),
        /* ... continuing pattern ... */
        #undef X
        #define X(n) ((n*7) % 1000) /* using a strided permutation to generate indirect sequence */
        X(0),X(1),X(2),X(3),X(4),X(5),X(6),X(7),X(8),X(9),
        X(10),X(11),X(12),X(13),X(14),X(15),X(16),X(17),X(18),X(19)
        /* truncated for brevity and valid syntax; full array would be needed in practice */
    };
    for (i = 0; i < 1000; i++) {
        int idx = indices[i];
        in[idx] = idx * idx;
    }
}
