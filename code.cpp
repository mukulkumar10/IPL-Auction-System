#include <iostream>
#include<conio.h>
#include <fstream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<sstream>

int a[8]={};
char b[8][5]={"CSK","KKR","MI","RCB","DD","RR","SRH","KXIP"};
using namespace std;
typedef struct node
{
    string data;
    struct node *a;
    struct node *b;
    struct node *c;
    struct node *d;
}Node;

void batsman(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<endl;
        batsman(root->a);
	}
	return;
}
void bowler(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<endl;
        bowler(root->a);
	}
	return;
}
void allrounder(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<endl;
        allrounder(root->a);
	}
	return;
}
void wicketkeeper(struct node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<endl;
        wicketkeeper(root->a);
	}
	return;
}
	
	Node *csk,*kkr,*mi,*rcb,*kxip,*srh,*rr,*dd=NULL;
	float cp=6000,kp=6000,mp=6000,rp=6000,pp=6000,dp=6000,hp=6000,bp=6000;
	
int equal(string s1, string s2)
{
	if((s1.compare(s2)) == 0)
		return 1;
	else
		return 0;
}
	
Node *newNode(string item)
{
	node *temp=new Node;
    temp->data=item;
    temp->a=temp->b=temp->c=temp->d=NULL;
    return temp;
}

	
Node *newNode1(string item)
{
	node *temp=new Node;
    temp->data=item;
    temp->a=NULL;
    return temp;
}

void team(Node *t)
{
	t->a=newNode("BATSMAN");
	t->b=newNode("BOWLER");
	t->c=newNode("ALL-ROUNDER");
	t->d=newNode("WICKETKEEPER");
}

void add(Node *head,string name)
{
	if(head->a==NULL)
	 {
	 	head->a=newNode1(name);
	 	return;
	 }
	 	//cout<<head->data;
	add(head->a,name);
}
int count=1;
Node* insert(Node* head, string name,string category)
{
	Node *temp=new Node;
	temp=head;
    /* If the tree is empty, return a new node */
    if (head == NULL) return newNode("1");
    /* Otherwise, recur down the tree */
    else if (equal(category,head->a->data)==1)
        add(head->a,name);
    else if (equal(category,head->b->data)==1)
        add(head->b,name);
	else if (equal(category,head->c->data)==1)
        add(head->c,name);
	else if (equal(category,head->d->data)==1)
        add(head->d,name);
    return temp;
    delete(temp);
}

void push(string s,string y,string g)
{
	if(s=="CSK")
		csk=insert(csk,y,g);
	else if(s=="KKR")
		kkr=insert(kkr,y,g);
	else if(s=="MI")
		mi=insert(mi,y,g);
	else if(s=="RCB")
		rcb=insert(rcb,y,g);
	else if(s=="RR")
		rr=insert(rr,y,g);
	else if(s=="DD")
		dd=insert(dd,y,g);
	else if(s=="SRH")
		srh=insert(srh,y,g);
	else
		kxip=insert(kxip,y,g);
}

