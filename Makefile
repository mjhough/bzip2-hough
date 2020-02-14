CC=g++
CPPFLAGS_XML2 = $(shell xml2-config --cflags)
CPPFLAGS_CURL = $(shell curl-config --cflags)
CPPFLAGS=-Wall -g $(CPPFLAGS_CURL) $(CPPFLAGS_XML2)
LD=g++
LDLIBS_XML2 = $(shell xml2-config --libs)
LDLIBS_CURL = $(shell curl-config --libs)
LDLIBS= $(LDLIBS_XML2) $(LDLIBS_CURL)
BIN=bzip2-hough

OBJS = bzip2-hough.o BurrowsWheelerTransform.o BWTElement.o MoveToFrontTransform.o RunLengthEncoding.o HuffmanNode.o HuffmanEncoding.o EncodingStep.o

all: bzip2-hough

bzip2-hough: $(OBJS)
	$(LD) $(CPPFLAGS) -o $@ $(OBJS) $(LDLIBS)

.c.o:
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *.out $(BIN) *.png *.html
