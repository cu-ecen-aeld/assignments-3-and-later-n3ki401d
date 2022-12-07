#!/usr/bin/bash

if [ $# -lt 2 ];
then
    if [ $# -lt 1 ]
    then
        echo "Parameters 'writefile' and 'writestr' not specified!"
    else
        echo "Parameter 'writestr' not specified!"
    fi
    exit 1
else
    fullPath=$1
    writeStr=$2
fi

dirsPath=${fullPath%/*}
fileName=${fullPath##*/}

mkdir -p ${dirsPath}
echo ${writeStr} > ${dirsPath}/${fileName}
