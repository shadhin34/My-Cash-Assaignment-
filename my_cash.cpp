#include<bits/stdc++.h>
#include<windows.h>
#define loading for(int i=0;i<4;i++){cout<<".";Sleep(400);}
#define gdby string str="Goodbye!";for(int i=0;i<str.size();i++){cout<<str[i];Sleep(300);} 

using namespace std;
string transaction()
{
    string trans_id="";
    srand(time(0));
    for(int i=0;i<8;i++)
    {
        int digit=rand()%9+1;
        trans_id+=to_string(digit);
    }
    return trans_id;
}
class Member{
    public:
int number;
int pin;
string name;
int amount;
Member(int number,int pin,string name)
{
this->number=number;
this->pin=pin;
this->name=name;
amount=0;
}
};
class history{
public:
vector<string>str;
};
class mycash
{
vector<Member>member;
vector<history>h;
public:
void Login()
{
    if(member.size()<=0)
    {
        cout<<"no member exist !\n";
        return;
    }
    int p,num;
    cout<<"enter the number of your account : ";
    cin>>num;
    // cin.ignore();
    cout<<"enter pin (5-digit): ";
    cin>>p;
    cin.ignore();
    int n=member.size();
    bool found=false;
    int idxx;
    for(int i=0;i<n;i++)
    {
        if(member[i].number==num && member[i].pin==p)
        {
             found=true;
             idxx=i;
             break;
        } 
    }
    if(found)
    {
        cout<<"\tmember found successfull !!!\n";
            Sleep(1000);
             mycash_menu(idxx);
    }
    else
    {
        cout<<"member doesn't exist \n\n";
    }
}
void Register()
{
    system("cls");
    long long p,num;
    string name;
    string numb;
    start:
    cout<<"Enter mobile no(11-digit) : ";
    cin>>num;
    numb=to_string(num);
    if(numb.size()<10)
    {
        cout<<" number not valid\n";
        goto start;
    }
     for(int i=0;i<member.size();i++)
    {
        if(member[i].number==num)
        {
            cout<<"member already exist\n";
            return;
        }
    }  
    cin.ignore();
    cout<<"enter name : ";
    getline(cin,name);
    again:
    cout<<"enter your pin(5-digit) : ";
    cin>>p;
      if(p<5)
    {
        cout<<"pin is too short try again!!\n";
        goto again;
    }
    cout<<"reconfirm your pin : ";
    int P;
    cin>>P;
      if(P<5)
    {
        cout<<"pin is too short try again!!\n";
        goto again;
    }
    if(P!=p)
    {
        cout<<"pin not matched !!\n";
        goto again;
    }
    srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";
cin>>otp_put;
if(otp==otp_put)
{
Member m(num,p,name);
    member.push_back(m);
    cout<<"member created successfully\n\n";
    history h1;
    h1.str.push_back("Tran ID  Description  Amount  Balance \n");
    h.push_back(h1);
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}
    
    cin.ignore();
cout << "Press any key to continue...";
    cin.get();
}
void update(int idx);
void remove_me(int idx);
void cash_in(int idx);
void send_money(int idx);
void cash_out(int idx);
void check_balance(int idx);
void pay_bill(int idx);
void history_check(int idx);
void change_name(int idx);
void change_pin(int idx);
void mycash_menu(int idx)
{
system("cls");
bool exit=false;
while(!exit)
{
    system("cls");
cout<<"********** MyCash Menu ******** \n";
cout<<"\n1. update me \n2. remove me \n3. send money\n4. cash-in\n5. cash-out\n";
cout<<"6. pay bill \n";
cout<<"7. check balance \n";
cout<<"8. history \n";
cout<<"9. log-out\n";
cout<<"enter your opinion (1-9) : ";
int chose;
cin>>chose;
switch(chose)
{
     case 1 : update(idx);
            break;
    case 2:remove_me(idx);
    return;
    break;
    case 3: send_money( idx);
        break;
    case 4: cash_in(idx); 
    break;
    case 5: cash_out(idx); 
    break;
    case 6: pay_bill(idx);
    break;
    case 7: check_balance(idx);
    break;
    case 8: history_check(idx);
    break;
    case 9: gdby cout<<endl;
    cin.ignore();
cout << "Press any key to back login...";
    cin.get();
    exit=true;
    break;
}
}

}

};

