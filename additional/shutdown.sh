#! /bin/bash
if [ "$1" ]
then
    echo "kill port $1 process..."
else
    echo "please use parameter to define port number"
fi

pid=$( netstat -antp | grep :::$1 | awk '{split($7,a,"/");} print a[1]')
if [ "$pid" ]
then
    echo "kill pid $pid"
    kill -9 $pid
else
    echo "PID is NOT Found!"
fi
