#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>


void vline(char);//Function Prototype


class ID //Class for USER ID
{
 public:

 char user_name[20];
 char password[20];

 char get_username() //Member function to get username
 {
  cout<<"\n\n\t Enter the user name of the ID: ";
  gets(user_name);
  return user_name[20];
 }

 char get_password() //Member function to get password
 {
  cout<<"\n\n\t  Enter the password of the ID: ";
  gets(password);
  return password[20];
 }

}login_id;


class reserve   //Class for the details of the bus
{
  public:

  int busn;
  char driver[20];
  char arrival[5];
  char depart[5];
  char from[20];
  char to[20];
  char seat[8][4][10];
  char user_ID[8][4][20];
  int cost;

  void display();  //Member function to display bus details

  void disp_seat();  //Member function to display seat details

  int check_empticket();  //Member function to check number of empty tickets in bus

  int check_empty(int i,int j) //Member function to check whether the seat is empty
  {
   if(strcmp(seat[i][j],"Empty")==0)
   {
    return 1;
   }
   else
   {
    return 0;
   }
  }
}bus[50];

void reserve::display()
  {
   clrscr();
   vline('*');
   cout<<"\n\n\t\t\t     The details of the bus";
   cout<<"\n\n";
   vline('*');
   cout<<"\n\n\n\tBus number: ";
   cout<<busn;
   cout<<"\n\n\tDriver's name: ";
   cout<<driver;
   cout<<"\n\n\tArrival time: ";
	   for(int a1=0;a1<5;a1++)
   {
    cout<<arrival[a1];
   }
   cout<<"\n\n\tDeparture time: ";
   for(a1=0;a1<5;a1++)
   {
    cout<<depart[a1];
   }
   cout<<"\n\n\tOrigin: ";
   cout<<from;
   cout<<"\n\n\tDestination: ";
   cout<<to;
   cout<<"\n\n\tCost: ";
   cout<<cost;
   cout<<"\n\n\n\n\t\t   Press any key to continue to seat map";
   getch();
 }

void reserve::disp_seat()
 {
  int s=0,p=0;
  for(int i=0;i<8;i++)
  {
   cout<<"\n";
   for(int j=0;j<4;j++)
   {
    if(j==2)
    {
     cout<<"\t";
    }
    s++;
    if(strcmp(seat[i][j],"Empty")==0)
    {
     cout.width(5);
     cout.fill(' ');
     cout<<s<<".";
     cout.width(10);
     cout.fill(' ');
     cout<<seat[i][j];
     p++;
     }
     else
     {
      cout.width(5);
      cout.fill(' ');
      cout<<s<<".";
      cout.width(10);
      cout.fill(' ');
      cout<<seat[i][j];
      }
     }
    }
  cout<<"\n\n\t\t     There are "<<p<<" seats empty in Bus No: "<<busn;
 }

int reserve::check_empticket()
 {
  int e=0;
  for(int i=0;i<8;i++)
  {
   for(int j=0;j<4;j++)
   {
    if(strcmp(seat[i][j],"Empty")==0)
    e++;
   }
  }
  return e;
 }

//Function prototypes

void loading(void);
void main_menu(void);
void admin_login(void);
void admin_mode(void);
void create_id(void);
void delete_id(void);
void standard_login(void);
void standard_mode(void);
void book_tickets(void);
void install_bus(void);
void show_bus(void);
void show_seats(reserve);
void cancel_ticket(void);


void vline(char ch) //Function to insert line
{
  for(int i=1;i<80;i++)
  cout<<ch;
}

void loading()
{
  clrscr();
  for(int i=1;i<=50;i++)
  {
   clrscr();
   cout<<"\n\n\n\n\t\t\t\t    Loading \n "<<'\n'<<'\t'<<'\t';
   for(int j=1;j<=i;j++)
   cout<<"²";
   cout<<"\n\n\t\t\t\t      "<<2*i<<"%";
   delay(150 - i*3);
  }
}


