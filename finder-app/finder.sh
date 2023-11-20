#!/bin/bash

set -u

filesdir=$1
searchstr=$2

NUM_OF_MATCHES=0
NUM_OF_FILES=0

if [ -e $filesdir ]; then
    for file in $filesdir/*; do
        NUM_OF_FILES=$((NUM_OF_FILES + 1))
        ((NUM_OF_MATCHES+=$(grep -c $searchstr $file)))
    done

    echo "The number of files are $NUM_OF_FILES and the number of matching lines are $NUM_OF_MATCHES"
else
    exit 1
fi
