OBJS = \
	bin/Object.o\
	bin/NSEW.o\
	bin/EastCCW.o \
	bin/PolarCW.o \
	bin/Track.o \
	bin/LinearTrack.o \
	bin/CornerTrack.o \
	bin/TriangularTrack.o \
	bin/RectangularTrack.o \
	bin/CrossTrack.o \
	bin/Cell.o \
	bin/Map.o \
	bin/CarTrait.o \
	bin/Car.o \

all: ${OBJS} bin/test/.test.success
#	gcc -o kcs ${OBJS} -lSDL -lSDL_image -lstdc++

TEST_OBJS = \
	${OBJS}\
	bin/test/TracksTestCase.o\
	bin/test/runtest.o

bin/test/runtest.o: src/test/runtest.cpp bin/test/TracksTestCase.o
	gcc -g -W -Wall -c -o $@ $< ${CFLAGS}

bin/test/runtest: ${TEST_OBJS}
	gcc -o bin/test/runtest ${TEST_OBJS} -lstdc++ -lcppunit
	
test: bin/test/runtest
	@bin/test/runtest
	@touch bin/test/.test.success

check: test

bin/test/.test.success: bin/test/runtest
	@bin/test/runtest
	@touch bin/test/.test.success
	@if [ ! -d bin/test ]; then echo "mkdir bin/test" && mkdir bin/test; fi

clean:
	rm -rf bin doc tracks.src.tar.gz

bin/%.o: src/%.cpp src/%.h
	@if [ ! -d bin ]; then echo "mkdir bin" && mkdir bin; fi
	@if [ ! -d bin/test ]; then echo "mkdir bin/test" && mkdir bin/test; fi
	gcc -g -W -Wall -c -o $@ $< -Isrc ${CFLAGS}

tar:
	tar -czvf tracks.src.tar.gz src Makefile

doc: doxygen

doxygen:
	doxygen src/Doxyfile