void start_screen() //Start Screen Function
{
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t     Welcome to VP Transports";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\n\n\n\n\n\t\t       Only Tatkal Tickets can be booked here" ;
 cout<<"\n\n\n\n\n\n\t\t\t     Press any key to continue";
 getch();
}


void main_menu()  //Main menu function
{
 clrscr();
 int choice1;
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t\t    MAIN MENU";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t      Choose the login mode";
 cout<<"\n\n\t\t\t      1.ADMIN Mode";
 cout<<"\n\n\t\t\t      2.STANDARD USER Mode";
 cout<<"\n\n\t\t\t      0.Exit";
 cout<<"\n\n\n\t   Enter your choice (0 ,1 or 2): ";
 cin>>choice1;
 switch(choice1)
 {
   case 1:admin_login();
	  break;
   case 2:standard_login();
	  break;
   case 0:cout<<"\n\n\n\n\t\t\t     Press any key to exit";
	  getch();
	  exit(0);
	  break;
   default:cout<<"\n\n\t\t\t     Enter a valid choice";
	  cout<<"\n\n\t\t\t   Press any key to continue";
	  getch();
	  main_menu();
	  getch();
	  break;
  }
}


void admin_login() //Function for admin login page
{
 clrscr();
 char admin_name[8],admin_pass[10],try_choice;
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t\t  ADMIN Login";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\n\t\t Enter the admin name: ";
 gets(admin_name);
 cout<<"\n\n\t\t   Enter the password: ";
 gets(admin_pass);
 if(strcmp("Pradesh",admin_name)==0 && strcmp("123456789",admin_pass)==0)
 {
  cout<<"\n\n\n\n\n\t\t\t       Login Successful";
  cout<<"\n\n\t\t\t   Press any key to continue";
  getch();
  admin_mode();
 }
 else
 {
  cout<<"\n\n\n\n\t\t     Either your name or password is incorrect";
  label1:
  cout<<"\n\n\t\t\t Do you want to try again(y/n):";
  cin>>try_choice;
  switch(try_choice)
  {
   case 'y':admin_login();
	    break;
   case 'n':cout<<"\n\n\t\t   Press any key to return back to main menu";
	    getch();
	    main_menu();
	    break;
   case 'Y':admin_login();
	    break;
   case 'N':main_menu();
	    break;
   default :cout<<"\n\n\t\t Enter a valid input";
	     goto label1;
  }
 }
 getch();
}

void admin_mode() //Admin Page
{
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t\t   ADMIN MENU";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t 1.To create a standard user ID.";
 cout<<"\n\n\t 2.To delete a existing standard user ID.";
 cout<<"\n\n\t 3.Add a bus to the database.";
 cout<<"\n\n\t 4.Return to main menu.";
 cout<<"\n\n\t 0.Exit.";
 cout<<"\n\n\t Enter your choice: ";
 int choice2;
 cin>>choice2;
 switch(choice2)
 {
  case 1:create_id();
	 break;
  case 2:delete_id();
	 break;
  case 3:install_bus();
	 break;
  case 4:cout<<"\n\n\t\t   Press any key to return back to main menu";
	 getch();
	 main_menu();
	 break;
  case 0:cout<<"\n\n\t\t\t     Press any key to exit";
	  getch();
	 exit(0);
	 break;
  default:cout<<"\n\n\t\t\t     Enter a valid choice";
	  cout<<"\n\n\t\t\t   Press any key to continue";
	  getch();
	  admin_mode();
	  break;
 }
 getch();
}


