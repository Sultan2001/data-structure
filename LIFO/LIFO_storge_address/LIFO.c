
#include "LIFO.h"


static uint_8 LIFO_is_full(LIFO_Buf_t * lifo_buf);
static uint_8 LIFO_is_empty(LIFO_Buf_t * lifo_buf);

LIFO_status LIFO_Add_item(LIFO_Buf_t * lifo_buf , void * item)
{
    LIFO_status ret=LIFO_no_error;
    if(NULL== lifo_buf )
        {
            ret=LIFO_NULL;

        }
    else
        {
            if(LIFO_is_full(lifo_buf))
            {
                ret=LIFO_full;

            }
            else
            {

                lifo_buf->Array_of_items[lifo_buf->top]=item;
                (lifo_buf->top)++;
                (lifo_buf->Count) ++;

            }



        }

return ret;
}
LIFO_status LIFO_get_item(LIFO_Buf_t * lifo_buf , void **item)
{

    LIFO_status ret=LIFO_no_error;
    if(NULL== lifo_buf)
        {
            ret=LIFO_NULL;

        }
    else
        {
            if(LIFO_is_empty(lifo_buf))
            {
                ret=LIFO_empty;

            }
            else
            {
                (lifo_buf->top)--;
                (lifo_buf->Count)--;
                 *item=lifo_buf->Array_of_items[lifo_buf->top];


            }


        }

return ret;

}
LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf , void ** buf , uint_32 length)
{

    LIFO_status ret=LIFO_no_error;
    if(NULL== lifo_buf || NULL == buf)
        {
            ret=LIFO_NULL;

        }
    else
        {
            lifo_buf->Count=0;
            lifo_buf->length=length;
            lifo_buf->top=0;
            lifo_buf->Array_of_items=buf;


        }

return ret;

}

static uint_8 LIFO_is_full(LIFO_Buf_t * lifo_buf)
{
    uint_8 status ;
    if(lifo_buf->Count >= lifo_buf->length)
    {
        status=1;
    }
    else
    {
        status=0;

    }

    return status;
}


static uint_8 LIFO_is_empty(LIFO_Buf_t * lifo_buf)
{
    uint_8 status ;
    if(lifo_buf->Count == 0)
    {
        status=1;
    }
    else
    {
        status=0;

    }

    return status;
}



