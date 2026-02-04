#include <stdio.h>

#include <inttypes.h>

extern int target_flags;
extern char fixed_regs[53];
extern char call_used_regs[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (reverse order traversal)
    int index_map[53];
    for (int temp = 0; temp < 53; temp++) {
        index_map[temp] = 52 - temp; // Reverse indexing
    }
    for (i = 0; i < 53; i++) {
        int idx = index_map[i];
        fixed_regs[idx] = (fixed_regs[idx] & ((target_flags & 33554432) ? 2 : 1)) != 0;
        call_used_regs[idx] = (call_used_regs[idx] & ((target_flags & 33554432) ? 2 : 1)) != 0;
    }
}
