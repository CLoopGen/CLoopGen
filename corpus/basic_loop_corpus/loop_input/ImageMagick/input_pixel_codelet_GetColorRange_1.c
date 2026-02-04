#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime

char start_color[4096];
char *p;

static char data_buffer[DATA_SIZE];

void init_vars() {
    // Initialize start_color as a null-terminated string with embedded parentheses and hyphen near the end
    memset(start_color, 0, sizeof(start_color));
    
    // Fill most of start_color with normal characters
    for (int i = 0; i < 4080; i++) {
        start_color[i] = 'a' + (i % 20);
    }
    
    // Insert some parenthesized sections
    start_color[100] = '(';
    start_color[101] = 'x';
    start_color[102] = 'y';
    start_color[103] = 'z';
    start_color[104] = ')';
    
    start_color[200] = '(';
    start_color[201] = '1';
    start_color[202] = '2';
    start_color[203] = ')';
    
    // Place '-' near the end to terminate the loop before buffer overflow
    start_color[4085] = '-';
    start_color[4086] = '\0';

    // Ensure p is initialized properly by other code via loop()
}