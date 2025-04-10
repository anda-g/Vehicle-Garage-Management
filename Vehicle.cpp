#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
using namespace std;
class Basic{
	protected:
		int id,year;
		char brand[20],model[20],type[20],plate[20];
	public:
		int getId(){
			return id;
		}
		int getYear(){
			return year;
		}
		char *getBrand(){
			return brand;
		}
		void setId(int i){
			id = i;
		}
		void setYear(int y){
			year = y;
		}
		void setBrand(char b[20]){
			strcpy(brand,b);
		}
		void setModel(char m[20]){
			strcpy(model,m);
		}
		void setType(char t[20]){
			strcpy(type,t);
		}
		void setPlate(char p[20]){
			strcpy(plate,p);
		}
		void input(){
			cout << "ID     : "; cin >> id ; cin.ignore();
			cout << "PLATE  : "; cin.getline(plate,20);
			cout << "BRAND  : "; cin.getline(brand,20);
			cout << "MODEL  : "; cin.getline(model,20);
			cout << "TYPE   : "; cin.getline(type,20);
			cout << "YEAR   : "; cin >> year; cin.ignore();	
		}
		void output(){
			cout << "|"
				 << setw(5)  << id
				 << setw(12) << plate
				 << setw(12) << brand
				 << setw(12) << model
				 << setw(11) << type
				 << setw(11) << year;
		}
};
class Feature{
	protected:
		char color[20];
		int seat,door;
	public:
		void setColor(char c[20]){
			strcpy(color,c);
		}
		void setSeat(int s){
			seat = s;
		}
		void setDoor(int d){
			door = d;
		}
		void input(){
			cout << "COLOR  : "; cin.getline(color,20);
			cout << "NUMBER OF SEATS : "; cin >> seat;
			cout << "NUMBER OF DOORS : "; cin >> door;
		}
		void output(){
			cout << setw(12) << color
				 << setw(11) << seat
				 << setw(11) << door;
		}
};
class General{
	protected:
		char engine[20];
		double horsepower,fuelCapacity,price;
	public:
		double getPrice(){
			return price;
		}
		void setEngine(char e[20]){
			strcpy(engine,e);
		}
		void setHorse(double horse){
			horsepower = horse;
		}
		void setFuel(double fuel){
			fuelCapacity = fuel;
		}
		void setPrice(double pri){
			price = pri;
		}
		void input(){
			cout << "ENGINE TYPE     : "; cin.ignore(); cin.getline(engine,20);
			cout << "HORSE POWER     : "; cin >> horsepower;
			cout << "FUEL CAPACITY   : "; cin >> fuelCapacity;
			cout << "PRICE           : "; cin >> price;
		}
		void output(){
			cout << setw(13) << engine
				 << setw(9) << horsepower
				 << setw(11) << fuelCapacity
				 << setw(12) << price << " $" << "   |";
		}
		void updatePrice(){
			price+=(price*0.1);
		}
};
class Vehicle:public Basic , public Feature , public General{
	private:
		char seller[20],buyer[20],cashier[20];
		double sprice,payment;
	public:
		void input(){
			Basic::input();
			Feature::input();
			General::input();
		}
		static void header(){
			cout << "=====================================================================================================================================================" << endl;
			cout << "|" 
				 << setw(5) << "ID"     << setw(4) << "|"
				 << setw(8) << "PLATE"  << setw(4) << "|"
				 << setw(8) << "BRAND"  << setw(4) << "|"
				 << setw(8) << "MODEL"  << setw(4) << "|"
				 << setw(7) << "TYPE"   << setw(4) << "|"
				 << setw(7) << "YEAR"   << setw(4) << "|"
				 << setw(8) << "COLOR"  << setw(4) << "|"
				 << setw(7) << "SEAT"   << setw(4) << "|"
				 << setw(7) << "DOOR"   << setw(4) << "|"
				 << setw(9) << "ENGINE" << setw(4) << "|"
				 << setw(5) << "HP"     << setw(4) << "|"
				 << setw(7) << "FUEL"   << setw(4) << "|"
				 << setw(8) << "PRICE"   << " $"<< setw(4) << "|" << endl;
			cout << "=====================================================================================================================================================" << endl;
		}
		void output(){
			Basic::output();
			Feature::output();
			General::output();
			cout << endl;
		}
		void setSell(char s[20],char b[20],char c[20],double p){
			strcpy(seller,s);
			strcpy(buyer,b);
			strcpy(cashier,c);
			sprice  = p;
			payment=price+(price*0.1);
		}
		void saleOutput(){
			Vehicle::output();
			cout << "|---------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| PRICE      " << setw(130) << sprice  << " $" << "   |" << endl;
			cout << "| TAX        " << setw(130) << "10"    << " %" << "   |" << endl;
			cout << "| PAYMENT    " << setw(130) << payment << " $" << "   |" << endl;
			cout << "| CUSTOMER   " << setw(130) << buyer   << "     |" << endl;
			cout << "| CASHIER    " << setw(130) << cashier << "     |" << endl;
		}
		friend void receipt(Vehicle);
};
class Employee{
	private:
		int id;
		char name[20],gender[20],position[20];
		double salary;
	public:
		Employee(){
			id       = 0;
			strcpy(name,"null");
			strcpy(gender,"null");
			strcpy(position,"null");
			salary   = 0;
		}
		Employee(int i,const char* n,const char* g,const char* p,double s){
			id = i;
			strcpy(name,n);
			strcpy(gender,g);
			strcpy(position,p);
			salary = s;
		}
		void input(){
			cout << "INPUT EMPLOYEE INFORMATION" << endl;
			cout << "ID       : "; cin >> id; cin.ignore();
			cout << "NAME     : "; cin.getline(name,20);
			cout << "GENDER   : "; cin.getline(gender,20);
			cout << "POSITION : "; cin.getline(position,20);
			cout << "SALARY   : "; cin>>salary;
		}
		static void header(){
			cout << "=========================================================================" << endl;
			cout << "|" << setw(5) << "ID" << setw(4) << "|"
				 << setw(13) << "LAST NAME"<< setw(5) << "|"
				 << setw(9) << "GENDER"   << setw(4) << "|"
				 << setw(11) << "POSITION" << setw(4) << "|"
				 << setw(9) << "SALARY" << " ($)" << setw(4) << "|" << endl;
			cout << "=========================================================================" << endl;
		}
		void output(){
			cout << "|";
			cout << setw(5) << id
				 << setw(17) << name
				 << setw(14) << gender
				 << setw(15) << position
				 << setw(13) << salary << "  $ " << setw(4) << "|" << endl;
		}
};
class auth{
	private: 
		char username[20];
		char password[20];
	public:
		char *getName(){
			return username;
		}
		char *getPass(){
			return password;
		}
		bool reg(){
			cout << " : REGISTER PAGE :" << endl;
			cout << "USERNAME : "; cin >> username;
			cout << "PASSWORD : ";
			int n=0;
			do{
				password[n] = getch();
				if(password[n] != '\r' || password[n] != '\b'){
					cout << "*";
				}
					n++;
			}while(password[n-1] != '\r');
			password[n-1] = '\0';
			char cfpass[20];
			n=0;
			cout << "\nCONFIRM PASSWORD : ";
			do{
				cfpass[n] = getch();
				if(cfpass[n] != '\r' || cfpass[n] != '\b'){
					cout << "*";
				}
					n++;
			}while(cfpass[n-1] != '\r');
			cfpass[n-1] = '\0';
			if(strcmp(password,cfpass)==0){
				return true;
			}else {
				return false;
			}
		}
};
void menu(){
	cout << "==========================< MENU >===========================" << endl;
	cout << "1. NEW VEHICLE		2. DISPLAY		3. SEARCH\n"
	     << "4. MODIFY		5. DELETE		6. SORT\n"
	     << "7. SELL VEHICLE		8. SALE HISTORY		9. EMPLOYEES\n"
	     << "10.CLEAR ALL		11.SIGN OUT		12.EXIT" << endl;
}
int menuModify(){
	int op;
	cout << "WHICH OPTION DO YOU WANT TO MODIFY?" << endl;
	cout << "1. MODIFY ID\n"
		 << "2. MODIFY PLATE ID\n"
		 << "3. MODIFY BRAND\n"
		 << "4. MODIFY MODEL\n"
		 << "5. MODIFY TYPE\n"
		 << "6. MODIFY YEAR\n"
		 << "7. MODIFY COLOR\n"
		 << "8. MODIFY SEAT\n"
		 << "9. MODIFY DOOR\n"
		 << "10.MODIFY ENGINE\n"
		 << "11.MODIFY HORSE POWER\n"
		 << "12.MODIFY FUEL CAPACITY\n"
		 << "13.MODIFY PRICE\n"
		 << "14.MODIFY ALL\n"
		 << "15.EXIT MODIFY"<< endl;
	cout << "CHOOSE ONE OPTION : "; cin >> op; cin.ignore();
	return op;
}
void receipt(Vehicle v){
	cout << "================================" << endl;
	cout << "|       VEHICLE INVOICE        |" << endl;
	cout << "|==============================|" << endl;
	cout << "| FROM COMPANY : " <<setw(13) << v.seller<< " |" << endl;
	cout << "| BILLED TO    : " <<setw(13) << v.buyer << " |" << endl;
	cout << "| CASHIER      : " <<setw(13) << v.cashier << " |" << endl;
	cout << "|==============================|" << endl;
	cout << "| VEHICLE ID   : " << setw(13) << v.id           << " |" << endl;
	cout << "| PLATE NUMBER : " << setw(13) << v.plate        << " |" << endl;
	cout << "| BRAND        : " << setw(13) << v.brand        << " |" << endl;
	cout << "| MODEL        : " << setw(13) << v.model        << " |" << endl;
	cout << "| TYPE         : " << setw(13) << v.type         << " |" << endl;
	cout << "| YEAR         : " << setw(13) << v.year         << " |" << endl;
	cout << "| COLOR        : " << setw(13) << v.color        << " |" << endl;
	cout << "| SEATS        : " << setw(13) << v.seat         << " |" << endl;
	cout << "| DOORS        : " << setw(13) << v.door         << " |" << endl;
	cout << "| EGINE        : " << setw(13) << v.engine       << " |" << endl;
	cout << "| HORSEPOWER   : " << setw(13) << v.horsepower   << " |" << endl;
	cout << "| FUEL CAPACITY: " << setw(13) << v.fuelCapacity << " |" << endl;
	cout << "|==============================|" << endl;
	cout << fixed << setprecision(2);
	cout << "| PRICE        : " << setw(11) << v.price << " $"       << " |" << endl;
	cout << "| TAX          : " << setw(11) << "10" << " %"   << " |" << endl;
	cout << "| TOTAL PRICE  : " << setw(11) << v.payment << " $" << " |" << endl;
	cout << fixed << setprecision(0);
	cout << "================================" << endl;
}

