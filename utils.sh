#/bin/bash

CLEAN_ARG="clean"
BUILD_ARG="build"
RUN_ARG="run"



function clean_project() {
    echo "[INFO] - Cleaning build files..."
    rm -r ./build
    echo "[INFO] - Done !"
}

function build_project() {
    echo "[STATUS] - Starting build..."
    mkdir ./build
    cd ./build

    echo "[STATUS] - Creating Makefile..."
    cmake ../CMakeLists.txt

    echo "[STATUS] - Building executable..."
    make

    echo "[STATUS] - Copying resources..."
    cp -r ../Ressources ./Ressources

    cd ..

    echo "[STATUS] - Done !"
}

function run_project() {
    ./build/Prehistoric
}


if [[ -z $1 ]] then
    echo "[ERROR] - No Argument was specified ! Please provide a correct argument and try again."
else

    if [[ "$1" == "$CLEAN_ARG" ]] then
        clean_project
    elif [[ "$1" == "$BUILD_ARG" ]] then
        build_project
    elif [[ "$1" == "$RUN_ARG" ]] then
        run_project
    else 
        echo "[ERROR] - Unknown argument ! Valid arguments are clean, build or run."
    fi
fi
