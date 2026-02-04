#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _StringInfo {
    char *path;
    unsigned char *datum;
    size_t length;
    size_t signature;
    char *name;
} StringInfo;

extern  StringInfo *string_info;
extern  unsigned char *p;
extern ssize_t i;
extern unsigned char *q;
extern unsigned char hex_digits[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (coalesced) access via local buffer to change memory write pattern
    // Instead of writing directly to q[], accumulate two hex characters in a local array and copy them consecutively.
    // This changes the memory access pattern on the output side to be more cache-friendly and burst-like.
    ssize_t len = (ssize_t)string_info->length;
    unsigned char local_hex[2];
    for (i = 0; i < len; i++) {
        local_hex[0] = hex_digits[(*p >> 4) & 15];
        local_hex[1] = hex_digits[*p & 15];
        // Perform consecutive write from local buffer
        *q++ = local_hex[0];
        *q++ = local_hex[1];
        p++;
    }
}