void create_id() //Function to create a user ID
{
 char choice='n';
 do
 {
  label3:
  fstream login("user.dat",ios::app|ios::binary);
  fstream login2("user.dat",ios::in|ios::binary);
  clrscr();
  ID user,confirm,check;
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t\t\t  Create a standard user ID";
  cout<<"\n\n";
  vline('*');
  user.get_username();
  cout<<"\n";
  cout<<"\t          Retype the user name: ";
  gets(confirm.user_name);
  if(strcmp(user.user_name,confirm.user_name)!=0)
  {
   cout<<"\n\n\n\n\n\t\tThe usernames that you have entered doesn't match";
   cout<<"\n\n\n\n\t\t\t   Press any key to try again";
   getch();
   goto label3;
  }
  while(!login2.eof())
  {
   login2.read((char*)&check,sizeof(check));
   if(strcmp(user.user_name,check.user_name)==0)
   {
    cout<<"\n\n\n\n\t\tThe username that you have entered already exists";
    cout<<"\n\n\n\n\t\t\t   Press any key to try again";
    getch();
    goto label3;
   }
  }
  login2.close();
  user.get_password();
  cout<<"\n";
  cout<<"\t           Retype the password: ";
  gets(confirm.password);
  if(strcmp(user.password,confirm.password)!=0)
  {
   cout<<"\n\n\n\n\n\t\tThe passwords that you have entered doesn't match";
   cout<<"\n\n\n\n\t\t\t   Press any key to try again";
   getch();
   goto label3;
  }
  login.write((char*)&user,sizeof(user));
  loading();
  clrscr();
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t\t\t  Create a standard user ID";
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\n\t\t     Your ID has been created successfully";
  login.close();
  cout<<"\n\n\t\t      Do you want to create another ID: ";
  cin>>choice;
 }
 while(choice=='y'||choice=='Y');
 cout<<"\n\n\t\t      Press any key to return to main menu";
 getch();
 admin_mode();
}


void delete_id() //Function to delete a user ID
{
 char choice='n';
 do
 {
  label4:
  clrscr();
  ID del_user,temp_del,confirm;
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t\t\t   Delete a standard user ID";
  cout<<"\n\n";
  vline('*');
  del_user.get_username();
  cout<<"\n";
  cout<<"\t          Retype the user name: ";
  gets(confirm.user_name);
  if(strcmp(del_user.user_name,confirm.user_name)!=0)
  {
   cout<<"\n\n\n\n\n\t\tThe usernames that you have entered doesn't match";
   cout<<"\n\n\t\t\t Do you want to try again(y/n):";
   cin>>choice;
   if(choice=='y'|choice=='Y')
   {
    goto label4;
   }
   else
   {
     cout<<"\n\n\t\t      Press any key to return to main menu";
     getch();
     admin_mode();
   }
  }
  del_user.get_password();
  cout<<"\n";
  cout<<"\t           Retype the password: ";
  gets(confirm.password);
  if(strcmp(del_user.password,confirm.password)!=0)
  {
   cout<<"\n\n\n\n\n\t\tThe passwords that you have entered doesn't match";
   cout<<"\n\n\t\t\t Do you want to try again(y/n):";
   cin>>choice;
   if(choice=='y'|choice=='Y')
   {
    goto label4;
   }
   else
   {
     cout<<"\n\n\t\t      Press any key to return to main menu";
     getch();
     admin_mode();
   }
   }
  char found='n';
  fstream del_org("user.dat",ios::in|ios::binary);
  fstream del_temp("temp.dat",ios::in|ios::app|ios::binary);
  while(!del_org.eof())
  {
   del_org.read((char*)&temp_del,sizeof(temp_del));
   if(strcmp(del_user.user_name,temp_del.user_name)!=0)
   {
    del_temp.write((char*)&temp_del,sizeof(temp_del));
   }
   if(strcmp(del_user.user_name,temp_del.user_name)==0&&strcmp(del_user.password,temp_del.password)==0)
   {
    found='y';
   }
  }
  del_org.close();
  del_temp.close();
  remove("user.dat");
  rename("temp.dat","user.dat");
  if(found=='y')
  {
   loading();
   clrscr();
   cout<<"\n\n";
   vline('*');
   cout<<"\n\n\t\t\t   Delete a standard user ID";
   cout<<"\n\n";
   vline('*');
   cout<<"\n\n\n\t\t     Your ID has been deleted successfully";
   cout<<"\n\n\t\t      Do you want to delete another ID: ";
   cin>>choice;
  }
  if(found=='n')
  {
   cout<<"\n\n\n\t\t           Your ID has not been found";
   cout<<"\n\n\t\t\t Do you want to try again(y/n):";
   cin>>choice;
  }
 }
 while(choice=='y' || choice=='Y');
 cout<<"\n\n\t\t      Press any key to return to main menu";
 getch();
 admin_mode();
}

