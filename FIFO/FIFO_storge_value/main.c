#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"


element_type buffer_1[5];
FIFO_status status;

int main()
{
    uint_32 i=0;
    uint_8 item=0;
    FIFO_Buf_t uart_fifo;
    FIFO_Buf_t I2C_fifo;

    // static allocation
    FIFO_init(&uart_fifo, buffer_1,5);

    // dynamic allocation
    element_type * buffer_2 = (element_type *)malloc(5*sizeof(element_type));
    FIFO_init(&I2C_fifo, buffer_2,5);

printf("------- test  uart Buffer -----\n");
printf("---- add\n");
    for ( i =0 ; i<3 ; i++)
    {
        status=FIFO_enqueue(&uart_fifo , i);
        if (status == FIFO_no_error)
        {
            printf("add %d\n",i);
        }
        else
        {
             printf("error : %d \n",status);

        }
    }

printf("---- get\n");

      for ( i =0 ; i<2 ; i++)
    {
        status=FIFO_dequeue(&uart_fifo , &item);
        if (status == FIFO_no_error)
        {
            printf("get %d\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }


    }
    printf("---- add\n");
    for ( i =0 ; i<5 ; i++)
    {
        status=FIFO_enqueue(&uart_fifo , i);
        if (status == FIFO_no_error)
        {
            printf("add %d\n",i);
        }
        else
        {
             printf("error : %d \n",status);

        }
    }

printf("---- get\n");

      for ( i =0 ; i<5 ; i++)
    {
        status=FIFO_dequeue(&uart_fifo , &item);
        if (status == FIFO_no_error)
        {
            printf("get %d\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }

    }

printf("-------- test  I2c Buffer -------\n");
printf("---- add\n");
    for ( i =0 ; i<5 ; i++)
    {
        status=FIFO_enqueue(&I2C_fifo , i);
        if (status == FIFO_no_error)
        {
            printf("add %d\n",i);
        }
        else
        {
             printf("error : %d \n",status);

        }
    }


printf("---- get\n");
      for ( i =0 ; i<5 ; i++)
    {
        status=FIFO_dequeue(&I2C_fifo , &item);
        if (status == FIFO_no_error)
        {
            printf("get %d\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }


    }




    return 0;
}
