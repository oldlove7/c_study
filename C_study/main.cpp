/* Banking System v 1.0
Written by oldlove7
*/


#include <iostream>
#include <windows.h>

using namespace::std;
const int NAME_LEN=20;

class Account
{
	int id;                //계좌번호
	int balance;           //잔액
	char* name;   //이름
	
	public
		Account(){}
	Account(int id, char* name, int balance)
	{
		this->id=id;


};

Account pArray[100];
int index=0;               //저장된 Account 수

void PrintMenu();          //메뉴출력
void MakeAccount();        //계좌 계설을 위한 함수
void Deposit();				//입금
void Withdraw();			//출금
void Inquire();				//잔액조회

enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void)
{
	int choice;



	while(1)
	{
		PrintMenu();
	    cout<<"선택: ";
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
	cout<<"1. 계좌계설"<<endl;
	cout<<"2. 입금 "<<endl;
	cout<<"3. 출금 "<<endl;
	cout<<"4. 잔액조회"<<endl;
	cout<<"5. 종료  "<<endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout<<"계좌계설-----"<<endl;
	cout<<"계좌 ID:  "; cin>>id;
	cout<<"이름   :  "; cin>>name;
	cout<<"입금액 :  "; cin>>balance;

	pArray[index].id = id;
	pArray[index].balance = balance;
	strcpy(pArray[index].name,name);

	index++;
}

void Deposit()
{
	int money;
	int id;

	cout<<"계좌 ID: "; cin>>id;
	cout<<"입금액:  "; cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i].id ==id)
		{
			pArray[i].balance+=money;
			cout<<"입금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다"<<endl;
}

void Withdraw()
{
	int money;
	int id;

	cout<<"계좌ID:  ";  cin>>id;
	cout<<"출금액:  ";  cin>>money;

	for(int i=0; i<index; i++)
	{
		if(pArray[i].id == id)
		{
			if(pArray[i].balance<money)
			{
				cout<<"잔액부족"<<endl;
				return;
			}
			pArray[i].balance-=money;
			cout<<"출금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID 입니다"<<endl;
}

void Inquire()
{
	for(int i=0; i<index; i++)
	{
		cout<<"계좌ID"<<pArray[i].id<<endl;
		cout<<"이름  "<<pArray[i].name<<endl;
		cout<<"잔액  "<<pArray[i].balance<<endl;
	}
}


