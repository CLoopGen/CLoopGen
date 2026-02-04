#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <string.h>
#include <time.h>

unsigned char *source;
size_t *length;
wchar_t *utf16;
ssize_t i;

static unsigned char source_data[131072]; // 128KB of data
static size_t length_value = 131071;      // Access up to index 131071, so length points to this
static wchar_t utf16_data[131072];        // Match size of source + 1 for boundary

void init_vars() {
    source = source_data;
    length = &length_value;
    utf16 = utf16_data;

    // Initialize source with non-zero data to simulate meaningful input
    for (size_t idx = 0; idx < sizeof(source_data); ++idx) {
        source_data[idx] = (unsigned char)(idx % 251);
    }

    // Ensure utf16 is initialized to zero to avoid garbage in unused regions
    memset(utf16_data, 0, sizeof(utf16_data));
}