void install_bus()
{
 char choice='n';
 do
 {
  clrscr();
  reserve ins;
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t\t\t   Add a bus to the database";
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\n\tEnter bus no: ";
  cin>>ins.busn;
  cout<<"\tEnter Driver's name: ";
  gets(ins.driver);
  cout<<"\n\tArrival time: ";
  gets(ins.arrival);
  cout<<"\tDeparture time: ";
  gets(ins.depart);
  cout<<"\n\tOrigin: ";
  gets(ins.from);
  cout<<"\tDestination: ";
  gets(ins.to);
  cout<<"\n\tCost: ";
  cin>>ins.cost;
  for(int i=0; i<8;i++)
  {
   for(int j=0;j<4;j++)
   {
    strcpy(ins.seat[i][j], "Empty");
   }
  }
  fstream inst("busdata.dat",ios::app|ios::binary);
  inst.write((char*)&ins,sizeof(ins));
  loading();
  clrscr();
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t\t\t   Add a bus to the database";
  cout<<"\n\n";
  vline('*');
  cout<<"\n\n\t The details of the bus had been added to the database successfully.";
  inst.close();
  cout<<"\n\n\t\t Do you want to add another bus to the database(y/n): ";
  cin>>choice;
 }while(choice=='Y'||choice=='y');
 cout<<"\n\n\t\t      Press any key to return to main menu";
 getch();
 admin_mode();
}

void standard_login() //Function for end user login
{
 ID temp_user;
 fstream std_login;
 std_login.open("user.dat",ios::out|ios::in|ios::binary);
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t\tStandard login";
 cout<<"\n\n";
 vline('*');
 login_id.get_username();
 login_id.get_password();
 char found='n';
 while(!std_login.eof())
 {
  std_login.read((char*)&temp_user,sizeof(temp_user));
  if(strcmp(temp_user.user_name,login_id.user_name)==0)
  {
   if(strcmp(temp_user.password,login_id.password)==0)
   {
   found='y';
   break;
   }
  }
 }
  if(found=='n')
  {
   cout<<"\n\n\n\n\n\n\n\n\n\t\t   Either your name or password is incorrect";
   label2:
   cout<<"\n\n\t\t\t   Do you want to try again(y/n):";
   char try_choice1;
   cin>>try_choice1;
   switch(try_choice1)
   {
    case 'y':standard_login();
	     break;
    case 'n':main_menu();
	     break;
    case 'Y':standard_login();
	     break;
    case 'N':main_menu();
	     break;
    default :cout<<"\n\n\t\t Enter a valid input";
	     goto label2;
  }
  }
 std_login.close();
 if(found=='y')
 {
  cout<<"\n\n\n\n\n\t\t\t       Login Successful";
  cout<<"\n\n\t\t\t   Press any key to continue";
  getch();
  standard_mode();
 }
}

void standard_mode() //Function for end user menu
{
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t      STANDARD USER MODE";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\n\n\t 1.Book Tickets.";
 cout<<"\n\n\t 2.View the details of bus by entering number";
 cout<<"\n\n\t 3.Cancel your booked Tickets";
 cout<<"\n\n\t 4.Main Menu";
 cout<<"\n\n\t 0.Exit";
 cout<<"\n\n\n\n\t Enter your choice(0 to 4): ";
 int choice3;
 cin>>choice3;
 switch(choice3)
 {
  case 1:book_tickets();
	 break;
  case 2:show_bus();
	 break;
  case 3:cancel_ticket();
	 break;
  case 4:main_menu();
	 break;
  case 0:exit(0);
	 break;
  default:cout<<"\n\n\n\t\t\t     Enter a valid choice";
	  cout<<"\n\n\t\t\t   Press any key to continue";
	  getch();
	  standard_mode();
 }
 getch();
}

