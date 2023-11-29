
#ifndef _FIFO_H
#define _FIFO_H

#include "Platform_Types.h"
#include "stdio.h"




#define element_type uint_16


typedef struct {

uint_32 length;
uint_32 Count;
element_type * head;
element_type * tail;
element_type * base;

}FIFO_Buf_t;

typedef enum {
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_NULL,



}FIFO_status;



//APIs
FIFO_status FIFO_init(FIFO_Buf_t * fifo_buf , element_type * buf , uint_32 length);
FIFO_status FIFO_enqueue(FIFO_Buf_t * fifo_buf , element_type item);
FIFO_status FIFO_dequeue(FIFO_Buf_t * fifo_buf , element_type *item);
FIFO_status FIFO_is_full(FIFO_Buf_t * fifo_buf);
FIFO_status FIFO_is_empty(FIFO_Buf_t * fifo_buf);



#endif // _FIFO_H
