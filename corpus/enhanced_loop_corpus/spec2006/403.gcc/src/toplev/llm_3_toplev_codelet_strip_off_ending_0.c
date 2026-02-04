#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset mirroring (simulate reverse scan using forward index mapping)
    int start = (len - 5) > 0 ? (len - 5) : 0;
    int end = len - 2;
    for (i = 0; start + i < end && (len - (start + i)) <= 6; i++) {
        int rev_index = len - (start + i);
        if (rev_index >= 2 && name[rev_index] == '.') {
            name[rev_index] = '\x00';
            break;
        }
    }
    // Adjust original 'i' to reflect logical iteration count in original context
    i = (start + i) < len ? (start + i - len + 6) : 4; // Approximate i update to preserve loop state semantics
}
