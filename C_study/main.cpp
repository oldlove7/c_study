/* Banking System v 3.0
Written by oldlove7

AccManager 라는 이름의 Control 클래스 멤법 함수의 정의
부분 클래스 밖으로 빼냄
*/


#include <iostream>
#include <windows.h>

using namespace::std;
const int NAME_LEN=20;

//************Acount Class************************//
class Account
{
	int id;                //계좌번호
	int balance;           //잔액
	char* name;   //이름
	
public:
	Account(){}    //So Important!!!
	Account(int id, char* name, int balance);

	Account(const Account& acc);

	~Account();

	int GetID() const;           //계좌번호 조회
	int GetBalance() const;      //잔액 조회
	void AddMoney(int val);      //입 금
	void MinMoney(int val);      //출금
	//상수화
	const char* GetName() const; //상수화
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
	cout<<"계좌 ID:  "<<id<<endl;
	cout<<"이   름:  "<<name<<endl;
	cout<<"잔   액:  "<<balance<<endl;
}

///////***********AccManager Class/////////
class AccManager
{
	Account* pArray[100];   //Account 저장을 위한 배열
	int index;              //저장된 Account 수

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
	cout<<"1. 계좌계설"<<endl;
	cout<<"2. 입금 "<<endl;
	cout<<"3. 출금 "<<endl;
	cout<<"4. 잔액조회"<<endl;
	cout<<"5. 종료  "<<endl;
}
//계좌개설
void AccManager::MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout<<"계좌계설-----"<<endl;
	cout<<"계좌 ID:  "; cin>>id;
	cout<<"이름   :  "; cin>>name;
	cout<<"입금액 :  "; cin>>balance;

	pArray[index++] = new Account(id,name,balance);
}
//입금
void AccManager::Deposit()
{
	int money;
	int id;

	cout<<"계좌 ID: "; cin>>id;
	cout<<"입금액:  "; cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i]->GetID()==id)
		{
			pArray[i]->AddMoney(money);
			cout<<"입금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다"<<endl;
}

void AccManager::Withdraw()
{
	int money;
	int id;

	cout<<"계좌ID:  ";  cin>>id;
	cout<<"출금액:  ";  cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i]->GetID()==id)
		{
			if(pArray[i]->GetBalance()<money)
			{
				cout<<"잔액부족"<<endl;
				return;
			}
			pArray[i]->MinMoney(money);
			cout<<"출금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다"<<endl;
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
	    cout<<"선택: ";
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

