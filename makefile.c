all: clean huffman

huffman:
	gcc huffman.c

clean:
	rm -f ./a.out
