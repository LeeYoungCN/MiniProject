#ifndef PUBLIC_DEF_H
#define PUBLIC_DEF_H
#include <iostream>

typedef char            UINT8;
typedef unsigned int    UINT32;
typedef int             SINT32;
typedef size_t          UINT64;

#define ITEM_OF(arr) static_cast<UINT32>(sizeof(arr)/sizeof(arr[0]))


#endif // PUBLIC_DEF_H