#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"operations.h"
#define SIZE 5
customer_t arr[SIZE];
int cont=0;

int main()
{
    int counter=0,operation;

label :printf("please choose what you want to do\n\n\
add new customer...enter 1\n\
edit customer...enter 2\n\
print customer data...enter 3\n\
transfer money...enter 4\n\
delete customer data...enter 5\n");
    scanf("%i",&operation);
    if(operation==1)
    {
        if(cont<SIZE)
        {
            add_new_customer(cont);
            cont++;
            printf("if you want to make another operation press 1\n");
            scanf("%i",&counter);
            if(counter==1)
            {
                goto label;
            }
        }
        else
        {
           printf("maximum number has reached,you can not add new customer\n");
           goto label;
        }
    }
    else if(operation==2)
    {   int id,i;
        int cont=0;
        printf("Enter customer id\n");
        scanf("%i",&id);
        for(i=0;i<5;i++)
        {
            if(arr[i].id==id)
            {
                edit_customer(i);
                break;
            }
        }
        printf("if you want to make another operation press 1\n");
        scanf("%i",&cont);
                if(cont==1)
        {
            goto label;
        }
    }
    else if(operation==3)
    {   int id,i;
        int cont=0;
        printf("Enter customer id\n\n");
        scanf("%i",&id);
        for(i=0;i<5;i++)
        {
            if(arr[i].id==id)
            {
                print_customer(i);
                break;
            }
        }
        printf("if you want to make another operation press 1\n");
        scanf("%i",&cont);
        if(cont==1)
        {
            goto label;
        }
    }
    else if(operation==4)
    {
        int cont=0;
        int source,destination;
        double amount;
        printf("transfer money from account id?\t");
        scanf("%i",&source);
        printf("transfer money to account id?\t");
        scanf("%i",&destination);
        printf("amount of money?\t");
        scanf("%lf",&amount);
        transfer_money(source,destination,amount);
        printf("if you want to make another operation press 1\n");
        scanf("%i",&cont);
        if(cont==1)
        {
            goto label;
        }

    }
    else if(operation==5)
    {   int id,i;
        printf("enter account id to be deleted\n");
        scanf("%i",&id);
        for(i=0;i<5;i++)
        {
            if(arr[i].id==id)
                break;
        }
        delete_customer(i);
        rearrange(i);
        printf("if you want to make another operation press 1\n");
        scanf("%i",&cont);
        if(cont==1)
        {
            goto label;
        }
    }


    return 0;
}
