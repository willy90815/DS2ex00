#include<stdio.h> 
#include<iostream>
#include<string.h>
#include<cstdlib> 
#include<vector>
#include<fstream>
using namespace std;


typedef struct collegeType{
	string fullName;
	int gNo; 
	
} cT;


class college{

	ifstream toRead;
	ofstream toWrite;

	public:
	vector<collegeType> aList;
	string token;

	string fileNameNum;

	bool openFile(){
		cout << endl << "Input 601, 602, ...[0]Quit):" ;
		string filename ;
		cin >> filename ;
		
		if(filename.compare("0") == 0)
		{
			return false;
		
		}
		
		fileNameNum = filename;
		
		
		filename.insert(0,"input");
		filename.operator+=(".txt");
		
		toRead.open(filename.c_str(), ifstream::in);
		
		if(!toRead.is_open()){
			cout << endl << "###" << filename <<" does not exist! ###" ;
			return openFile();
			
		} // if
		
		else{
			
			Skip();
			
			
			
			
			while(!toRead.eof()){
				cT collegeData;
				
				ReadLine(collegeData);
				
				
				if( collegeData.fullName.compare("\n")==0)
					return true;
				if(collegeData.fullName.compare("")!=0)
					aList.push_back(collegeData);
				
				
				
				
			} // while
			
			
			toRead.close();
			
			return true;

		} // else
		
	} // open File
	
	SaveFile(){
    	string filename;
      	filename = "output";

    	filename.operator+=(fileNameNum + ".txt" );
    	toWrite.open(filename.c_str());
    	
    	
    	
    	for( int y = 0 ; y < aList.size() ; y++ ){
    		toWrite << aList[y].fullName;
		} // for
    	

    	
    	toWrite.close();

	} // SaveFile
	
	
	
	
	InsertSort(){
		
		for(int y = 0; y<aList.size();y++){
			
			for(int x = y; x >=0 ; x-- ){
				
				if( aList[y].gNo<aList[x].gNo ){
					Swap(aList[x],aList[y]);
					y--;
				} // if 
			} // for
			if(y%5000 == 0)
			cout<<y<<endl;
		} // for
		
		cout <<endl <<aList.size();
	
	
	} // InsertSort

	
	private:
	void ReadLine(cT &collegeData){
		
		int counter = 0;
		token = "";
		while(token [token.length()-1] != '\n'&& !toRead.eof()){
			
			counter++;
			getToken();
			
			if( counter == 9 ){
				collegeData.gNo = atoi(token.c_str());
			} // if
			
			if(toRead.eof() && token[token.length()-1] != '\n'){
				token.operator+=("\n");
			} // if	
			
			collegeData.fullName.operator+=(token);
			
		} // while
	} //Read Line
	
	void getToken(){
		char ch = '\0';
		token = "";
		
			
		
		while(ch !='\t'&& ch != '\n'&& !toRead.eof()){
			ch = toRead.get();
			token.operator+=(ch);
		} // while
		
		

		
	} // getToken
	
	void Skip( ){
		char ch = '\n';
		for( int y = 0; y<3 ; y){
			toRead.get(ch);
			if( ch == '\n')
				y++;
		} // for
	} // Skip
	
	
	void Swap(cT& C1 ,cT &C2 ){
		cT temp;
		temp = C1;
		C1 = C2;
		C2 = temp;

	} // Swap
	
	
};

int main(void){
	int command;
	college thisFile; 
	
	do{
		cout<<endl<<"******************************";
		cout<<endl<<"*0.Quit.                     *"; 
		cout<<endl<<"*1.Insert Sort               *";
		cout<<endl<<"*2.Merge Sort                *";
		cout<<endl<<"******************************"<<endl;
		cin >> command;
	
		switch(command){
			case 0: break;
			
			case 1: if(thisFile.openFile()) {
				thisFile.InsertSort();
				thisFile.SaveFile();
				thisFile.aList.clear();
				break;
			} // case 1
			
			case 2:if(thisFile.openFile()){
				thisFile.SaveFile();
				thisFile.aList.clear();
				break;
			} // case 2
			
		}	// switch
		
		
		
		
	} while(command!=0);
	
	
	
	
} // main
