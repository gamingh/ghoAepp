#!/bin/bash

echo "*****************************************"
echo "Building Kaidan binary"
echo "*****************************************"

mkdir ../build; cd ../build/

cmake ..
make -j$(nproc)
