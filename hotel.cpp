#include<fstream.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<windows.h>
char a[15];

class HOTEL         //DECLARATION OF CLASS                                    {
 	int rno,toc;
	char cnm[30];
  	float nod,fare;
  	void calcfare()
  	{
    		if(toc==3)
    		fare=nod*500;
    		else
    		if(toc==2)
    		fare=nod*1000;
    		else
    		if(toc==1)
    		fare=nod*1500;
  	}
  	public:
  	void showhotel()                       //SHOWING THE DETAILS
  	{
    		system("color fc");
	 	cout<<"\n\n\n\n";
	 	cout<<"\n ROOM NO.            :"<<rno<<"  \t\t\t           
                 Customer name : "<<cnm;
	        cout<<"\n No. of days to stay :"<<nod<<"  \t\t\t Type           
                 of class : "<<toc;
	 	cout<<"\n Total Fare          :"<<fare<<"\n\n";
  	}
  	int RNO()
  	{
	return rno;
  	}
  	char *CNM()
  	{
  	return cnm;
  	}
  	void inhotel();
  	void minhotel();
};
void HOTEL::inhotel()			        //TAKING DETAILS
{
	int c;
	ifstream f("count.txt");
	system("color fc");
	cout<<"\n\nInput the details of the customer\n";
	room:
	cout<<"\nEnter the room no. to stay:- ";
	cin>>rno;
	if((rno>=100&&rno<=156)!=1)
	{
		cout<<"\nRooms available b/w 100-156\n";
		goto room;
	}
	while(!f.eof())
	{
		f>>c;
		if(!f)
		break;
		if(c==rno)
		{
			cout<<"\nRoom already allocated !!!!! See  
above\n";
			f.seekg(0);
			goto room;
		}
	}
	f.close();
	system("color fc");
	cout<<"\nEnter customer name:- ";
	gets(cnm);
	again:
	cout<<"\nEnter the type of class(1,2 or 3rd class):- ";
	cin>>toc;
	if(toc>3)
	{
		cout<<"\nPLEASE GIVE CORRECT INPUT!!!!!";
		goto again;
	}
	cout<<"\nEnter expected no. of days to stay:- ";
	cin>>nod;
	calcfare();
}
void HOTEL::minhotel()                       //TAKING DETAILS 
  FOR MODIFYING
{
	system("color f8");
	cout<<"\n\nEnter customer name:- ";
	system("color fc");
	gets(cnm);
	again:
	cout<<"\nEnter the type of class(1,2 or 3rd class):- ";
	cin>>toc;
	if(toc>3)
	{
		cout<<"\nPLEASE GIVE CORRECT INPUT!!!!!";
		goto again;
	}
	cout<<"\nEnter expected no. of days to stay:- ";
	cin>>nod;
}

void password()                                      //GETTING PASSWORD
{
	clrscr();
	int j;
	system("color f7");
	cout<<"\nYou have 3 chances\n";
	cout<<"\nEnter the password (for ending press space tab)\n";
	for(j=0;j<3;j++)
	{
		for(int i=0;a[i-1]!=' ';i++)
		{
			a[i]=getch();
			cout<<'*';
		}
		if(strcmp(a,"9451822236 ")==0)
		{
			cout<<"\nCorrect\n";
			getch();
			break;
		}
		else
		cout<<"\n\nWrong\n"<<2-j<<" attempt left";
	}
}
void available()                                      //AVAILABLE
{
	clrscr();
	system("color fc");
	int c;
	ifstream fi("count.txt");
	cout<<"\nRoom allocated are [ B/W 100-156 ] :- ";
	while(!fi.eof())
	{
		fi>>c;
		if(!fi)
		break;
		cout<<c<<",";
	}
	fi.close();
}

