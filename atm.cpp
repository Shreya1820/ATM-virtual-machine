#include <iostream>

using namespace std;

struct node
{
    int atmno;
    int pin;
    int balance;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
        
    }

    void add_node(int no,int pin,int balance)
    {
        node *temp = new node;

        temp->atmno = no;
        temp->pin=pin;
        temp->balance=balance;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
            
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void withdraw(int no,int pin,int amount)
    {
      node *cur= new node;

      cur=head;

      while(cur->atmno != no)
      {
        cur=cur->next;
      }

      if(cur==NULL)
      {
        cout<<"Invalid atm card no.";
        return;
      }

       for(int i=3;i>0;i--)
      {
          if(cur->pin!=pin)
           {
              if(i==0)
              {
                  cout<<"\nNo attempts left.Please try after some time.";
                  return;
              }
              else
                  cout<<"\nIncorrect pin number.\n"<<--i<<" ateempts left";
            }
      }     
          if(cur->pin==pin && cur->atmno==no)
          {
            cur->balance=cur->balance - amount;
            cout<<"\nYour withdrawn amount is="<<amount;
            cout<<"\nYour balance is="<<cur->balance;
          }

    } 
    
    void deposit(int no,int pin,int amount)
    {
      node *cur= new node;

      cur=head;

      while(cur->atmno != no)
      {
        cur=cur->next;
      }
      if(cur == NULL)
      {
        cout<<"Invalid atm card no.";
        return;
      }


       for(int i=3;i>0;i--)
      {
          if(cur->pin!=pin)
           {
              if(i==0)
              {
                  cout<<"\nNo attempts left.Please try after some time.";
                  return;
              }
              else
                  cout<<"\nIncorrect pin number.\n"<<--i<<" ateempts left";
            }
      }     
          if(cur->pin==pin)
          {
            cur->balance=cur->balance + amount;
            cout<<"\nYour withdrawn amount is="<<amount;
            cout<<"\nYour balance is="<<cur->balance;
            return;
          }

    }

    void display(int no,int pin ,int amount)
    {
      node *cur= new node;

      cur=head;

      while(cur->atmno != no)
      {
        cur=cur->next;
      }
      if(cur == NULL)
      {
        cout<<"Invalid atm card no.";
        return;
      }

     for(int i=3;i>0;i--)
      {
          if(cur->pin!=pin)
           {
              if(i==0)
              {
                  cout<<"\nNo attempts left.Please try after some time.";
                  return;
              }
              else
                 cout<<"\nIncorrect pin number.\n"<<--i<<" attempts left";
            }
    }     
          if(cur->pin==pin)
          {
            cout<<"Your current balance="<<cur->balance;
            return;
          }


    }

    void transfer(int no, int pin)
    {
      node *cur= new node;

      int ac2,amount;

      cur=head;

      while(cur->atmno != no)
      {
        cur=cur->next;
      }

      if(cur==NULL)
      {
        cout<<"Invalid atm card no.";
        return;
      }

       for(int i=3;i>0;i--)
      {
          if(cur->pin!=pin)
           {
              if(i==0)
              {
                  cout<<"\nNo attempts left.Please try after some time.";
                  return;
              }
              else
                  cout<<"\nIncorrect pin number.\n"<<--i<<" ateempts left";
            }
      }     
          if(cur->pin==pin)
          {
            cout<<"Enter the account number of the account to be transfered:";
            cin>>ac2;
            cout<<"Enter the amount to be transferred:";
            cin>>amount;
            cur->balance=cur->balance - amount;
            cout<<"\nYou have transfered Rs."<<amount<<" to a/c no: "<<ac2;
            cout<<"\nYour balance is="<<cur->balance;
          }
 
    }

};

int main()
{
    linked_list a;

    int choice,card,pin,bal,amount;

    for(;;){

      cout<<"\n\t*************************MENU******************************";
			cout<<"\n\t*                        1)Create new account             *";
			cout<<"\n\t*                        2)Withdraw from Account          *";
			cout<<"\n\t*                        3)Deposit to Account             *";
			cout<<"\n\t*                        4)Transfer to an Account         *";
			cout<<"\n\t*                        5)Check Balance                  *";
			cout<<"\n\t*                        6)Exit                           *";
			cout<<"\n\t*************************MENU******************************";
      cout<<"\nChoose an option from the below menu:\n";
			cin>>choice;
    
    switch(choice)
    {
      case 1:cout<<"Enter your card no:";
             cin>>card;
             cout<<"Enter your pin:";
             cin>>pin;
             cout<<"Deposit money to activate your account:";
             cin>>bal;
             a.add_node(card,pin,bal);
             break;

      case 2:cout<<"Enter your card no:";
             cin>>card;
             cout<<"Enter your pin:";
             cin>>pin;
             cout<<"Enter the amount to be withdrawn:";
             cin>>amount; 
             a.withdraw(card,pin,amount);
             break; 

      case 3:cout<<"Enter your card no:";
             cin>>card;
             cout<<"Enter your pin:";
             cin>>pin;
             cout<<"Enter the amount to be deposited:";
             cin>>amount;
             a.deposit(card,pin,amount);
             break;     

      case 4:cout<<"Enter your card no:";
             cin>>card;
             cout<<"Enter your pin:";
             cin>>pin;
             a.transfer(card,pin);
             break;

      case 5:cout<<"Enter your card no:";
             cin>>card;
             cout<<"Enter your pin:";
             cin>>pin;
             a.display(card,pin,amount);
             break;       


               

      default:cout<<"********************************************************";
              cout<<"*          Thank You!! Visit Again!!                   *";
              cout<<"********************************************************";
               return 0;       
    }

    }

    
    return 0;
}
