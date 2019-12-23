#include<iostream>
#include<cstdlib>
#include<string.h>
#include<iomanip>
#define size 63

using namespace std;
class airlines;

int reserve=70;

class airlines
{
public:
    airlines();
    ~airlines();
	void main_menu();	 //Menu function.
	void make_reservation();	// To make reservation.
	void cancel_reservation();	//To cancel reservation.
	void Search_passenger();//To search passengers
    void Discount();//to print a discount
    void print_report();	 //To print the status report.


private:
        char gen,ID[25],ID_num[25];
		string fname, lname, menu;
		int reserve_num, seat_num,x,cancel,age,n,i, phone_num;
		float fare;
};

airlines temp1[64];

airlines::airlines()//constructor
{
        cancel=0;
        i=0;
}

airlines::~airlines()
{

}

void airlines::main_menu()
{
int choice;

airlines temp;
do{
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Make Reservation    ...... '1' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Cancel Reservation  ...... '2' \n ";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Search Passenger    ...... '3' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Discount            ...... '4' \n";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Print status Report ...... '5' \n ";
cout <<"\t\t ------------------------------ \n";
cout <<"\t\t Quit                ...... '6' \n ";
cout <<"\t\t ------------------------------ \n";
cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
cout <<"\n Option :: ";


	cin >> choice;


	switch (choice)	 //starting case.
	{
	case 1: system("CLS"); temp.make_reservation();
					break;
	case 2: system("CLS"); temp.cancel_reservation();
					break;
	case 3: system("CLS"); temp.Search_passenger();
                    break;
	case 4: system("CLS"); temp.Discount();
					break;
    case 5: system("CLS"); temp.print_report();
					break;
	case 6: cout << "\n\nBrought To You By DEPSTAR CSE-2 Students\n\n\n";
					break;

	default: cout<<" ERROR You entered invalid option! \n\n";
		break;
	}
}while(choice != 6 );// Ending case loop.
}

void airlines:: make_reservation()	 //This function makes reservation.
{
	int meal_choice, x;
	int m;

	cout<<"\n\nEnter no. of tickets you want to book: ";
    cin>>n;

    for(m=0;m<n;m++)
    {
    cout<<"\n\nEnter First Name of person: ";
	cin>>temp1[i].fname;
	cout<<"--------------------------------\n";

	cout<<"Enter Last Name of Person: ";
	cin>>temp1[i].lname;
	cout<<"--------------------------------\n";

	cout<<"Enter ID of the person: ";
	cin>>temp1[i].ID;
	cout<<"--------------------------------\n";

	cout<<"Enter Phone Number of Person: ";
	cin>>temp1[i].phone_num;
	cout<<"--------------------------------\n";

    int a=4,k,j;//shows arrangement of seats
	cout<<"  0  1     2  3  4     5  6\n";
	for(k=0;k<9;k++)
	{
	    cout<<"\n";
		cout<<k;
		cout<<" "<<(char)a<<"  "<<(char)a<<"     "<<(char)a;
        cout<<"  "<<(char)a<<"  "<<(char)a<<"     "<<(char)a<<"  "<<(char)a;
        cout<<"\n";
	}
	cout << "Please Enter the Seat Number(Which is less than or equal to  63): ";

		cin>>temp1[i].x;//if seat no. is greater than 100
		while(temp1[i].x>size)
        {
		cout<<"   Try again:: ";
		cin >>temp1[i].x;
		}

		temp1[i].seat_num=temp1[i].x;

        for(int z=0;z<63;z++)
        {
            if(i==z) continue;

            while(temp1[i].x==temp1[z].seat_num)
            {
                cout<<"   Try again:: This seat is already taken";
                cin>>temp1[i].x;
                temp1[i].seat_num=temp1[i].x;
            }
        }


     //******************************************************************************
	// prints the menu list and prompts to make a choice.

		cout <<endl<< "Please Enter Your Menu Preference from below:"<<endl;
		cout << "   Veg     ..... '1'\n";
		cout << "   Non-Veg ..... '2'\n";
		cout << "   No meal ..... '3'\n\n";

		cout <<"   Your Choice :: ";
		cin >> meal_choice;

		while(meal_choice>3 || meal_choice<1){
		cout<<"   Try Again:: ";
		cin>>meal_choice;
		}

		if (meal_choice == 1)
		temp1[i].menu = "veg";

		else if (meal_choice == 2)
		temp1[i].menu = "Non-Veg";

		else
		temp1[i].menu = "No meal";

	reserve++;   //increments the reservation numbers
	temp1[i].reserve_num=reserve;
	i++;
	cout <<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout << "YOUR RESERVATION NUMBER IS :: " << reserve << "\n\n";
	cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    }

}

