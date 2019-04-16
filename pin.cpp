#include<iostream>
#include<cstring>
#include "BUS.h"
using namespace std;
#define size 20
struct hashtable
{
	string username;
	int pin;
	int seat1;
};
class account
{
	hashtable h[size];
	public:
	account()
	{
		for(int i=0;i<size;i++)
		{
			h[i].username="----";
			h[i].pin=-1;
		}
	}
	int hash_fun(int pin)
	{
		return(pin % size);
	}
	int collision(int k,string un,int p,int mode)
	{
		if(mode==0)
		{
			for(int i=k;i<(k-1);i++)
			{
				if(k==size)
				i=0;
				if(h[i].pin==-1)
				{
					h[i].pin=p;
					h[i].username=un;
					break;
				}			
			}
		}
		if(mode==1)
		{
			for(int i=k;i<(k-1);i++)
			{
				if(k==size)
				i=0;
				if(h[i].pin==p && h[i].username==un)
				{
					cout<<"Succesfull login\n";
					break;
				}
				if(h[i].pin!=p || h[i].username!=un)
				{
					cout<<"login credential failure\n";
					return -1;
				}			
			}
		}	
	}
	void insert()
	{
		cout<<"\tUsername:\t";
		string p;
		cin>>p;cout<<endl;
		cout<<"\tPin:\t";
		int t;
		cin>>t;
		int key=hash_fun(t);
		if(h[key].pin==-1)
		{
			h[key].username=p;
			h[key].pin=t;
		}
		else
		{
			collision(key,p,t,0);
		}
		cout<<"\n\tAccount created successfully\n";
	}
	int login()
	{
		cout<<"\tUsername:\t";
		string p;
		cin>>p;cout<<endl;
		cout<<"\tPin:\t";
		int t;
		cin>>t;
		int key=hash_fun(t);
		if(h[key].username==p && h[key].pin==t)
		{
		cout<<"succesfull login\n";
		 bus b;
    int con;
	b.bus1(10,5);
    int ch;
    int seat=0;
		cout<<"\t\t\t"<<"\033[21;44m"<<"BUS BOOKING SYSTEM"<<"\033[0m"<<endl;
		cout<<"-------------------------------------------------------------\n";
    do
    {
        cout<<"1.Display\n2.Booking\n3.cancel booking\n";
        cout<<"enter the choice: \n";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			int s;
			cin>>s;
			switch(s)
			{
				case 1:cout<<"\t\t\t"<<"\033[20;44m"<<"MINIBUS"<<"\033[0m"<<endl;b.bus_display(5,4);break;
				case 2:cout<<"\t\t\t"<<"\033[20;44m"<<"LUXERYBUS"<<"\033[0m"<<endl;b.bus_display(10,5);break;
				case 3:cout<<"\t\t\t"<<"\033[20;44m"<<"SLEEPERBUS"<<"\033[0m"<<endl;b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";
				b.booking1(h[key].seat1);break;
			}
			break;
            case 2:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			cin>>s;switch(s)
			{
				case 1:cout<<"\t\t\t"<<"\033[20;44m"<<"MINIBUS"<<"\033[0m"<<endl;b.bus_display(5,4);break;
				case 2:cout<<"\t\t\t"<<"\033[20;44m"<<"LUXERYBUS"<<"\033[0m"<<endl;b.bus_display(10,5);break;
				case 3:cout<<"\t\t\t"<<"\033[20;44m"<<"SLEEPERBUS"<<"\033[0m"<<endl;b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";break;
			}
			cout<<"\nenter seat number\t";
			cin>>seat;
			h[key].seat1=seat;
			b.booking1(h[key].seat1);break;
            case 3:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			cin>>s;switch(s)
			{
				case 1:b.bus_display(5,4);break;
				case 2:b.bus_display(10,5);break;
				case 3:b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";break;
			}b.cancel();break;
		default: cout<<"Wrong input\n";break;
        }
        cout<<"do you want to continue";
        cin>>con;
    }while(con==1);
		}
		else
		{
			int t=collision(key,p,t,1);
			if(t==-1)
			return -1;
		}
	}
};
int main()
{
	account f;
	int t;
//	f.insert();
cout<<"\n\t\tBus booking login\n";
	int ch;
	int counter=4;
	do
	{
		cout<<"\n\t1:Create a new account\n\t2:Login\n\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
			f.insert();
			break;
			case 2:
			t=f.login();
			if(t==-1)
			{cout<<"t:\t";
			cin>>t;}
			else
			{
			cout<<"\nLogin credential\n";
			t=0;
			//counter--;
			//cout<<counter<<"chances remaining after that account will be blocked temporary\n";
			}break;
			
			default:cout<<"\n\tWrong key!!!\n";
			break;
		}
		cout<<"Back to menu?[1/0]\n";
		cin>>t;
	}	
	while(t!=0);
}	
