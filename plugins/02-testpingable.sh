#!/bin/bash

testpingable()
{
    host=$1
    ping -c 2 "$1"
}
#main entry
#test below hosts is pingable or not
testpingable "192.168.0.199"
testpingable "192.168.0.190"
