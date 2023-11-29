#ifndef _LIFO_H
#define _LIFO_H

#include "Platform_Types.h"

#include "stdio.h"

//type definitions

typedef struct LIFO_Buf
{
    uint_32 length;
    uint_32 Count;
    uint_32 * Head;
    uint_32 * base;


}LIFO_Buf_t;


typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_NULL


}LIFO_status;




//APIs
LIFO_status LIFO_Add_item(LIFO_Buf_t * lifo_buf , uint_32 item);
LIFO_status LIFO_get_item(LIFO_Buf_t * lifo_buf , uint_32 *item);
LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf , uint_32 * buf , uint_32 length);












#endif // _LIFO_H
