#include <stdio.h>

#include <inttypes.h>

extern char call_used_regs[53];
extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified condition and minimized arithmetic
    const int base = 20 + 1 + 7 + 1 + 7 + 1;
    const int start = base;
    const int end = base + 7;
    for (i = 0; i < 26; i++) {
        if (!call_used_regs[i]) {
            if (i < 8 || (i >= start && i <= end))
                reg_alloc_order[pos++] = i;
        }
        if (!call_used_regs[52 - i] && (52 - i) != i) {
            if ((52 - i) < 8 || ((52 - i) >= start && (52 - i) <= end))
                reg_alloc_order[pos++] = 52 - i;
        }
    }
}
