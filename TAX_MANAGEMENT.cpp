#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

//KLASI POU THA KLIRONOMITHEI APO OLA TA AKINITA
class Ktisi{
	protected:
string address;
float epifania;
int year;//etos apoktisis
public:
virtual float Ypologismos()=0;

Ktisi(string _address,float _epifania,int _year)
{
	address=_address;
	epifania=_epifania;
	year=_year;
	
}

virtual void print()=0;
};

class Katoikies:public Ktisi{
	private:
	int orofos;
	string eidos;//Monokatikia h poloikatikia
	
	public:
	float Ypologismos(){
	
	if (eidos.compare("Monokatikia")==0)
	return 1.3*epifania+150;//an einai monokatikia	
	else
return 1.1*epifania+5*orofos+100;//an einai poloikatikia
}

Katoikies(string _address,float _epifania,int _year,int _orofos,string _eidos):Ktisi( _address, _epifania,_year)
{
	orofos=_orofos;
	eidos=_eidos;
}

 void print(){
 		cout<<"KATOIKIES"<<endl;
cout<<"\nADDRESS OF PROPERTY: "<<address<<"\nEPIFANIA: "<<epifania<<"\nETOS APOKTISIS: "<<year<<"\nOrofos: "<<orofos<<"\nEidos: "<<eidos<<endl;	
	
}
};


class Eborika_akinhta:public Ktisi{
	private:
int eborikotita; //apo 1 mexri 10	
public:
		float Ypologismos(){return 2*epifania+200*eborikotita;}
	
		
		Eborika_akinhta(string _address,float _epifania,int _year,int _eborikotita):Ktisi( _address, _epifania,_year)
{
	eborikotita=_eborikotita;
}

		 void print(){
		 	cout<<"Eborika_akinhta"<<endl;
cout<<"\nADDRESS OF PROPERTY: "<<address<<"\nEPIFANIA: "<<epifania<<"\nETOS APOKTISIS: "<<year<<"Eborikotita: "<<eborikotita<<endl;	
	
}
};



class oikopeda:public Ktisi{
	private:
	string oikoismos;//entos h ektos oikismou
	string kalliergeitai;
	
	public:
		float Ypologismos(){
		
			if (!oikoismos.compare("Entos"))
		    return 0.3*epifania+250;//gia ta entos
		    else
	     	return 0.3*epifania+70;}//gia ta ektos
oikopeda(string _address,float _epifania,int _year,string _oikoismos,string _kalliergeitai):Ktisi( _address, _epifania,_year)
{
	oikoismos=_oikoismos;
	kalliergeitai=_kalliergeitai;
}
 void print(){
 			 	cout<<"Oikopeda"<<endl;
cout<<"\nADDRESS OF PROPERTY: "<<address<<"\nEPIFANIA: "<<epifania<<"\nETOS APOKTISIS: "<<year<<"Oikoismos: "<<oikoismos<<"\nKalliergeitai: "<<kalliergeitai<<endl;	
}
};





class Dilosi{
	private:
	string onoma;
	string address;
	string AFM;
	int year;//pote egine h ipovolh ths aitisishs
	list <Ktisi*> k;
	bool akuri;
	public:
		
		
		
