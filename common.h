//
// Necessary definitions taken from the Quake 3 engine
//


//#include <stddef.h>

#include <stdlib.h>

//#include <sys/types.h>

//#include <stdio.h>

typedef unsigned char                byte;
typedef enum {qfalse, qtrue}    qboolean;

#define NYT HMAX                                      /* NYT = Not Yet Transmitted */
#define INTERNAL_NODE (HMAX+1)
#define MAX_MSGLEN                              16384           // max length of a message, which may
                                                                                        // be fragmented into multiple packets
#define Com_Memset memset
#define Com_Memcpy memcpy

typedef struct {
        qboolean        allowoverflow;  // if false, do a Com_Error
        qboolean        overflowed;             // set to true if the buffer size failed (with allowoverflow set)
        qboolean        oob;                    // set to true if the buffer size failed (with allowoverflow set)
        byte    *data;
        int             maxsize;
        int             cursize;
        int             readcount;
        int             bit;                            // for bitwise reads and writes
} msg_t;

typedef struct nodetype {
        struct  nodetype *left, *right, *parent; /* tree structure */
        struct  nodetype *next, *prev; /* doubly-linked list */
        struct  nodetype **head; /* highest ranked node in block */
        int             weight;
        int             symbol;
} node_t;

#define HMAX 256 /* Maximum symbol */

typedef struct {
        int                     blocNode;
        int                     blocPtrs;

        node_t*         tree;
        node_t*         lhead;
        node_t*         ltail;
        node_t*         loc[HMAX+1];
        node_t**        freelist;

        node_t          nodeList[768];
        node_t*         nodePtrs[768];
} huff_t;

typedef struct {
        huff_t          compressor;
        huff_t          decompressor;
} huffman_t;

