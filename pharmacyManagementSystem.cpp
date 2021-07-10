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
class pharmacyManagementSystem {
    public:
        void mainMenu(); // Pharmacy Management System Main Menu
    void search(); // Search For Certain Medicine
    void takeOrder(); // Orders To Be Taken
    void deleteOrder(); // Delete The Medicine
    void modify(); // Modify The Medicine/ Customer Information
    void orderList(); // Display The Order List
    void dailySummary(); // Display The Summary List
    void exit(); // Exit Function
    void displayMedicine(); // Displays The Set Of Medicine
    void displayCustomers(); // Displays The Set Of Customers - Back Up
    pharmacyManagementSystem(); // Constuctor
};

pharmacyManagementSystem::pharmacyManagementSystem() {} // Constructor For Class pharmacyManagementSystem

// Structure Of Type Node
struct node {
    string customerName;
    string date;
    string medicineName[MAX] = {
        "Dolo 650",
        "CITRA C",
        "Bupropion",
        "Zoloft",
        "Sumitop",
        "Omeprazole",
        "Digene",
        "HealthVit",
        "Naproxen",
        "Neurobion"
    };
    int recieptNumber;
    int quantity[MAX];
    int x, menu2[MAX];
    float amount[MAX];
    double Medicine[MAX] = {
        200.00,
        200.00,
        500.00,
        400.00,
        500.00,
        300.00,
        100.00,
        400.00,
        300.00,
        300.00
    };
    double total;
    node * prev;
    node * next;
    node * link;
}* q, * temp; // Pointer Of Type Node

node * start_ptr = NULL;
node * head = NULL;
node * last = NULL;

void pharmacyManagementSystem::mainMenu() {
    pharmacyManagementSystem pharmacyManagementSystemObj;
    int choice;
    do {
        cout << "\n\t    Pharmacy Management System \n";
        cout << "==================================================\n\n";
        cout << "--------------------------------------------------\n";
        cout << "||\t1. Search For The Medicine/Customer \t||\n";
        cout << "||\t2. New Medicine Order \t\t\t||\n";
        cout << "||\t3. Delete Latest Medicine Order Details ||\n";
        cout << "||\t4. Modify Order List \t\t\t||\n";
        cout << "||\t5. Print Reciept And Make Payment \t||\n";
        cout << "||\t6. Daily Summary Of Total Sales \t||\n";
        cout << "||\t7. Display Available Medicine \t\t||\n";
        cout << "||\t8. Display Back Up Customer Details \t||\n";
        cout << "||\t9. Exit \t\t\t\t||\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            pharmacyManagementSystemObj.search();
            break;
        }

        case 2: {
            pharmacyManagementSystemObj.takeOrder();
            break;
        }

        case 3: {
            pharmacyManagementSystemObj.deleteOrder();
            break;
        }

        case 4: {
            pharmacyManagementSystemObj.modify();
            break;
        }

        case 5: {
            pharmacyManagementSystemObj.orderList();
            break;
        }

        case 6: {
            pharmacyManagementSystemObj.dailySummary();
            break;
        }

        case 7: {
            pharmacyManagementSystemObj.displayMedicine();
            break;
        }

        case 8: {
            pharmacyManagementSystemObj.displayCustomers();
            break;
        }

        case 9: {
            pharmacyManagementSystemObj.exit();
            system("CLS");
            break;
        }

        default: {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n" <<
                endl;
            break;
        }
        }
    } while (choice != 9);
}

// Search Function
void pharmacyManagementSystem::search() {
    system("CLS");
    string search;
    string line;
    int choice, offset, flag = 0;
    node * temp;
    temp = new node;
    ifstream in ; in .open("takeCustomerInfo.txt");
    cout << "=====================================================" << endl;
    cout << "Search :\n";
    cout << "=====================================================" << endl;
    cout << "Enter The Name Of The Customer You Wish To Search In The Records : "; // Search For Customer
    cin >> search;
    cout << endl;
    if ( in .is_open()) {
        while (! in .eof()) {
            getline( in , line);
            offset = line.find(search, 0);
            if (offset != string::npos) {
                cout << "The Searched Entity " << search << " Is Found In The Records!" << endl; // Searched Entity Found
                flag = 1;
            }
        }
        if (!flag) {
            cout << "The Searched Entity " << search << " Isn't Found In The Records!" << endl; // Searched Entity Not Found
        } in .close();
    } else {
        cout << "Couldn't Open File" << endl;
        system("PAUSE");
    }
    system("PAUSE");
    system("CLS");
}

