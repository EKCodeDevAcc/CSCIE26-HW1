#!/bin/sh
# processing script for train-numbers.html

    eval $(./qryparse)
    echo "Content-Type: text/plain"
    echo ""

    echo "A number of trains stop at $station on $day"
    ./train-numbers "$station" "$day"
