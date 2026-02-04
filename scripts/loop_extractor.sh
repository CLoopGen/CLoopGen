#!/bin/bash 

if [ $# -lt 2 ]; then
    echo "usage: $0 <loopExtractor>  <source> <target> [INCLUDE_DIR] [CFLAGS]"
    exit 1
fi

LOOPEXT="$1"
SOURCE_DIR="$2"
TARGET_DIR="$3"
INCLUDE_DIR="$4"
CFLAGS="$5" 

mkdir -p "$TARGET_DIR"

if [ ! -d "$SOURCE_DIR" ]; then
    echo "usage: source dir '$SOURCE_DIR' does not exist"
    exit 1
fi

find "$SOURCE_DIR" -name "*.c" -type f | while read -r file; do
    filename="$file"
    file_base=$(basename "$filename" .c)
    target_subdir="$TARGET_DIR/$file_base"
    mkdir -p "$target_subdir"
    
    $LOOPEXT -out "$target_subdir/$file_base" "$filename" -- -x c $INCLUDE_DIR $CFLAGS
    
    if [ $? -ne 0 ]; then
        echo "Extraction failed for $filename"
    fi
done