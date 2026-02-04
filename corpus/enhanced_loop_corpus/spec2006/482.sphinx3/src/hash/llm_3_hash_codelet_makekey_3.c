#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uint8;

typedef int int32;

extern uint8 *data;
extern int32 len;
extern char *key;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Read with Interleaved Write
    // Access 'data' with a stride of 2 (even indices only), and write corresponding pairs in 'key'
    // Introduces non-unit stride in input and maintains strided output, reducing total iterations.
    int32 count = 0;
    for (i = 0; i < len; i += 2, j += 4) {
        // Only process if current and next byte are within bounds
        if (i + 1 < len) {
            key[j]       = 'A' + (data[i] & 15);
            key[j + 1]   = 'J' + ((data[i] >> 4) & 15);
            key[j + 2]   = 'A' + (data[i + 1] & 15);
            key[j + 3]   = 'J' + ((data[i + 1] >> 4) & 15);
        } else {
            // Handle odd-length tail
            key[j]       = 'A' + (data[i] & 15);
            key[j + 1]   = 'J' + ((data[i] >> 4) & 15);
            j++; // Adjust j since only two chars written
        }
        count++;
    }
    // Adjust final j value based on actual writes (optional side-effect fix)
    // Note: j is global, so mutation affects outside state
}
