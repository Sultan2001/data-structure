
#ifndef _LIFO_h
#define _LIFO_h
#include "stdio.h"
#include "Platform_Types.h"

typedef struct {

void ** Array_of_items;
uint_32 length;
uint_32 Count;
uint_32 top;

}LIFO_Buf_t;


typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_NULL


}LIFO_status;


// APIS
LIFO_status LIFO_Add_item(LIFO_Buf_t * lifo_buf , void * item);
LIFO_status LIFO_get_item(LIFO_Buf_t * lifo_buf , void **item);
LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf , void ** buf , uint_32 length);







#endif // _LIFO_h