void airlines:: cancel_reservation()	//This function cancels reservation.
{	int num,flag=0;

	cout << "Please Enter your reservation Number here: ";
	cin >> num;

	for(int i=0;i<63;i++)
    {

        if(num==temp1[i].reserve_num)
        {
            flag=1;
            temp1[i].reserve_num=0;
        cout<<endl<<endl<<"The reserved seat has been canceled that you have entered"<<endl;
            if(cin.get()=='\n')
            {
            reserve--;
            cancel++;
            }
        }
    }
        if(flag==0)
            {
             cout<<endl<<"*** Nothing to delete or invalid entry *** !!! Please try again";
            }
        else
        {

        }

}

void airlines:: Search_passenger()	//This function helps to search a passenger
{//either by first name

		int reservenum,i,flag=0;//to take temporary name from a user
		cout << "Please enter your reservation number here: ";
		cin >> reservenum;
		cout<<endl;

            for(i=0;i<63;i++)
            {
            if(temp1[i].reserve_num==reservenum)
            {
                flag=1;
                cout << " First Name     : " <<temp1[i].fname << endl;
				cout << " Last Name      : " <<temp1[i].lname << endl;
				cout << " ID.No          : " <<temp1[i].ID << endl;
				cout << " Phone number   : " <<temp1[i].phone_num << endl;
				cout << " seat Number    : " <<temp1[i].x << endl;
				cout << " Reservation No.: " <<temp1[i].reserve_num<< endl;
				cout<<  " Meal Choice is : "<<temp1[i].menu<<endl;
				return;
            }
            }

            if(flag==0)
                {
                     cout<<endl<<"*** NOT FOUND!!! invalid entry *** !!! Please try again";
                }

}
//********************************************************************************************
void airlines:: Discount()//Discount function
{
    cout<<"*******************************************************************************";

	cout<<"\n Discount Rules:";
	cout<<"\n1. If Passenger is below or equal 14 year then 30% discount on fare.";
	cout<<"\n2. If Passenger is female & below or equal 14 year, Extra 10% discount on fare.";
	cout<<"\n3. If Passenger is male then there is no extra discount on fare.";

	cout<<"\n********************************************************************************";

	cout<<endl<<"Enter the Age of a Passenger:";
	cin>>age;

	cout<<"\nEnter Your Gender:'m' for male and 'f' for female : ";
	cin>>gen;

    cout<<"\nEnter Air Ticket fare RS:";
	cin>>fare;

	if(age<=14)
	{
		//cout<<"\n Press Enter to get the discount\n";

		if(gen=='f')
		{
			fare=fare-(fare*0.4);
			cout<<endl<< "You are eligible to get 30% + 10% Extra Discount on fare.";
			cout<<endl<<"Air Ticket fare after Discount is "<<fare<<endl;
		}
		else if(gen=='m')
		{
			fare=fare-(fare*0.3);
			cout<<endl<<"You are eligible to get 30% Discount";
			cout<<endl<<"Air Ticket fare after Discount is "<<fare<<endl;
		}
	}
	else
	{
		cout<<"You are not eligible to get Discount!";
	}

}//end of the discount function.


void airlines:: print_report()	 //This function prints the status report of the flight.
{
	cout<<"The number of reserved seats are: " << reserve <<endl;
    cout<<"The number of cancelled seats are:"<<cancel<<endl;
}

//********************************************************************************************

int main()
{
    airlines a1,temp1[40];//array of objects to store the information of passengers

	system("CLS");	// clean the terminal
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout << "\t     WELCOME TO AIRLINE RESERVATION SYSTEM \n";
	cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
	cout<<" ..................... MENU OPTIONS .............................\n"<<endl;

	a1.main_menu();	//calling the menu function.
	return 0;
}


