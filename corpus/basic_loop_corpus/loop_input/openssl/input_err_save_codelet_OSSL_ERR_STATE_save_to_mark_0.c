#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct err_state_st {
    int err_flags[16];
    int err_marks[16];
    unsigned long err_buffer[16];
    char *err_data[16];
    size_t err_data_size[16];
    int err_data_flags[16];
    char *err_file[16];
    int err_line[16];
    char *err_func[16];
    int top;
    int bottom;
};

typedef struct err_state_st ERR_STATE;

int count;
int top;
ERR_STATE *thread_es;

void init_vars() {
    thread_es = (ERR_STATE *)calloc(1, sizeof(ERR_STATE));
    if (!thread_es) exit(1);

    thread_es->top = 15;
    thread_es->bottom = 0;

    for (int i = 0; i < 16; ++i) {
        thread_es->err_flags[i] = 0;
        thread_es->err_marks[i] = (i == 8) ? 1 : 0;
        thread_es->err_buffer[i] = (unsigned long)(i * 1000);
        thread_es->err_data_size[i] = 128 * 1024; // ~128KB per data block
        thread_es->err_data[i] = (char *)calloc(thread_es->err_data_size[i], 1);
        if (!thread_es->err_data[i]) exit(1);
        memset(thread_es->err_data[i], 'A' + (i % 26), thread_es->err_data_size[i]);
        thread_es->err_data_flags[i] = 0;
        thread_es->err_file[i] = strdup("default_file.c");
        thread_es->err_line[i] = 100 + i;
        thread_es->err_func[i] = strdup("default_function");
    }
}