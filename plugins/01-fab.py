#!/usr/bin/python

def fab(max):
    if (max == 1) or (max == 2):
        return 1

    return fab(max - 1) + fab(max - 2)

if __name__ == '__main__':
    print "fab 10: %d" % (fab(10))
