#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int nb_words;
    uint8_t words[546];
} BigInt;

extern BigInt *b;
extern int i;
extern uint8_t *w;
extern uint16_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access (backward traversal through the words array)
    int idx;
    for (idx = b->nb_words - 1; idx >= 0 && c; idx--) {
        uint8_t *reverse_w = &(b->words[idx]);
        c += *reverse_w;
        *reverse_w = c & ((1 << 8) - 1);
        c >>= 8;
    }
    // Update original pointer if side effects are needed (e.g., reflect final state)
    w = &(b->words[0]); // Ensure w is left in a consistent state
}
