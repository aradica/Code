#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include <ctime>
using namespace std;
//number of slots; temporary storage
const int SIZE = 500;
string Temp[SIZE];
string DEFAULT = "data.txt";

//display start menu
void Start(){
	cout << " ________________________________________________________" << endl;
	cout << "|   Welcome to MyConsole v0.4a by Andrija Radica         |" << endl;
	cout << "| To display a list of commands enter c, to quit press q |" << endl;
	cout << "|________________________________________________________|" << endl;
}
//display available commands
void Commands(){
	cout << "Press F11 to toggle fulscreen." << endl;
	cout << "c - view available commands" << endl;
	cout << "q - quit" << endl;
	cout << "x - clear all screan" << endl;
	cout << "r - clear all screen and view start message" << endl;
	cout << "i - input text into slot N" << endl;
	cout << "d - output text from slot N" << endl;
	cout << "s - save all slots" << endl;
	cout << "u - change default save file for slots" << endl;
	cout << "z - view save location" << endl;
	cout << "p - load file into slots" << endl;
	cout << "h - create new file" << endl;
	cout << "j - delete file" << endl;
	cout << "e - erase all slots" << endl;
	cout << "v - view number of available slots" << endl;
	cout << "f - display text from file" << endl;
	cout << "t - display current date and time" << endl;
	cout << "n - perform basic mathematical calculations" << endl;
	cout << "l - list folder and save content to file_names.txt" << endl; 
}

//save data to slot N
void Input(int N){
	cin.ignore();
	if (N < SIZE){
		getline(cin,Temp[N]);
		cout << "Data successfully stored in slot " << N << endl;
				
	}
	else{
		cout << "Invalid N" << endl;
	}
	
}
//display data from slot N
void Output(int N2){
	if (N2 < SIZE){
		if (Temp[N2] == ""){
			cout << "This slot is empty. " << endl;
			}
		else{
			cout << Temp[N2] << endl;
		}
		
	}

	else{
		cout << "Invalid N" << endl;
	}
		
}
//erase all slots
void Erase(){
	for(int i = 0; i < SIZE; i++){
		Temp[i] = "";
	}
	cout << "All slots were erased. " << endl; 
}
//save slots to disk
void Save(){
	ofstream myfile;
	myfile.open (DEFAULT.c_str());
	for (int i = 0; i < SIZE; i ++){
		myfile << Temp[i] << endl;
	}
	myfile.close();
	cout << "All slots were sucessfully saved to " << DEFAULT << endl;
}
//display the content of a text file
void ReadFile(string filename){
	string line;
	ifstream myfile(filename.c_str());
	if(myfile.is_open()){
		cout << endl;
		cout << "--------------------------------------------------" << endl;
		while (getline (myfile,line)){
			cout << line << endl;
		}
		myfile.close();
		cout << "--------------------------------------------------" << endl;
	}
	else{
		cout << "Unable to open file." << endl;
 	}
	
}
//create a new file
void Newfile(string filename2){
	ofstream outfile (filename2.c_str());
	cout << "File created sucessfully." << endl;
}
//change default save
void Changesave(string filename4){
	fstream file(filename4.c_str());
	if (file.good()){
		DEFAULT = filename4;
		cout << "Storage location sucessfully changed." << endl;
	}
	else{
		cout << "Invalid file" << endl;
	}
}

//load file into slots
void Load(string filename5){
	string line2;
	ifstream myfile2(filename5.c_str());
	int i = 0;
	if(myfile2.is_open()){
		while (getline (myfile2,line2) and i < SIZE){
			Temp[i] =  line2;
			i += 1;
		}
		myfile2.close();
		cout << "Slots updated." << endl;
	}
	else{
		cout << "Unable to open file." << endl;
 	}

}
//delete a file
void Deletefile(string filename3){
	if( remove(filename3.c_str()) != 0 ){
		cout << "Error deleting file." << endl;
	}
    
  else{
  	cout << "File successfully deleted." << endl;
  }

}

//make an list of file names
void List(){
	system( "dir /b /s /a-d * > file_names.txt" );
	cout << "File names saved to file_names.txt" << endl;
}
//display the local time and date
void Time(){
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "The local date and time is: " << dt;
}
void Calculator(){
	float a;
	float b;
	char o;
	cin >> a >> o >> b;
	switch(o){
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			cout << a / b;
			break;
		case '^':
			cout << pow(a,b);
			break;
	}
	cout << endl;
	
	
}

//main
int main(){
	Start();
	bool x = 1;
	char c;
	while(x == 1){
		cout << "<< ";
		cin >> c;
		string file;
		switch(c){
			case 'c':
				Commands();
				break;
			case 'q':
				cout << "Exiting..." << endl;
				x = 0;
				break;
			case 'x':
				system("cls");
				break;
				
			case 'n':
				Calculator();
				break;
			case 'r':
				system("cls");
				Start();
				break;
				
			case 'i':
				int N;
				//cout << "Use slot: ";
				cin >> N;
				if(cin.fail()){
					cout << "Error - invalid value for N" << endl;
					cin.clear();
				}
				else{
					Input(N);
				}
				break;
				
				
			case 'd':
				int N2;
				//cout << "View slot: ";
				cin >> N2;
				if(cin.fail()){
					cout << "Error - invalid value for N" << endl;
					cin.clear();
				}
				else{
					Output(N2);
				}
				break;
				
			case 'e':
				Erase();
				break;
				
			case 's':
				Save();
				break;
				
			case 'h':
				cin >> file;
				Newfile(file);
				break;
				
			case 'j':
				cin >> file;
				Deletefile(file);
				break;
				
			case 'v':
				cout << SIZE << " slots available" << endl;
				break;
				
			case 'f':
				cin >> file;
				ReadFile(file);
				break;
				
			case 'u':
				cin >> file;
				Changesave(file);
				break;
				
			case 'p':
				cin >> file;
				Load(file);
				break;
				
			case 'l':
				List();
				break;
					
			case 't':
				Time();
				break;
				
			case 'z':
				cout << DEFAULT << endl;
				break;
					
			default:
				cout << "Unknown command." << endl;

			}
			
	}
	return 0;
}
