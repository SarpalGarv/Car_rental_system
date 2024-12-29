#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class ManageSystem
{
public:
    void details();
    void addItem();
    void readItem();
    void updateItem();
    void deleteItem();
};

void ManageSystem::details()
{
    system("cls");
    cout << "Press the following keys to go through the details" << endl << endl;
    cout << "1. Add rented car details" << endl;
    cout << "2. Read rented car details" << endl;
    cout << "3. Update rented car details" << endl;
    cout << "4. Delete rented car details" << endl;
    cout << "5. Exit the car rental management system" << endl;
}

void ManageSystem::addItem()
{
    system("cls");

    int sno;
    string pn, pa, cn, cpn, d, csd;
    fstream file;

    cout << "Enter the following details:" << endl;

    cout << "Enter the Serial No (integer): ";
    cin >> sno;
    cin.ignore(); // Clear the input buffer
    cout << "Enter the Person Name: ";
    getline(cin, pn);
    cout << "Enter the Person Address: ";
    getline(cin, pa);
    cout << "Enter the Date (dd-mm-yy): ";
    getline(cin, d);
    cout << "Enter the Car Name: ";
    getline(cin, cn);
    cout << "Enter the Car Plate Number: ";
    getline(cin, cpn);
    cout << "Enter the Car Submission Date (dd-mm-yy): ";
    getline(cin, csd);

    file.open("managesystem.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Error opening file for writing." << endl;
        return;
    }

    file << sno << "|" << pn << "|" << pa << "|" << d << "|" << cn << "|" << cpn << "|" << csd << endl;
    file.close();
    cout << "Item added successfully." << endl;
}

void ManageSystem::readItem()
{
    system("cls");

    fstream file;
    file.open("managesystem.txt", ios::in);
    if (!file)
    {
        cout << "File Opening Error...." << endl;
        return;
    }

    cout << "Review the following details:" << endl << endl;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int sno;
        string pn, pa, cn, cpn, d, csd;

        string snoStr;
        getline(ss, snoStr, '|');
        sno = stoi(snoStr);
        getline(ss, pn, '|');
        getline(ss, pa, '|');
        getline(ss, d, '|');
        getline(ss, cn, '|');
        getline(ss, cpn, '|');
        getline(ss, csd, '|');

        cout << "Serial No = " << sno << endl;
        cout << "Person Name = " << pn << endl;
        cout << "Person Address = " << pa << endl;
        cout << "Date = " << d << endl;
        cout << "Car Name = " << cn << endl;
        cout << "Car Plate Number = " << cpn << endl;
        cout << "Car Submission Date = " << csd << endl << endl;
    }

    file.close();
}

void ManageSystem::updateItem()
{
    system("cls");

    int sno, usno, count = 0;
    string pn, pa, cn, cpn, d, csd;
    fstream file, tempFile;

    tempFile.open("temp.txt", ios::out);
    file.open("managesystem.txt", ios::in);

    if (!file)
    {
        cout << "File Opening Error" << endl;
        return;
    }

    cout << "Update the following details:" << endl;
    cout << "Enter the Serial No to update (integer): ";
    cin >> usno;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int sno;
        string pn, pa, cn, cpn, d, csd;

        string snoStr;
        getline(ss, snoStr, '|');
        sno = stoi(snoStr);
        getline(ss, pn, '|');
        getline(ss, pa, '|');
        getline(ss, d, '|');
        getline(ss, cn, '|');
        getline(ss, cpn, '|');
        getline(ss, csd, '|');

        if (sno == usno)
        {
            cout << "What do you want to update? Choose a number:" << endl;
            cout << "1. Person Name" << endl;
            cout << "2. Person Address" << endl;
            cout << "3. Date (dd-mm-yy)" << endl;
            cout << "4. Car Name" << endl;
            cout << "5. Car Plate Number" << endl;
            cout << "6. Car Submission Date (dd-mm-yy)" << endl;

            int updateChoice;
            cout << "Enter your choice (integer): ";
            cin >> updateChoice;
            cin.ignore(); // Clear the input buffer

            switch (updateChoice)
            {
            case 1:
                cout << "Enter updated Person Name: ";
                getline(cin, pn);
                break;
            case 2:
                cout << "Enter updated Person Address: ";
                getline(cin, pa);
                break;
            case 3:
                cout << "Enter updated Date (dd-mm-yy): ";
                getline(cin, d);
                break;
            case 4:
                cout << "Enter updated Car Name: ";
                getline(cin, cn);
                break;
            case 5:
                cout << "Enter updated Car Plate Number: ";
                getline(cin, cpn);
                break;
            case 6:
                cout << "Enter updated Car Submission Date (dd-mm-yy): ";
                getline(cin, csd);
                break;
            default:
                cout << "Invalid choice. No update made." << endl;
                break;
            }
            count++;
        }

        tempFile << sno << "|" << pn << "|" << pa << "|" << d << "|" << cn << "|" << cpn << "|" << csd << endl;
    }

    if (count == 0)
        cout << "Serial No not found." << endl;

    file.close();
    tempFile.close();

    remove("managesystem.txt");
    rename("temp.txt", "managesystem.txt");
}

void ManageSystem::deleteItem()
{
    system("cls");

    int sno, dsno, count = 0;
    string pn, pa, cn, cpn, d, csd;
    fstream file, tempFile;

    cout << "Delete the following details:" << endl;
    cout << "Enter the Serial No to delete (integer): ";
    cin >> dsno;

    tempFile.open("temp.txt", ios::out);
    file.open("managesystem.txt", ios::in);

    if (!file)
    {
        cout << "File Opening Error" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        int sno;
        string pn, pa, cn, cpn, d, csd;

        string snoStr;
        getline(ss, snoStr, '|');
        sno = stoi(snoStr);
        getline(ss, pn, '|');
        getline(ss, pa, '|');
        getline(ss, d, '|');
        getline(ss, cn, '|');
        getline(ss, cpn, '|');
        getline(ss, csd, '|');

        if (sno == dsno)
        {
            cout << "One item deleted successfully." << endl;
            count++;
        }
        else
        {
            tempFile << sno << "|" << pn << "|" << pa << "|" << d << "|" << cn << "|" << cpn << "|" << csd << endl;
        }
    }

    if (count == 0)
        cout << "Serial No not found." << endl;

    file.close();
    tempFile.close();

    remove("managesystem.txt");
    rename("temp.txt", "managesystem.txt");
}

int main()
{
    ManageSystem ms;
    int choice;
    char x;

    do {
        ms.details();
        cout << "Enter your choice (integer): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do {
                ms.addItem();
                cout << "Do you want to add another item? (y/n): ";
                cin >> x;
            } while (x == 'y');
            break;
        case 2:
            ms.readItem();
            break;
        case 3:
            ms.updateItem();
            break;
        case 4:
            ms.deleteItem();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "\n";
        system("pause");
    } while (true);

    return 0;
}
