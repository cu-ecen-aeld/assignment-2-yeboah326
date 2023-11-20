#!/bin/bash
set -u # Ensures that all arguments are specified

writefile=$1
writestr=$2
directory=$(dirname "$writefile")

if [ ! -e $directory ]; then
    echo "does not exist"
    mkdir -p $directory
fi

echo $writestr > $writefile
