#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "usage: $0 <source> <loopListFile>"
    exit 1
fi

SOURCE_DIR="$1"
CORPUS_FILE="$2"

if [ ! -d "$SOURCE_DIR" ]; then
    echo "error: source dir '$SOURCE_DIR' not exists or not a directory."
    exit 1
fi

> "$CORPUS_FILE"

success_count=0
failure_count=0

while IFS= read -r -d '' file; do
    abs_path=$(realpath "$file")
    
    if [ ! -f "$abs_path" ]; then
        continue
    fi

    if clang -fsyntax-only -w  "$abs_path"  2>/dev/null; then
        echo "$abs_path" >> "$CORPUS_FILE"
        success_count=$((success_count + 1))
    else
        failure_count=$((failure_count + 1))
        rm "$abs_path"
    fi

done < <(find "$SOURCE_DIR" -name "*.c" -type f ! -name "input*.c" -print0)