void run_with(const char* filename) {
	system("CLS");
  ifstream ip(filename);
  float price,k;
  string a,b,c,d,e,f,g,h,team,y;
while(!ip.eof())
{
	stringstream ss;
	count=1;
	getline(ip,a,',');
	getline(ip,b,',');
	getline(ip,c,',');
	getline(ip,d,',');
	getline(ip,e,',');
	getline(ip,f,',');
	getline(ip,g,',');
	getline(ip,h,'\n');
	cout<<"Player Number : "<<a<<"\n"<<"Type : "<<b<<"\n"<<"SET : "<<c<<"\n"<<"Name : "<<d<<" "<<e<<"\n"<<"Country : "<<f<<"\n"<<"Speciality : "<<g<<"\n"<<"Price : "<<h<<"\n";
	cout<<"\nCurrent available purse : \n";
	cout<<"CSK : "<<cp<<"L KKR : "<<kp<<"L MI: "<<mp<<"L RCB : "<<bp<<"L RR : "<<rp<<"L DD : "<<dp<<"L SRH : "<<hp<<"L KXIP : "<<pp<<"L"<<endl;
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
	
	while(count!=0)
	{
	cout<<"Enter owning team : ";
	cin>>team;
	cout<<"Enter buying price (in Lakhs) : ";
	cin>>price;
	ss<<h;ss>>k;
	if(price>=k)
	{
		count=0;
		if(team=="CSK" && cp>=20 && (cp-price)>=0)
			cp=cp-price;
		else if(team=="KKR" && kp>=20 && (kp-price)>=0)
			kp=kp-price;
		else if(team=="MI" && mp>=20 && (mp-price)>=0)
			mp=mp-price;
		else if(team=="RCB" && bp>=20&& (bp-price)>=0)
			bp=bp-price;
		else if(team=="RR" && rp>=20 && (rp-price)>=0)
			rp=rp-price;
		else if(team=="DD" && dp>=20 && (dp-price)>=0)
			dp=dp-price;
		else if(team=="SRH" && hp>=20 && (hp-price)>=0)
			hp=hp-price;
		else if(team=="KXIP" && pp>=20 && (pp-price)>=0)
			pp=pp-price; 
		else
		{
			cout<<"\nPurse Limit Exceeded !!\nTry again with another team.\n";
			count++;
		}
	}
	else
	{
		cout<<"\nPrice is less then BASE PRICE .\nTRY AGAIN\n";
		count++;
	}
}

	y=d+" "+e;
	push(team,y,g);
	
	system("CLS");
}
cout<<"Summary of set : "<<endl;
	cout<<csk->data<<" : \n=================================="<<endl;
	batsman(csk->a);cout<<"\n";
	bowler(csk->b);cout<<"\n";
	allrounder(csk->c);cout<<"\n";
	wicketkeeper(csk->d);cout<<"\n";
	
	cout<<kkr->data<<" : \n=================================="<<endl;
	batsman(kkr->a);cout<<"\n";
	bowler(kkr->b);cout<<"\n";
	allrounder(kkr->c);cout<<"\n";
	wicketkeeper(kkr->d);cout<<"\n";
	
	cout<<mi->data<<" : \n=================================="<<endl;
	batsman(mi->a);cout<<"\n";
	bowler(mi->b);cout<<"\n";
	allrounder(mi->c);cout<<"\n";
	wicketkeeper(mi->d);cout<<"\n";
	
	cout<<dd->data<<" : \n=================================="<<endl;
	batsman(dd->a);cout<<"\n";
	bowler(dd->b);cout<<"\n";
	allrounder(dd->c);cout<<"\n";
	wicketkeeper(dd->d);cout<<"\n";
	
	cout<<rcb->data<<" : \n=================================="<<endl;
	batsman(rcb->a);cout<<"\n";
	bowler(rcb->b);cout<<"\n";
	allrounder(rcb->c);cout<<"\n";
	wicketkeeper(rcb->d);cout<<"\n";
	
	cout<<rr->data<<" : \n=================================="<<endl;
	batsman(rr->a);cout<<"\n";
	bowler(rr->b);cout<<"\n";
	allrounder(rr->c);cout<<"\n";
	wicketkeeper(rr->d);cout<<"\n";
	
	cout<<kxip->data<<" : \n=================================="<<endl;
	batsman(kxip->a);cout<<"\n";
	bowler(kxip->b);cout<<"\n";
	allrounder(kxip->c);cout<<"\n";
	wicketkeeper(kxip->d);cout<<"\n";
	
	cout<<srh->data<<" : \n=================================="<<endl;
	batsman(srh->a);cout<<"\n";
	bowler(srh->b);cout<<"\n";
	allrounder(srh->c);cout<<"\n";
	wicketkeeper(srh->d);cout<<"\n";
	
ip.close();
}
int main()
{
	csk=newNode("Chennai Super Kings");kkr=newNode("Kolkata Knight Riders");mi=newNode("Mumbai Indians");rcb=newNode("Royal Challengers Bangalore");
	rr=newNode("Rajasthan Royals");dd=newNode("Delhi Daredevils");kxip=newNode("Kings XI Punjab");srh=newNode("Sunrisers Hyderabad");
	team(csk);team(kkr);team(mi);team(rcb);team(rr);team(dd);team(kxip);team(srh);
	int j,z=1;
	char ll[][20]={"D:\Book1.csv","D:\Book2.csv","D:\Book3.csv"};
for(j=0;j<3;j++)
{
if(z==1)
run_with(ll[j]);
else
cout<<"Try Again : ";
cout<<"Enter 1 to continue with another set : ";
cin>>z;
} 
}