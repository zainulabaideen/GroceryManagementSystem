#include<windows.h>
#include<iostream>
#include<string>
using namespace std;


//global variables
 int index=0,totalindex=0; 
const int MAX_SIZE = 1000;
int itemquantity[ MAX_SIZE],itemprice[ MAX_SIZE];
string itemname[MAX_SIZE];
int arraynumber=0;
int getitemquantity[MAX_SIZE],subtotalamount[MAX_SIZE];
string getitemname[MAX_SIZE];
int add();
int edit();
int retrive();
int delet();
int compare();
int retriveuserdata(int totalamout);

int main(){
			string z;
	int totalamout=0;
string newusername,newpasword,username,pasword;
int no,choice,usorad;
int userchoice;
	system("CLS");
home:
	totalamout=0;
	cout<<"Press 0 if you want to go out of program\n";
	cout<<"Press 1 if you are administrator \nPress 2 if you are a User: ";
	cin>>usorad;
	while(usorad!=0){
	if(usorad==1){
	
//	Sign up
signup:
	system("CLS");
cout<<"Press 1 for Sign Up\nPress 2 for Login:";
cin>>no;
if(no==1){


system("CLS");
	cout<<"Sign Up\n";
	cout<<"Enter Your User Name:";
	cin>>newusername;
	cout<<" Enter Your Pasword:";
	cin>>newpasword;
	no=2;
	 }

//	Login 
 if(no==2){

system("CLS");	
//
	cout<<"LogIn\n";
	cout<<"Enter Your User Name:";
	cin>>username;
	cout<<"Enter Your Pasword:";
	cin>>pasword;
	if(username==newusername && pasword==newpasword){			
	system("CLS");
	cout<<"\tWelcome\n\n";
choices:
	
	
//	CRUD
	cout<<"Press 1 to enter data\nPress 2 to Update data\nPress 3 to Delete data\nPress 4 to retrive data\nPress 5 to exit.";
	cin>>choice;
	switch(choice){
		
		case 1:{
		system("CLS");
			add();
			Sleep(3000);
				system("CLS");
			goto choices;
				
			}
			case 2:{
			system("CLS");
			cout<<edit();
				system("CLS");
			goto choices;
			}
		    case 3:{
			
			cout<<delet();
					Sleep(2000);
					system("CLS");
						
					goto choices;
			}
		case 4:{
			system("CLS");
			cout<<retrive();
				cout<<"\nPress any key to go to userside  ";
				cin>>z;
				system("CLS");
				goto choices;
			}
			case 5:{
					system("CLS");
				goto home;
				
			
			}
			
		default:{
			cout<<"Invalid Input";
			break;
		}	
			
	}
}
	


	else {
		cout<<"Invalid Username Or Pasword";
		Sleep(3000);
		goto signup;
	}
	
	}
}
//userside


		else if(usorad==2){
			userside:
				system("CLS");
			cout<<"Welcome to User/Saling Side\n";
			cout<<"Press 1 to buy\nPress 2 to get total \nPress 3 to go to main page: ";
			cin>>userchoice;
			switch(userchoice){

			case 1:{
					system("CLS");
				compare();
				Sleep(3000);
				goto userside;
			}
			
			case 2 :{
					
	
				retriveuserdata(totalamout);
				cout<<"\nPress any key to go to userside  ";
				cin>>z;
				arraynumber=0;
				goto userside;
				system("CLS");	
			

			}
				
			case 3:{
				system("CLS");
				goto home;
				
			}
			default:{
				cout<<"Invalid Input";
				break;
			}
	}
		}
		else{
			usorad=0;
		}
		
	}

return 0;
}



//global Functions

int add(){
	cout<<"How many Items do you want to add:";
	cin>>index;	
	itemprice[index],itemname[index],itemquantity[index];
	if(totalindex==0){

	for(int i=0; i<index; i++){
	cout<< "Enter "<<i+1<<" Item Name:";
	cin>>itemname[i];	
		cout<< "Enter " <<i+1<< " Item Quantity:";
	cin>>itemquantity[i];	
		cout<< "Enter " <<i+1<<" Item Price:";
	cin>>itemprice[i];	
	
	}
		totalindex+=index;	
		}
		else{
		
				for(int i=totalindex; i<index+totalindex; i++){
	cout<< "Enter "<<i+1<<" Item Name:";
	cin>>itemname[i];	
		cout<< "Enter " <<i+1<< " Item Quantity:";
	cin>>itemquantity[i];	
		cout<< "Enter " <<i+1<<" Item Price:";
	cin>>itemprice[i];	
				
	}
	totalindex+=index;
}
	cout<<endl<<"\t\tYour Complete Items Are\n\n";
	
	cout<<"Sr.\t\tName\t\tQuantity\tPrice\n\n";
	for(int i=0; i<totalindex; i++){
		cout<<i+1<<"\t\t"<<itemname[i]<<"\t\t"<<itemquantity[i]<<"\t\t"<<itemprice[i]<<"\t\t"<<endl;
	
	}
}