		Dilosi()
{
	onoma="N/A";
	address="N/A";
	AFM="N/A";
	year=0;
	
}
		
Dilosi(string _onoma,string _address,string _AFM,int _year)
{
	onoma=_onoma;
	address=_address;
	AFM=_AFM;
	year=_year;
	
}
//Ypologismos enfia akinitwn pou anikoun se kapoia dilwsi 
float calc1()
{
	float sum=0;
		list <Ktisi*>::iterator pos;
for(pos=k.begin();pos!=k.end();pos++) //display all elements
sum=sum+(*pos)->Ypologismos();
return sum;
}


//Poses dilwseis exoun memonomeno akinito me foro panw apo X eurw 
float calc2(float x)
{
	int  counter=0;
list <Ktisi*>::iterator pos;
for(pos=k.begin();pos!=k.end();pos++) //display all elements
if((*pos)->Ypologismos()>x)
counter++;
return counter ;
}


//eisagwgi deilwsis ktisis
void insertDilosi(Ktisi *d)
{
k.push_back(d);
}
//diagrafi dilwsis ktisis
void deleteKtisi()
{
k.pop_back();
cout<<"H TELEUTAIA SAS KTISI DIAGRAFIKE"<<endl;
}


string getAFM()
{
	return AFM;
}

void display()
{
	
	
	cout<<"===========================PLIROFORIES FOROLOGOUMENOU=============================="<<endl;
	cout<<"ONOMA: "<<onoma<<"\nADDRESS: "<<address<<"\nAFM: "<<AFM<<"\nYEAR: "<<year<<endl;
	cout<<"===========================PLIROFORIES AKINITWN=============================="<<endl;
	list <Ktisi*>::iterator pos;
for(pos=k.begin();pos!=k.end();pos++) //display all elements
(*pos)->print();

}
//SETERS
void setnewname(string onomaup)
{
	onoma=onomaup;
}


void setnewaddress(string addressup)
{
	address=addressup;
}

void setnewafm(string afmup)
{
	AFM=afmup;
}


void setnewyear(int yearup)
{
	year=yearup;
}


void setakuri()
{
	akuri=false;
}

};




