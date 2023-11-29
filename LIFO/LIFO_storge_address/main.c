#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"
#include "Platform_Types.h"
void * buffer_1[5];
LIFO_status status;

int main()
{
    void * item=NULL;
    LIFO_Buf_t uart_lifo;
    LIFO_Buf_t I2C_lifo;

    // static allocation
    LIFO_init(&uart_lifo, buffer_1,5);

    // dynamic allocation
    void ** buffer_2 = (void **)malloc(2*sizeof(void *));
    LIFO_init(&I2C_lifo, buffer_2,2);



printf("------- test  uart Buffer -----\n");
printf("---- add\n");
uint_8 v1=22;
double v2=2.4;
uint_8 v3='b';
status=LIFO_Add_item(&uart_lifo , &v1);
        if (status == LIFO_no_error)
        {
            printf("add 0x%x\n",&v1);

        }
        else
        {
             printf("error : %d \n",status);

        }

status=LIFO_Add_item(&uart_lifo , &v2);
        if (status == LIFO_no_error)
        {
            printf("add 0x%x\n",&v2);
        }
        else
        {
             printf("error : %d \n",status);

        }

    printf("---- get\n");
     status=LIFO_get_item(&uart_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);
            printf("get %f\n",*(double*)item);

        }
        else
        {
            printf("error : %d \n",status);

        }
    status=LIFO_get_item(&uart_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);
            printf("get %i\n",*(uint_8*)item);
        }
        else
        {
            printf("error : %d \n",status);

        }
    status=LIFO_get_item(&uart_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }


printf("-------- test  I2c Buffer -------\n");
printf("---- add\n");

status=LIFO_Add_item(&I2C_lifo , &v1);
        if (status == LIFO_no_error)
        {
            printf("add 0x%x\n",&v1);
        }
        else
        {
             printf("error : %d \n",status);

        }

status=LIFO_Add_item(&I2C_lifo , &v2);
        if (status == LIFO_no_error)
        {
            printf("add 0x%x\n",&v2);
        }
        else
        {
             printf("error : %d \n",status);

        }
status=LIFO_Add_item(&I2C_lifo , &v3);
        if (status == LIFO_no_error)
        {
            printf("add 0x%x\n",&v3);
        }
        else
        {
             printf("error : %d \n",status);

        }

    printf("---- get\n");
     status=LIFO_get_item(&I2C_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }
    status=LIFO_get_item(&I2C_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }
    status=LIFO_get_item(&I2C_lifo , &item);
        if (status == LIFO_no_error)
        {
            printf("get 0x%x\n",item);

        }
        else
        {
            printf("error : %d \n",status);

        }
return 0;
}
