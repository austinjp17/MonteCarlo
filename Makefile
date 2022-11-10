build:
	g++ mcpi_part1.cxx -g -O2 -o m1.o
	g++ mcpi_part3.cxx -g -O2 -o m3.o
clean:
	rm -rf *.o