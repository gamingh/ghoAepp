#!/bin/bash

echo "*****************************************"
echo "Building ghoAepp binary"
echo "*****************************************"

mkdir ../build; cd ../build/

cmake ..
make -j$(nproc)
