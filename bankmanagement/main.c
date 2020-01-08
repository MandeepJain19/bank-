#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void ask();
void login();
void createaccount();
void mainmenu();
void update();
void trans();
void balance();
void deleteacc();
void atm();
void close();
void fordelay();
struct bank
{
    char date[10],name[20],address[30];
    int accno,age,phnum,pin;
    float amt;
}head,updatee;
int main()
{
    mainmenu();
    getch();
}
//void ask()
//{
//    int check;
//    printf("BANK MANAGEMENT ");
//    printf("\n enter 1 for existing coustomer enter 2 for new account ");
//    scanf("%d",&check);
//    if(check==1)
//    {
//        login();
//    }
//    else if(check==2)
//    {
//        createaccount();
//    }
//    else
//    {
//        printf("\tenter correct number ");
//        ask();
//    }
//
//}
//void login()
//{
//    char uname[20];
//    int pass;
//    printf("\n");
//    printf("\tEnter Username : ");
//    scanf("%s",uname);
//    printf("\n");
//    printf("\tEnter password : ");
//    scanf("%d",&pass);
//    if((strcmp(uname,"mandeep")==0)&&(pass==1234))//return zero when 2 string is same
//    {
//        printf("\tHELLO %s",uname);
//        mainmenu();
//    }
//    else
//    {
//        printf("enter the correct username and password ");
//        login();
//    }
//
//}
void createaccount()
{
    system("cls");

    struct bank create,ch;
    FILE *fp;
int choice;
  printf("\n\n\n\t\t\t\tCREATE ACCOUNT\n");
    fp=fopen("detail.txt","a");
    printf("\n\tEnter Account number : ");
    scanf("%d",&create.accno);
    printf("\n\tEnter Name : ");
    scanf("%s",create.name);
    printf("\n\tEnter current date : ");
    scanf("%s",create.date);
     printf("\n\tEnter phone number : ");
     scanf("%d",&create.phnum);
    printf("\n\tEnter your Age : ");
    scanf("%d",&create.age);
    printf("\n\tEnter your Address : ");
    scanf("%s",create.address);
    printf("\n\tEnter Cash you want deposite : ");
    scanf("%f",&create.amt);
    printf("\n\tEnter Pin : ");
    scanf("%d",&create.pin);
//    while(fscanf(fp,"%s %d %s %d %d %s %f %d",ch.date,&ch.accno,ch.name,&ch.phnum,&ch.age,ch.address,&ch.amt,&ch.pin)
//          {
//            if(ch.accno==create.accno)
//            {
//                printf("\n\t\t Account number already exist");
//            }
//          }
    fprintf(fp,"%s %d %s %d %d %s %f %d\n",create.date,create.accno,create.name,create.phnum,create.age,create.address,create.amt,create.pin);
    fclose(fp);
printf("\n\tBank account created sucsesfully ");
printf("\nFor Mainmenu press 1 to exit press 2 ");
scanf("%d",&choice);
if(choice==1)
{
    system("cls");
    mainmenu();
}
else{
    close();
}


}
void mainmenu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\tWELCOME BANK MANAGEMENT SYSTEM\n");
    printf("\n\t\t\t\t[1] Update Account Information\n ");
    printf("\t\t\t\t[2] Transaction\n");
    printf("\t\t\t\t[3] Check balance\n ");
    printf("\t\t\t\t[4] Delete Account\n");
    printf("\t\t\t\t[5] Create Account\n ");
    printf("\t\t\t\t[6] Exit ");

    printf("\n\t\t\tEnter respective number for the following ");
    scanf("%d",&choice);
      printf("\n\tLoading");
          for(int i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
    if(choice==1)
    {
        int i;

        system("cls");
        update();
    }
    else if(choice==2)
    {
        system("cls");
        trans();
    }
    else if(choice==3)
    {
        system("cls");
        balance();
    }
    else if (choice==4)
    {
        system("cls");
        deleteacc();
    }

    else if(choice==5)
    {
        createaccount();
    }
    else if (choice==6)
    {
        exit(1);
    }
    else
    {
        printf("\n\t\t\t\tEnter valid number ");
        fordelay(100000000000000000);
        system("cls");
        mainmenu();
    }

}
void update()
{
    FILE *neww,*old;
    int x,i;
    int choice;
    old=fopen("detail.txt","r");
    neww=fopen("new.txt","a");//new file to updatation
    printf("\n\n\n\t\t\t\t\t\tUPDATE ACCOUNT\n\n\n");
    printf("\t\tEnter the Account number you want to update : ");
    scanf("%d",&updatee.accno);
    printf("\n\t\tEnter Pin ");
    scanf("%d",&updatee.pin);
    while(fscanf(old,"%s %d %s  %d %d %s %f %d ",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)//scan each n every data of file and save in variables
    {
        if((head.accno==updatee.accno)&&(head.pin==updatee.pin))
        {
            x=1;
            printf("\n\t\t Enter 1 to update phone number and enter 2 for update address ");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n\t\tEnter new Phone number : ");
                scanf("%d",&updatee.phnum);
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,updatee.phnum,head.age,head.address,head.amt,head.pin );//update num will printed in new file
                printf("\n\tUpdating ");
                 for(int i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(". ");

                }
                printf("\n\t Changes Saved");
                printf("\nPress any key to exit");
            }
            else if (choice==2)
            {
                printf("\n\t\tEnter new Address : ");
                scanf("%s",updatee.address);
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,updatee.address,head.amt,head.pin );
                 printf("\n\tUpdating ");
                 for(int i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(". ");

                }
                printf("\n\t Changes Saved");
                printf("\nPress any key to exit");            }
        }

        else
           {
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
           }
    }
    if(x!=1)
    {
        printf("\n\tCheck Account Number and Pin ");
    }
    fclose(old);
    fclose(neww);
    old=fopen("detail.txt","w");//delete data of file
    fclose(old);
    old=fopen("detail.txt","a");//write new data
    neww=fopen("new.txt","r");
    while(fscanf(neww,"%s %d %s %d %d %s %f %d",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)
    {
                fprintf(old,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
    }
    fclose(neww);
    fclose(old);
    remove("new.txt");
}
void trans()
{

    struct bank trans;
    FILE *old,*neww;
    old=fopen("detail.txt","r");
    neww=fopen("new.txt","a");
    int n,x;
    float addamt,lessamt;
    printf("\n\n\n\t\t\t\t\t\tTRANSACTION");
    printf("\n\n\t\tEnter Account number for this transaction : ");
    scanf("%d",&updatee.accno);
     printf("\n\t\tEnter Pin ");
    scanf("%d",&updatee.pin);
    while(fscanf(old,"%s %d %s %d %d %s %f %d ",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)//scan each n every data of file and save in variables
    {
        if((head.accno==updatee.accno)&&(head.pin==updatee.pin))
        {
            x=1;
           printf("\n\t\tEnter 1 for Deposite 2 for withdrawal : ");
           scanf("%d",&n);
           if(n==1)
           {
               printf("\n\t\tEnter Amount to be deposite ");
               scanf("%f",&trans.amt);
               head.amt=head.amt+trans.amt;
               printf("\n\n\t\t %f Deposited in your Bank Account ",trans.amt);
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
                 printf("\n\tprocessing ");
                 for(int i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(". ");

                }
                printf("\n\t Done");
                printf("\nPress any key to exit");
           }
           else if(n=2)
           {
               printf("\n\t\tEnter Amount to withdrawal ");
               scanf("%f",&trans.amt);
               head.amt=head.amt-trans.amt;
                printf("\n\n\t\t %f Withdrawal from your Bank Account ",trans.amt);
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
                printf("\n\tprocessing ");
                 for(int i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(". ");

                }
                printf("\n\t Done");
                printf("\n Press any key to exit");
           }
        }
        else
        {
                fprintf(neww,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
        }
    }
       if(x!=1)
    {
        printf("\n\tCheck Account Number and Pin ");
    }
    fclose(old);
    fclose(neww);
    old=fopen("detail.txt","w");//delete data of file
    fclose(old);
    old=fopen("detail.txt","a");//write new data
    neww=fopen("new.txt","r");
    while(fscanf(neww,"%s %d %s %d %d %s %f %d",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)
    {
                fprintf(old,"%s %d %s %d %d %s %f %d",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
    }
    fclose(neww);
    fclose(old);
    remove("new.txt");
}
void balance()
{
       struct bank check;
    FILE *old;
    int x;
    old=fopen("detail.txt","r");
    printf("\n\n\n\t\t\t\t\t\tBALANCE");
    printf("\n\n\t\tEnter Account number : ");
    scanf("%d",&check.accno);
     printf("\n\t\tEnter Pin ");
    scanf("%d",&check.pin);
    while(fscanf(old,"%s %d %s %d %d %s %f %d ",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)//scan each n every data of file and save in variables
        {
            if((head.accno==check.accno)&&(head.pin==check.pin))
            {
                x=1;
                    printf("\n\n\t\t\tAccount number :: %d",head.accno);
                    printf("\n\n\t\t\tName :: %s",head.name);
                    printf("\n\n\t\t\tCash Deposited :: %f",head.amt);

            }


        }
        if(x!=1)
        {
                printf("\n\t Check Account Number and Pin ");
                fordelay(1000000000);
                system("cls");
                balance();
        }
        fclose(old);

    }
void deleteacc()
{
    struct bank del;
    FILE *old,*neww;
    int x;
    old=fopen("detail.txt","r");
    neww=fopen("new.txt","a");
    printf("\n\n\n\t\t\t\t\t\tDelete Account ");
    printf("\n\n\t\tEnter Account Number to delete : ");
    scanf("%d",&del.accno);
    printf("\n\t\tEnter pin ");
    scanf("%d",&del.pin);
    while(fscanf(old,"%s  %d %s %d %d %s %f %d  ",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)
    {
        if((head.accno!=del.accno)&&(head.pin!=del.pin))
        {
            fprintf(neww,"%s  %d %s %d %d %s %f %d \n",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
        }
        else
        {
            x=1;
            printf("\n\tDeleting ");
                 for(int i=0;i<=6;i++)
                {
                    fordelay(100000000);
                    printf(". ");

                }
            printf("\n\n\tAccount deleted Successfuly ");
        }
}
if(x!=1)
{
    printf("\n\tCheck Account Number ot Pin");
}

  fclose(old);
    fclose(neww);
    old=fopen("detail.txt","w");//delete data of file
    fclose(old);
    old=fopen("detail.txt","a");//write new data
    neww=fopen("new.txt","r");
    while(fscanf(neww,"%s %d %s %d %d %s %f %d \n ",head.date,&head.accno,head.name,&head.phnum,&head.age,head.address,&head.amt,&head.pin)!=EOF)
    {
                fprintf(old," %s %d %s %d %d %s %f %d \n",head.date,head.accno,head.name,head.phnum,head.age,head.address,head.amt,head.pin );
    }
    fclose(neww);
    fclose(old);
    remove("new.txt");


}
void atm()
{
    printf("atm");
}
void close()
{
    printf("sytem if closiing......");
}
void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
    {
        k=1;
    }
}



