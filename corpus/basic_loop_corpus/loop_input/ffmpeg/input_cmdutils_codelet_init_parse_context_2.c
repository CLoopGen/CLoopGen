#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct OptionGroupDef {
    const char *name;
    const char *sep;
    int flags;
} OptionGroupDef;

typedef struct OptionDef {
    const char *name;
    int flags;
    union {
        void *dst_ptr;
        int (*func_arg)(void *, const char *, const char *);
        size_t off;
    } u;
    const char *help;
    const char *argname;
} OptionDef;

typedef struct Option {
    const OptionDef *opt;
    const char *key;
    const char *val;
} Option;

typedef struct AVDictionary AVDictionary;

typedef struct OptionGroup {
    const OptionGroupDef *group_def;
    const char *arg;
    Option *opts;
    int nb_opts;
    AVDictionary *codec_opts;
    AVDictionary *format_opts;
    AVDictionary *resample_opts;
    AVDictionary *sws_dict;
    AVDictionary *swr_opts;
} OptionGroup;

typedef struct OptionGroupList {
    const OptionGroupDef *group_def;
    OptionGroup *groups;
    int nb_groups;
} OptionGroupList;

typedef struct OptionParseContext {
    OptionGroup global_opts;
    OptionGroupList *groups;
    int nb_groups;
    OptionGroup cur_group;
} OptionParseContext;

OptionGroupDef *groups;
int i;

static OptionParseContext octx_storage;
OptionParseContext *octx = &octx_storage;

void init_vars() {
    const int num_groups = 65536;
    octx->nb_groups = num_groups;

    octx->groups = (OptionGroupList *)calloc(num_groups, sizeof(OptionGroupList));
    if (!octx->groups) exit(1);

    groups = (OptionGroupDef *)calloc(num_groups, sizeof(OptionGroupDef));
    if (!groups) exit(1);

    for (int j = 0; j < num_groups; j++) {
        groups[j].name = "group";
        groups[j].sep = ":";
        groups[j].flags = 0;
        octx->groups[j].group_def = &groups[j];
        octx->groups[j].groups = NULL;
        octx->groups[j].nb_groups = 0;
    }

    octx->global_opts.group_def = NULL;
    octx->global_opts.arg = NULL;
    octx->global_opts.opts = NULL;
    octx->global_opts.nb_opts = 0;
    octx->global_opts.codec_opts = NULL;
    octx->global_opts.format_opts = NULL;
    octx->global_opts.resample_opts = NULL;
    octx->global_opts.sws_dict = NULL;
    octx->global_opts.swr_opts = NULL;

    octx->cur_group = octx->global_opts;
}