// Take Order Function
void pharmacyManagementSystem::takeOrder() {
    system("CLS");
    int i;
    float totalPrice = 0;
    string takeOrderText;
    cout << "\nSelect The Medicines That You Would Like To Buy\n";
    cout << "------------------------------------------------ \n\n";
    node * temp;
    temp = new node;
    // ofstream out("takeCustomerInfo.txt");
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);
    ifstream in ("takeOrder.txt");
    for (i = 0; i < 14; i++) {
        getline( in , takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
    cout << "Type Reciept Number: ";
    cin >> temp -> recieptNumber;
    out << "Reciept Number : " << temp -> recieptNumber << endl;
    cout << "Enter Customer Name: ";
    cin >> temp -> customerName;
    out << "Customer Name : " << temp -> customerName << endl;
    cout << "Enter Date: ";
    cin >> temp -> date;
    out << "Date : " << temp -> date << endl;
    cout << "" << endl;
    cout << "\"NOTE : Maximum 10 Medicine Can Be Ordered Per Transaction\" \n";
    cout << "Please Enter The Total Count Of Medicine You Would Like To Order: ";
    cin >> temp -> x;
    out << "Number Of Medicine Ordered : " << temp -> x << endl;
    if (temp -> x > MAX) {
        cout << "Excessive Amount Of Medicine Ordered Error!";
        system("PAUSE");
    } else {
        for (i = 0; i < temp -> x; i++) {
            cout << "Please Enter The Medicine That You Wish To Buy : ";
            cin >> temp -> menu2[i];
            cout << "Medicine Name: " << temp -> medicineName[temp -> menu2[i] - 1] << endl;
            out << "Medicine Name : " << temp -> medicineName[temp -> menu2[i] - 1] << endl;
            cout << "Count Of The Respective Medicine : ";
            cin >> temp -> quantity[i];
            out << "Medicine Quantity : " << temp -> quantity[i] << endl;
            temp -> amount[i] = temp -> quantity[i] * temp -> Medicine[temp -> menu2[i] - 1];
            totalPrice = totalPrice + temp -> amount[i];
        }
        cout << "You've Been Charged With Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
        out << "Total Price : Rs. " << totalPrice << ".00\n" <<
            endl;
        out << "==================================\n" <<
            endl;
        cout << "===========================================================================" << endl;
        cout << "Order Placed Successfully" << endl;
        cout << "===========================================================================" << endl;
        cout << "Head To The Reciept Menu To Pay The Bill" << endl;
        cout << "===========================================================================" << endl;
        temp -> next = NULL;
        if (start_ptr != NULL) {
            temp -> next = start_ptr;
        }
        start_ptr = temp;
        system("PAUSE");
        system("CLS");
    }
}

// Delete Order Function
void pharmacyManagementSystem::deleteOrder() {
    system("CLS");
    int i, num, count;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter the Receipt Number You Wish To Delete : ";
    cin >> num;
    node * q;
    node * temp;
    bool found;

    if (start_ptr == NULL)
        cerr << "Empty List, No Entries Detected To Delete\n";
    else {
        if (start_ptr -> recieptNumber == num) {
            q = start_ptr;
            start_ptr = start_ptr -> next;
            count--;
            if (start_ptr == NULL)
                last = NULL;
            delete q;
            cout << "The Reciept is Deleted Successfully!" << endl;
        } else {
            found = false;
            temp = start_ptr;
            q = start_ptr -> next;
            while ((!found) && (q != NULL)) {
                if (q -> recieptNumber != num) {
                    temp = q;
                    q = q -> next;
                } else
                    found = true;
            }
            if (found) {
                temp -> next = q -> next;
                count--;
                if (last == q)
                    last = temp;
                delete q;
                cout << "The Reciept is Deleted Successfully!" << endl;
            } else
                cout << "Sorry, No Such Receipt Found!\n" << endl;
        }
    }
}

// Modify Order/Customer Details Function
void pharmacyManagementSystem::modify() {
    system("CLS");
    int i, sid;
    bool found;
    found = false;
    float totalPrice = 0;
    node * temp;
    temp = start_ptr;
    ofstream out;
    out.open("takeCustomerInfo.txt", ios::out | ios::app);

    cout << "Enter Receipt Number To Modify: ";
    cin >> sid;
    if (temp == NULL || sid == 0) {
        cout << "No Such Record Found To Modify!" << endl;
    } else {
        while (temp != NULL && !found) {
            if (temp -> recieptNumber == sid) {
                found = true;
            } else {
                temp = temp -> next;
            }
            if (found) {
                cout << "Change Reciept Number : ";
                cin >> temp -> recieptNumber;
                out << "Reciept Number : " << temp -> recieptNumber << endl;
                cout << "Change Customer Name : ";
                cin >> temp -> customerName;
                out << "Customer Name : " << temp -> customerName << endl;
                cout << "Change Date : ";
                cin >> temp -> date;
                out << "Date : " << temp -> date << endl;
                cout << "" << endl;
                cout << "\"NOTE : Maximum 10 Medicine Can Be Ordered Per Transaction\" \n";
                cout << "Please Enter The Total Count Of Medicine You Would Like To Order: ";
                cin >> temp -> x;
                out << "Number Of Medicine Ordered : " << temp -> x << endl;
                if (temp -> x > MAX) {
                    cout << "Excessive Amount Of Medicine Ordered Error!";
                    system("PAUSE");
                } else {
                    for (i = 0; i < temp -> x; i++) {
                        cout << "Please Enter The Medicine That You Wish To Buy : ";
                        cin >> temp -> menu2[i];
                        cout << "Medicine Name: " << temp -> medicineName[temp -> menu2[i] - 1] << endl;
                        out << "Medicine Name : " << temp -> medicineName[temp -> menu2[i] - 1] << endl;
                        cout << "Count Of The Respective Medicine : ";
                        cin >> temp -> quantity[i];
                        out << "Medicine Quantity : " << temp -> quantity[i] << endl;
                        temp -> amount[i] = temp -> quantity[i] * temp -> Medicine[temp -> menu2[i] - 1];
                        totalPrice = totalPrice + temp -> amount[i];
                    }
                    cout << "You've Been Charged With Amount Of Rs. " << totalPrice << ".00" << endl; // Displaying The Total Price Charged
                    out << "Total Price : Rs. " << totalPrice << ".00\n" << endl;
                    out << "==================================\n" << endl;
                    temp = temp -> next;
                    system("CLS");
                }
                cout << "Record Modification Successful!" << endl;
            } else {
                if (temp != NULL && temp -> recieptNumber != sid) {
                    cout << "Invalid Reciept Number, Kindly Check The Reciept Number Entered" << endl;
                }
            }
        }
    }
}

// Order List Function
void pharmacyManagementSystem::orderList() {
    int i, num, num2;
    bool found = false; // Search Variable
    system("cls");
    node * temp;
    temp = start_ptr;
    float totalPrice = 0;

    cout << "Enter the Reciept Number To Print The Reciept : ";
    cin >> num2;
    cout << "\n";
    cout << "=====================================================" << endl;
    cout << "List Of Orders :\n";
    cout << "=====================================================" << endl;

    if (temp == NULL) // Entered Receipt Number Is Invalid
    {
        cout << "No Such Receipt Number Found In Our Record!\nKindly Enter The Correct Receipt Number\n\n";
    }
    while (temp != NULL && !found) {
        if (temp -> recieptNumber == num2) {
            found = true;
        } else {
            temp = temp -> next;
        }
        if (found) // Print The Receipt
        {
            cout << "Reciept Number : " << temp -> recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp -> customerName << endl;
            cout << "Order Date : " << temp -> date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp -> x; i++) {
                cout << "|    " << temp -> medicineName[temp -> menu2[i] - 1] << "     ";
                cout << "|        " << temp -> quantity[i] << "        ";
                cout << "|    " <<
                    " Rs." << temp -> amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp -> amount[i];
            }
            cout << "Total Bill : " <<
                " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "\n";
            b:
                cout << "Type In The Amount To Be Payed : ";
            cin >> num;
            if (num < totalPrice) {
                cout << "Kindly Pay The Prescribed Amount!\n" <<
                    endl;
                goto b;
            } else if (num > totalPrice) {
                cout << "_____________________________________________________\n";
                cout << "Payment Done Successfully!" << endl;
                cout << "Here's Your Change Of Rs. " << num - totalPrice << ".00" << endl;
                cout << "Thank You" << endl;
            } else {
                cout << "Payment Done Successfully!\nThank You\n";
                cout << "_____________________________________________________\n";
            }
        }
    }
    system("PAUSE");
    system("CLS");
}

