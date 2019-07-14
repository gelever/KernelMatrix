#!/bin/sh

BASE_DIR=${PWD}
BUILD_DIR=${BASE_DIR}/build
EXTRA_ARGS=$@

mkdir -p $BUILD_DIR
cd $BUILD_DIR

rm CMakeCache.txt
rm -rf CMakeFiles

BUILD_TYPE=Debug

CC=gcc CXX=g++ cmake \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    ${BASE_DIR} \
    ${EXTRA_ARGS}
