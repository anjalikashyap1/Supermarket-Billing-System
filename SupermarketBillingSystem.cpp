#include <iostream>
#include <fstream>
using namespace std;

class shopping {
public:
    int pcode;
    string pname;
    float dis;
    float price;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
m:
    int choice;
    string email, password;
    cout<<"\n\n\t\t\t  ______________________________________________________________________________";
    cout<<"\n\t\t\t |                        S-U-P-E-R-M-A-R-K-E-T                                 |";
    cout<<"\n\t\t\t |-----------------------------Main Menu----------------------------------------|";
    cout<<"\n\t\t\t |______________________________________________________________________________|";
    cout<<"\n\t\t\t |                                                                              |";
    cout<<"\n\t\t\t |  1) Administrator                                                            |";
    cout<<"\n\t\t\t |  2) Buyer                                                                    |";
    cout<<"\n\t\t\t |  3) Exit                                                                     |";
    cout<<"\n\t\t\t |______________________________________________________________________________|";
    cout<<"\n\n\t\t\t Please Enter Your Choice  : ";
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "\n\t\tPlease Enter Your Email = ";
        cin >> email;
        cout << "\n\t\tPlease Enter Your Password = ";
        cin >> password;

        if (email == "abc@gmail.com" && password == "1234") {
            administrator();
        } else {
            cout << "\n\t\tInvalid!  Please check again!";
        }
        break;
    }
    case 2: {
        buyer();
        break;
    }
    case 3: {
        exit(0);
    }
    default: {
        cout << "\n\t\tPlease Select From Given Option!";
    }
    }
    goto m;
}

void shopping::administrator() {
m:
    int c;
    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|                           ADMINISTRATOR                                      |";
    cout << "\n\t\t\t|-----------------------------Main Menu----------------------------------------|";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\t\t\t|                                                                              |";
    cout << "\n\t\t\t|________1) Add the Product.                                                   |";
    cout << "\n\t\t\t|________2) Modify the Product.                                                |";
    cout << "\n\t\t\t|________3) Delete the Product.                                                |";
    cout << "\n\t\t\t|________4) show Product List.                                                 |";
    cout << "\n\t\t\t|________5) Back to Main Menu.                                                 |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\n\t\t\t Please Enter Your Choice  : ";
    cin >> c;

    switch (c) {
    case 1: {
        add();
        break;
    }
    case 2: {
        edit();
        break;
    }
    case 3: {
        rem();
        break;
    }
    case 4:{
        list();
        break;
    }
    case 5: {
        menu();
        break;
    }
    default:
        cout << "\n\t\t\t Invalid choice";
    }
    goto m;
}

void shopping::buyer() {
m:
    int c;

    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|                             ----BUYER----                                    |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\t\t\t|                                                                              |";
    cout << "\n\t\t\t|  1) Buy                                                                      |";
    cout << "\n\t\t\t|  2) Go back                                                                  |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\n\t\t\t Please Enter Your Choice  : ";
    cin >> c;

    switch (c) {
    case 1: {
        receipt();
        break;
    }
    case 2: {
        menu();
        break;
    }
    default:
        cout << "\n\n\t\t Invalid Choice !";
    }
}

void shopping::add() {
    fstream data;
    int c;
    string n;
    float p, d;
    int token = 0;

    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|                             ----Add New Product----                          |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\n\t\t\t  Product code of the product: ";
    cin >> c;
    cout << "\n\t\t\t|   Name of the product: ";
    cin >> n;
    cout << "\n\t\t\t|   Price of the product: ";
    cin >> p;
    cout << "\n\t\t\t|   Discount on product: ";
    cin >> d;

    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << c << "  " << n << "   " << p << "  " << d << "\n";
        data.close();
    } else {
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();

        if (token == 1) {
            cout << "\n\n\t\t\t Duplicate Product Code. Please Enter Again!";
            add(); // Recursive call to add() if there's a duplicate code
        } else {
            data.open("database.txt", ios::app | ios::out);
            data << c << "  " << n << "  " << p << "  " << d << "\n";
            data.close();
            cout << "\n\n\t\t\t Record Inserted ! ";
        }
    }
}

void shopping::edit() {
    fstream data, data1;
    int c;
    int token = 0;
    string n;
    float p, d;
    int pkey;

    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|                             ----Modify the Product----                       |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\n\t\t\t   Enter the Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n\t\t File Doesn't Exist !";
    } else {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t\t\t Enter the new code : ";
                cin >> c;
                cout << "\n\n\t\t\t Name of the Product : ";
                cin >> n;
                cout << "\n\n\t\t\t Price : ";
                cin >> p;
                cout << "\n\n\t\t\t Discount : ";
                cin >> d;
                data1 << c << "  " << n << "  " << p << "  " << d << "\n";
                cout << "\n\n\t\t\t Record Edited !";
                token++;
            } else {
                data1 << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n\t\t\t Record Does not found!";
        }
    }
} 

void shopping::rem() {
    fstream data, data1;
    int pkey, token = 0;

    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|                             ----Delete Product----                           |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    cout << "\n\n\t\t\t Enter Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n\t\t\t File Doesn't Exist !";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t\t\t Product Deleted Successfully !";
                token++;
            } else {
                data1 << pcode << "  " << pname << "  " << price << "  " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n\t\t\t Record Does not found!";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n\t\t\t ______________________________________________________________________________";
    cout << "\n\t\t\t|             ProNo.                Name               Price                   |";
    cout << "\n\t\t\t|______________________________________________________________________________|";
    data >> pcode >> pname >> price >> dis;

    while (!data.eof()) {
        cout << "\n\n\t\t\t" <<"\t\t"<< pcode << "\t\t" << pname << "\t\t" << price;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float total = 0, amount = 0, discount = 0;

    cout << "\n\n\t\t\t Receipt : ";
    data.open("database.txt", ios::in);
    if (data.eof()) {
        cout << "\n\t\t Empty database";
    } else {
        data.close();
        list();
        cout << "\n\n\t\t\t ______________________________________________________________________________";
        cout << "\n\t\t\t|                         ----Please Place The Order----                       |";
        cout << "\n\t\t\t|______________________________________________________________________________|";

        do {
        m:
            cout << "\n\n\t\t\t Enter the Product Code : ";
            cin >> arrc[c];
            cout << "\n\n\t\t\t Enter the Product Quantity : ";
            cin >> arrq[c];

         /* for (int i = 0; i < c; i++) {
                if (arrc[c] == arrq[i]) {
                    cout << "\n\n\t\t\tDuplicate Product Code. Please Enter Again ! ";
                    goto m;
                }
            }*/
            c++;
            cout << "\n\n\t\t\t Do you want to buy another product. If yes then press y else n. : ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');

        cout << "\n\t\t\t------------------------------------------------Receipt----------------------------------------------";
        cout << "\n\n\t\t\t\tProduct No.\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with discount";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    discount = amount - (amount * dis / 100);
                    total += discount;
                    cout<<"\n\n\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price <<"\t"<<amount<<"\t"<<discount;
                }
               
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }

    cout << "\n\n\t\t\t_______________________________________________________________________________________________________";
    cout << "\n\n\t\t\tTotal Amount : " << total;
}

int main() {
    shopping s;
    s.menu();

    return 0;
}
