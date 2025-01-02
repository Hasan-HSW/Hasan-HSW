#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include <cstdlib>
using namespace std;
void readfile();
void addpatient();
void displaydata();
void menu();
void readfiledelete();
void deleterecord();

//void deleterecord();
char ch;
const int size = 100;
int IDnumber[size];
string firstname[size];
string lastname[size];
string phonenumber[size];
string nationality[size];

int dIDnumber[size];
string dfirstname[size];
string dlastname[size];
string dphonenumber[size];
string dnationality[size];
string na, ln, fn, pn;
int id;



int Eindex();
int Edindex();
int Lindex(int idnum);
void writefile();
void writefiledelete();
bool Sindex(int idno);

void modify();	
void totalcharge();
void deleterecord();

int c=0; // counter

struct Data {
    string name, address, disease, gender, description;
    int specialRoomNo, age;
};


struct Node {

    Data data;
    Node* next;
};






//**********************************************************************************************************************************************************
void addpatient()
{
	string x;
	int idno;
	do{
		int label=Eindex();
		if (label==-1)
		{
			cout<<"\n\t\tno avialable space for new patient\n";
			return;
		}


		bool h;
		do{
			system("cls");
			cout<<"\n\nPLEASE ENTER THE ID NUMBER:  ";
			cin>>idno;

			if(Sindex(idno))
			{
				cout<<"\n\t\tTHE patient NUMBER IS EXIST, TRY AGAIN\n";
				h=1;
			}
			else 
				h=0;
		}while(h);


		IDnumber[label]=idno;
		
		cout<<"\n\nPLEASE ENTER THE patient first name:  ";
		cin>>fn;
		cout<<"\n\nPLEASE ENTER THE patient last name:  ";
		cin>>ln;
		cout<<"\n\nPLEASE ENTER THE patient phone number:  ";
		cin>>pn;
		cout<<"\n\nPLEASE ENTER THE nationality  ";
		cin>>na;

		firstname[label]=fn;
		lastname[label]=ln;
		phonenumber[label]=pn;
		nationality[label]=na;
		


		cout<<"\n\n\nTO ADD MORE ENTER (Y).. OR To Exit Enter (N) ";
		cin>>x;
	}while(x!="N" && x!="n");

	cout<<"\nTHE RECORD IS SUCCESSFULY CREATED..";
}
//*****************************************************************
void readfile()						// READING THE INFORMATION FROM THE FILE
{
	ifstream inFile;
	inFile.open("patient.txt");
	if(!inFile)
	{
		return;
	}
	int i = 0 ;
	while(!inFile.eof() )
	{
		int idno; fn,ln,pn,na;
		inFile>>idno;
		if(idno<=0)
			return;
		inFile>>fn>>ln>>pn>>na;

		IDnumber[i]=idno;
		firstname[i]=fn;
		lastname[i]=ln;
		phonenumber[i]=pn;
		nationality[i]=na;

		i++;
	}
	for (int i=0;i<=c;i++)

	inFile.close();
}


void invoicemenu()
{
	cout << "What type of treatment the patient had? \n";
	cout << "1. Surgery \n";
	cout << "2. Stay at hospital. \n";
	cout << "3. Medication. \n";
}



void writefile()						// WRITING THE DATA INTO THE FILE
{
	ofstream outFile;
	outFile.open("patient.txt");
	int i=0;
	for(i=0; i < size; i++)
	{
		if(IDnumber[i]==0) 
			break;
		outFile<<"\n"<<IDnumber[i]<<"\t"<<firstname[i]<<"\t"<<lastname[i]<<"\t"<<phonenumber[i]<<"\t"<<
			nationality[i];

	}
	outFile.close();
}


bool Sindex(int idno)				// RETURN TRUE IF THE patient EXIST
{
	for(int i=0; i < size; i++)
	{
		if (IDnumber[i]==0)
			return false;
		if (IDnumber[i]==idno)
			return true;
	}
	return false;
}


int Eindex()					// SEARCH  EMPTY INDEX IN ARRAY
{
	for(int i=0; i < size ;i++)
	{
		if (IDnumber[i]==0)
			return i;
	}
	return -1;
}


int Lindex(int idnum)			// SEARCH THE patient INDEX IN ARRAY
{
	for(int i=0; i < size ;i++)
	{
		if (IDnumber[i]==0)
			return -1;
		if (IDnumber[i]==idnum)
			return i;
	}
	return -1;
}


