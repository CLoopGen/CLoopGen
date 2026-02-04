#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef enum {
    UndefinedPrimitive,
    AlphaPrimitive,
    ArcPrimitive,
    BezierPrimitive,
    CirclePrimitive,
    ColorPrimitive,
    EllipsePrimitive,
    ImagePrimitive,
    LinePrimitive,
    PathPrimitive,
    PointPrimitive,
    PolygonPrimitive,
    PolylinePrimitive,
    RectanglePrimitive,
    RoundRectanglePrimitive,
    TextPrimitive
} PrimitiveType;

typedef enum {
    UndefinedMethod,
    PointMethod,
    ReplaceMethod,
    FloodfillMethod,
    FillToBorderMethod,
    ResetMethod
} PaintMethod;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _PrimitiveInfo {
    PointInfo point;
    size_t coordinates;
    PrimitiveType primitive;
    PaintMethod method;
    char *text;
    MagickBooleanType closed_subpath;
} PrimitiveInfo;

typedef enum {
    UndefinedException,
    WarningException = 300,
    ResourceLimitWarning = 300,
    TypeWarning = 305,
    OptionWarning = 310,
    DelegateWarning = 315,
    MissingDelegateWarning = 320,
    CorruptImageWarning = 325,
    FileOpenWarning = 330,
    BlobWarning = 335,
    StreamWarning = 340,
    CacheWarning = 345,
    CoderWarning = 350,
    FilterWarning = 352,
    ModuleWarning = 355,
    DrawWarning = 360,
    ImageWarning = 365,
    WandWarning = 370,
    RandomWarning = 375,
    XServerWarning = 380,
    MonitorWarning = 385,
    RegistryWarning = 390,
    ConfigureWarning = 395,
    PolicyWarning = 399,
    ErrorException = 400,
    ResourceLimitError = 400,
    TypeError = 405,
    OptionError = 410,
    DelegateError = 415,
    MissingDelegateError = 420,
    CorruptImageError = 425,
    FileOpenError = 430,
    BlobError = 435,
    StreamError = 440,
    CacheError = 445,
    CoderError = 450,
    FilterError = 452,
    ModuleError = 455,
    DrawError = 460,
    ImageError = 465,
    WandError = 470,
    RandomError = 475,
    XServerError = 480,
    MonitorError = 485,
    RegistryError = 490,
    ConfigureError = 495,
    PolicyError = 499,
    FatalErrorException = 700,
    ResourceLimitFatalError = 700,
    TypeFatalError = 705,
    OptionFatalError = 710,
    DelegateFatalError = 715,
    MissingDelegateFatalError = 720,
    CorruptImageFatalError = 725,
    FileOpenFatalError = 730,
    BlobFatalError = 735,
    StreamFatalError = 740,
    CacheFatalError = 745,
    CoderFatalError = 750,
    FilterFatalError = 752,
    ModuleFatalError = 755,
    DrawFatalError = 760,
    ImageFatalError = 765,
    WandFatalError = 770,
    RandomFatalError = 775,
    XServerFatalError = 780,
    MonitorFatalError = 785,
    RegistryFatalError = 790,
    ConfigureFatalError = 795,
    PolicyFatalError = 799
} ExceptionType;

typedef struct SemaphoreInfo SemaphoreInfo;

struct _ExceptionInfo {
    ExceptionType severity;
    int error_number;
    char *reason;
    char *description;
    void *exceptions;
    MagickBooleanType relinquish;
    SemaphoreInfo *semaphore;
    size_t signature;
};

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _MVGInfo {
    PrimitiveInfo **primitive_info;
    size_t *extent;
    ssize_t offset;
    PointInfo point;
    ExceptionInfo *exception;
} MVGInfo;

static PrimitiveInfo *primitive_info_array = NULL;
static PrimitiveInfo **primitive_info_ptr = NULL;
static size_t *extent_ptr = NULL;
static ExceptionInfo *exception_info = NULL;
MVGInfo *mvg_info = NULL;
double extent = 0;
ssize_t i;

void init_vars() {
    const size_t data_size = 131072; // ~1MB of PrimitiveInfo (each ~8 bytes)
    
    primitive_info_array = (PrimitiveInfo*)calloc(data_size, sizeof(PrimitiveInfo));
    if (!primitive_info_array) exit(1);
    
    primitive_info_ptr = (PrimitiveInfo**)malloc(sizeof(PrimitiveInfo*));
    if (!primitive_info_ptr) exit(1);
    primitive_info_ptr[0] = primitive_info_array;
    
    extent_ptr = (size_t*)malloc(sizeof(size_t));
    if (!extent_ptr) exit(1);
    *extent_ptr = data_size - 1;
    extent = (double)(data_size - 1);
    
    exception_info = (ExceptionInfo*)calloc(1, sizeof(ExceptionInfo));
    if (!exception_info) exit(1);
    exception_info->severity = UndefinedException;
    exception_info->signature = 0x12345678UL;
    
    mvg_info = (MVGInfo*)calloc(1, sizeof(MVGInfo));
    if (!mvg_info) exit(1);
    mvg_info->primitive_info = primitive_info_ptr;
    mvg_info->extent = extent_ptr;
    mvg_info->offset = 0;
    mvg_info->exception = exception_info;
}