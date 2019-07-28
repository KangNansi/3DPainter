#!/bin/sh

echo "Building 3DPainter..."

#Bash parameters
set -e

#Utils functions
call () {
    echo "$@"
    "$@"
}

compile () {
    for i in $1
    do
        echo "Compiling $i..."
        g++ -c -o ${i/src/obj} $i $2
    done
}

# Check folders
[ ! -d "./obj" ] && mkdir ./obj
[ ! -d "./bin" ] && mkdir ./bin

# Parameters
GTK_FLAGS=`pkg-config gtkmm-3.0 --cflags`
GTK_LIBS=`pkg-config gtkmm-3.0 --libs`

SRC_WIDGETS=$(find ./src/widgets -name *.cpp)

compile "$SRC_WIDGETS" "$GTK_FLAGS"

# Build objs
call g++ -c -o obj/main.o src/main.cpp $GTK_FLAGS

#Build program
call g++ -o ./bin/3DPainter obj/main.o $GTK_LIBS


