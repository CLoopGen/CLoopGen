#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *s;
char *sep;
int *len;
int i;
int j;

static char s_buffer[131072]; // 128KB buffer for s
static char sep_buffer[5] = { ' ', '\t', '\n', '\r' }; // common separators
static int len_value;

void init_vars() {
    // Initialize sep to point to static separator array
    sep = sep_buffer;
    
    // Initialize s to point to the internal buffer
    s = s_buffer;
    
    // Fill the buffer with non-separator printable ASCII except the last few
    for (size_t idx = 0; idx < sizeof(s_buffer) - 4; idx++) {
        s[idx] = 'A' + (idx % 26);
    }
    
    // Place a separator near the end to allow loop to terminate naturally
    s[sizeof(s_buffer) - 4] = ' ';  // This will be matched by sep
    s[sizeof(s_buffer) - 3] = 'X';  // Continue after break
    s[sizeof(s_buffer) - 2] = 'Y';
    s[sizeof(s_buffer) - 1] = '\0'; // Ensure null termination
    
    // Initialize len to point to our counter variable
    len = &len_value;
    
    // Initialize loop indices
    i = 0;
    j = 0;
    
    // Reset length counter
    len_value = 0;
}