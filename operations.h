#ifndef bank_H
#define bank_H
void add_new_customer(int x);
void edit_customer(int x);
void print_customer(int x);
void transfer_money(int source_id,int destination_id,double amount);
void delete_customer(int i);
void rearrange(int deleted);
typedef struct cust
{
  char name[50];
  double balance;
  char type[8];
  int id;
}customer_t;

#endif
