#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *d;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every second character backward from the end
    // Simulates non-unit stride access pattern, still achieving forward skip semantics via pre-adjustment
    if (!len) return;

    STRLEN step = 2;
    STRLEN adjusted_len = (len + step - 1) / step; // Ceiling division to cover all needed strides
    char *base = d - 1; // Offset base to allow symmetric indexing

    // First pass: strided read to determine how many full strides of whitespace exist
    STRLEN i;
    for (i = 0; i < adjusted_len; ++i) {
        STRLEN idx = i * step;
        if (idx >= len) break;
        char c = *(d + idx);
        if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')) {
            break;
        }
    }

    // Determine how far we can move forward based on contiguous initial strides
    STRLEN max_consecutive = i * step;
    char *new_d = d;
    STRLEN new_len = len;

    // Now advance linearly up to max_consecutive, but only if all chars in range are whitespace
    for (; max_consecutive > 0; --max_consecutive) {
        if (!(*new_d == ' ' || *new_d == '\t' || *new_d == '\n' || *new_d == '\r' || *new_d == '\f'))
            break;
        ++new_d;
        --new_len;
    }

    // Final cleanup for any remaining leading whitespace not caught due to stride gaps
    for (; new_len && (*new_d == ' ' || *new_d == '\t' || *new_d == '\n' || *new_d == '\r' || *new_d == '\f');
         --new_len, ++new_d)
        ;

    d = new_d;
    len = new_len;
}