void book_tickets()   //Function to book tickets
{
 label15:
 reserve book_ticket,temp,temp1;
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t\t  Book Tickets\n\n";
 vline('*');
 cout<<"\n\n\t Enter the bus number: ";
 cin>>temp1.busn;
 int n,temp_seat;
 fstream ticket("busdata.dat",ios::in|ios::out|ios::binary|ios::app);
 ticket.seekg(0);
 char choice10='n';
 while(!ticket.eof())
 {
  ticket.read((char*)&book_ticket,sizeof(book_ticket));
  if(book_ticket.busn==temp1.busn)
  {
   if(book_ticket.check_empticket()!=0)
   {
    cout<<"\n\n\tEnter the number of tickets to be booked: ";
    cin>>n;
    if(n>book_ticket.check_empticket())
    {
     cout<<"\n\n\tThere are only "<<book_ticket.check_empticket()<<" available in the bus";
     cout<<"\n\n\t\t\t    Do you want to try again(y/n): ";
     cin>>choice10;
     cout<<"\n\n\n\t\t\t     Press any key to continue";
     getch();
     if(choice10=='Y'||choice10=='y')
     {
      goto label15;
     }
     else
     {
      cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
      getch();
      standard_mode();
     }
    }
    cout<<"\n\n";
    top:
    for(int i=1;i<=n;i++)
    {
     cout<<"\n\t Enter the seat number for passenger "<<i<<": ";
     cin>>temp_seat;
     if(temp_seat>32)
     {
      cout<<"\n\tThere are only 32 seats available in this bus.";
      cout<<"\n\n\t\t\t    Do you want to try again(y/n): ";
      cin>>choice10;
      getch();
      if(choice10=='Y'||choice10=='y')
      {
       goto label15;
      }
      else
      {
       cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
       getch();
       standard_mode();
      }
     }
     if(book_ticket.check_empty((temp_seat/4),(temp_seat%4)-1)==1)
     {
      cout<<"\n\t Enter the name of passenger "<<i<<": ";
      cin>>book_ticket.seat[temp_seat/4][(temp_seat%4)-1];
      strcpy(book_ticket.user_ID[temp_seat/4][(temp_seat%4)-1],login_id.user_name);
     }
     else
     {
      cout<<"\n\t This seat is reserved for other passenger";
      cout<<"\n\n\n\t\t\t     Press any key to continue";
      getch();
      goto top;
     }
    }
    fstream del_temp("temp.dat",ios::in|ios::out|ios::app|ios::binary);
    ticket.seekg(0);
    del_temp.seekp(0);
    while(!ticket.eof())
    {
     ticket.read((char*)&temp,sizeof(temp));
     if(book_ticket.busn!=temp.busn)
     {
      del_temp.write((char*)&temp,sizeof(temp));
     }
    }
    del_temp.close();
    ticket.close();
    remove("busdata.dat");
    rename("temp.dat","busdata.dat");
    fstream twrite("busdata.dat",ios::app|ios::binary);
    twrite.write((char*)&book_ticket,sizeof(book_ticket));
    twrite.close();
    loading();
    clrscr();
    cout<<	"\n\n";
    vline('*');
    cout<<"\n\n\t\t\t\t  Book Tickets\n\n";
    vline('*');
    cout<<"\n\n\t\t   Your tickets have been booked successfully";
    cout<<"\n\n\t The cost for the ticket is "<<n*book_ticket.cost;
    cout<<"\n\n\t Please pay the bill to the conductor before you start the journey";
    cout<<"\n\n\t Please carry each of the traveller's ID card for verification";
    cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
    break;
   }
  }
  if(book_ticket.check_empticket()==0)
  {
    cout<<"\n\n\t There are no tickets available in this bus";
    cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
    getch();
    standard_mode();
  }
 }
 getch();
 standard_mode();
}


