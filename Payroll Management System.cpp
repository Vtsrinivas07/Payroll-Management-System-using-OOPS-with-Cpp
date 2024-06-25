#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Employee_management
{
private:
    string name;
    string id;
    string designation;
    int age;
    int experience;
    long long basic_salary, hra, da, i_tax, net_salary;
    long long pf;
    char medicalAllowance;
    char transportAllowance;

public:
    void menu()
    {
        int choice;
        char x;
        int dep;

        cout << "\n-------------------------------" << endl;
        cout << "\n>> PAYROLL MANAGEMENT SYSTEM <<" << endl;
        cout << "\n-------------------------------" << endl;
        cout << "\n 1. Enter New Employee's Record" << endl;
        cout << "\n 2. Modify an Employee Record" << endl;
        cout << "\n 3. Delete an Employee Record" << endl;
        cout << "\n 4. Salary Record of an Employee" << endl;
        cout << "\n 5. Display an Employee's Record" << endl;
        cout << "\n 6. Display Records of all the Employees" << endl;
        cout << "\n 7. Exit" << endl;
        cout << "\n.................................." << endl;
        cout << "\n>> Choice Options: [1/2/3/4/5/6/7] <<" << endl;
        cout << "\n.................................." << endl;
        cout << "\n ENTER YOUR CHOICE: ";
        cin >> dep;
        switch (dep)
        {
        case 1:
            while (1)
            {
                insert();
                cout << "\nAdd Another Employee Record Press (Y or N) : ";
                cin >> x;
                if (x == 'y' || x == 'Y')
                {
                    continue;
                }
                else if (x == 'n' || x == 'N')
                {
                    break;
                }
                else
                {
                    cout << "Enter Valid Input...\n";
                }
            }
            system("cls");
            menu();
            break;

        case 2:
            do
            {
                modify();
                cout << "\nModify Another Employe Record Press (Y or N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            menu();
            break;

        case 3:
            do
            {
                deleted();
                cout << "\nDelete Another Employe Record Press (Y or N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            menu();
            break;

        case 4:
            do
            {
                income();
                cout << "\nView Another Employe Salary Record Press (Y or N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            menu();
            break;

        case 5:
            do
            {
                display();
                cout << "\nView Another Employe Data? (Y or N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            menu();
            break;

        case 6:
            do
            {
                list();
                cout << "\nWant to go to main menu? (Y) : ";
                cin >> x;
            } while (x == 'n' || x == 'N');
            system("cls");
            menu();
            break;

        case 7:
            exit(0);
            break;
        default:
            cout << "\n Invalid Choice... Please Try Again...\n";
        }
    }

    void insert()
    {
        system("cls");
        fstream file;
        cout << "\n------------------------------------- INSERT EMPLOYEE DATA -------------------------------------------" << endl;
        cout << "\n Enter Name of Employee: ";
        cin.ignore();
        getline(cin, name);
        cout << "\n Enter Employee ID : ";
        cin >> id;
        cout << "\n Enter Designation: ";
        getchar();
        getline(cin, designation);
        cout << "\n Enter Employee Age: ";
        cin >> age;
        cout << "\n Enter Employee Annual Package: ";
        cin >> basic_salary;
        cout << "\n Enter Employee Experience: ";
        cin >> experience;
        cout << "\n Enter Medical Allowance (Y/N): ";
        while (1)
        {
            cin >> medicalAllowance;
            if (medicalAllowance == 'y' || medicalAllowance == 'Y')
            {
                cout << "Medical Allowance Acquired.\n";
                break;
            }
            else if (medicalAllowance == 'n' || medicalAllowance == 'N')
            {
                cout << "Medical Allowance not Acquired.\n";
                break;
            }
            else
            {
                cout << "Please enter valid Input.\n";
            }
        }
        cout << "\n Enter Transport Allowance (Y/N): ";
        while (1)
        {
            cin >> transportAllowance;
            if (transportAllowance == 'y' || transportAllowance == 'Y')
            {
                cout << "Transport Allowance Acquired.\n";
                break;
            }
            else if (transportAllowance == 'n' || transportAllowance == 'N')
            {
                cout << "Transport Allowance not Acquired.\n";
                break;
            }
            else
            {
                cout << "Please enter valid Input.\n";
            }
        }
        cout << "\n Successfully Entered Details Of Employee";
        file.open("Employee_Record.txt", ios::app | ios::out);
        file << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << " " << medicalAllowance << " " << transportAllowance << "\n";
        file.close();
    }

    void modify()
{
    system("cls");
    string checkId;
    int found = 0;
    fstream file, tempFile;
    
    cout << "\n------------------------------------- MODIFY EMPLOYEE DATA ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    tempFile.open("temp.txt", ios::out | ios::app);

    if (!file || !tempFile)
    {
        cout << "\nError in opening file!";
        return;
    }

    cout << "\nEnter employee id to modify: ";
    cin >> checkId;

    while (file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance)
    {
        if (checkId == id)
        {
            cout << "\n Enter Name of Employee: ";
            cin.ignore();
            getline(cin, name);
            cout << "\n Enter Employee ID : ";
            cin >> id;
            cout << "\n Enter Designation: ";
            cin.ignore();
            getline(cin, designation);
            cout << "\n Enter Employee Age: ";
            cin >> age;
            cout << "\n Enter Employee Annual Package: ";
            cin >> basic_salary;
            cout << "\n Enter Employee Experience: ";
            cin >> experience;
            cout << "\n Enter Medical Allowance (Y/N): ";
            while (1)
            {
                cin >> medicalAllowance;
                if (medicalAllowance == 'y' || medicalAllowance == 'Y')
                {
                    cout << "Medical Allowance Acquired.\n";
                    break;
                }
                else if (medicalAllowance == 'n' || medicalAllowance == 'N')
                {
                    cout << "Medical Allowance not Acquired.\n";
                    break;
                }
                else
                {
                    cout << "Please enter valid Input.\n";
                }
            }
            cout << "\n Enter Transport Allowance (Y/N): ";
            while (1)
            {
                cin >> transportAllowance;
                if (transportAllowance == 'y' || transportAllowance == 'Y')
                {
                    cout << "Transport Allowance Acquired.\n";
                    break;
                }
                else if (transportAllowance == 'n' || transportAllowance == 'N')
                {
                    cout << "Transport Allowance not Acquired.\n";
                    break;
                }
                else
                {
                    cout << "Please enter valid Input.\n";
                }
            }
            tempFile << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << " " << medicalAllowance << " " << transportAllowance << "\n";
            found++;
        }
        else
        {
            tempFile << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << " " << medicalAllowance << " " << transportAllowance << "\n";
        }
    }

    file.close();
    tempFile.close();

    remove("Employee_Record.txt");
    rename("temp.txt", "Employee_Record.txt");

    if (found == 0)
    {
        cout << "\nEmployee ID Not Found.. Please Try Again";
    }
}


    void deleted()
    {
        system("cls");
        string checkId;
        fstream file, file1;
        int found = 0;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n------------------------------------- DELETE EMPLOYEE DATA ------------------------------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\nNo Data is Present..";
        }
        else
        {
            cout << "\nEnter employee id to remove data: ";
            cin >> checkId;
            file1.open("record.txt", ios::app | ios::out);
            file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            while (!file.eof())
            {
                if (checkId != id)
                {
                    file1 << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << " " << medicalAllowance << " " << transportAllowance << "\n";
                }
                else
                {
                    found++;
                    cout << "\nSuccessfully Deleted Data of Employee with ID: " << checkId;
                }
                file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            }
            if (found == 0)
            {
                cout << "\nEmployee ID Not Found.. Please Try Again";
            }
            file1.close();
            file.close();
            remove("Employee_Record.txt");
            rename("record.txt", "Employee_Record.txt");
        }
    }

    void income()
    {
        system("cls");
        fstream file;
        string checkId;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n------------------------------------- SALARY DETAILS OF EMPLOYEE -------------------------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\nNo Data is Present..";
        }
        else
        {
            cout << "\nEnter employee id: ";
            cin >> checkId;
            file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            while (!file.eof())
            {
                if (checkId == id)
                {
                    hra = 0.10 * basic_salary;  // House Rent Allowance
                    da = 0.05 * basic_salary;   // Dearness Allowance
                    pf = 0.12 * basic_salary;   // Provident Fund
                    i_tax = 0.07 * basic_salary; // Income Tax
                    net_salary = basic_salary + hra + da - pf - i_tax; // Net Salary calculation
                    cout << "\nEmployee ID: " << id << endl;
                    cout << "\nEmployee Name: " << name << endl;
                    cout << "\nEmployee Age: " << age << endl;
                    cout << "\nEmployee Annual Package: " << basic_salary << endl;
                    cout << "\nEmployee Net Salary: " << net_salary << endl;
                }
                file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            }
        }
        file.close();
    }

    void display()
    {
        system("cls");
        fstream file;
        string checkId;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n------------------------------------- DISPLAY EMPLOYEE DATA ------------------------------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\nNo Data is Present..";
        }
        else
        {
            cout << "\nEnter employee id: ";
            cin >> checkId;
            file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            while (!file.eof())
            {
                if (checkId == id)
                {
                    cout << "\nEmployee ID: " << id << endl;
                    cout << "\nEmployee Name: " << name << endl;
                    cout << "\nEmployee Designation: " << designation << endl;
                    cout << "\nEmployee Age: " << age << endl;
                    cout << "\nEmployee Annual Package: " << basic_salary << endl;
                    cout << "\nEmployee Experience: " << experience << endl;
                    cout << "\nMedical Allowance: " << medicalAllowance << endl;
                    cout << "\nTransport Allowance: " << transportAllowance << endl;
                }
                file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            }
        }
        file.close();
    }

    void list()
    {
        system("cls");
        fstream file;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n------------------------------------- EMPLOYEE DATA LIST ---------------------------------------------" << endl;
        file.open("Employee_Record.txt", ios::in);
        if (!file)
        {
            cout << "\nNo Data is Present..";
        }
        else
        {
            file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            while (!file.eof())
            {
                cout << "\nEmployee ID: " << id << endl;
                cout << "\nEmployee Name: " << name << endl;
                cout << "\nEmployee Designation: " << designation << endl;
                cout << "\nEmployee Age: " << age << endl;
                cout << "\nEmployee Annual Package: " << basic_salary << endl;
                cout << "\nEmployee Experience: " << experience << endl;
                cout << "\nMedical Allowance: " << medicalAllowance << endl;
                cout << "\nTransport Allowance: " << transportAllowance << endl;
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                file >> name >> id >> designation >> age >> basic_salary >> experience >> medicalAllowance >> transportAllowance;
            }
        }
        file.close();
    }
};

int main()
{
    Employee_management system;
    string username;
    string pw;
    cout << "\n###############################################";
    cout << "\n ----------------------------------------------";
    cout << "\n||   WELCOME TO PAYROLL MANAGEMENT SYSTEM    ||";
    cout << "\n ----------------------------------------------";
    cout << "\n###############################################";
    do
    {
        cout << "\nENTER USERNAME: ";
        cin >> username;
        cout << "\nENTER PASSWORD: ";
        cin >> pw;
        if ((username == "pms") && (pw == "123"))
        {
            cout << "\n----------SUCCESSFULLY LOGGED IN-------------" << endl;
            system.menu();
        }
        else
        {
            cout << "\n############## INVALID CREDENTIALS #############" << endl;
            cout << "\nPLEASE ENTER CORRECT DETAILS--: " << endl;
        }
    } while (username != "pms" || pw != "123");

    return 0;
}
