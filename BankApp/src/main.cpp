#include <iostream>
#include <fstream>
using namespace std;
int accountNumber = 0;

class account
{
private:
    int accountNumber;
    string pasword;
    string userName;
    double accountBalance;

public:
    account(int accountNumber, string userName, string pasword)
    {
        this->accountNumber = accountNumber;
        this->userName = userName;
        this->pasword = pasword;
        accountBalance = 0.0;
    }

    friend account *addAccount();
    void add_to_File();
    friend void showAccount();
    friend void updateAccount();
    friend void deleteAccount();
    friend void depositMoney();
    friend void withdrawMoney();
    friend void add_to_CheckUpFile();
    friend void sendMoney();

    friend void getMoney(string, int);
};

void add_to_CheckUpFile(string ChechUpFile)
{
    string line;
    ofstream accountsCheckupOut(ChechUpFile);
    ifstream accoutsIn("accounts.txt");
    while (getline(accoutsIn, line))
    {
        accountsCheckupOut << line << endl;
    }
    accountsCheckupOut << line << endl;
    accountsCheckupOut.close();
    accoutsIn.close();
}

void getMoney(string fieldAccount, int money)
{
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == fieldAccount)
        {
            accountsOut << line << endl;
            for (int i = 0; i < 2; i++)
            {
                getline(accountsIn, line);
                accountsOut << line << endl;
            }
            getline(accountsIn, line);
            double moneyBeyond = stod(line);
            moneyBeyond += money;

            accountsOut << moneyBeyond << endl;

            cout << "Para alindi.";

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
}

void sendMoney(string sendingAccount, string fieldAccount, int money)
{
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == sendingAccount)
        {
            accountsOut << line << endl;
            for (int i = 0; i < 2; i++)
            {
                getline(accountsIn, line);
                accountsOut << line << endl;
            }
            getline(accountsIn, line);
            double moneyBeyond = stod(line);
            moneyBeyond -= money;

            accountsOut << moneyBeyond << endl;

            cout << "Para gonderildi.";

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
    getMoney(fieldAccount, money);
}

void account::add_to_File()
{

    ofstream accountsOut;

    accountsOut.open("accounts.txt", ios::app);
    accountsOut << this->userName << endl;
    accountsOut << this->pasword << endl;
    accountsOut << this->accountNumber << endl;
    accountsOut << this->accountBalance << endl
                << endl
                << endl;
    cout << accountsOut.tellp();
    add_to_CheckUpFile("checkup.txt");
    accountsOut.close();
}
account *addAccount(string accountName, string accountPasword)
{

    int bankccountNumber = ++accountNumber;

    account *h = new account(bankccountNumber, accountName, accountPasword);

    return h;

    add_to_CheckUpFile("checkup.txt");
}

void showAccount(string userName, string password)
{
    ifstream accountsIn("accounts.txt");
    string line;
    while (getline(accountsIn, line))
    {
        if (line == userName)
        {
            cout << "account adi: " << line;
            getline(accountsIn, line);
            if (line == password)
            {
                cout << "account sifresi: " << line;
                getline(accountsIn, line);
                cout << "account no: " << line;
                getline(accountsIn, line);
                cout << "account bakiyesi: " << line;
            }
            else
            {
                cout << "Yanlis sifre.";
                break;
            }

            break;
        }
    }
    accountsIn.close();
}

void showAllAccounts()
{
    ifstream accountsIn("account2s.txt");
    string line;
    while (getline(accountsIn, line))
    {
        if (!line.empty())
        {
            cout << "account adi: " << line << endl;
            getline(accountsIn, line);
            cout << "account sifresi: " << line << endl;
            getline(accountsIn, line);
            cout << "account no: " << line << endl;
            getline(accountsIn, line);
            cout << "account bakiyesi: " << line << endl;
        }
    }
    accountsIn.close();
}

void updateAccount(string userName)
{
    string newPassword;
    string newUsername;
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == userName)
        {
            cout << "Lutfen yeni ismi giriniz:" << endl;
            cin >> newUsername;
            accountsOut << newUsername << endl;
            getline(accountsIn, line);
            cout << "Lutfen yeni sifreyi giriniz:" << endl;
            cin >> newPassword;
            accountsOut << newPassword << endl;

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
}

