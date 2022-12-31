/*
===========================================|
	Name :-	Faizan ul hassan		   |
===========================================|
	Roll No :-	19I-1976			   |
===========================================|
	Section :-	CS-F				   |
===========================================|
	OOP PROJECT					   |
===========================================|
*/

#include <iostream>
#include <ctime>
//#include "conio.h"
#include <string>
#include <fstream>
using namespace std;

void input ();
int validation ( int acc_no , int pin_code );

class reciept 
{
private:    
    int accountNo;
    int pincode;
    float balance;
    string naam;
public:
    reciept(float bal, int no, int pin , string n) 
    {
        accountNo = no;
        balance = bal;
        pincode = pin;
        naam = n;
    }
    void displayReciept() 
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "\n\t\t\t\t\t===============================================";
        cout << "\n\t\t\t\t\t--------------Transaction Receipt--------------";
        cout << "\n\t\t\t\t\t===============================================";
        cout << "\n\t\t\t\t\t     Thank you for using our atm."<<endl;
        cout << "\n\t\t\t\t\t     Name           => "<<naam<<endl;
        cout << "\n\t\t\t\t\t     Account No.    => " << accountNo << endl;
        cout << "\n\t\t\t\t\t     PinCode        => "<< pincode<<endl;
        cout << "\n\t\t\t\t\t     Balance        => $" << balance << endl;
        cout << "\n\t\t\t\t\t     Time           => "<<dt;
        cout << "\n\t\t\t\t\t===============================================";
    }
};
//============================================================================================================

class atm
{
protected:
    int account_no , pin_code , atm_limit , withdraw_amount ;
    float bank_balance , deposit_amount;
    string name;
public:
    
    atm()   // default 
    {
        account_no=0; pin_code=0; ; bank_balance=0.0;  
    }
    
    atm(int a , int b , float c , string n)  // parametric 
    {
        account_no=a;
        pin_code=b;
        bank_balance=c;
        atm_limit = 10000;
        withdraw_amount=0;
        deposit_amount=1;
        name = n;
    } 
    // setters 
    void setbalance   ( float a )   {  bank_balance=a;     }
    void setatm_limit ( int b )     {  atm_limit=b;        }
    void setwithdraw  ( int c )     {  withdraw_amount=c;  }
    void setdeposit   ( int d )     {  deposit_amount=d;   }  
    // getters
    float getbalance()      {   return bank_balance ;   }
    int getaccount_no()     {   return account_no;      }
    int getpin_code()       {   return pin_code;        }
    int getatm_limit()      {   return atm_limit;       }
    int getwithdraw()       {   return withdraw_amount; }
    int getdeposit()        {   return deposit_amount;  }
    string getname()        {   return name;            }

//==================================================================================================================================================

