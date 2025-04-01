#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class User {
public:
    string name;
    string address;
    long cno;

    User(string name, string address, long cno)
        : name(name), address(address), cno(cno) {}
};

class Taj {
    static int billno;
    User* u;
    string food1 = "Icecream";
    string food2 = "Pav Bhaji";
    string food3 = "Pani Puri";
    string food4 = "Veg Biryani";
    string food5 = "Samosa";
    string food6 = "Bislery";

    double price1 = 50;
    double price2 = 80;
    double price3 = 30;
    double price4 = 100;
    double price5 = 15;
    double price6 = 20;

    int qty1 = 0;
    int qty2 = 0;
    int qty3 = 0;
    int qty4 = 0;
    int qty5 = 0;
    int qty6 = 0;

public:
    Taj() {
        u = nullptr;
    }

    void addUser() {
        cout << "Enter name: ";
        string name;
        cin >> name;
        cout << "Enter address: ";
        string address;
        cin >> address;
        cout << "Enter cno: ";
        long cno;
        cin >> cno;
        u = new User(name, address, cno);
        makeOrder();
    }

    void makeOrder() {
        bool b = true;

        do {
            int sno = 1;
            cout<<"Choose Your Menu:"<<endl;
            cout << sno++ << " " << food1 << "    " << price1 << endl;
            cout << sno++ << " " << food2 << "    " << price2 << endl;
            cout << sno++ << " " << food3 << "    " << price3 << endl;
            cout << sno++ << " " << food4 << "    " << price4 << endl;
            cout << sno++ << " " << food5 << "    " << price5 << endl;
            cout << sno++ << " " << food6 << "    " << price6 << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter quantity: ";
                    cin >> qty1;
                    break;
                case 2:
                    cout << "Enter quantity: ";
                    cin >> qty2;
                    break;
                case 3:
                    cout << "Enter quantity: ";
                    cin >> qty3;
                    break;
                case 4:
                    cout << "Enter quantity: ";
                    cin >> qty4;
                    break;
                case 5:
                    cout << "Enter quantity: ";
                    cin >> qty5;
                    break;
                case 6:
                    cout << "Enter quantity: ";
                    cin >> qty6;
                    break;

            }

            cout << "1. If you want to order more 2. Generate bill: ";
            int option;
            cin >> option;
            if (option == 2)
                b = false;
        } while (b);
        bill();
    }

    void bill() {
        int sno = 1;
        int sum = 0;

        if (qty1 != 0) {
            cout << sno++ << " " << food1 << " " << qty1 << " " << price1 << " = " << qty1 * price1 << endl;
            sum += qty1 * price1;
        }
        if (qty2 != 0) {
            cout << sno++ << " " << food2 << " " << qty2 << " " << price2 << " = " << qty2 * price2 << endl;
            sum += qty2 * price2;
        }
        if (qty3 != 0) {
            cout << sno++ << " " << food3 << " " << qty3 << " " << price3 << " = " << qty3 * price3 << endl;
            sum += qty3 * price3;
        }
        if (qty4 != 0) {
            cout << sno++ << " " << food4 << " " << qty4 << " " << price4 << " = " << qty4 * price4 << endl;
            sum += qty4 * price4;
        }
        if (qty5 != 0) {
            cout << sno++ << " " << food5 << " " << qty5 << " " << price5 << " = " << qty5 * price5 << endl;
            sum += qty5 * price5;
        }
        if (qty6 != 0) {
            cout << sno++ << " " << food6 << " " << qty6 << " " << price6 << " = " << qty6 * price6 << endl;
            sum += qty6 * price6;
        }

        cout << "Total: " << sum << endl;
        cout << "Enter payment amount: ";
        int payment;
        cin >> payment;

        if (payment >= sum) {
            cout << "Payment successful" << endl;
            try {
                writeToFile();
            } catch (const char* msg) {
                cerr << msg << endl;
            }
        } else {
            cout << "Payment not successful" << endl;
            bill();
        }
    }

    void writeToFile() {
        ofstream file("C:\\Users\\shivam\\OneDrive\\Desktop\\FileHandling\\Bill.txt");

        if (file.is_open()) {
            file << "Bill number: " << ++billno << endl;
            file << "Date: " << getDate() << endl;
            file << "Time: " << getTime() << endl;
            file << "Customer name: " << u->name << endl;
            file << "________________" << endl;

            int sno = 1;
            int sum = 0;

        if (qty1 != 0) {
            cout << sno++ << " " << food1 << " " << qty1 << " " << price1 << " = " << qty1 * price1 << endl;
            sum += qty1 * price1;
        }
        if (qty2 != 0) {
            cout << sno++ << " " << food2 << " " << qty2 << " " << price2 << " = " << qty2 * price2 << endl;
            sum += qty2 * price2;
        }
        if (qty3 != 0) {
            cout << sno++ << " " << food3 << " " << qty3 << " " << price3 << " = " << qty3 * price3 << endl;
            sum += qty3 * price3;
        }
        if (qty4 != 0) {
            cout << sno++ << " " << food4 << " " << qty4 << " " << price4 << " = " << qty4 * price4 << endl;
            sum += qty4 * price4;
        }
        if (qty5 != 0) {
            cout << sno++ << " " << food5 << " " << qty5 << " " << price5 << " = " << qty5 * price5 << endl;
            sum += qty5 * price5;
        }
        if (qty6 != 0) {
            cout << sno++ << " " << food6 << " " << qty6 << " " << price6 << " = " << qty6 * price6 << endl;
            sum += qty6 * price6;
        }

            file << "Total: " << getSum() << endl;
            file << "Thanks, please visit again" << endl;
            file << "________________" << endl;

            file.close();
        } else {
            throw "Unable to open file for writing.";
        }
    }

    string getDate() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        char date[80];
        strftime(date, 80, "%d %b %Y", localTime);
        return string(date);
    }

    string getTime() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        char time[80];
        strftime(time, 80, "%H:%M:%S", localTime);
        return string(time);
    }

    int getSum() {
        return qty1 * price1 + qty2 * price2+ qty3 * price3 + qty4 * price4 + qty5 * price5 + qty6 * price6;
    }
};

int Taj::billno = 0;

int main() {
    Taj t;
    int choice;

    for (;;) {
        cout << "1. Add user 2. Generate bill 3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                t.addUser();
                break;
            case 2:
                t.makeOrder();
                break;
            case 3:
                cout << "Application stopped" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

