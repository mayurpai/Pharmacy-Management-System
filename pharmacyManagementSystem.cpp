/*  File Structure Mini Project On "Pharmacy Management System"
*   By Mayur Pai B H & Prathiksha Kamath  
*/

// Standard Libraries
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define MAX 10

// Header File
using namespace std;

// Base Class
class pharmacyManagementSystem
{
public:
    void mainMenu();            // Pharmacy Management System Main Menu
    void searchMedicine();      // Search For Certain Medicine
    void takeOrder();           // Orders To Be Taken
    void deleteOrder();         // Delete The Medicine
    void modify();              // Modify The Medicine/ Customer Information
    void orderList();           // Display The Order List
    void dailySummary();        // Display The Summary List
    void exit();                // Exit Function
    pharmacyManagementSystem(); // Constuctor
};

pharmacyManagementSystem::pharmacyManagementSystem() {} // Constructor For Class pharmacyManagementSystem

// Structure Of Type Node
struct node
{
	string customerName;
	string date;
    string medicineName[10]={"Dolo 650","CITRA C","Bupropion","Zoloft","Sumitop","Omeprazole","Digene","HealthVit","Naproxen","Neurobion"};
	int recieptNumber;
	int quantity[10];
	int x, menu2[10];
    float amount[10];
	double Medicine[10] = {200.00,200.00,500.00,400.00,500.00,300.00,100.00,400.00,300.00,300.00};
	double total;
	node *prev;
	node *next;
	node *link; 
}*q, *temp;    // Pointer Of Type Node

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

void pharmacyManagementSystem::mainMenu() {
pharmacyManagementSystem pharmacyManagementSystemObj;
    int choice;
    do
    {
        cout << "\t\t\t    Pharmacy Management System \n";
        cout << "\t\t==================================================\n\n";
        cout << "\t\t--------------------------------------------------\n";
        cout << "\t\t||\t1. Search For The Medicine \t\t||\n";
        cout << "\t\t||\t2. New Medicine Order \t\t\t||\n";
        cout << "\t\t||\t3. Delete Latest Medicine Order Details ||\n";
        cout << "\t\t||\t4. Modify Order List \t\t\t||\n";
        cout << "\t\t||\t5. Print Reciept And Make Payment \t||\n";
        cout << "\t\t||\t6. Daily Summary Of Total Sales \t||\n";
        cout << "\t\t||\t7. Exit \t\t\t\t||\n";
        cout << "\t\t--------------------------------------------------\n";
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            pharmacyManagementSystemObj.searchMedicine();
            break;
        }

        case 2:
        {
            pharmacyManagementSystemObj.takeOrder();
            break;
        }

        case 3:
        {
            pharmacyManagementSystemObj.deleteOrder();
            system("PAUSE");
            break;
        }

        case 4:
        {
            pharmacyManagementSystemObj.modify();
            system("PAUSE");
            break;
        }

        case 5:
        {
            pharmacyManagementSystemObj.orderList();
            system("PAUSE");
            break;
        }

        case 6:
        {
            pharmacyManagementSystemObj.dailySummary();
            system("PAUSE");
            break;
        }

        case 7:
        {
            pharmacyManagementSystemObj.exit();
            goto a;
            break;
        }

        default:
        {
            cout << "\t\tYou Entered An Invalid Key Input\n\t\tKindly, Re-enter The Input! \n" << endl;
            break;
        }
        }
    } while (choice != 7);
    a:    // Goto
    cout << "\t\tThank You So Much!" << endl;
    // return 0;
}

void pharmacyManagementSystem::searchMedicine() {}

void pharmacyManagementSystem::takeOrder() {
    system("CLS");
	int i;
    float totalPrice = 0;
    string takeOrderText;
	cout <<"\nSelect The Medicines That You Would Like To Buy\n";
	cout <<"------------------------------------------------ \n\n";
	node *temp;
	temp = new node;
    ofstream out("takeCustomerInfo.txt");
	ifstream in("takeOrder.txt");
    for(i=0;i<14;i++) {
        getline(in, takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
	cout << "Type Reciept Number: ";
    cin >> temp->recieptNumber;
    out << "Reciept Number : " << temp->recieptNumber << endl ;
	cout << "Enter Customer Name: ";
	cin >> temp->customerName;
    out << "Customer Name : " << temp->customerName << endl ;
	cout <<"Enter Date: ";
	cin >>temp->date;
    out << "Date : " << temp->date << endl ;
    cout << "" << endl;
	cout <<"\"NOTE : Maximum 10 Medicine Can Be Ordered Per Transaction\" \n";
	cout <<"Please Enter The Total Count Of Medicine You Would Like To Order: ";
	cin >> temp->x;
    out << "Number Of Medicine Ordered : " << temp->x << endl ;
	if (temp->x >10)
	{
		cout << "Excessive Amount Of Medicine Ordered Error!";
		system("PAUSE");
	}
	else{
	for (i=0; i<temp->x; i++)
	{	
		cout << "Please Enter The Medicine That You Wish To Buy : ";
		cin >> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        out << "Medicine Name : " << temp->medicineName[temp->menu2[i]-1] << endl;
        cout << "Count Of The Respective Medicine : ";
        cin >> temp->quantity[i];
        out << "Medicine Quantity : " << temp->quantity[i] << endl;
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        totalPrice = totalPrice + temp->amount[i]; 
	}
    cout << "You've Been Charged With Amount Of Rs. "<< totalPrice << ".00" <<endl;
    out << "Total Price : " << totalPrice << endl;
	cout <<"==========================================================================="<<endl;
    cout << "Order Placed Successfully"<<endl;
    cout <<"==========================================================================="<<endl;
    cout << "Head To The Reciept Menu To Pay The Bill"<<endl;
    cout <<"==========================================================================="<<endl;
	system ("PAUSE");
    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("CLS");
}
}

void pharmacyManagementSystem::deleteOrder() {}
void pharmacyManagementSystem::modify() {}
void pharmacyManagementSystem::orderList() {}
void pharmacyManagementSystem::dailySummary() {}
void pharmacyManagementSystem::exit() {}

// Main Function
int main(void)
{
    system("CLS");
    pharmacyManagementSystem pharmacyManagementSystemObj;
    cout << "\n\t\t\t    Pharmacy Management System \n";
    cout << "\t\t==================================================\n\n";
    cout << "\t\t--------------------------------------------------\n";
    cout << "\t\t||\tFile Structure Mini Project \t\t||\n";
    cout << "\t\t||\tBy : \t\t\t\t\t||\n";
    cout << "\t\t||\tMayur Pai B H 4SF18IS053 \t\t||\n";
    cout << "\t\t||\tPrathiksha Kamath 4SF18IS069 \t\t||\n";
    cout << "\t\t--------------------------------------------------\n";
    system("PAUSE");
    system("CLS");
    pharmacyManagementSystemObj.mainMenu();
    return 0;
}