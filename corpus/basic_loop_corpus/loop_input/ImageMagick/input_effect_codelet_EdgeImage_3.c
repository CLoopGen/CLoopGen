#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedKernel,
    UnityKernel,
    GaussianKernel,
    DoGKernel,
    LoGKernel,
    BlurKernel,
    CometKernel,
    BinomialKernel,
    LaplacianKernel,
    SobelKernel,
    FreiChenKernel,
    RobertsKernel,
    PrewittKernel,
    CompassKernel,
    KirschKernel,
    DiamondKernel,
    SquareKernel,
    RectangleKernel,
    OctagonKernel,
    DiskKernel,
    PlusKernel,
    CrossKernel,
    RingKernel,
    PeaksKernel,
    EdgesKernel,
    CornersKernel,
    DiagonalsKernel,
    LineEndsKernel,
    LineJunctionsKernel,
    RidgesKernel,
    ConvexHullKernel,
    ThinSEKernel,
    SkeletonKernel,
    ChebyshevKernel,
    ManhattanKernel,
    OctagonalKernel,
    EuclideanKernel,
    UserDefinedKernel
} KernelInfoType;

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _KernelInfo {
    KernelInfoType type;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    MagickRealType *values;
    double minimum;
    double maximum;
    double negative_range;
    double positive_range;
    double angle;
    struct _KernelInfo *next;
    size_t signature;
} KernelInfo;

KernelInfo *kernel_info;
ssize_t i;

void init_vars() {
    kernel_info = (KernelInfo*)calloc(1, sizeof(KernelInfo));
    if (!kernel_info) exit(1);

    // Aim for ~64MB of data: values array of doubles (8 bytes each)
    // So we want about 8M elements -> sqrt(8M) ~ 2800x2800
    kernel_info->width = 2828;
    kernel_info->height = 2828;
    size_t num_elements = kernel_info->width * kernel_info->height;

    kernel_info->values = (MagickRealType*)calloc(num_elements, sizeof(MagickRealType));
    if (!kernel_info->values) {
        free(kernel_info);
        exit(1);
    }

    kernel_info->type = UnityKernel;
    kernel_info->x = 0;
    kernel_info->y = 0;
    kernel_info->minimum = 0.0;
    kernel_info->maximum = 0.0;
    kernel_info->negative_range = 0.0;
    kernel_info->positive_range = 0.0;
    kernel_info->angle = 0.0;
    kernel_info->next = NULL;
    kernel_info->signature = 0x12345678UL;
}