#!/usr/bin/bash

if [ $# -lt 2 ];
then
    if [ $# -lt 1 ]
    then
        echo "Parameters 'filesdir' and 'searchstr' not specified!"
    else
        echo "Parameter 'searchstr' not specified!"
    fi
    exit 1
else
    filesDir=$1
    searchStr=$2
fi

files=`grep -i -l -r $searchStr $filesDir | wc -l`
lines=`grep -i -r $searchStr $filesDir | wc -l`

echo "The number of files are ${files} and the number of matching lines are ${lines}"