int edit(){
	int updatedkey=0;
//Preveious data
	cout<<"Previous Data\n\n";
	cout<<"Sr.\t\tName\t\tQuantity\tPrice\n\n";
	for(int i=0; i<totalindex; i++){
		cout<<i+1<<"\t\t"<<itemname[i]<<"\t\t"<<itemquantity[i]<<"\t\t"<<itemprice[i]<<"\t\t"<<endl;
	
	}
//	new data
cout<<"Enter the Item No. You want to Update:";
cin>>updatedkey;
	if(updatedkey<=totalindex){
	cout<< "Enter "<<updatedkey<<" Item Name:";
	cin>>itemname[updatedkey-1];	
	cout<< "Enter " <<updatedkey<< " Item Quantity:";
	cin>>itemquantity[updatedkey-1];	
	cout<< "Enter " <<updatedkey<<" Item Price:";
	cin>>itemprice[updatedkey-1];
}
else{

	cout<<"Invalid Number";
	Sleep(3000);
	}
}

int delet(){
int deldata=0;
int delchoice;
cout<<"Press 1 if you want to delete the entire data and 2 for a single data:";
cin>>delchoice;
int found=0;
if(delchoice==1){
	totalindex=0;
	cout<<"All Data Deleted Successfully.";
}
if(delchoice==2){
cout<<"Enter the Item No. You want to Delete:";
cin>>deldata;
	for(int i=0; i<totalindex; i++){
	if(deldata==i+1){
			for(int j=i; j<=totalindex; j++){
			itemname[j]=itemname[j+1];
			itemprice[j]=itemprice[j+1];
			itemquantity[j]=itemquantity[j+1];
			found++;
			}
		
		totalindex--;
		}
}
if(found==0){
	cout<<"Data Not Found";
	return 0;
}		
else{
	cout<<"Data Deleted Successfully!!";
	return 0;
		}
	}
}
int retrive(){
	cout<<"Sr.\t\tName\t\tQuantity\tPrice\n\n";
	for(int i=0; i<totalindex; i++){
		cout<<i+1<<"\t\t"<<itemname[i]<<"\t\t"<<itemquantity[i]<<"\t\t"<<itemprice[i]<<"\t\t"<<endl;
	
	}	
}


//userside
int compare(){
	char y;			
//	if(get)
	while( y!='e'){
		system("CLS");
			cout<<"Enter the item name you want to buy in small alphabets(a-z):";
			cin>>getitemname[arraynumber];
		for(int i=0; i<totalindex; i++){
	
		if(getitemname[arraynumber]==itemname[i]){
			cout<<"How much do you want( in numbers ):";
			cin>>getitemquantity[arraynumber];
			if(getitemquantity[arraynumber]<=itemquantity[i]){
			
			itemquantity[i]=itemquantity[i]-getitemquantity[arraynumber];
			subtotalamount[arraynumber]=getitemquantity[arraynumber]*itemprice[i];
			break;
			}
			else{
				cout<<"\nNot Enough Stock is Available";
			}
			break;
		}
		if(i==totalindex-1){
			cout<<"\nThe Item is not Available Now";
		}

		}
		arraynumber++;	
		cout<<"\nPress e for stop buying and press any key to continue?";
	cin>>y;
	}
	int j=1;
	
		cout<<"Sr.\t\tName\t\tQuantity\tPer Item\tSubtotal\n\n";
	for(int i=0; i<arraynumber; i++){
		if(subtotalamount[i]>0){
		
		cout<<j<<"\t\t"<<getitemname[i]<<"\t\t"<<getitemquantity[i]<<"\t\t"<<itemprice[i]<<"\t\t"<<subtotalamount[i]<<endl;
	j++;
}
	}
		
}
int retriveuserdata(int totalamout){
	int j=1;
	cout<<"Sr.\t\tName\t\tQuantity\tPer Item\tSubtotal\n\n";
	for(int i=0; i<arraynumber; i++){
		
		if(subtotalamount[i]>0){
		
		
		cout<<j<<"\t\t"<<getitemname[i]<<"\t\t"<<getitemquantity[i]<<"\t\t"<<itemprice[i]<<"\t\t"<<subtotalamount[i]<<"\t\t"<<endl;
		totalamout=totalamout+subtotalamount[i];
		j++;
		}
	
	}
	cout<<"\n\nYour total Amount is = "<<totalamout<<"\n";

}