void menu()
{
	cout<<"\n\n\t   TO UPDATE.. CHOOSE FROM THE MENUE: ";
	cout<<"\n\n\t1. UPDATE THE ID NUMBER FIELD:\t";
	cout<<"\n\n\t2. UPDATE THE FIRST NAME FIELD:\t";
	cout<<"\n\n\t3. UPDATE THE LAST NAME FEILD:\t";
	cout<<"\n\n\t4. UPDATE THE PHONE NUMBER FELD:\t";
	cout<<"\n\n\t5. UPDATE THE NATIONALITY FEILD:\t";
	
	cout<<"\n\n\tPLEASE ENTER YOUR CHOICE:\t";
}

//**************************************************************
void modify()						//   UPDATE patient INFORMATION
{

	system("cls");
		menu();
	int IDno;

	cout<<"\n\nPLEASE ENTER ID NUMBER:  ";
	cin>>IDno;

	if(!Sindex(IDno))
	{
		cout<<"\n\t\t  ID NUMBER IS NOT FOUND\n";
		return ;
	}

	int S=Lindex(IDno);

	IDnumber[S]=IDno;
	
	int x;
	do{
		system("cls");
		menu();
		cin>>x;
		switch(x){
		case 1:
			cout<<"\n\nPLEASE ENTER THE ID NUMBER";
			cin>>IDno;
			IDnumber[S]=IDno;
			cout<<"\n\nTHANK YOU";
			break;
		case 2:

			cout<<"\n\nPLEASE ENTER THE FIRST NAME:  ";
			cin>>fn;
			firstname[S]=fn;
			cout<<"\n\nTHANK YOU ";
			break;
		case 3:

			cout<<"\n\nPLEASE ENTER THE LAST NUMBER :  ";
			cin>>ln;
			lastname[S]=ln;
			cout<<"\n\nTHANK YOU";
			break;
		case 4:

			cout<<"\n\nPLEASE ENTER THE PHONE NUMBER:  ";
			cin>>pn;
			phonenumber[S]=pn;
			cout<<"\n\nTHANK YOU";
			break;
		case 5:
			cout<<"\n\nPLEASE ENTER THE NATIONALITY:  ";
			cin>>na;
			nationality[S]=na;
			cout<<"\n\nTHANK YOU";
			break;
		
		default:cout<<"\n\nINVALID ENTERED ... TRY AGAIN ";
		}
		cout<<"\n\nWOULD YOU LKE TO CHANGE ANOTHER FEILD?(Y/N):";
		
		cin>>ch;
	}

	while(ch !='n'&& ch!='N');

	cout<<"\nTHE patient FILE IS UPDATED..";
}


//**************************************************************
void displaydata()
{
ifstream infile;

	infile.open("patient.txt");
	if (infile)
	while (!infile.eof())
	{
		infile >> IDnumber[c] >> firstname[c] >> lastname[c] >> phonenumber[c] >> nationality[c];
		c++;
	}
	infile.close();
}

void deleterecord()
{
	system("cls");
	int id_no,ss;
	cout<<"\n\n\t PLEASE ENTER THE CUSTOMER NUMBER ";
	cin>>id_no;
	if(!Sindex(id_no))
	{
		cout<<"\n\t\tcustomer number is not found\n";
		return ;
	}

	ss=Lindex(id_no);

	if(IDnumber[ss+1]==0)
	{
		IDnumber[ss]=0;
		cout<<"\n\n\t Record is deleted ";
		return;
	}


	for(int i=ss;i<size-1;i++)
	{
		if(IDnumber[i+1]==0)
		{IDnumber[i]=0;
		cout<<"\n\n\t Record is deleted ";
		i=size;
		}
		else
			IDnumber[i]=IDnumber[i+1];


	}
	cout<<"\n\n\t Record is deleted ";

	//*****************
	string x;
	
	
		int label=Edindex();
		if (label==-1)
		{
			cout<<"\n\t\tno avialable space for new patient\n";
			return;
		}
		dIDnumber[label]=id_no;
		dfirstname[label]=fn;
		dlastname[label]=ln;
		dphonenumber[label]=pn;
		dnationality[label]=na;

	cout<<"\nTHE RECORD IS SUCCESSFULY CREATED in delete file ..";
	writefiledelete();

}

int Edindex()					// SEARCH  EMPTY INDEX IN ARRAY
{
	for(int i=0; i < size ;i++)
	{
		if (dIDnumber[i]==0)
			return i;
	}
	return -1;
}

void writefiledelete()
{
	ofstream outFile;
	outFile.open("deletepatient.txt");
	int i=0;
	for(i=0; i < size; i++)
	{
		if(dIDnumber[i]==0) 
			break;
		outFile<<"\n"<<dIDnumber[i]<<"\t"<<dfirstname[i]<<"\t"<<dlastname[i]<<"\t"<<dphonenumber[i]<<"\t"<<
			dnationality[i];

	}
	outFile.close();
}

