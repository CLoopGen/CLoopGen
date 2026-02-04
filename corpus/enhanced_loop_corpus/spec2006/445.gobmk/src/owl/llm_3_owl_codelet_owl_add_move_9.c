#include <stdio.h>

#include <inttypes.h>

struct owl_move_data {
    int pos;
    int value;
    const char *name;
    int same_dragon;
    int escape;
    int defense_pos;
};


extern struct owl_move_data *moves;
extern int move;
extern int value;
extern  char *reason;
extern int same_dragon;
extern int escape;
extern int defense_pos;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Access via Pointer Arithmetic
    // Replace direct array indexing with pointer-based access to alter memory access pattern.
    // We traverse backwards using a pointer to struct owl_move_data.
    struct owl_move_data *base = moves;  // Base address
    struct owl_move_data *curr = base + k;  // Point to current position

    for (; k >= 0; k--) {
        struct owl_move_data *prev = curr - 1;
        if (k == 0 || value <= prev->value) {
            if (k < 3) {
                curr->pos = move;
                curr->value = value;
                curr->name = reason;
                curr->same_dragon = same_dragon;
                curr->escape = escape;
                curr->defense_pos = defense_pos;
            }
            break;
        }
        if (k < 3)
            *curr = *prev;

        curr--;  // Move pointer backward
    }
}