    float main_menu()	// main menu which will appear after entering valid acc_no and pincode
    {   
        int n;
        cout<<"\n\t\t\t\t\tEnter choice.";
        cout<<"\n\t\t\t\t\t1 => balance."<<endl;
        cout<<"\n\t\t\t\t\t2 => withdraw."<<endl;
        cout<<"\n\t\t\t\t\t3 => deposit."<<endl;
        cout<<"\n\t\t\t\t\t4 => exit."<<endl;
        cout<<"\n\t\t\t\t\tEnter => ";
        cin>>n;
        while ( n<1 || n>4 )	// input validation
        {
            cout<<"\n\t\t\t\t\tInvalid. Enter => ";
            cin>>n;
        }
        if (n==1)	// for balance
        {
        cout<<"\n\t\t\t\t\t============ Show balance ============"<<endl;    
        show_bank_balance();
        }
        else if (n==2)	// for withdraw
        {  
        cout<<"\n\t\t\t\t\t============ Withdraw money ============"<<endl;      
        withdraw();
        }
        else if (n==3)	// for deposit
        {
        cout<<"\n\t\t\t\t\t============ Deposit money ============"<<endl;
        deposit();       
        }
        else if (n==4)	// for exiting a user
        {
            return bank_balance;
        }
        return bank_balance;
    }
//===========================================================================================================    
    void show_bank_balance()  
    {   
        cout<<"\n\t\t\t\t\tBank balance => $"<<bank_balance<<endl;
        cout<<"\n\t\t\t\t\t======================================"<<endl;
        main_menu();
    }
//===========================================================================================================    
    void withdraw ()
    {   
        cout<<"\n\t\t\t\t\tEnter choice.";
        cout<<"\n\t\t\t\t\t1 => $20"<<endl;
        cout<<"\n\t\t\t\t\t2 => $40"<<endl;
        cout<<"\n\t\t\t\t\t3 => $60"<<endl;
        cout<<"\n\t\t\t\t\t4 => $100"<<endl;
        cout<<"\n\t\t\t\t\t5 => $200"<<endl;
        cout<<"\n\t\t\t\t\t6 => Cancel"<<endl;		// withdraw menu
        float x,y,z,a;	// variables to be used in this function only
        cout<<"\n\t\t\t\t\tEnter => ";
        cin>>a;
        while ( a<1 || a>6 )  	// input validation  
        {   
            cout<<"\n\t\t\t\t\tInvalid choice."<<endl;
            withdraw(); 
        }
        if ( a==1 )	
        {   
            x=20;
            if ( x>getbalance() || x>getatm_limit() ) // checking if user have enough balance or atm has enough money
            {
                cout<<"\n\t\t\t\t\tNot enough cash."<<endl;
                withdraw();	// if any condition is true then go to withdraw menu
            }
            else
            {
            y = getbalance() - x;  // withdrawing money		// withdraw from user bank balance
            setbalance(y);  // setting new balance		// updating value of balance
            z = getatm_limit() - x;		// withdraw from atm machine
            setatm_limit(z);			// updating value of atm_limit
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();   	// transaction successfull so go to main menu
            }
        }
        else if ( a==2 )
        {   
            x=40;
            if ( x>getbalance() || x>getatm_limit() )
            {
                cout<<"\n\t\t\t\t\tNot enough cash."<<endl;
                withdraw();
            }
            else
            {
            y = getbalance() - x;  // withdrawing money
            setbalance(y);  // setting new balance
            z = getatm_limit() - x;
            setatm_limit(z);
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
	       cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();   
            }
        }        
        else if ( a==3 )
        {   
            x=60;
            if ( x>getbalance() || x>getatm_limit() )
            {
                cout<<"\n\t\t\t\t\tNot enough cash."<<endl;
                withdraw();
            }
            else
            {
            y = getbalance() - x;  // withdrawing money
            setbalance(y);  // setting new balance
            z = getatm_limit() - x;
            setatm_limit(z);
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();   
            }
        }        
        else if ( a==4 )
        {   
            x=100;
            if ( x>getbalance() || x>getatm_limit() )
            {
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
                withdraw();
            }
            else
            {
            y = getbalance() - x;  // withdrawing money
            setbalance(y);  // setting new balance
            z = getatm_limit() - x;
            setatm_limit(z);
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();   
            }
        }        
        else if ( a==5 )
        {   
            x=200;
            if ( x>getbalance() || x>getatm_limit() )
            {
                cout<<"\n\t\t\t\t\tNot enough cash."<<endl;
                withdraw();
            }
            else
            {
            y = getbalance() - x;  // withdrawing money
            setbalance(y);  // setting new balance
            z = getatm_limit() - x;
            setatm_limit(z);
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();   
            }
        }        
        else if ( a==6 )	// if user cancle withdraw menu then go to main menu
        {
            cout<<"\n\t\t\t\t\tTransaction cancelled."<<endl;
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t========================================"<<endl;
            main_menu();	
        }        
    }
//===========================================================================================================
void deposit ()	
    {   //Time function will be written in this function
        float x,y;	// variables for this function only
        cout<<"\n\t\t\t\t\t0 => cancel \n\t\t\t\t\t1 => Deposit."<<endl;
        int a;
        cout<<"\n\t\t\t\t\tEnter choice => ";
        cin>>a;
        while ( a<0 || a>1 )	// input validation of other than 0 or 1
        {
            cout<<"\n\t\t\t\t\tInvalid. Enter : "<<endl;
            cin>>a;
        }
        if ( a==0 )    // if 0 then cancel transaction and go to main menu 
        {  
            cout<<"\n\t\t\t\t\tTransaction cancelled."<<endl;
            cout<<"\n\t\t\t\t\t======================================="<<endl;
            main_menu();
        }
        else if ( a==1 )	// if user choose to dpeosit money
        {
            cout<<"\n\t\t\t\t\tEnter cents => ";
            cin>>deposit_amount;
            while (deposit_amount < 1 )		// to avoid negative values or 0 
            {
                cout<<"\n\t\t\t\t\tEnter cents => ";
                cin>>deposit_amount;		// user will enter no of cents
            }
                // time function implemented for 10 seconds
			 int count=120;
			 cout<<"\n\t\t\t\t\tPress enter to confirm."<<endl;
                cout<<"\n\t\t\t\t\t120 seconds start now. "<<endl;
                cin.ignore();
                cin.clear();
                // while ( !kbhit() ) 
                // {
				// struct timeval tv;
				// tv.tv_sec = 1;
                //     tv.tv_usec = 50000;
				// select(0, NULL, NULL, NULL, &tv);
                //     if ( count==0 ) 
                //     {
                //         cout<<"\n\t\t\t\t\tCancelled due to inactivity."<<endl;
                //         cout<<"\n\t\t\t\t\t======================================="<<endl;
				//     main_menu();
                //     }   
                //     cout<<count<<" ";
                //     count--;
                // }     
            x = deposit_amount / 100;	// formula to convert cents into dollars
            y = getbalance() + x;	// adding in balance
            setbalance (y);		// updating balance
            cout<<"\n\t\t\t\t\tTransaction successfull."<<endl;
            cout<<"\n\t\t\t\t\tBalance => $"<<getbalance()<<endl;
            cout<<"\n\t\t\t\t\t======================================="<<endl;
            main_menu();	// after successfull call main menu
        }
    }
//===========================================================================================================
};
class finishuser : public atm
{
protected:
    float b;
    int acc,pin;
    string n;
public:
        void quitting(atm object)
        {
            b = object.getbalance();
            acc = object.getaccount_no();
            pin = object.getpin_code();
            n = object.getname();
            reciept r (b , acc , pin , n);
            r.displayReciept();
		  // 5 second display before clear screen
		  int count=5;
            cin.ignore();
            cin.clear();
        //     while ( !kbhit() ) 
        //     {
		// 	struct timeval tv;
		// 	tv.tv_sec = 1;
        //        tv.tv_usec = 50000;	
		// 	select(0, NULL, NULL, NULL, &tv);
        //        if ( count==0 ) 
        //        {
		// 		system("clear");
		// 		input();				    
        //        }   
        //        count--;
        //    }             
        }
};

