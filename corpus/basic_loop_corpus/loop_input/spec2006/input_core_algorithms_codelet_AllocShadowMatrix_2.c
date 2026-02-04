#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct dpshadow_s {
    char **xtb;
    char **mtb;
    char **itb;
    char **dtb;
    int *esrc;
};

int rows = 1024;
int M = 1000;
struct dpshadow_s *tb;
int i;

static char *alloc_char_ptr_array(size_t size) {
    char *ptr = (char *)calloc(size, sizeof(char));
    if (!ptr) exit(1);
    return ptr;
}

static char **alloc_and_init_tb_array(char *base, int stride) {
    char **arr = (char **)calloc(rows, sizeof(char *));
    if (!arr) exit(1);
    for (int idx = 0; idx < rows; idx++) {
        arr[idx] = base + idx * stride;
    }
    return arr;
}

void init_vars() {
    char *xtb_base = alloc_char_ptr_array(rows * 5);
    char *mtb_base = alloc_char_ptr_array(rows * (M + 2));
    char *itb_base = alloc_char_ptr_array(rows * (M + 2));
    char *dtb_base = alloc_char_ptr_array(rows * (M + 2));

    tb = (struct dpshadow_s *)calloc(1, sizeof(struct dpshadow_s));
    if (!tb) exit(1);

    tb->xtb = alloc_and_init_tb_array(xtb_base, 5);
    tb->mtb = alloc_and_init_tb_array(mtb_base, M + 2);
    tb->itb = alloc_and_init_tb_array(itb_base, M + 2);
    tb->dtb = alloc_and_init_tb_array(dtb_base, M + 2);
    tb->esrc = (int *)calloc(rows, sizeof(int));
    if (!tb->esrc) exit(1);
}