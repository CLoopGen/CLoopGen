#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *a;
unsigned char *p;

static char data[1 << 24]; // 16 MB of data

void init_vars() {
    size_t len = sizeof(data) - 1; // Leave space for null terminator
    size_t i;

    // Seed random generator for varied input
    srand((unsigned int)(time(NULL)));

    // Fill with mostly valid characters, but include an invalid one near the end to trigger break
    const char valid_ranges[] =
        "+,-./0123456789"           // '+' to ':'
        "@ABCDEFGHIJKLMNOPQRSTUVWXYZ" // '@' to 'Z'
        "_"
        "abcdefghijklmnopqrstuvwxyz"; // 'a' to 'z'

    for (i = 0; i < len - 1; i++) {
        data[i] = valid_ranges[rand() % (sizeof(valid_ranges) - 1)];
    }

    // Insert an invalid character (e.g., '`' is ASCII 96, just after '_') or other non-matching
    data[len - 1] = '`'; // Not in any allowed range: breaks condition

    // Null terminate
    data[len] = '\0';

    // Initialize external pointers
    a = data;
}