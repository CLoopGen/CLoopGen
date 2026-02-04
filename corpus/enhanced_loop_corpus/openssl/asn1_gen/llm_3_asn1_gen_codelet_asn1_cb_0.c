#include <stdio.h>

#include <inttypes.h>

extern  char *elem;
extern int len;
extern int i;
extern int vlen;
extern  char *p;
extern  char *vstart;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index map (simulating gather-style access)
    // We create a local index array that defines the access order (sequential here, but could be arbitrary)
    int indices[512]; // Assume max length is bounded for stack allocation
    int max_len = len < 512 ? len : 511;
    for (int j = 0; j < max_len; j++) {
        indices[j] = j; // Identity mapping for realism, but enables indirect access pattern
    }
    for (i = 0, p = elem; i < max_len; i++) {
        char *current_p = elem + indices[i]; // Indirect pointer calculation
        if (*current_p == ':') {
            vstart = current_p + 1;
            vlen = len - (int)(vstart - elem);
            len = (int)(current_p - elem);
            break;
        }
    }
}
