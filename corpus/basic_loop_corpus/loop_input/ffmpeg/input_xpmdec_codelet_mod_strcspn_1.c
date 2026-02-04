#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *string;
char *reject;
int i;
int j;

static char *alloc_string;
static char *alloc_reject;

void init_vars() {
    size_t string_size = 64 * 1024 * 1024; // 64 MB to target ~0.01s runtime
    alloc_string = (char *)calloc(string_size, sizeof(char));
    if (!alloc_string) exit(1);

    // Create a mix of code-like content with comments and rejectable characters
    size_t pos = 0;
    const char pattern[] = "abc/* comment */def// another comment\nghi";
    const int pattern_len = sizeof(pattern) - 1;
    while (pos < string_size - 32) {
        int len = (pattern_len + (rand() % 16)) & ~7;
        for (int k = 0; k < len && pos < string_size - 32; k++) {
            alloc_string[pos++] = pattern[k % pattern_len];
        }
    }
    // Ensure null termination
    alloc_string[string_size - 1] = '\0';
    string = alloc_string;

    // Initialize reject string with some characters that appear in the pattern
    alloc_reject = (char *)malloc(5);
    if (!alloc_reject) exit(1);
    strcpy(alloc_reject, "xyz");
    reject = alloc_reject;

    // Initialize loop indices
    i = 0;
    j = 0;
}