int main()
{
system("cls");

mycash m1;
cout<<"\t*** MY Cash Login ***\n";
bool outer_exit=false;
while(!outer_exit)
{
cout<<"\t 1. Login \n \t 2. Register\n\t 3. Exit \n";
cout<<"\t\t Enter your opinion : ";
int opinion;
cin>>opinion;
switch(opinion)
{   
    case 1: m1.Login();
    break;
    case 2: m1.Register();
            break;
    case 3 :  gdby cout<<endl;
    cin.ignore();
cout << "Press any key to continue...";
    cin.get();
    outer_exit=true;
        break;
}
}

    return 0;
}

void mycash::update(int idx)
{
    system("cls");
bool exit=false;
while(!exit)
{
    cout<<"1. change name\n";
    cout<<"2. change pin\n";
    cout<<"3. exit\n";
    cout<<"enter your chose : ";
    int chose;
    cin>>chose;
    switch(chose)
    {
        case 1: change_name(idx);
        break;
   case 2: change_pin(idx);
   break;
case 3: exit=true;
cin.ignore();
cout << "Press any key to continue...";
    cin.get();
    break;
    }
}

}

void mycash::remove_me(int idx)
{
    srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";
cin>>otp_put;
if(otp==otp_put)
{
vector<Member>member2=member;
    int n=member2.size();
    member.clear();
    for(int i=0;i<n;i++)
    {
        if(idx==i)continue;
        member.push_back(member2[i]);
    }
     cout<<"removing your account.";
    loading cout<<endl;
    cout<<"\tDeleted\n";
    cin.ignore();
cout << "Press any key to log-out...";
    cin.get();
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}

}
void mycash::cash_in(int idx)
{
    int money;
cout<<"how much money you wanna add : ";
cin>>money;

member[idx].amount+=money;
cout<<"processing.";
loading cout<<endl;

cout<<money<<" $ added successfully!\n\n";

cout<<"current balance = "<<member[idx].amount<<" $ "<<endl<<endl;


string tran=transaction();
string TK=to_string(money);
string am=to_string(member[idx].amount);
h[idx].str.push_back(tran+" cash-in      "+TK + "     "+am+"\n");
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}
void mycash::send_money(int idx)
{
    cout<<" account number : "<<member[idx].number<<endl;
    cout<<" current balance = "<<member[idx].amount<<endl;
    int send_amount,acc_no;
    cout<<"enter reciver account number :";
    cin>>acc_no;
    int n=member.size();
    bool found=false;
    int acc_idx;
    for(int i=0;i<n;i++)
    {
        if(member[i].number==acc_no)
        {
            found=true;
            acc_idx=i;
            break;
        }
    }
    if(found)
    {
        cout<<"reciver account found !!\n";
        cout<<"reciver account name : "<<member[acc_idx].name<<endl;
        cout<<"reciver account number :"<<member[acc_idx].number<<endl;
        cout<<"\n how much do you want to send : ";
        cin>>send_amount;
        if(send_amount>member[idx].amount)
        {
            cout<<"\tinsufficiend balance !!\n";
        }
        else
        {
             srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";
cin>>otp_put;
if(otp==otp_put)
{
member[acc_idx].amount+=send_amount;
            member[idx].amount-=send_amount;
            cout<<"sending money.";
            loading cout<<endl;
             cout<<"your current balance = "<<member[idx].amount<<endl;
              cout<<member[acc_idx].name<<"balance transfered= "<<send_amount<<endl;

            string tran=transaction();
            string TK=to_string(send_amount);
           string am=to_string(member[idx].amount);
          h[idx].str.push_back(tran+" send_money   "+TK + "     "+am+"\n");
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}
}
}
else
    {
        cout<<"\tsorry account not found !!\n";
    }
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}
void mycash::cash_out(int idx)
{
    cout<<"Your account number : "<<member[idx].number<<endl;
    cout<<"your current balance = "<<member[idx].amount<<endl;
    int cash_out;
    cout<<"how much you wanna cash out : ";
    cin>>cash_out;
    if(cash_out>member[idx].amount)
    {
        cout<<"\tinsufficient balance !!\n";
    }
    else
    {
 srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";
cin>>otp_put;
if(otp==otp_put)
{
 cout<<"processing.";
loading cout<<endl;
member[idx].amount-=cash_out;
cout<<"\tcash out successfull\n";
string tran=transaction();
string TK=to_string(cash_out);
string am=to_string(member[idx].amount);
h[idx].str.push_back(tran+" cash-out     "+TK + "      "+am+"\n");
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}
       
    }
    cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}
