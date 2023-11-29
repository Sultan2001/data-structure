
#include "FIFO.h"




FIFO_status FIFO_init(FIFO_Buf_t * fifo_buf , element_type * buf , uint_32 length)
{
    FIFO_status ret=FIFO_no_error;
    if(NULL == fifo_buf || NULL==buf )
    {
        ret=FIFO_NULL;

    }
    else
    {

        fifo_buf->Count=0;
        fifo_buf->length=length;
        fifo_buf->base=buf;
        fifo_buf->head=buf;
        fifo_buf->tail=buf;
    }

    return ret;

}
FIFO_status FIFO_enqueue(FIFO_Buf_t * fifo_buf , element_type item)
{
   FIFO_status ret=FIFO_no_error;
    if(NULL == fifo_buf)
    {
        ret=FIFO_NULL;

    }
    else
    {
        if(FIFO_full == FIFO_is_full(fifo_buf))
        {

            ret=FIFO_full;
        }
        else
        {

            *(fifo_buf->head)=item;

            (fifo_buf->Count)++;
            // to make circuler fifo
            if(fifo_buf->head == fifo_buf->base + fifo_buf->length )
            {

                 fifo_buf->head =fifo_buf->base;
            }
            else
            {
                 (fifo_buf->head)++;

            }
        }

    }

    return ret;

}
FIFO_status FIFO_dequeue(FIFO_Buf_t * fifo_buf , element_type *item)
{
   FIFO_status ret=FIFO_no_error;
    if(NULL == fifo_buf)
    {
        ret=FIFO_NULL;

    }
    else
    {
        if(FIFO_empty == FIFO_is_empty(fifo_buf))
        {

            ret=FIFO_empty;
        }
        else
        {
            *item=*(fifo_buf->tail);
            (fifo_buf->Count)--;
        // to make circuler fifo
        if(fifo_buf->tail == fifo_buf->base + fifo_buf->length )
        {
            fifo_buf->tail = fifo_buf->base;

        }
        else
        {
            (fifo_buf->tail)++;

        }

        }

    }

    return ret;

}

FIFO_status FIFO_is_full(FIFO_Buf_t * fifo_buf)
{
    FIFO_status ret=FIFO_no_error;
    if(NULL == fifo_buf)
    {
        ret=FIFO_NULL;

    }
    else
    {

        if(fifo_buf->Count >= fifo_buf->length)
        {

            ret=FIFO_full;
        }
        else
        {
            ret=FIFO_no_error;
        }
    }

    return ret;

}
FIFO_status FIFO_is_empty(FIFO_Buf_t * fifo_buf)
{
    FIFO_status ret=FIFO_no_error;
    if(NULL == fifo_buf)
    {
        ret=FIFO_NULL;

    }
    else
    {
        if(fifo_buf->Count == 0 )
        {

            ret=FIFO_empty;
        }
        else
        {
            ret=FIFO_no_error;
        }

    }

    return ret;


}