bool sort(fstream& file,fstream& temp){
	Vehicle veh,arr[100],ttemp,sort;
	int i,j,n,op;
	bool check;
	while(file.read((char*)&veh,sizeof(Vehicle))){
		arr[n]=veh;
		n++;
	}
	cout << "SORT WILL BE ORDERED BY : " << endl;
	cout << "1. ID\n"
		 << "2. BRAND NAME\n"
		 << "3. YEAR\n"
		 << "4. PRICE\n" 
		 << "5. STOP SORTING"<< endl;
	cout << "INPUT YOUR OPTION HERE : "; cin >> op; cin.ignore();
	check = true;
	switch (op){
		case 1:
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if((arr[i].getId())>(arr[j].getId())){
						ttemp=arr[i];
						arr[i]=arr[j];
						arr[j]=ttemp;
					}
				}
				sort = arr[i];
				temp.write((char*)&sort,sizeof(Vehicle));
			}
			cout << "SORT COMPLETED" << endl;
			break;
		case 2:
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if(strcmp(arr[i].getBrand(),arr[j].getBrand())>0){
						ttemp=arr[i];
						arr[i]=arr[j];
						arr[j]=ttemp;
					}
				}
				sort = arr[i];
				temp.write((char*)&sort,sizeof(Vehicle));
			}
			cout << "SORT COMPLETED" << endl;
			break;
		case 3:
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if((arr[i].getYear())>(arr[j].getYear())){
						ttemp=arr[i];
						arr[i]=arr[j];
						arr[j]=ttemp;
					}
				}
				sort = arr[i];
				temp.write((char*)&sort,sizeof(Vehicle));
			}
			cout << "SORT COMPLETED" << endl;
			break;
		case 4:
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if((arr[i].getPrice())>(arr[j].getPrice())){
						ttemp=arr[i];
						arr[i]=arr[j];
						arr[j]=ttemp;
					}
				}
				sort = arr[i];
				temp.write((char*)&sort,sizeof(Vehicle));
			}
			cout << "SORT COMPLETED" << endl;
			break;
		default :
			check = false ;
			if(op!=5) cout << "INVALID OPTION" << endl;	
	}
	return check;
}
int main(){
	Vehicle veh;
	auth a;
	Employee emp1(777,"SOVANNDA","MALE","CEO",900);
	Employee emp2(101,"NADEAN","MALE","MANAGER",600);
	Employee emp3(102,"SONGHAK","MALE","MECHANIC",600);
	Employee emp4(103,"SOVANN","MALE","ENGINEER",500);
	Employee emp5(104,"VISAL","MALE","DRIVER",500);
	Employee emp6(105,"VORNEATH","FEMALE","ACCOUNTANT",450);
	Employee emp7(106,"KHEMARITA","FEMALE","DESIGNER",600);
	Employee emp;
	double price;
	int carcount,carsellcount,empcount;
	int n=0,ns=0,op=0,m,ne,i,j,k,sid;
	bool check;
	char buyer[20],cashier[20];
	char company[20] = "V4 COMPANY";
	fstream file,filesell,temp,fileemp,auth;
	int modifyOp,accOp;
	int intSet;
	char charSet[20];
	double doubleSet;
	bool status;
	char user[20], pass[20];
	int numofLogin =0;
	signout:
	do{
		system("cls");
		if(numofLogin==3){
			cout << "YOU CANT LOGIN RIGHT NOW\n"
				 << "TRY AGAIN LATER" << endl;
			exit(0);
		}
		cout << "\tTO ACCESS THE PROGRAM\n";
		cout << "YOU HAVE TO LOGIN OR REGISTER AN ACCOUNT" << endl;
		cout << "1. LOGIN\n"
			 << "2. REGISTER\n"
			 << "3. EXIT" << endl; 
		cout << "TYPE IN ONE OPTION : "; cin >> accOp; cin.ignore();
		if(accOp!=3) system("cls");
		switch(accOp){
			case 1:
				status = false;
				auth.open("acc.bin",ios::in|ios::binary);
				if(!auth || auth.peek() == EOF){
					cout << "YOU MUST REGISTER FIRST" << endl;
				}else{
					cout << " : LOG IN PAGE :" << endl;
					cout << "USERNAME : "; cin >> user;
					cout << "PASSWORD : ";
					int n=0;
					do{
						pass[n] = getch();
						if(pass[n] != '\r' || pass[n] != '\b'){
							cout << "*";
						}
							n++;
					}while(pass[n-1] != '\r');
					pass[n-1] = '\0';
					auth.read((char*)&a,sizeof(auth));
					if(strcmp(user,a.getName())==0 && strcmp(pass,a.getPass())==0){
						cout << "\nLOG IN SUCCESS" << endl;
						usleep(900000);
						status = true;
						numofLogin =0;
					}else {
						cout << "\nINCORRECT USERNAME OR PASSWORD" << endl;
						numofLogin++;
						getch();
					}
						
				}
				auth.close();
				break;
			case 2:
				status = false;
				auth.open("acc.bin",ios::out|ios::binary);
				if(!auth){
					cout << "ERROR IN CREATING FILE" << endl;
					exit(0);
				}else{
					if(a.reg()){
						auth.write((char*)&a,sizeof(auth));
						cout << "\nREGISTER SUCCESS" << endl;
						usleep(900000);
						status = true;
						numofLogin =0;
					}else{
						numofLogin++;
						cout << "\nINCORRECT INPUT" << endl;
						getch();
					}
				}
			default:
				if(accOp==3){
					exit(0);
				}else{
					cout << "INVALID OPTION" << endl;
				}
				auth.close();
				break;	
		}
		
	}while (status != true);
	
	do{
		system("cls");
		menu();
		cout << "INPUT YOUR OPTION [1-12] : "; cin >> op;
		if (op!=12) system("cls");
		switch(op){
			case 1:
				file.open("vehicles.bin",ios::in|ios::binary);
				carcount=0;
				if(file || file.peek() == EOF){
					while(file.read((char*)&veh,sizeof(Vehicle))){
						carcount++;
					}
				}
				file.close();
				file.open("vehicles.bin",ios::app|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				cout << "INPUT THE NUMBER OF VEHICLES : "; cin >> n;
				for (i=0;i<n;i++){
					cout << "====< VEHICLE [" << ++carcount << "] >====" << endl;
					veh.input();
					file.write((char*)&veh,sizeof(Vehicle));
				}
				file.close();
				break;
			case 2:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else {
					cout << "=====================================================================================================================================================" << endl;
					cout << "|                                                                 VEHICLES IN GARAGE                                                                |" << endl;
					Vehicle::header();
					int count = 0;
					while(file.read((char*)&veh,sizeof(Vehicle))){
						veh.output();
						count ++;
					}
					cout << "=====================================================================================================================================================" << endl;
					cout << "TOTAL VEHICLES IN THE GARAGE : " << count;
				}
				file.close();
				break;
			case 3:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				check = false;
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else{
					cout << "TYPE IN THE ID TO SEARCH : "; cin >> sid;
					while(file.read((char*)&veh,sizeof(veh))){
						if(sid==veh.getId()){
							Vehicle::header();
							veh.output();
							cout << "=====================================================================================================================================================" << endl;
							check = true;
						}
					}
					if(!check) cout << "SEARCH NOT FOUND";	
				}
				file.close();
				break;
			case 4:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				temp.open("temp.bin",ios::out|ios::binary);
				if(!temp){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				check = false;
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else{
					cout << "TYPE IN THE ID TO SEARCH FOR MODIFY : "; cin >> sid;
					while(file.read((char*)&veh,sizeof(veh))){
						if(sid==veh.getId()){
							Vehicle::header();
							veh.output();
							cout << "=====================================================================================================================================================" << endl;
							modifyOp = menuModify();
							switch(modifyOp){
								case 1:
									cout << "TYPE IN NEW ID : "; cin >> intSet; cin.ignore();
									veh.setId(intSet);
									break;
								case 2:
									cout << "TYPE IN NEW PLATE ID : "; cin.getline(charSet,20);
									veh.setPlate(charSet);
									break;
								case 3:
									cout << "TYPE IN NEW BRAND : "; cin.getline(charSet,20);
									veh.setBrand(charSet);
									break;
								case 4:
									cout << "TYPE IN NEW MODEL : "; cin.getline(charSet,20);
									veh.setModel(charSet);
									break;
								case 5:
									cout << "TYPE IN NEW TYPE OF VEHICLE : "; cin.getline(charSet,20);
									veh.setType(charSet);
									break;
								case 6:
									cout << "TYPE IN NEW YEAR OF VEHICLE : "; cin >> intSet; cin.ignore();
									veh.setYear(intSet);
									break;
								case 7:
									cout << "TYPE IN NEW COLOR OF VEHICLE : "; cin.getline(charSet,20);
									veh.setColor(charSet);
									break;
								case 8:
									cout << "TYPE IN NEW SEAT OF VEHICLE : "; cin >> intSet; cin.ignore();
									veh.setSeat(intSet);
									break;
								case 9:
									cout << "TYPE IN NEW DOOR OF VEHICLE : "; cin >> intSet; cin.ignore();
									veh.setDoor(intSet);
									break;
								case 10:
									cout << "TYPE IN NEW ENGINE : "; cin.getline(charSet,20);
									veh.setEngine(charSet);
									break;
								case 11:
									cout << "TYPE IN NEW VALUE OF HORSEPOWER : "; cin >> doubleSet;
									veh.setHorse(doubleSet);
									break;
								case 12:
									cout << "TYPE IN NEW VALUE OF FUEL CAPACITY : "; cin >> doubleSet;
									veh.setFuel(doubleSet);
									break;
								case 13:
									cout << "TYPE IN NEW PRICE : "; cin >> doubleSet;
									veh.setPrice(doubleSet);
									break;
								case 14:
									cout << "INPUT NEW INFORMATION" << endl;
									veh.input();
									break;
								default: if(modifyOp!=15) cout << "INVALID OPTOIN" << endl;
							}
							temp.write((char*)&veh,sizeof(Vehicle));
							if(modifyOp >=1 && modifyOp <=14){
								cout << "MODIFY COMPLETED" << endl;
								check = true;
							}
						}else{
							temp.write((char*)&veh,sizeof(Vehicle));
						}
					}
					if(!check && modifyOp !=15) cout << "SEARCH NOT FOUND";	
				}
				file.close();
				temp.close();
				remove("vehicles.bin");
				rename("temp.bin","vehicles.bin");
				break;
			case 5:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				temp.open("temp.bin",ios::out|ios::binary);
				if(!temp){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				check = false;
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else{
					cout << "TYPE IN THE ID TO SEARCH : "; cin >> sid;
					while(file.read((char*)&veh,sizeof(veh))){
						if(sid==veh.getId()){
							Vehicle::header();
							veh.output();
							cout << "=====================================================================================================================================================" << endl;
							check = true;
							cout << "THIS RECORD IS DELETED" << endl;
						}
						else{
							temp.write((char*)&veh,sizeof(Vehicle));	
						}
					}
					if(!check) cout << "SEARCH NOT FOUND";	
				}
				file.close();
				temp.close();
				remove("vehicles.bin");
				rename("temp.bin","vehicles.bin");
				break;
			case 6:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				temp.open("temp.bin",ios::out|ios::binary);
				if(!temp){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else{
					check = sort(file,temp);
				}
				file.close();
				temp.close();
				if(check){
					remove("vehicles.bin");
					rename("temp.bin","vehicles.bin");
				}else{
					remove("temp.bin");
				}
				break;
			case 7:
				file.open("vehicles.bin",ios::in|ios::binary);
				if(!file){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				temp.open("temp.bin",ios::out|ios::binary);
				if(!temp){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				filesell.open("sellvehicles.bin",ios::app|ios::binary);
				if(!filesell){
					cerr << "ERROR CREATING FILE" << endl;
					exit(0);
				}
				check = false;
				if(file.peek() == EOF){
					cout << "THE VEHICLE IS EMPTY" << endl;
				}else{
					cout << "TYPE IN THE ID TO SEARCH FOR SELL : "; cin >> sid;
					while(file.read((char*)&veh,sizeof(veh))){
						if(sid==veh.getId()){
							Vehicle::header();
							veh.output();
							cout << "=====================================================================================================================================================" << endl;
							cout << "PRICE FOR SELL            : "; cin >> price;
							cout << "THE CAR WILL BE BILLED TO : "; cin.ignore();cin.getline(buyer,20);
							cout << "CASHIER'S NAME            : "; cin.getline(cashier,20);
							cout << "WAIT FOR THE RECEIPT";
							for (k=0;k<3;k++){
								if(k==0){
									system("Color 4");	
								}else if(k==1){
									system("Color 6");
								}else if(k==2){
									system("Color 2");
								}
								cout << ".";
								usleep(900000);
							}
							system("Color 7");
							system("cls");
							veh.setSell(company,buyer,cashier,price);
							receipt(veh);
							check = true;
							filesell.write((char*)&veh,sizeof(Vehicle));
						}else{
							temp.write((char*)&veh,sizeof(Vehicle));
						}
					}
					if(!check) cout << "SEARCH NOT FOUND";
				}
				file.close();
				filesell.close();
				temp.close();
				remove("vehicles.bin");
				rename("temp.bin","vehicles.bin");
				break;
			case 8:
				filesell.open("sellvehicles.bin",ios::in|ios::binary);
				if(!filesell || filesell.peek() == EOF){
					cerr << "ERROR CREATING FILE" << endl;
					cout << "NO SALES HISTORY" << endl;
				}else{
					carsellcount=0;
					cout << "=====================================================================================================================================================" << endl;
					cout << "|                                                                    SALES HISTORY                                                                  |" << endl;
					Vehicle::header();
					while(filesell.read((char*)&veh,sizeof(Vehicle))){
						veh.saleOutput();
						carsellcount++;
						cout << "=====================================================================================================================================================" << endl;
					}
					cout << "TOTAL VEHICLES SOLD OUT : " << carsellcount;
				}
				filesell.close();
				break;
			case 9:
				Employee::header();
				emp1.output();
				emp2.output();
				emp3.output();
				emp4.output();
				emp5.output();
				emp6.output();
				emp7.output();
				fileemp.open("employees.bin",ios::in|ios::binary);
				empcount=7;
				while(fileemp.read((char*)&emp,sizeof(Employee))){
					emp.output();
					empcount++;
				}
				fileemp.close();
				cout << "=========================================================================" << endl;
				cout << "TOTAL EMPLOYEES : " << empcount << endl;
				cout << "DO YOU WANT TO ADD MORE EMPLOYEES? [Y/N] : ";
				switch(getch()){
					case 'Y':
					case 'y':
						filesell.open("employees.bin",ios::app|ios::binary);
						cout << "\nINPUT THE NUMBER OF EMPLOYEES : "; cin >> ne;
						for(i=0;i<ne;i++){
							emp.input();
							filesell.write((char*)&emp,sizeof(Employee));
						}
						filesell.close();
					break;
				}
				break;
			case 10:
				remove("vehicles.bin");
				remove("sellvehicles.bin");
				remove("employees.bin");
				cout << "ALL DATA ARE CLEARED" << endl;
				break;
			case 11: 
				goto signout;
				break;
			default:
				if(op==12) return 0;
				cout << "INVALID OPTION..." << endl;
		}
		cout << "\nPRESS [Esc] TO EXIT...";	
	}while(getch()!=27);
	return 0;
}
