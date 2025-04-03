#include<iostream>
#include<string>

using namespace std;


class Sensor{
	protected :
		string name;
		string mdl;
		int life;
		int time;
		int sugar_value;
		
		public :
			Sensor(string nam, string mod, int lif, int tim, int value) : name(nam), mdl(mod) , life(lif), time(tim), sugar_value(value){
			}
			
			virtual void checkBloodSugarLevel()=0;
			
			virtual void displayRemainingUsage(){
				int remain = life - time;
				if(remain>0){
					cout << "Remaining usage days : " << remain << " days\n"<<endl;
				}
				else cout << "You should buy a new one! This one is finished\n" << endl;
			}
			void getInfo(){
			cout << name << "'s Blood Sugar Check :" <<endl;
			cout << "Sensor Model : " << mdl <<endl;
			cout <<"Testing with blood sugar : " << sugar_value <<endl;
			checkBloodSugarLevel();
			displayRemainingUsage();
			
		    }
			virtual ~Sensor(){
				cout <<"sensor destructed for " << name <<endl;
			}
			
			void Set_name(string nam){
				name=nam;
			}
			void Set_mdl(string mod){
				mdl=mod;
			}
			void Set_life(int lif){
				life=lif;
			}
			void Set_time(int tim){
				time=tim;
			}
			void Set_value(int value){
				sugar_value = value;
			}
			
			
	
};

class Dexcom : public Sensor{
	public :
		Dexcom(string nam,string mod ,int lif, int tim, int value) : Sensor(nam,mod,lif,tim,value){
			
		}
		void checkBloodSugarLevel() {
			if(sugar_value<60){
				cout << "Critical low blood sugar!" << endl;
				}
				else if(sugar_value<=110){
					cout <<"Normal blood sugar."<<endl;
				}
				else cout << "High blood sugar!"<<endl ;
		}
		void displayRemainingUsage() {
				int remain = life - time + 10;
					if(remain>0){
					cout << "Remaining usage days : " << remain << " days\n"<<endl;
				}
				else cout << "You should buy a new one! This one is finished.\n" << endl;
				
			}
};

class Abbot : public Sensor{
	public:
	Abbot(string nam, string mod ,int lif, int tim, int value) : Sensor(nam,mod,lif,tim,value){
	}
	void checkBloodSugarLevel() {
			if(sugar_value<80){
				cout << "Critical low blood sugar!"<<endl;
				}
				else if(sugar_value<=130){
					cout <<"Normal blood sugar."<<endl;
				}
				else cout << "High blood sugar!"<<endl;
		}
		void displayRemainingUsage()  {
				int remain = life - time + 7;
					if(remain>0){
					cout << "Remaining usage days : " << remain << " days\n"<<endl;
				}
				else cout << "You should buy a new one! This one is finished.\n" << endl;
		}
		
	
};

class Medtrum : public Sensor{
	public:
	Medtrum (string nam, string mod,int lif, int tim, int value) : Sensor(nam,mod,lif,tim,value){
	}
	void checkBloodSugarLevel() {
			if(sugar_value<75){
				cout << "Critical low blood sugar!";
				}
				else if(sugar_value<=120){
					cout <<"Normal blood sugar." << endl;
				}
				else cout << "High blood sugar!";
		}
		void displayRemainingUsage() {
				int remain = life - time +5;
					if(remain>0){
					cout << "Remaining usage days : " << remain << " days\n"<<endl;
				}
				else cout << "You should buy a new one! This one is finished.\n" << endl;
		}
		
};

int main(){
	int i;
	Sensor *sens[3];
	
	sens[0] = new Dexcom("Naz","G7",55,50,120);
	sens[1] = new Abbot("Gizem","Libre2",70,63,75);
	sens[2] = new Medtrum("Yaren","S7-960",40,35,110);
	
	for(i=0; i<3; i++){
		sens[i]->getInfo();
	}
	
	for(i=0; i<3; i++){
		delete sens[i];
	}
	
	
}







