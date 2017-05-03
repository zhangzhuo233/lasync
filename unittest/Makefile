.PHONY: all
.PHONY: clean
.PHONY: lib

OBJS = $(shell objs="" ; for file in `ls *.cpp *.c 2>/dev/null` ; do obj=`echo $$file |sed -r 's/(.*)\.(c|cpp)/\1/g'`; objs="$$objs $$obj" ; done ; echo $$objs)

CXXFLAGS = -g -I ../lib ../lib/*.o


all: lib $(OBJS)

lib:
	cd ../lib; $(MAKE)

clean:
	rm -fr $(OBJS) ../lib/*.o Test-??????