// Daily Summary Function
void pharmacyManagementSystem::dailySummary() {
    int i, num;
    system("CLS");
    node * temp;
    temp = start_ptr;
    float totalPrice = 0;

    if (temp == NULL) // Invalid Receipt Code
    {
        cout << "No Orders To Show!\n" <<
            endl;
    } else {
        cout << "\n";
        cout << "=====================================================" << endl;
        cout << "Daily Summary Of All Orders \n"; // Print All YTransactions Occurred
        cout << "=====================================================" << endl;

        while (temp != NULL) {
            cout << "Reciept Number : " << temp -> recieptNumber;
            cout << "\n";
            cout << "Customer Name: " << temp -> customerName << endl;
            cout << "Order Date : " << temp -> date << endl;
            cout << "_____________________________________________________" << endl;
            cout << "=====================================================" << endl;
            cout << "|  Medicine Name  |  	Quantity    |  Total Price  |" << endl;
            cout << "=====================================================" << endl;
            for (i = 0; i < temp -> x; i++) {
                cout << "|    " << temp -> medicineName[temp -> menu2[i] - 1] << "     ";
                cout << "|        " << temp -> quantity[i] << "        ";
                cout << "|    " <<
                    " Rs." << temp -> amount[i] << "    |" << endl;
                cout << "_____________________________________________________" << endl;
                totalPrice = totalPrice + temp -> amount[i];
            }
            cout << "Total Bill : " <<
                " Rs." << totalPrice << ".00" << endl; // Displaying The Total Bill
            cout << "_____________________________________________________\n";

            temp = temp -> next;
        }
    }
    system("PAUSE");
    system("CLS");
}