void mycash::check_balance(int idx)
{
    cout<<" account name : "<<member[idx].name<<endl;
    cout<<" account number : "<<member[idx].number<<endl;
    cout<<" current balance = "<<member[idx].amount<<endl;
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}
void mycash::pay_bill(int idx)
{
    cout<<"\t**Bill payment system**\n";
    cout<<"1. netflix\n";
    cout<<"2. travel\n";
    cout<<"3. food\n";
    cout<<"4. entertainment\n";
    cout<<"5. internet-Bill\n";
    int chose;
    cout<<"where do you want payment ? = ";
    cin>>chose;
    int tk;
    cout<<"how much you want to pay :";
    cin>>tk;
    
if(tk>member[idx].amount)
    {
        cout<<"\tinsufficient balance !!\n";
    }
    else
    {
        
 srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";
cin>>otp_put;
if(otp==otp_put)
{
member[idx].amount-=tk;
cout<<"processing.";
loading cout<<endl;
cout<<"payment successfully\n";
string Tran=transaction();
string TK=to_string(tk);
string am=to_string(member[idx].amount);
h[idx].str.push_back(Tran+" payment      "+TK + "      "+am+"\n");
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}

    }
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}

void mycash::history_check(int idx)
{
    int n=h[idx].str.size();
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<h[idx].str[i]<<endl;
    }
    cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}

void mycash::change_name(int idx)
{
    cout<<"your current name : "<<member[idx].name<<endl;
    string newname;
    cin.ignore();
   cout<<"enter new name : ";
   getline(cin,newname);
    srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";      
cin>>otp_put;
if(otp==otp_put)
{
    member[idx].name=newname;
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}

cout<<"\t\nupdate complete !!\n\n";
cout<<"new name : "<< member[idx].name<<endl;
cout<<"pin     : "<<member[idx].pin<<endl;
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}
void mycash::change_pin(int idx)
{
    int fpin,spin;
    again:
    cout<<"enter new pin(5-digit) : ";
    cin>>fpin;
    cout<<"reconfirm your pin : ";
    
    cin>>spin;
    if(fpin!=spin)
    {
        cout<<"pin not matched !!\n";
        goto again;
    }
    if(spin<5)
    {
        cout<<"pin is too short try again!!\n";
        goto again;
    }
 

 srand(time(0));
   string otp="";
   for(int i=0;i<=3;i++)
   {
    int digit=rand()%9+1;
    string s=to_string(digit);
    otp+=s;
   }
   cout<<"\tyour otp is : "<<otp<<endl;
   cout<<"4 digit otp has been sent to you number, please check !\n";
   varification:
string otp_put;
cout<<"enter your otp : ";        
cin>>otp_put;
if(otp==otp_put)
{
member[idx].pin=fpin;
}
else
{
    cout<<"otp is wrong ,try again\n";
    goto varification;
}

cout<<"\t\nupdate complete !!\n\n";
cout<<"new name : "<< member[idx].name<<endl;
cout<<"your pin : "<<member[idx].pin<<endl;
cin.ignore();
cout << "Press any key to main menu...";
    cin.get();
}