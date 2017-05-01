#!/usr/bin/python

def factor(step):
    if(step == 0) or (step == 1):
        return 1
    return step * factor(step - 1)
if __name__ == '__main__':
    print "factor 6: %d" % (factor(6))
