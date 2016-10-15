/* Banking System v 1.0
Written by oldlove7
*/


#include <iostream>
#include <windows.h>

using namespace::std;
const int NAME_LEN=20;

class Account
{
	int id;                //���¹�ȣ
	int balance;           //�ܾ�
	char* name;   //�̸�
	
public:
	Account(){}    //So Important!!!
	Account(int id, char* name, int balance)
	{
		this->id=id;
		this->balance=balance;
		this->name=new char[strlen(name)+1];
	}
	~Account(){
		delete []name;
	}

	int GetID(){return id;}
	int GetBalance(){return balance;}
	void AddMoney(int val){
		balance+=val;
	}
	void MinMoney(int val){
		balance -=val;
	}
	char* GetName(){
		return name;
	}
	void ShowAllData(){
		cout<<"���� ID:  "<<id<<endl;
		cout<<"��   ��:  "<<name<<endl;
		//printf("name : %s \n",name);
		cout<<"��   ��:  "<<balance<<endl;
	}
};

Account* pArray[100];
int index=0;               //����� Account ��

void PrintMenu();          //�޴����
void MakeAccount();        //���� �輳�� ���� �Լ�
void Deposit();				//�Ա�
void Withdraw();			//���
void Inquire();				//�ܾ���ȸ

enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void)
{
	int choice;



	while(1)
	{
		PrintMenu();
	    cout<<"����: ";
	    cin>>choice;
		switch(choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case INQUIRE:
			Inquire();
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

void PrintMenu()
{
	cout<<"---menu-----"<<endl;
	cout<<"1. ���°輳"<<endl;
	cout<<"2. �Ա� "<<endl;
	cout<<"3. ��� "<<endl;
	cout<<"4. �ܾ���ȸ"<<endl;
	cout<<"5. ����  "<<endl;
}
//���°���
void MakeAccount()
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
void Deposit()
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

void Withdraw()
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

void Inquire()
{
	for(int i=0; i<index; i++)
	{
		pArray[i]->ShowAllData();
	}
}


