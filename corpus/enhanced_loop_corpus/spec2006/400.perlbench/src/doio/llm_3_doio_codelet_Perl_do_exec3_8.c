#include <stdio.h>

#include <inttypes.h>

extern char *cmd;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with prefetching simulation using array indexing
    const char *str = cmd;
    int64_t i = 0;
    if (!str) {
        s = cmd;
        return;
    }
    // Use index-based consecutive access with lookahead simulation
    for (i = 0; str[i]; i++) {
        char c = str[i];
        if (!((c >= 'A' && c <= 'Z') || 
              (c >= 'a' && c <= 'z') || 
              (c >= '0' && c <= '9') || 
              (c == '_'))) {
            break;
        }
        // Optional: simulate prefetch of next few elements via indexing
        // (Compiler may optimize this into better memory access patterns)
        __builtin_prefetch(&str[i + 16], 0, 0);
    }
    s = (char*)&str[i]; // Set s to point at first invalid or null terminator
}
