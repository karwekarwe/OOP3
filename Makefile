CC = g++
CFLAGS = -Wall -std=c++17
TESTS = test/test_Vector.cpp test/catch_amalgamated.cpp vector/vector.h

.PHONY: all clean test

all: v0 #v1 v2 v3

v0: vector/3.0main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h vector/vector.h
	$(CC) $^ -o $@

#v1: vector/3.0main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h vector/vector.h
#	$(CC) $(CFLAGS) -O1 $^ -o $@

#v2: vector/3.0main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h vector/vector.h
#	$(CC) $(CFLAGS) -O2 $^ -o $@

#v3: vector/3.0main.cpp vector/ranka.cpp vector/failuGen.cpp vector/isFailo.cpp vector/papFunkcijos.cpp vector/rusiavimasGen.cpp vector/student.h vector/funkcijos.h vector/vector.h
#	$(CC) $(CFLAGS) -O3 $^ -o $@

test: $(TESTS)  vector/vector.h
	$(CC) $(CFLAGS) $^ -o tests
	./tests

clean:
	rm -f v0 tests