//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
int main()
{
    input();
    return 0;
}
//===========================================================================================================
void input ()	// taking input from user and their validation
{
        cout << "\n\t\t\t\t\t==============================================="<<endl;
        cout << "\n\t\t\t\t\t-------------- Welcome To My Atm --------------"<<endl;
        cout << "\n\t\t\t\t\t==============================================="<<endl;
        int acc_no , pin_code;
        cout<<"\n\t\t\t\t\tEnter 5 digit acc_no => ";
        cin>>acc_no;
        while (acc_no < 10000 || acc_no > 99999)
        {
            cout<<"\n\t\t\t\t\tInvalid acc_no. Enter again => ";
            cin>>acc_no;
        }     
        cout<<"\n\t\t\t\t\tEnter 5 digit pin_code => ";
        cin>>pin_code;
        while (pin_code < 10000 || pin_code > 99999)
        {
            cout<<"\n\t\t\t\t\tInvalid pin_code. Enter again => ";
            cin>>pin_code;
        }
        validation ( acc_no , pin_code );	// sending values for validation
}
//===========================================================================================================
int validation ( int acc_no , int pin_code )
{
    string array[10];	// getting from file in string
    string names[10];
    float balance[10];	// for bank balance
    int account[10];	// for account nos
    int pincode[10];	// for pincodes
    bool found;
    bool found1;
    int index=0;

    fstream read;
    fstream data;
    read.open( "./bal.txt" );
    data.open( "./info.txt" );
        for (int i=0 ; i<10 ; i++)
        {
            while ( getline ( read , array[i] , ',' ) ) // using this method o get from file where entries are separated by ','
            {
                balance[i] = std::stof ( array[i] );	// getting bank balances one by one
                break;
            }   
        }
        data.seekg(0);		// Read form beginning of file
        for (int i=0 ; i<10 ; i++)
        {
            while ( getline ( data , array[i] , ',' ) ) // using this method o get from file where entries are separated by ','
            {
                account[i] = std::stoi ( array[i] );	// getting acc_nos one by one
                break;
            }   
        }
        data.seekg(0);		// Read form beginning of file
        data.ignore(59); 
        for (int i=0 ; i<10 ; i++)
        {
            while ( getline ( data , array[i] , ',' ) ) // using this method o get from file where entries are separated by ','
            {
                pincode[i] = std::stoi ( array[i] );	// getting pin_codes one by one
                break;
            }   
        }
        data.seekg(0);
        data.ignore(120);
        for (int i=0 ; i<10 ; i++)
        {
            while ( getline ( data , array[i] , ',' ) ) // using this method o get from file where entries are separated by ','
            {
                names[i] = array[i] ;	// getting pin_codes one by one
                break;
            }   
        }        
        // checking the existance
        for ( int i=0 ; i<10 ; i++ )
        {
            if ( acc_no == account[i] )
            {
                found = true;	// if found then break and keep record of index
                break;
            }
            else
            {
                index++;
                found = false;
            }
        }
        if (found==true)
        {
            cout<<"\n\t\t\t\t\tAccount no at "<<index+1<<endl;	// showing index at which it is found
        }
        else
        {
            cout<<"\n\t\t\t\t\tAccount no not found in file."<<endl;	// if not found then take input again frmo user in input function
            input();
        }
        if ( pin_code == pincode[index] )	// checking pincode at corrosponding index, if found then valid else take input again
        {
            cout<<"\n\t\t\t\t\tPin_code matched."<<endl;
            cout<<"\n\t\t\t\t\tYour balance is  => $"<<balance[index]<<endl;	// showing balance
            
            atm object ( acc_no , pin_code , balance[index] , names[index] ); 	// sending in parametric constructor of base class

            float updated_bal = object.main_menu(); 	
            balance[index] = updated_bal;

            read.seekg(0);  // Writing the updated balances in file again
            for(int i = 0;i < 10; i++)
            {
                read<<balance[i]<<",";
            }
            read<<endl;
              
            finishuser obj;
            obj.quitting(object);         
            input();
        }
        else
        {
            cout<<"\n\t\t\t\t\tPincode not matched."<<endl;
            input();
        }
    read.close();	// closing file
    return 0;	
}
