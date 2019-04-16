//*****************************************
/*MINIPROJECT
           BUS BOOKING SYSTEM
 VIPUL BHAGWAT     SECOC306
 PRATIK DHORE      SECOC313
 AAYUSH GATTAWAR   SECOC318
 AMOL MARATHE      SECOC339
 © All rights are reserved
*/
//***************************************** 

#include <iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int bit;
    string name;
    long int pin;
    int seat_number;
    node *next;
    node *prev;
};



class bus
{
    int x;
    node *nn;
     int h=1;
public:
    node *header[10];
    bus()
    {
        nn=0;
        for(x=0;x<10;x++)
        {header[x]=NULL;}
    }
    void bus_display(int q,int w);
    void booking();
void booking1(int n);
	void bus1(int q,int w);
	void cancel();
};

//for creating linkedlist
void bus::bus1(int q,int w)
{    
	int i,j;
    for(i=0;i<q;i++)
    {
        for(j=0;j<w;j++)
        {
            nn=new node;
            nn->bit=0;
            nn->name="";
            nn->seat_number=(i+1)*10+j+1;;
            nn->next=nn->prev=NULL;
            if(header[i]==NULL)
            {
                header[i]=nn;
                nn->next=header[i];
                nn->prev=header[i];
            }
            else
            {
                node *cn;
                cn=header[i];
                while(cn->next!=header[i])
                {
                    cn=cn->next;
                }
                nn->next=cn->next;
                cn->next=nn;
                nn->prev=cn;
                header[i]->prev=nn;
            }
        }
    }
}

//for displaying linked list
void bus::bus_display(int q,int w)
{    int i=0;
    cout<<"\n";
    for(i=0;i<q;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<"------";
            if(j==1)
                cout<<"\t";
        }
        cout<<endl;
        int n=0;
        node *cn;
        cn=header[i];
        do
        {
            if(cn->bit==0)
            {
                cout<<"\033[36;40m"<<"| "<<cn->seat_number<<" |"<<"\033[0m";
            }
            else if(cn->bit==1)
                cout<<"\033[35;40m"<<"| ## |"<<"\033[0m";
            n++;
            if(n==2)
                cout<<"\t";
            cn=cn->next;
        }while(cn!=header[i]);
        cout<<"\n";
        
    }
    for(int j=0;j<5;j++)
    {
        cout<<"------";
        if(j==1)
            cout<<"\t";
    }
    cout<<endl;
    cout<<"##=not available\n";
}
//for booking seat
void bus::booking()
{
    int n;

    cout<<"enter the seat number you want to book";
    cin>>n;
    //h++;
    h=rand()%10000;
    {
    	node *cn;
        cn=header[(n/10)-1];
        for(int i=1;i<n%10;i++)
        {
            cn=cn->next;
        }
        if(cn->bit==1)
        {
            cout<<"\n SORRY THIS SEAT IS ALREADY BOOKED \n";
        }
        else
        {
            cout<<"enter name:";
            cin>>cn->name;
            cn->bit=1;
		cn->pin=h;
		cout<<"*****pin is"<<cn->pin<<"*****\n";
		cout<<"save this pin as it is required at the time of cancelation!!!\n";
        }
    }
}
void bus::booking1(int n)
{
    //int n;

    //cout<<"enter the seat number you want to book";
    //cin>>n;
    //h++;
    h=rand()%10000;
    {
    	node *cn;
        cn=header[(n/10)-1];
        for(int i=1;i<n%10;i++)
        {
            cn=cn->next;
        }
        if(cn->bit==1)
        {
            cout<<"\n SORRY THIS SEAT IS ALREADY BOOKED \n";
        }
        else
        {
            cout<<"enter name:";
            cin>>cn->name;
            cn->bit=1;
		cn->pin=h;
		cout<<"*****pin is"<<cn->pin<<"*****\n";
		cout<<"save this pin as it is required at the time of cancelation!!!\n";
        }
    }
}


//for cancelling the booking
void bus::cancel()
{
	int n;
	cout<<"enter the seat number for which you want to cancel booking";
	cin>>n;
	{
		node *cn;
		cn=header[(n/10)-1];
		for(int i=1;i<n%10;i++)
		{
			cn=cn->next;
		}
		if(cn->bit==0)
		{
		cout<<"SORRY THIS SEAT IS NOT BOOKED";
		}
		else if(cn->bit==1)
		{
			int flag1=0;
			int f;
			do
			{
				cout<<"enter pin";
				cin>>f;
				if(f==cn->pin)
				{
				cn->bit=0;
				cn->name="";
				}
				else
				{
				cout<<"wrong pin\n";
				flag1++;
				cout<<5-flag1<<"chances are remaining\n";
				}
			}
			while(f!=cn->pin && flag1<5);
			if(flag1==5)
			{			
			cout<<"5 chances are done try again after sometime!\n";
			}
			else
			{
				cout<<"Seat is successfully cancelled!!\n";
			}
		}
	
	}

}
