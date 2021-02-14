#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char* xyDecToHex(int Value)          // Wandeln X,Y-Decimal zu HEX um
{
    char *CharRes = new (char);
    sprintf(CharRes, "%X", Value);
	
	char *CharRes2 = new (char);
	
	if(Value > -1 && Value < 16){
		
		*CharRes2 = *CharRes;
		*CharRes = 48;
		CharRes++;
		*CharRes = 48;
		CharRes++;
		*CharRes = *CharRes2;
		CharRes++;
		*CharRes='\0';
		CharRes -= 3;
		
	}else if(Value > 15 && Value < 256){
		
		*CharRes2 = *CharRes;
		CharRes++;
		CharRes2++;
		*CharRes2 = *CharRes;
		CharRes--;
		CharRes2--;
		*CharRes = 48;
		CharRes++;
		*CharRes = *CharRes2;
		CharRes++;
		CharRes2++;
		*CharRes = *CharRes2;
		CharRes++;
		*CharRes='\0';
		CharRes -= 3;
	}
	return CharRes;
}

char* rgbDecToHex(int Value)       // Wandeln R,G,B-Decimal zu HEX um
{
    char *CharRes = new (char);
    sprintf(CharRes,"%X", Value);
	
	char *CharRes2 = new (char);
	
	if(Value > -1 && Value < 16){
		
		*CharRes2 = *CharRes;
		*CharRes = 48;
		CharRes++;
		*CharRes = *CharRes2;
		CharRes++;
		*CharRes='\0';
		CharRes -= 2;
	}
    
	return CharRes;
}

string hexAll(int x,int y,int red,int green,int blue){  // X,Y,R,G,B-Werte zusammenfügen
	
	string hexall= "";
	
	string strx = xyDecToHex(x);
	string stry = xyDecToHex(y);
	string strred = rgbDecToHex(red);
	string strgreen = rgbDecToHex(green);
	string strblue = rgbDecToHex(blue);
	
	hexall = strx+stry+strred+strgreen+strblue;
	
	return hexall;
}

string hexXY(int x,int y){  // X,Y-Werte zusammenfügen
	
	string hexxy= "";
	
	string strx = xyDecToHex(x);
	string stry = xyDecToHex(y);
	
	hexxy = strx+stry;
	
	return hexxy;
}

void sendhexAllToSwing(int x,int y,int red,int green,int blue){  // Schicken die X,Y,R,G,B-Werte nach Java-Swing
	
   cout<<hexAll(x,y,red,green,blue)<<"\n";
   cout.flush();
   
}

void sendhexXYToSwing(int x,int y){   // Schicken die X,Y-Werte nach Java-Swing

   cout<<hexXY(x,y)<<"\n";
   cout.flush();
	
}

void setPixel(int x,int y,int red,int green,int blue){
	
sendhexAllToSwing(x,y,red,green,blue);

}

std::string getPixel(int x,int y){
	
sendhexXYToSwing(x,y);

string rgb;

cin>>rgb;

cout<<rgb<<"\n";

return rgb;

}

int getJPanelWidth(){
	
int width = 0;
	
cout<<"W"<<"\n";
	
string line;

cin>>line;

width = stoi(line);

return width;
	
}

int getJPanelHeight(){
	
int height = 0;
	
cout<<"H"<<"\n";
	
string line;

cin>>line;

height = stoi(line);

return height;
	
}
