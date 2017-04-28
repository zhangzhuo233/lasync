.PHONY: all
.PHONY: clean

OBJS = $(shell objs="" ; for file in `ls *.cpp *.c 2>/dev/null` ; do obj=`echo $$file |sed -r 's/(.*)\.(c|cpp)/\1.o/g'`; objs="$$objs $$obj" ; done ; echo $$objs)

CXXFLAGS = -g
all: $(OBJS)

clean:
	rm -fr $(OBJS)