void readfiledelete()
{
ifstream infile;

	infile.open("deletepatient.txt");
	if (infile)
	while (!infile.eof())
	{
		infile >> dIDnumber[c] >> dfirstname[c] >> dlastname[c] >> dphonenumber[c] >> dnationality[c];
		c++;
	}
	infile.close();	
}

void totalcharge()
{

	system("cls");
	
	int IDno;
	cout<<"\n\nPLEASE ENTER ID NUMBER:  ";
	cin>>IDno;

	if(!Sindex(IDno))
	{
		cout<<"\n\t\t  ID NUMBER IS NOT FOUND\n";
		return ;
	}

	int S=Lindex(IDno);

	IDnumber[S]=IDno;
	
	int x,ch_surgery,stay_ch,med_ch,total=0;
	do{
		system("cls");
		cout<<"what type of treatment the patient had ? \n"<<endl;
		cout<<"1.surgery ? \n"<<endl;
		cout<<"2.stay at hospital ?\n "<<endl;
		cout<<"3.medication ? \n"<<endl;
		cout<<"choose from above menu ?\n "<<endl;
		int z;
		cin>>x;
		switch(x){
		case 1:
			cout<<"PLEASE ENTER surgery charge \n"<<endl;
			cout<<"1. surgery 1  "<<endl;
			cout<<"2. surgery 2  "<<endl;
			cout<<"3. surgery 3  "<<endl;
			cin>>z;
			if (z==1)
              ch_surgery = 100;
			else if (z==2)
              ch_surgery = 200;
			else if (z==3)
              ch_surgery = 300;
			else 
              ch_surgery = 0;
			break;
		case 2:
		cout<<"PLEASE ENTER how many days stay at hospital "<<endl;
			cin>>z;
			stay_ch=z*200;
			break;
		case 3:
			cout<<"PLEASE ENTER medication charge "<<endl;
			cout<<"1. med 1  "<<endl;
			cout<<"2. med 2  "<<endl;
			cout<<"3. med 3  "<<endl;
			cin>>z;
			if (z==1)
              med_ch = 100;
			else if (z==2)
               med_ch = 200;
			else if (z==3)
              med_ch = 300;
			else 
              med_ch = 0;
			break;
	
		
		
		}
		cout<<"\n\nWOULD YOU LKE TO  ANOTHER treatment?(Y/N):";
		
		cin>>ch;
	}

	while(ch !='n'&& ch!='N');

	total += ch_surgery + stay_ch+med_ch ; 
	cout << "IDnumber " << "\t" << "total" << endl;
	cout << IDnumber[IDno] << "\t" << total << endl;
}








Node* insertFront(Node* head, Data data)
{
    Node* temp = new Node;
    temp->data = data;

    temp->next = head;
    head = temp;
    return head;

}//end of insertFront Function

//============================================

Node* append(Node* head, Data data) {

    Node* temp = new Node;

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return head;
    }

    Node* last = head;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = temp;

    clog << "Append completed" << endl;

    return head;

}//end of append function


//========================================


