#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    UndefinedColorspace,
    CMYColorspace,
    CMYKColorspace,
    GRAYColorspace,
    HCLColorspace,
    HCLpColorspace,
    HSBColorspace,
    HSIColorspace,
    HSLColorspace,
    HSVColorspace,
    HWBColorspace,
    LabColorspace,
    LCHColorspace,
    LCHabColorspace,
    LCHuvColorspace,
    LogColorspace,
    LMSColorspace,
    LuvColorspace,
    OHTAColorspace,
    Rec601YCbCrColorspace,
    Rec709YCbCrColorspace,
    RGBColorspace,
    scRGBColorspace,
    sRGBColorspace,
    TransparentColorspace,
    xyYColorspace,
    XYZColorspace,
    YCbCrColorspace,
    YCCColorspace,
    YDbDrColorspace,
    YIQColorspace,
    YPbPrColorspace,
    YUVColorspace,
    LinearGRAYColorspace,
    JzazbzColorspace,
    DisplayP3Colorspace,
    Adobe98Colorspace,
    ProPhotoColorspace,
    OklabColorspace,
    OklchColorspace,
    CAT02LMSColorspace
} ColorspaceType;

typedef enum {
    UndefinedPixelTrait = 0,
    CopyPixelTrait = 1,
    UpdatePixelTrait = 2,
    BlendPixelTrait = 4
} PixelTrait;

typedef unsigned long long MagickSizeType;
typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _PixelInfo {
    ClassType storage_class;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    double fuzz;
    size_t depth;
    MagickSizeType count;
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType black;
    MagickRealType alpha;
    MagickRealType index;
} PixelInfo;

typedef struct _HNodeInfo {
    struct _HNodeInfo *child[16];
    PixelInfo *list;
    size_t extent;
    MagickSizeType number_unique;
    size_t level;
} HNodeInfo;

HNodeInfo *node_info;
PixelInfo **histogram;
ssize_t i;
PixelInfo *p;

static PixelInfo *pixel_array = NULL;
static PixelInfo **histogram_array = NULL;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t element_size = sizeof(PixelInfo);
    const MagickSizeType num_elements = (data_size_mb * 1024 * 1024) / element_size;

    pixel_array = (PixelInfo*)calloc(num_elements, sizeof(PixelInfo));
    if (!pixel_array) exit(1);

    histogram_array = (PixelInfo**)calloc(num_elements, sizeof(PixelInfo*));
    if (!histogram_array) exit(1);

    for (MagickSizeType idx = 0; idx < num_elements; idx++) {
        pixel_array[idx].storage_class = idx % 3 == 0 ? DirectClass : (idx % 3 == 1 ? PseudoClass : UndefinedClass);
        pixel_array[idx].colorspace = (idx % 35) + 1;
        pixel_array[idx].alpha_trait = (idx % 4) + 1;
        pixel_array[idx].fuzz = idx * 0.01;
        pixel_array[idx].depth = 8 + (idx % 16);
        pixel_array[idx].count = idx;
        pixel_array[idx].red = (double)(idx % 256) / 255.0;
        pixel_array[idx].green = (double)((idx * 7) % 256) / 255.0;
        pixel_array[idx].blue = (double)((idx * 13) % 256) / 255.0;
        pixel_array[idx].black = (double)((idx * 19) % 256) / 255.0;
        pixel_array[idx].alpha = 1.0 - ((double)(idx % 100) / 100.0);
        pixel_array[idx].index = idx * 1.5;
    }

    for (MagickSizeType idx = 0; idx < num_elements; idx++) {
        histogram_array[idx] = &pixel_array[idx];
    }

    node_info = (HNodeInfo*)malloc(sizeof(HNodeInfo));
    if (!node_info) exit(1);

    node_info->number_unique = num_elements;
    for (int c = 0; c < 16; c++) {
        node_info->child[c] = NULL;
    }
    node_info->list = NULL;
    node_info->extent = 0;
    node_info->level = 0;

    histogram = histogram_array;
    p = pixel_array;
}