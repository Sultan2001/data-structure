#include <stdio.h>
#include <stdlib.h>

#include "LIFO.h"
#include "Platform_Types.h"
uint_32 buffer_1[5]; //5*sizeof(uint_32) = 200 byte
LIFO_status status;

int main()
{
    uint_32 i=0;
    uint_32 item=0;
    LIFO_Buf_t uart_lifo;
    LIFO_Buf_t I2C_lifo;

    // static allocation
    LIFO_init(&uart_lifo, buffer_1,5);

    // dynamic allocation
    uint_32 * buffer_2 = (uint_32 *)malloc(5*sizeof(uint_32));
    LIFO_init(&I2C_lifo, buffer_2,5);

printf("------- test  uart Buffer -----\n");
printf("---- add\n");
    for ( i =0 ; i<5 ; i++)
    {
        status=LIFO_Add_item(&uart_lifo , i);
        if (status == LIFO_no_error)
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
        status=LIFO_get_item(&uart_lifo , &item);
        if (status == LIFO_no_error)
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
        status=LIFO_Add_item(&I2C_lifo , i);
        if (status == LIFO_no_error)
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
        status=LIFO_get_item(&I2C_lifo , &item);
        if (status == LIFO_no_error)
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
