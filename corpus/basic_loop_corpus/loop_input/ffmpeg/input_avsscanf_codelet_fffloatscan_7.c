#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct FFFILE {
    size_t buf_size;
    unsigned char *buf;
    unsigned char *rpos;
    unsigned char *rend;
    unsigned char *shend;
    ptrdiff_t shlim;
    ptrdiff_t shcnt;
    void *cookie;
    size_t (*read)(struct FFFILE *, unsigned char *, size_t);
} FFFILE;

FFFILE *f;
size_t i;

static unsigned char *global_buf;
static FFFILE global_file;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    global_buf = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    if (!global_buf) exit(1);

    global_file.buf_size = data_size;
    global_file.buf = global_buf;
    global_file.rpos = global_buf + data_size - 1;
    global_file.rend = global_buf + data_size;
    global_file.shend = global_buf + data_size - 4;
    global_file.shlim = 0;
    global_file.shcnt = 0;
    global_file.cookie = NULL;
    global_file.read = NULL;

    f = &global_file;
    i = (data_size > 3) ? data_size / 2 : 3 + 1;
}

// Note: The loop function is defined externally and will be linked in.