void changeNode(Node* head, Data data, Data newData)
{
    while (head != NULL)
    {
        if (head->data.name == data.name)
        {
            head->data = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function


void changeNode(Node* head, string data, string newData)
{
    while (head != NULL)
    {
        if (head->data.name == data)
        {
            head->data.name = newData;
            break;
        }

        head = head->next;
    }
}//end of changeNode function



//=======================================


void printLinkedList(Node* head)
{
    if (head == NULL)
    {
        cout << "Head is null" << endl;
        return;
    }

    while (head->next != NULL)
    {
        cout << "Name: " << head->data.name << ", Address: " << head->data.address
            << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
            << ", Description: " << head->data.description << ", Age: " << head->data.age
            << ", Specialist No: " << head->data.specialRoomNo << endl;
        head = head->next;
    }
    cout << "Name: " << head->data.name << ", Address: " << head->data.address
        << ", Gender: " << head->data.gender << ", Disease: " << head->data.disease
        << ", Description: " << head->data.description << ", Age: " << head->data.age
        << ", Specialist No: " << head->data.specialRoomNo << endl;

}//end of printLinkedList function

//========================================



int listLength(Node* head) {
    int temp = 0;

    if (head == NULL)
    {
        cout << "Node is empty" << endl;
        return 0;
    }

    while (head->next != NULL)
    {
        ++temp;
        head = head->next;
    }

    return temp + 1;
}//end of the listLength function

//============================================


void delElement(Node* head, int loc)
{
    Node* temp = new Node;

    temp = head;

    if (head == NULL) {

        cout << "Nod is null" << endl;
        return;
    }


    for (int i = 1; i <= loc; ++i)
    {
        temp = temp->next;
        if (i < loc) {
            head = head->next;
        }//end of if statement

    }//end of for statement

    head->next = temp->next;

}//end of delElement function

//===========================================


Node* searchList(Node* head, Data v) {

    if (head == NULL)
    {
        cout << "Node is empty returning null" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v.name)
    {
        head = head->next;
        ++l;
    }

    cout << "Element found at location " << l << endl;

    return head;

}//end of searchList function




//==============================================



Node* searchList(Node* head, string v) {

    if (head == NULL)
    {
        cout << "Node is empty returning null" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v)
    {
        head = head->next;
        ++l;
    }

    cout << "Element found at location " << l << endl;

    return head;

}//end of searchList function




//=======================================================================


Data inputPatients()
{
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;

    cout << "Enter Patient Name: ";
    cin.ignore();//clearing buffer
    getline(cin, name);

    cout << "Enter Patient Address: ";
    getline(cin, address);

    cout << "Enter Patient Disease: ";
    getline(cin, disease);

    cout << "Enter Patient Gender: ";
    getline(cin, gender);

    cout << "Enter Disease Description: ";
    getline(cin, description);

    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;

    cout << "Enter Patient Age: ";
    cin >> age;

    p.name = name;
    p.address = address;
    p.gender = gender;
    p.description = description;
    p.specialRoomNo = specialRoomNo;
    p.age = age;

    clog << "Completed input operation" << endl;

    return p;

}//end of inputPatients function

//============================================================================

int main()
{
	Node* head = NULL;
    Data patient;
    string nameToSearch;
    string oldName, newName;
	int choose;	
do
	{
		system("cls");											
		
		cout<<"\n\n\t  PLEASE SELECT FROM THE MENUE  ";
		cout << "\n\n\t Please choose one of the below options:   \n";
	cout << "--------------------------------------\n";
	cout << "1.add patient number \n";
	cout << "2.modify patient record  \n";
	cout << "3.delete patient record \n";
	cout << "4.list of all patients  \n";
	cout << "5.issue invoice for apatients \n";
	cout << "6.list of all deleted patients  \n";
	cout << "7.Add normal patient \n";
	cout << "8.Add critically ill patient \n";
	cout << "9.Take patient to Doctor \n";
	cout << "10.Display list \n";
	cout << "11.Health status report, \n";
	cout << "12.exit \n";	
		
		cin>>choose;

		readfile();
		system("cls");

		switch(choose)
		{

		case 1:
			readfile();
			addpatient();
		writefile();
			break;

		case 2:
		   modify();
			writefile();
			break;
		case 3:
			deleterecord();		
			writefile();
			
			break;
		case 4:
			displaydata();

			for (int i=0;i<c;i++)
			cout << IDnumber[i] <<"\t"<< firstname[i] <<"\t"<< lastname[i] <<"\t"<< phonenumber[i] <<"\t"<< nationality[i]<<endl;

			break;
		case 5:
			totalcharge();
			break;
		case 6: 
			readfiledelete();
		for (int i=0;i<c;i++)
			cout << dIDnumber[i] <<"\t"<< dfirstname[i] <<"\t"<< dlastname[i] <<"\t"<< dphonenumber[i] <<"\t"<< dnationality[i]<<endl;
			break;
		case 7: 
			 cout << "Enter Patient Details Below" << endl;
            patient = inputPatients();
            head = append(head, patient);
			break;
		case 8: 
		 if (listLength(head) < 2)
            {
                cout << "Length is less then two.\nTerminating program" << endl;
                exit(1);
            }
            else {
                cout << "Enter location where you want to delete a patient, at least three patients must be in list? ";
                int l;
                cin >> l;
                delElement(head, l - 1);
            }//end of else of case 2
			break;
		case 9: 
		cout << "Enter name to search patient: ";
            cin.ignore();
            getline(cin, nameToSearch);
            searchList(head, nameToSearch);	
			break;
		case 10: 
		 cout << "You have " << listLength(head) << " Patients in your Hospital." << endl;
			break;
		case 11: 
		 printLinkedList(head);
		break;
		case 12:
			cout<<"\n\n\n\n\n\n\t\t                 GOOD BYE.....";		
			break;
		default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(choose!=12);

	return 0;
}

