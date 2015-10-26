# About
This is an Node.js module implementing the Adaptive Huffman Coding algorithm described in Sayood's Data Compression book. The code was originally written by Id Software and Tim Angus and was compiled to Javascript using Emscripten. It was then turned into a Node.js module. The base code is taken from the ioQuake3 engine and thus this project is published under the same GNU license.

#Prerequisites
To use, the only prerequisite is to have node.js installed. If you wish to build then you need to have the appropriate build tools installed and setup as well as Emscripten if you wish to compile to JS.

#Using
Find the module `huffman.js` in the module directory. Use huffman compress as follows:
```JavaScript
//Parameters: String to compress, length of string, offset within string to start compression at.
var huff_compress = require('./huffman.js').cwrap('compress', 'string', ['string', 'number', 'number']);
var msg = "Hello, world!";
var compressed_msg = huff_compress(msg, msg.length, 3);
console.log(msg.length);
```
Would return: "Hel[compressed text]"

To avoid passing raw bytes from the module to the calling program, the module will return a string of hex codes representing the bytes of the encoded string. This string most be decoded into a buffer object.  You can use the following code snippet to do this for you:
```JavaScript
/*
  Convenience method which turns a space delimited string of octets into a buffer
*/
function hexStrToBuffer(hexStr) {
  var hexArr = new Array();
  var tokens = hexStr.split(" ");

  hexArr.push("0xFF");
  hexArr.push("0xFF");
  hexArr.push("0xFF");
  hexArr.push("0xFF");

  //find all the hex octets until the second null byte
  var firstNullHit = false;
  for(var i=0; i < tokens.length && (tokens[i] != 0 || !firstNullHit); i++) {
    hexArr.push("0x" + tokens[i]);
    if(tokens[i] == 0)
      firstNullHit = true;
  }

  var buffer = new Buffer(hexArr);
  return buffer;
}
```

#Building
To compile the C code to JS using Emscripten, please run: `make`

To compile the C code to a system executbale run: `make -f makefile.c`

# Good to Know
Currently only compresison is supported, decompression is a WIP. Uses the same prebuilt frequency table as the ioQuake3 engine. This frequency table can be modified in the common.h file.
