#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dir_info {
    char *path;
    int length;
    int prefix;
    int count;
    int dir_idx;
    int used;
};

struct dir_info *dirs = NULL;
int *saved = NULL;
int *savehere = NULL;
int ndirs = 0;
int i = 0;

void init_vars() {
    ndirs = 16384;

    dirs = (struct dir_info *)calloc(ndirs, sizeof(struct dir_info));
    saved = (int *)calloc(ndirs, sizeof(int));
    savehere = (int *)calloc(ndirs, sizeof(int));

    for (int idx = 0; idx < ndirs; idx++) {
        dirs[idx].path = (char *)malloc(16);
        sprintf(dirs[idx].path, "/dir%d", idx);
        dirs[idx].length = (idx % 128) + 1;
        dirs[idx].prefix = (idx == 0) ? -1 : (idx - 1);
        dirs[idx].count = (idx % 10) + 1;
        dirs[idx].dir_idx = -1;
        dirs[idx].used = 0;
        saved[idx] = (idx % 64) + 1;
        savehere[idx] = 0;
    }
}