// Display Medicine Function 
void pharmacyManagementSystem::displayMedicine() {
    cout << endl;
    system("CLS");
    string takeOrderText;
    ifstream in ("takeOrder.txt");
    for (int i = 0; i < 14; i++) {
        getline( in , takeOrderText);
        cout << takeOrderText << endl;
    }
    cout << "" << endl;
    system("PAUSE");
}

// Display Back-Up Customer Details 
void pharmacyManagementSystem::displayCustomers() {
    cout << endl;
    system("CLS");
    string takeCustomerInfo;
    ifstream in ("takeCustomerInfo.txt");
    // in.seekg(0, ios::end); 
    // int len = in.tellg();
    // if (len == 0) {    
    //     cout << "No Entries Found!" << endl;
    //     system("PAUSE"); 
    // }
    while (! in .eof()) {
        getline( in , takeCustomerInfo);
        cout << takeCustomerInfo << endl;
    }
    system("PAUSE");
}

// Exit Function
void pharmacyManagementSystem::exit() {
    cout << "\nYou Chose To Exit" << endl;
    cout << "Thank You So Much!\n" <<
        endl;
    system("PAUSE");
}

// Main Function
int main(void) {
    system("CLS");
    pharmacyManagementSystem pharmacyManagementSystemObj;
    cout << "\n\t    Pharmacy Management System \n";
    cout << "==================================================\n\n";
    cout << "--------------------------------------------------\n";
    cout << "||\tFile Structure Mini Project \t\t||\n";
    cout << "||\tBy : \t\t\t\t\t||\n";
    cout << "||\tMayur Pai B H 4SF18IS053 \t\t||\n";
    cout << "||\tPrathiksha Kamath 4SF18IS069 \t\t||\n";
    cout << "--------------------------------------------------\n";
    system("PAUSE");
    system("CLS");
    pharmacyManagementSystemObj.mainMenu(); // Calling Main Menu To Run
    return 0;
}
/***************************************END OF PROGRAM***************************************/