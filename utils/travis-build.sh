#!/bin/bash

echo "*****************************************"
echo "Building ghoAepp binary"
echo "*****************************************"

mkdir ../build; cd ../build/

cmake .. -GNinja
cmake --build .
