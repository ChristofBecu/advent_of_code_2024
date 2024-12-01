#!/bin/bash

set -e

BUILD_MODE="MinSizeRel" # Debug / Release / RelWithDebInfo / MinSizeRel / None
SOURCE_DIR="./"
BUILD_DIR="./build"
BUILD_OUTPUT_DIR="./build/output"

showUsage() {
    echo "Usage: ./build.sh [OPTION]"
    echo 
    echo "Options:"
    echo "  -b | --build  build the project"
    echo "  -c | --clean  clean up the build artifacts"
    echo "  -h | --help   show this help"
}

createDirectories() {
    mkdir -p "$BUILD_DIR"
    mkdir -p "$BUILD_OUTPUT_DIR"
}

clean() {
    echo "Cleaning build artifacts..."
    rm -rf "$BUILD_DIR"
    echo "Clean complete."
}

build() {
    if [ ! -d "$BUILD_DIR" ]; then
        echo "Creating build directory..."
        createDirectories
    fi
    # Run CMake to configure and generate build files
    echo "Configuring the project..."
    cmake -S "$SOURCE_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_MODE"

    # Build the project
    echo "Building the project..."
    cmake --build "$BUILD_DIR"
    echo "Build complete."
    run
}

run() {
    echo "Running the project..."
    "$BUILD_OUTPUT_DIR"/part1
    "$BUILD_OUTPUT_DIR"/part2
}


# Parse command line arguments
case "$1" in
    -h|--help)
        showUsage
        exit 0
        ;;
    -c|--clean)
        clean
        ;;
    -b|--build)
        build
        ;;
    *) 
        echo "Unknown option: $1"
        showUsage
        exit 1
        ;;
esac

