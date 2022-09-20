#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"operations.h"
extern  customer_t arr[5];
extern int cont;

void add_new_customer(int x)
{
    printf("Enter customer name\n");
    fflush(stdin);
    gets(arr[x].name);
    printf("Enter customer balance\n");
    scanf("%lf",&arr[x].balance);
    type:printf("Enter account type\n");
    fflush(stdin);
    gets(arr[x].type);
    if(strcmp(arr[x].type,"debit")&&strcmp(arr[x].type,"credit"))
    {
        printf("Enter a valid account type,debit or credit\n");
        goto type;
    }
    printf("Enter customer id\n");
    scanf("%i",&arr[x].id);


}
void edit_customer(int x)
{
    printf("customer id=%i\n\n",arr[x].id);
    add_new_customer(x);
}
void print_customer(int x)
{
    printf("customer name= %s\n",arr[x].name);
    printf("customer balance= %lf\n",arr[x].balance);
    printf("account type= %s\n",arr[x].type);
    printf("account id= %i\n",arr[x].id);
}
void transfer_money(int source_id,int destination_id,double amount)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        if(arr[i].id==source_id)
        {
            break;
        }
    }
    for(j=0;j<5;j++)
    {
        if(arr[j].id==destination_id)
        {
            break;
        }
    }
    arr[i].balance-=amount;
    arr[j].balance+=amount;
    printf("transfer is done\n\n");
}
void delete_customer(int i)
{
    strcpy(arr[i].name,"unknown");
    arr[i].balance=0;
    strcpy(arr[i].type,"unknown");
    arr[i].id=0;
    printf("customer has been deleted\n\n");
}
void rearrange(int deleted)
{
    while(deleted<50)
    {
        arr[deleted]=arr[deleted+1];
        deleted++;
    }
    cont=9;
}
