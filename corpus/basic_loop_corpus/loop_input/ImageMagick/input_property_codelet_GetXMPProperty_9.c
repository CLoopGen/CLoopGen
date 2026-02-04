#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *xmp_profile;
char *p;

static char *profile_buffer = NULL;
static size_t buffer_size = 1024 * 1024 * 64; // 64 MB

void init_vars() {
    if (profile_buffer != NULL) return;

    profile_buffer = (char *)malloc(buffer_size);
    if (!profile_buffer) exit(1);

    memset(profile_buffer, 'a', buffer_size - 3);
    profile_buffer[buffer_size - 3] = '<';
    profile_buffer[buffer_size - 2] = 'x';
    profile_buffer[buffer_size - 1] = '\x00';

    xmp_profile = profile_buffer;
    p = NULL;
}