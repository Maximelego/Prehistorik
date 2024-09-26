#/bin/bash

function install_sdl2() {
    echo "[STATUS] - Installing the necessary SDL2 libraries..."

    sudo apt install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-2.0-0
    sudo apt install libsdl2-dev libsdl2-gfx-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-ttf-dev

    echo "[STATUS] - Done !"
}

function install_doxygen() {
    echo "[STATUS] - Installing the necessary SDL2 libraries..."
    sudo apt install doxygen
    echo "[STATUS] - Done !"
}   

echo "[INFO] - Installing dependancies !"

install_sdl2
install_doxygen