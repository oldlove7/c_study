/* Banking System v 3.0
Written by oldlove7

AccManager ��� �̸��� Control Ŭ���� ��� �Լ��� ����
�κ� Ŭ���� ������ ����
*/


#include <iostream>
#include <windows.h>

using namespace::std;
const int NAME_LEN=20;

//************Acount Class************************//
class Account
{
	int id;                //���¹�ȣ
	int balance;           //�ܾ�
	char* name;   //�̸�
	
public:
	Account(){}    //So Important!!!
	Account(int id, char* name, int balance);

	Account(const Account& acc);

	~Account();

	int GetID() const;           //���¹�ȣ ��ȸ
	int GetBalance() const;      //�ܾ� ��ȸ
	void AddMoney(int val);      //�� ��
	void MinMoney(int val);      //���
	//���ȭ
	const char* GetName() const; //���ȭ
	void ShowAllData();
};

Account::Account(int id, char* name, int balance)
{
	this->id=id;
	this->balance=balance;
	this->name=new char[strlen(name)+1];
	strcpy(this->name,name);
}

Account::Account(const Account& acc)
{
	this->id = acc.id;
    this->balance = acc.balance;
	this->name = new char[strlen(acc.name)+1];
	strcpy(this->name, name);
}

Account::~Account()
{
	delete []name;
}

int Account::GetID() const{
	return id;
}

int Account::GetBalance() const {
	return balance;
}

void Account::AddMoney(int val)
{
	balance += val;
}

void Account::MinMoney(int val)
{
	balance -= val;
}

const char* Account::GetName() const
{
	return name;
}

void Account::ShowAllData()
{
	void ShowAllData();
	cout<<"���� ID:  "<<id<<endl;
	cout<<"��   ��:  "<<name<<endl;
	cout<<"��   ��:  "<<balance<<endl;
}

///////***********AccManager Class/////////
class AccManager
{
	Account* pArray[100];   //Account ������ ���� �迭
	int index;              //����� Account ��

public:
	AccManager();
	void PrintMenu();
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void Inquire();
};

AccManager::AccManager()
{
	index=0;   
}

void AccManager::PrintMenu()
{
	cout<<"---menu-----"<<endl;
	cout<<"1. ���°輳"<<endl;
	cout<<"2. �Ա� "<<endl;
	cout<<"3. ��� "<<endl;
	cout<<"4. �ܾ���ȸ"<<endl;
	cout<<"5. ����  "<<endl;
}
//���°���
void AccManager::MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout<<"���°輳-----"<<endl;
	cout<<"���� ID:  "; cin>>id;
	cout<<"�̸�   :  "; cin>>name;
	cout<<"�Աݾ� :  "; cin>>balance;

	pArray[index++] = new Account(id,name,balance);
}
//�Ա�
void AccManager::Deposit()
{
	int money;
	int id;

	cout<<"���� ID: "; cin>>id;
	cout<<"�Աݾ�:  "; cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i]->GetID()==id)
		{
			pArray[i]->AddMoney(money);
			cout<<"�ԱݿϷ�"<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�"<<endl;
}

void AccManager::Withdraw()
{
	int money;
	int id;

	cout<<"����ID:  ";  cin>>id;
	cout<<"��ݾ�:  ";  cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i]->GetID()==id)
		{
			if(pArray[i]->GetBalance()<money)
			{
				cout<<"�ܾ׺���"<<endl;
				return;
			}
			pArray[i]->MinMoney(money);
			cout<<"��ݿϷ�"<<endl;
			return;
		}
	}
	cout<<"��ȿ���� ���� ID �Դϴ�"<<endl;
}

void AccManager::Inquire()
{
	for(int i=0; i<index; i++)
	{
		pArray[i]->ShowAllData();
	}
}



enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int main(void)
{
	int choice;
	AccManager manager;

	while(1)
	{
		manager.PrintMenu();
	    cout<<"����: ";
	    cin>>choice;
		switch(choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.Deposit();
			break;
		case WITHDRAW:
			manager.Withdraw();
			break;
		case INQUIRE:
			manager.Inquire();
			break;
		case EXIT:
			return 0;
		default:
			cout<<"Illegal select.."<<endl;
			break;
		}
	}
	return 0;
}

