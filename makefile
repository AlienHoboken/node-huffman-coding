all: clean huffman

huffman:
	emcc huffman.c -s LINKABLE=1 -s EXPORTED_FUNCTIONS="['_compress']" -o huffman.js

clean:
	rm -f ./huffman.js