int main ()
{
		int s;
	vector<Dilosi> dil;//enas vector pou periexei mesa tou oles tis dilwseis twn forologoumenwn opou kathe dilwsei exei mia lista apo akinita ta opoia exei o kathe forologoumenos
	 system("cls");

	
	 do 
    {
    	
     system("cls");
     printf("CHOOSE AN OPTION: \n");
     printf("==================================================\n");
     printf("0:EXIT\n");
     printf("1:PROSTHIKI DILWSIS\n");
     printf("2:TROPOPOISH DILOSIS \n");
     printf("3:AKYRWSH DHLWSHS\n");
     printf("4:EMFANISI PLHROFORIVWN\n");
	
	cin>>s;
    
switch (s)
{
case 1:
{
		 system("cls");
cout<<"==================STOIXEIA FOROLOGOUMENOU=============== "<<endl;
string tempname,tempaddress,tempafm;//dieuthinsi forologoumenou
int tempyear;
cin.ignore();
cout<<"Onoma: ";
getline(cin,tempname);
cout<<"ADDRESS: ";
getline(cin,tempaddress);
cout<<"AFM:  "<<endl;
getline(cin,tempafm);
cout<<"YEAR:  "<<endl;
cin>>tempyear;
	Dilosi a1(tempname,tempaddress,tempafm,tempyear);


int flag;
do
{


cout<<"\n==================STOIXEIA AKINITOU==================== "<<endl;
string temp2address;//dieuthinsi akinitou
float tempepifania;
int temp2year;//etos apoktisis

cin.ignore();
cout<<"DIEYTHINSI AKINITOU: ";
getline(cin,temp2address);
cout<<"Epifaneia: ";
cin>>tempepifania;
cout<<"Etos apoktisis: ";
cin>>temp2year;
cout<<"\n==================ANALYTIKA STOIXEIA================ "<<endl;
cout<<"\nTI EIDOUS AKINITO EINAI:"<<endl;
int ch;
     printf("1:Katoikia\n");
     printf("2:Eborikou akinhto\n");
     printf("3:Oikopedo\n");
     cin>>ch;
switch(ch)
{
	case 1:
		{
	system("cls");
	int temporofos;
	string tempeidos;//Monokatikia h poloikatikia
	cout<<"OROFOS: ";
	cin>>temporofos;
	cin.ignore();
		cout<<"Eidos: ";
	getline(cin,tempeidos);
Katoikies *b1=new Katoikies(temp2address,tempepifania,temp2year,temporofos,tempeidos);
a1.insertDilosi(b1);


system("pause");
	break;
}

	case 2:
{
		system("cls");
int tempeborikotita; //apo 1 mexri 10	
cout<<"Eborikotita: ";
cin>>tempeborikotita;
 Eborika_akinhta *b2=new Eborika_akinhta(temp2address,tempepifania,temp2year,tempeborikotita);
a1.insertDilosi(b2);
	system("pause");
	break;
}
	
	
	case 3:
{
		system("cls");
	string tempoikoismos;//entos h ektos oikismou
	string tempkalliergeitai;
	cin.ignore();
	cout<<"Oikismos: ";
	getline(cin,tempoikoismos);
		cout<<"Kalliergeitai: ";
	getline(cin,tempkalliergeitai);
	oikopeda *b3=new oikopeda(temp2address,tempepifania,temp2year,tempoikoismos,tempkalliergeitai);
a1.insertDilosi(b3);
system("pause");
	break;
	
}

}


cout<<"\nTHES NA KANEIS ALLI DILWSI "<<tempname<<endl;
     printf("Press 0 if not else press anything else\n");
cin>>flag;

}
while(flag!=0);
dil.push_back(a1);

break;
}
  
case 2:
	{
	
	string	afmup,onomaup,addressup;
	int yearup;
			system("cls");
	cout<<"============================UPDATE===================="<<endl;
	cout<<"Dwse to afm"<<endl;
	cin>>afmup;
	
	 
	for (int j2=0;j2<dil.size();j2++)
	if(afmup.compare(dil[j2].getAFM())==0)
	{

cout<<"VRETHIKE"<<endl;	
  printf("CHOOSE AN OPTION: \n");
     printf("==================================================\n");
     printf("1:ENIMERWSI STOIXEIWN FOROLOGOUMENOU\n");
     printf("2:PROSTHIKI AKINITOU\n");
     printf("3:DIAGRAFI AKINITOU\n");
     int q;
     cin>>q;
     
     if (q==1)
     {
cin.ignore();
cout<<"Neo Onoma: ";
getline(cin,onomaup);
cout<<"Nea ADDRESS: ";
getline(cin,addressup);
cout<<"Neo AFM:  "<<endl;
getline(cin,afmup);
cout<<"Neo YEAR:  "<<endl;
cin>>yearup;
  
    dil[j2].setnewname(onomaup);
    dil[j2].setnewaddress(addressup);
    dil[j2].setnewafm(afmup);
    dil[j2].setnewyear(yearup);
}
 
     if(q==2)
     {
     	
cout<<"\n==================STOIXEIA NEOY AKINITOU==================== "<<endl;
string temp3address;//dieuthinsi akinitou
float temp3epifania;
int temp3year;//etos apoktisis

cin.ignore();
cout<<"DIEYTHINSI AKINITOU: ";
getline(cin,temp3address);
cout<<"Epifaneia: ";
cin>>temp3epifania;
cout<<"Etos apoktisis: ";
cin>>temp3year;
cout<<"\n==================NEA ANALYTIKA STOIXEIA================ "<<endl;
cout<<"\nTI EIDOUS AKINITO EINAI:"<<endl;
int ch2;
     printf("1:Katoikia\n");
     printf("2:Eborikou akinhto\n");
     printf("3:Oikopedo\n");
     cin>>ch2;
switch(ch2)
{
	case 1:
		{
	system("cls");
	int temp3orofos;
	string temp3eidos;//Monokatikia h poloikatikia
	cout<<"OROFOS: ";
	cin>>temp3orofos;
	cin.ignore();
		cout<<"Eidos: ";
	getline(cin,temp3eidos);
Katoikies *b1=new Katoikies(temp3address,temp3epifania,temp3year,temp3orofos,temp3eidos);
dil[j2].insertDilosi(b1);


system("pause");
	break;
}

	case 2:
{
		system("cls");
int temp3eborikotita; //apo 1 mexri 10	
cout<<"Eborikotita: ";
cin>>temp3eborikotita;
 Eborika_akinhta *b2=new Eborika_akinhta(temp3address,temp3epifania,temp3year,temp3eborikotita);
dil[j2].insertDilosi(b2);
	system("pause");
	break;
}
	
	
	case 3:
{
		system("cls");
	string temp3oikoismos;//entos h ektos oikismou
	string temp3kalliergeitai;
	cin.ignore();
	cout<<"Oikismos: ";
	getline(cin,temp3oikoismos);
		cout<<"Kalliergeitai: ";
	getline(cin,temp3kalliergeitai);
	oikopeda *b3=new oikopeda(temp3address,temp3epifania,temp3year,temp3oikoismos,temp3kalliergeitai);
dil[j2].insertDilosi(b3);
system("pause");
	break;	
}	
	 }
 }
 
if(q==3)
{
dil[j2].deleteKtisi();
}

		system("pause");
	}
break;
}

case 3:
{
	system("cls");
	int foundx=0;//flag gia to an vrethike to afm 
	string afmak;//afm akurwsis 
    cout<<"DWSE TO AFM GIA AKURWSI: "<<endl;
	cin>>afmak;
	for (int j6=0;j6<dil.size();j6++)
	if(afmak.compare(dil[j6].getAFM())==0)
		{
		foundx=1;
		dil[j6].setakuri();
		}
if (foundx)
cout<<"AKIROTHIKE"<<endl;
else
cout<<"DEN VRETHIKE TO AFM"<<endl;
	system("pause");
break;
}

case 4:
{
			system("cls");
int ch4;
printf("CHOOSE AN OPTION: \n");
     printf("==================================================\n");
	    printf("1:Poses dilwseis exoun sinoliko foro panw apo X eurw\n");
     printf("2:Poses dilwseis exoun memonomeno akinito me foro panw apo X eurw \n");
     printf("3:Top 10\n");
     

     cin>>ch4;//CHOICE
     
   //  Poses dilwseis exoun sinoliko foro panw apo X eurw
     if (ch4==1)
     {
     			system("cls");
     	int counter=0;
     	float x;
     	cout<<"DWSE POSO: ";
     	cin>>x;
     	
     	float a[dil.size()];//enas pinakas me oles tis dilwseis opou tha boun ta posa apo ola ta akinita 
	for (int j2=0;j2<dil.size();j2++)
		 a[j2]=dil[j2].calc1();
     	
     	for (int j2=0;j2<dil.size();j2++)
     	if(a[j2]>x)
         counter++ ;
	 	cout<<"OI DILWSEIS EINAI: "<<counter<<endl;
	 
	 }
     
     
    // Poses dilwseis exoun memonomeno akinito me foro panw apo X eurw 
      if (ch4==2)
     {
     	int x,counter=0;
     			system("cls");
     			cout<<"DWSE TON ARITHMO TWN XRHMATWN"<<endl;
				 cin>>x; 
	    for (int j2=0;j2<dil.size();j2++)
     	counter=counter+dil[j2].calc2(x);
     	cout<<counter;
	 }
     
     //10 dhlwseis me ton megalutero foro
      if (ch4==3)
     {
     			system("cls");
     	float a[dil.size()];//enas pinakas me oles tis dilwseis opou tha boun ta posa apo ola ta akinita 
     	for (int j2=0;j2<dil.size();j2++)
		 a[j2]=dil[j2].calc1();
		 
    //TAKSINOMISI PINAKA
	 float temp;
   	for(int i=0; i<dil.size(); i++)
	{
    for(int j=0; j<dil.size()-i-1; j++)
  {
    if( a[j] < a[j+1])
    {
      temp = a[j];
      a[j] = a[j+1];
      a[j+1] = temp;
    } 
  }
}
     	//EMFANISI 10 MEGALUTERWN DILWSEWN 
		 for(int i=0; i<dil.size(); i++)
     cout<<	a[i]<<endl;	
	 }	
	system("pause");
break;
}
}
}
while(s!=0);




for (int j=0;j<dil.size();j++)
dil[j].display();

	return 0;}


