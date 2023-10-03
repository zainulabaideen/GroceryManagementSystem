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