void deleteAccount(string userName)
{
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == userName)
        {
            for (int i = 0; i < 3; i++)
                getline(accountsIn, line);

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
}

void depositMoney(string userName, double money)
{
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == userName)
        {
            accountsOut << line << endl;
            for (int i = 0; i < 2; i++)
            {
                getline(accountsIn, line);
                accountsOut << line << endl;
            }
            getline(accountsIn, line);
            double moneyBeyond = stod(line);
            money += moneyBeyond;

            accountsOut << money << endl;

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
}

void withdrawMoney(string userName, double money)
{
    string line;
    ifstream accountsIn("checkup.txt");
    ofstream accountsOut("accounts.txt");

    while (getline(accountsIn, line))
    {
        if (line == userName)
        {
            accountsOut << line << endl;
            for (int i = 0; i < 2; i++)
            {
                getline(accountsIn, line);
                accountsOut << line << endl;
            }
            getline(accountsIn, line);
            double moneyBeyond = stod(line);
            moneyBeyond -= money;

            accountsOut << money << endl;

            continue;
        }
        accountsOut << line << endl;
    }
    add_to_CheckUpFile("checkup.txt");
    accountsIn.close();
    accountsOut.close();
}

int main()
{
    cout << endl
         << endl
         << "Banka islemlerine hosgeldiniz..." << endl;
    cout << "Yapmak istediginiz islemi giriniz..." << endl;
    cout << "1-account olustur" << endl;
    cout << "2-account goruntuleme" << endl;
    cout << "3-account guncelleme" << endl;
    cout << "4-account silme" << endl;
    cout << "5-Para yatirma icin" << endl;
    cout << "6-Para cekme" << endl;
    cout << "7-Tum listeyi goster" << endl;
    cout << "8-Cikis icin" << endl;
    cout << "9-Para gonderme icin"<<endl;
    char choice;
    cin >> choice;

    double money;
    string userName;
    string password;
    string sendingAccount;
    string fieldAccount;
    if (choice == '1')
    {
        cout << "Hesap ekleme islemine hosgeldiniz..." << endl;
        cout << "Lutfen kullanici adinizi giriniz..." << endl;
        cin >> userName;
        cout << "Lutfen sifrenizi giriniz..." << endl;
        cin >> password;
        account *newAccount = addAccount(userName, password);
        newAccount->add_to_File();
    }
    else if (choice == '2')
    {
        cout << "Hesap gorutuleme islemlerine hosgeldiniz..." << endl;

        cout << "Hesabinizin kullanici adini giriniz..." << endl;
        cin >> userName;

        cout << "Hesabinizin sifresini giriniz..." << endl;
        cin >> password;

        showAccount(userName, password);
    }
    else if (choice == '3')
    {
        cout << "Hesap guncelleme islemlerine hosgeldiniz..." << endl;

        cout << "Hesabinizin kullanici adini giriniz..." << endl;
        cin >> userName;

        updateAccount(userName);
    }

    else if (choice == '4')
    {
        cout << "Hesap silme islemine hosgeldiniz.";
        cout << "Lutfen silinecek kullanici adini giriniz..." << endl;
        cin >> userName;
        deleteAccount(userName);
    }

    else if (choice == '5')
    {
        cout << "Lutfen para yatirilacak ismi giriniz:" << endl;
        cin >> userName;
        cout << "Lutfen yatirilacak parayi giriniz:" << endl;
        cin >> money;
        depositMoney(userName, money);
    }

    else if (choice == '6')
    {
        cout << "Lutfen para ceklicek ismi giriniz:" << endl;
        cin >> userName;
        cout << "Lutfen cekilecek parayi giriniz:" << endl;
        cin >> money;
        withdrawMoney(userName, money);
    }

    else if (choice == '7')
    {
        showAllAccounts();
    }

    else if (choice == '8')
    {
        cout << "Hoscakalin." << endl;
        return 0;
    }
    else if (choice == '9')
    {
        cout<<"Para yatiracak ismi giriniz."<<endl;
        cin>>sendingAccount;
        cout<<"Para yatirilacak ismi giriniz."<<endl;
        cin>>fieldAccount;
        cout<<"Yatirilacak tutari giriniz."<<endl;
        cin>>money;

        sendMoney(sendingAccount, fieldAccount,money);
    }

    else
    {
        cout
            << "hatali islem..." << endl;
    }

    return 0;
}