void WRITE()                                  //WRITING TO THE FILE
{
	char ch;
	int i,c;
	HOTEL h;
	ofstream fout("hotel.dat",ios::app|ios::binary);
	cout<<"\n\n";
	do
	{
		ofstream fou("count.txt",ios::app);
		available();
		h.inhotel();
		c=h.RNO();
		fou<<c<<" ";
		fout.write((char *)&h,sizeof(h));
		fou.close();
		cout<<"\nRecord successfully added-----";
		cout<<"\n\n\n\n Want to enter more record 
???(y/n)......";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fout.close();
}
void READ()                                //READING FROM THE FILE
{
	clrscr();
	int flag=0;
	char ch;
	HOTEL h;
	ifstream fin("hotel.dat",ios::binary);
	system("color f5");
	cout<<"\n RECORDS IN THE FILE ARE--------------
         \n\n";
	while(!fin.eof())
	{
		fin.read((char *)&h,sizeof(h));
		if(!fin)
		break;
		flag=1;
		h.showhotel();
		cout<<"\n\tHit any key for next record";
		getch();
		clrscr();
	}
	system("color f5");
	fin.close();
	if(flag==0)
	{
		cout<<"\n No records ";
		cout<<"\n\n\t Hit any key to go back to the     
                 Menu........";
		getch();
	}
	if(flag!=0)
	{
		cout<<"\n\tNo furthur Records";
		cout<<"\n\n\t\t Hit any key to go back to the 
                 Menu........";
		getch();
	}
}
void search()                                //SEARCHING THE RECORDS
{
	SEARCH:
	system("color f2");
	clrscr();
	HOTEL h;
	int no,flag=0,c;
	char str[30],stay;
	ifstream fin;
	fin.open("hotel.dat",ios::binary);
	system("color f2");
	cout<<"\t\t\t  SEARCHING MENU";
	cout<<"\n\t\t    ----------------------------";
         //MENU FOR SEARCHING           
	cout<<"\n\n\t1.Search by room no.";                                 
	cout<<"\n\t2.Search by name";
	cout<<"\n\n\tChoose your Option :-";
	cin>>c;
	switch(c)
	{
		case 1:  system("color f2");
//SEARCHING BY ROOM NO.
       		cout<<"\n\n\tEnter the room no. to search :";     
       		cin>>no;
       		while(!fin.eof())
	     	{
               	            fin.read((char *)&h,sizeof(h));
                  		if(!fin)
       			break;
       			if(h.RNO()==no)
     			{
       				flag=1;
       				h.showhotel();
     			}
     		}
		if(flag==0)
      		cout<<"\n\tRecord does not exist";
      		break;
		case 2:  system("color f2");
//SEARCHING BY NAME
               		cout<<"\n\n\tEnter the name to be search :-";                                  
               		gets(str);
               		while(!fin.eof())
               		{
               			fin.read((char *)&h,sizeof(h));
      			            if(!fin)
      				break;
      				if(strcmpi(h.CNM(),str)==0)
				{
       					flag=1;
       					h.showhotel();
       					cout<<"\n\tPress any key for next
record.....";
					getch();
       					clrscr();
     				}
      			}
		if(flag==0)
      		cout<<"\n\tRecord does not exist";
      		break;
		default:system("color f2");
                 	            cout<<"\n\n\tsorry!!! wrong choice Try Again";
	}
	system("color f2");
	cout<<"\n\n\tPress 's' to search more or hit any key to go 
back to the Menu..... ";
	stay=getch();
	if(stay=='s'||stay=='S')
	goto SEARCH;
}
void modify()                               //MODIFYING THE REOCRDS
{
	system("color f2");
	HOTEL h;
	password();
	if(strcmp(a,"9451822236 ")==0)
	{
		MODI:
		clrscr();
		int no,flag=0;
		fstream inout("hotel.dat",ios::in | ios::out| ios::binary);
		system("color f2");
		cout<<"\n\nEnter the room no. to be modify:- ";
		cin>>no;
		while(!inout.eof())
		{
			inout.read((char *)&h,sizeof(h));
			if(!inout)
			break;
			if(h.RNO()==no)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			inout.seekg(-1*sizeof(h),ios::cur);
			cout<<"\n\nEnter the new record";
			h.minhotel();
			inout.write((char *)&h,sizeof(h));
			cout<<"\n\nRecord modified successfully---";
			inout.close();
		}
		if(!flag)
		{
			cout<<"\n Record does no existed";
      		}
   	}
	else
	{
		cout<<"\n Wrong password!!! You Are not 
Authorised....";
		getch();
		exit(0);
	}
	cout<<"\n\nPress 's' to modify more or hit any key to go back
to the Menu..... ";
	char stay;
	stay=getch();
	if(stay=='s'||stay=='S')
	goto MODI;
}
void del()                                           //DELETING RECORD
{
	system("color f1");
	int flag=0,no,c;
	char ch;
	HOTEL h,h1;
	password();
	if(strcmp(a,"9451822236 ")==0)
	{
		char confirm='n';
		int flag=0;
		clrscr();
		system("color f1");
		ifstream fin("hotel.dat",ios::binary);
		ofstream fout("hotel1.dat",ios::app | ios::binary);
		ifstream fi("count.txt",ios::in);
		ofstream fou("count1.txt",ios::out);
		cout<<"\n enter the room no whose record is to be
deleted :-";
		cin>>no;
		while(!fin.eof())
		{
			fin.read((char *)&h,sizeof(h));
			if(h.RNO()== no)
			{
				if(!fin)
				break;
				h.showhotel();
				flag=1;
				cout<<"\nAre you sure, you want to delete 
this record?(y/n)...";
				cin>>confirm;
				if(confirm=='n')
				fout.write((char *)&h,sizeof(h));
			}
			else
			fout.write((char *)&h,sizeof(h));	
		}
		if(flag==1 && confirm=='y' || confirm=='Y' )
		{
			cout<<"\n\tRecord deleted successfully";
			cout<<"\n\n\thit any key to go back to the
Menu.....";
			getch();
		}
		if(flag==0)
		{
			cout<<"\n Record not found!!!\n";
			cout<<"\n\thit any key to go back to the 
Menu.....";
			getch();
		}
		fin.close();
		fout.close();
		remove("hotel.dat");
		rename("hotel1.dat","hotel.dat");
      		if(flag==1 && confirm=='y' || confirm=='Y' )
      		{
			while(!fi.eof())
			{
				fi>>c;
				if(!fi)
				break;
				if(c!=no)
				fou<<c<<" ";

         			}
      			fi.close();
			fou.close();
			remove("count.txt");
			rename("count1.txt","count.txt");
      		}

	}
	else
	{
		cout<<"\nSorry you are not Authorised!!!";
		getch();
		exit(0);
	}
}
void main()                                          //VOID MAIN
{
	char ch;
	int c;
	char i=16;
	start:
	clrscr();
	system("color f4");
	cout<<"\t\t\t HOTEL ROOM BOOKING RECORD";
	cout<<"\t\t\t\t\t\t ----------------------------------------";
	cout<<"\n\n OPERATION MENU "<<i<<i<<i<<i;
	cout<<"\n ------------------------";
	cout<<"\n\n\t 1.Save record....";
	cout<<"\n\t 2.Display all records....";
	cout<<"\n\t 3.Search any record.....";
	cout<<"\n\t 4.Modify records....";
	cout<<"\n\t 5.Delete record....";
	cout<<"\n\t 6.About.....";
   	cout<<"\n\t 7.Exit";
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<"\n\n Enter ur choice :-";
	cin>>c;
	switch(c)
	{
		case 1:WRITE();
             		break;
      		case 2:READ();
             		break;
		case 3:search();
             		break;
		case 4:modify();
             		break;
		case 5:del();
             		break;
      		case 6:clrscr();
      		 system("color f0");
             		cout<<"\n\n>Its a record keeping software for the 
customers               
staying ";
             		cout<<"in the hotel.It provide flexibility to the 
hotel's staff to ";
             		cout<<"manage the information of the customers.";
             		cout<<"\n\n>Use different options in the menu 
according to your
use.";	
cout<<"\n\n>The modification and deletion is password protected 
so that";
cout<<" unauthorized person can't use the software";
             		cout<<"\n\n\tPresented By 
:\n\tAnupam\n\n\tanupamking24@gmail.com";
             		cout<<"\n\n\n\tcopyright.nic";
		cout<<"\n\n\n\t\t\thit any key to go back to the 
Menu.....";
             		getch();
             		break;
		case 7:clrscr();
      		            system("color f5");
       			  cout<<"\n\n\t\t\t  THANK YOU";
cout<<"\n\n\n\t\tDEVELOPER     : "<<"ANUPAM SAHA";
cout<<"\n\n\t\tGMAIL ID      : "<<"anupamking24@gmail.com";
cout<<"\n\t\tLANGUAGE UESD : "<<"C++ Programming";
        			cout<<"\n\t\tCLASS         : "<<"12th 'A' Science";
        			cout<<"\n\t\tTYPE          : "<<"As a project";
       			cout<<"\n\t\tHELPER        :"<<"Mrs.Lovely 
Mam";
       			cout<<"\n\n\n\t\t     Press any key........";
       			getch();
       			exit(0);
		      default:cout<<"\n sorry!!! wrong choice Try Again ";
      			getch();
	}
	goto start;
}

