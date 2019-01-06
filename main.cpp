#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <conio.h>
#include<string.h>

using namespace std;

int signup();
int login();
int usercheck();
int passchecK();
int users();

int main()
{

		int a;
//mainview
        system("cls");
		cout<<"\n\t\tYou can login if you already sign up once.";
		cout<<"\n\t\t\t0.Exit";
		cout<<"\n\t\t\t1.Sign Up";
		cout<<"\n\t\t\t2.Login";
		cout<<"\n\t\t\t3.Users which sign up (If you don't sign up atleast for once, it will return you)";
		cout<<"\n\t\t\tReply(1/2/3/4): ";
		a=getche();
		switch(a)
		{
            case 0:
                exit(0);
            case 1:
                signup();
            case 2:
                login();
            case 3:
                users();
		}
/*
		if(a==1){//signup
			signup();
		}
		else if(a==2){//login
			login();
		}
		else if(a==3){//total users
			users();
		}
		else if(a==0){
			exit(0);
		}
		else{
			main();
		}
*/
	return 0;
}

//signup
	int signup(){
		system("cls");

		ofstream file1;
		ofstream file2;
		file1.open("username.dat",ios::app);
		file2.open("pass.dat",ios::app);
			int p1=0;
			char ch,suser[20],spass[30];
			cout<<"\n\n\t\t\t Sign UP"<<endl;
			cout<<"\n\t\t\tUsername: ";
			cin>>suser;
			file1<<suser<<endl;
			cout<<"\n\t\t\tPassword: ";
			while(1){
				ch=getch();
				if(ch==13){
					spass[p1]='\0';
					break;
				}
				else if(ch==8){
					if(p1>0){
						p1--;
						cout<<"\b \b";
					}
				}
				else{
					spass[p1++]=ch;
					cout<<"* \b";
				}
			}
		file2<<spass<<endl;
		file1.close();
		file2.close();
		main();
	}

//login
	int login(){
		usercheck();
	}
//passcheck
	int passcheck(){
		ifstream file02;
		file02.open("pass.dat",ios::binary);
		char ch,lpass[20],allpass[100];
		int p2=0;
		cout<<"\n\t\t\tEnter Password: ";
		while(1){
				ch=getch();
				if(ch==13){
					lpass[p2]='\0';
					break;
				}
				else if(ch==8){
					if(p2>0){
						p2--;
						cout<<"\b \b";
					}
				}
				else{
					lpass[p2++]=ch;
					cout<<"* \b";
				}
		}
		while(!file02.eof()){
			file02>>allpass;
			if(strcmp(lpass,allpass)==0){
				for(int c1=1;c1<30;c1++){
					system("cls");
					cout<<"\n\n\t\t\tUser Found, Login Successful.";
				}
			}
		}
		if(!strcmp(lpass,allpass)==0){
			for(int c3=1;c3<30;c3++){
				system("cls");
				cout<<"\n\n\t\t\tPassword is Wrong. Try again.";
			}
		}
		file02.close();
		main();
	}
//usercheck
	int usercheck(){
		ifstream file01;
		file01.open("username.dat",ios::binary);
			system("cls");
			char alluser[100],luser[20];
			cout<<"\n\n\t\t\t Login";
			cout<<"\n\n\t\t\tEnter Username: ";
			cin>>luser;
			while(!file01.eof()){
				file01>>alluser;
				if(strcmp(luser,alluser)==0){
					passcheck();
				}
			}
			if(!strcmp(luser,alluser)==0){
				for(int c2=1;c2<30;c2++){
					system("cls");
					cout<<"\n\n\t\t\tUsername not Found. Sign up First.";
				}
				main();
			}
		file01.close();
	}
//users
	int users(){
		system("cls");
		fstream file003;
		file003.open("username.dat",ios::in);
			int d=1;
			char userread[200];
			cout<<"\n\t\t\tUsernames which already signed up."<<endl;
			while(!file003.eof()){
					if(file003=='\0'){
						main();
					}
					file003>>userread;
					cout<<userread<<endl;
			}
		file003.close();
		cout<<endl;
		for(int d=1;d<11000;d++){ //delay for a moment
			cout<<"-----\b\b\b\b\b";
		}
		main();
	}