void show_bus() //Function to show the details of a bus
{
 reserve temp,search;
 clrscr();
 vline('*');
 cout<<"\n\n\t\t\t     The details of the bus";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\n\t Enter the bus number: ";
 cin>>temp.busn;
 fstream disp("busdata.dat",ios::in|ios::out|ios::binary);
 while(!disp.eof())
 {
  disp.read((char*)&search,sizeof(search));
  if(search.busn==temp.busn)
  {
   search.display();
   show_seats(search);
   break;
  }
 }
  disp.close();
  cout<<"\n\n\n\t\t      Press any key to return to main menu";
  getch();
  standard_mode();
 }

void show_seats(reserve seat)  //Function to show the seat map of a bus
{
 clrscr();
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t The details of the seats of the bus";
 cout<<"\n\n";
 vline('*');
 cout<<"\n";
 seat.disp_seat();
 cout<<"\n\n\n\t\t      Press any key to return to main menu";
 getch();
 standard_mode();
}

void cancel_ticket() //Function to cancel a booked ticket
{
 label6:
 clrscr();
 reserve del,temp,temp2;
 char choice='n';
 int seats;
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n\t\t\t   Cancel the booked tickets";
 cout<<"\n\n";
 vline('*');
 cout<<"\n\n";
 do
 {
  cout<<"\t Enter the bus number: ";
  cin>>temp.busn;
  fstream bus("busdata.dat",ios::binary|ios::in);
  while(!bus.eof())
  {
   bus.read((char*)&del,sizeof(del));
   if(del.busn==temp.busn)
   {
    cout<<"\n\n\t Enter the seat number to be cancelled: ";
    cin>>seats;
    if(strcmp(del.seat[seats/4][(seats%4)-1],"Empty")!=0)
    {
     if(strcmp(del.user_ID[seats/4][(seats%4)-1],login_id.user_name)!=0)
     {
      cout<<"\n\n\t\tThis ticket is not booked from your user id";
      cout<<"\n\n\t\t\tDo you want to try again(y/n): ";
      cin>>choice;
      if(choice=='y'||choice=='Y')
      {
       goto label6;
      }
      else
      {
       standard_mode();
      }
     }
     strcpy(del.seat[seats/4][(seats%4)-1],"Empty");
     fstream temp1("temp1.dat",ios::app|ios::binary);
     bus.seekg(0);
     while(!bus.eof())
     {
      bus.read((char*)&temp2,sizeof(temp2));
      if(del.busn!=temp2.busn)
      {
       temp1.write((char*)&temp2,sizeof(temp2));
      }
     }
     temp1.write((char*)&del,sizeof(del));
     temp1.close();
     bus.close();
     remove("busdata.dat");
     rename("temp1.dat","busdata.dat");
     loading();
     clrscr();
     cout<<"\n\n";
     vline('*');
     cout<<"\n\n\t\t\t   Cancel the booked tickets";
     cout<<"\n\n";
     vline('*');
     cout<<"\n\n\t\t Your booked seat have been cancelled successfully";
     cout<<"\n\n\t Do yo want cancel one more ticket(Y/N): " ;
     cin>>choice;
     break;
    }
    else
    {
     cout<<"\n\n\t The selected seat havent booked by anyone";
     cout<<"\n\n\t\t\t Do yo want to try again(Y/N): " ;
     cin>>choice;
     if(choice=='y'||choice=='Y')
     goto label6;
     else
     {
       cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
       getch();
       standard_mode();
     }
    }
   }
  }
}while(choice=='y'||choice=='Y');
 cout<<"\n\n\n\n\t\t      Press any key to return to main menu";
 getch();
 standard_mode();
}

void main() //Main Function
{
 start_screen();
 main_menu();
}