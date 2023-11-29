
#include "LIFO.h"

static uint_8 LIFO_is_full(LIFO_Buf_t * lifo_buf);
static uint_8 LIFO_is_empty(LIFO_Buf_t * lifo_buf);
LIFO_status LIFO_Add_item(LIFO_Buf_t * lifo_buf , uint_32 item)
{
    LIFO_status status = LIFO_no_error;
    if(lifo_buf->base == NULL || lifo_buf->Head == NULL || lifo_buf==NULL)
    {
        status=LIFO_NULL;

    }
    else
    {
        if(LIFO_is_full(lifo_buf))
        {
            status=LIFO_full;

        }
        else
        {
            *(lifo_buf->Head) = item;
            lifo_buf->Count ++;
            lifo_buf->Head ++;

        }

    }

return status;
}
LIFO_status LIFO_get_item(LIFO_Buf_t * lifo_buf , uint_32 *item)
{
 LIFO_status status = LIFO_no_error;
    if(lifo_buf->base == NULL || lifo_buf->Head == NULL || lifo_buf==NULL || item==NULL)
    {
        status=LIFO_NULL;

    }
    else
    {
        if(LIFO_is_empty(lifo_buf))
        {
            status=LIFO_empty;

        }
        else
        {
            lifo_buf->Count --;
            lifo_buf->Head --;
             *item =*(lifo_buf->Head);


        }

    }

return status;
}
LIFO_status LIFO_init(LIFO_Buf_t * lifo_buf , uint_32 * buf , uint_32 length)
{

    LIFO_status status = LIFO_no_error;
    if(lifo_buf == NULL || buf==NULL)
    {

        status = LIFO_NULL;
    }
    else
    {
        lifo_buf->base = buf;
        lifo_buf->Head=buf;
        lifo_buf ->length= length;
        lifo_buf->Count = 0;


    }



    return status;
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
