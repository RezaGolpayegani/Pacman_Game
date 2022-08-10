#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <fstream>


using namespace std;
char tmp_map[30][90];

char map[30][90] = {
	"+#######################################################################################+",
	"|                                                                                       |",
	"|##############             #####################################           ############|",
	"|                                                                                       |",
	"|                                                                                       |",
	"|                                                                                       |",
	"|                                                                                       |",
	"|                                                                                       |",
	"|                                                                                       |",
	"|                                                                                       |",
    "|                                                                                       |",
	"|                                                                                       |",
	"|                  #######################################################              |",
	"|                                                                                       |",
	"|################################                       ################################|",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|                                                                                       |",
	"|                                          #                                            |",
	"|#######                   #################################                 ###########|",
	"|                                                                                       |",
	"+#######################################################################################+",
};

void ShowMap()
{
	for(int i = 0; i <30; i++) {
		printf("%s\n",map[i] );
	}
}

void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}

int randrange(int min,int max){
	int k;
	srand(k++);
	return (rand()%(max-min))+min;
}

int randrangenb(int min,int max){
	srand(time(0));
	return (rand()%(max-min))+min;
}



void move_B(short *x, short *y, short *direction)
{
	if(map[*y][*x + *direction] == ' ')
	{
		gotoxy(*x, *y);
		cout << " ";
		map[*y][*x]=' ';


		*x += *direction;
		gotoxy(*x, *y);
		cout << "B";
		map[*y][*x]='B';


	}//if
	else
	{
		*direction *= -1;
		if(map[*y][*x + *direction] == ' ')
		{
			gotoxy(*x, *y);
			cout << " ";
			map[*y][*x]=' ';


			*x += *direction;
			gotoxy(*x, *y);
			cout << "B";
			map[*y][*x]='B';


		}//if
	}//else
}//move B


void move_A(short *x, short *y, short *direction)
{
	if(map[*y+ *direction][*x ] == ' ')
	{
		gotoxy(*x, *y);
		cout << " ";
		map[*y][*x]=' ';


		*y += *direction;
		gotoxy(*x, *y);
		cout << "A";
		map[*y][*x]='A';


	}//if
	else
	{
		*direction *= -1;
		if(map[*y + *direction][*x] == ' ')
		{
			gotoxy(*x, *y);
			cout << " ";
			map[*y][*x]=' ';


			*y += *direction;
			gotoxy(*x, *y);
			cout << "A";
			map[*y][*x]='A';


		}//if
	}//else

}//move A

void move_C(short *x, short *y, short *direction)
{
		if(map[*y+ *direction][*x+ *direction] == ' ')
	{
		gotoxy(*x, *y);
		cout << " ";
		map[*y][*x]=' ';

		*x +=*direction;
		*y += *direction;
		gotoxy(*x, *y);
		cout << "C";
		map[*y][*x]='C';


	}//if
	else
	{
		*direction *= -1;
		if(map[*y + *direction][*x + *direction] == ' ')
		{
			gotoxy(*x, *y);
			cout << " ";
			map[*y][*x]=' ';

		    *x += *direction;
			*y += *direction;
			gotoxy(*x, *y);
			cout << "C";
			map[*y][*x]='C';


		}//if
	}//else

}//move_C





void start_and_init(){

bool running=true;
int x=1,y=1;
int oldx,oldy;

system("cls");
ShowMap();
gotoxy( x, y ); cout << "H";

//B tas->

int nb,i,j;
nb=randrangenb(5,15);
short xb[nb],yb[nb];

xb[0]=randrange(3,86);
yb[0]=randrange(2,28);
for(i=1;i<nb;i++){
	xb[i]=randrange(3,86);
	yb[i]=randrange(2,28);
	for(j=0;j<i;j++){
		if(xb[i]==xb[j])
		xb[i]=randrange(3,86);
		if(yb[i]==yb[j])
		yb[i]=randrange(2,28);
	}//for j
	if(map[yb[i]][xb[i]]=='#')
	{
	i--;
    continue;
	}//if
}//for i

for(i=0;i<nb;i++)
if(map[yb[i]][xb[i]]==' ')
{gotoxy( xb[i], yb[i] ); cout << "B";}

short b[nb];
for(i=0;i<nb;i++)
b[i]=1;




//A tas->
int na;
na=randrangenb(5,15);
short xa[na],ya[na];

xa[0]=randrange(3,86);
ya[0]=randrange(2,28);
for(i=1;i<na;i++){
	xa[i]=randrange(3,86);
	ya[i]=randrange(2,28);
	for(j=0;j<i;j++){
		if(xa[i]==xa[j])
		xa[i]=randrange(3,86);
		if(ya[i]==ya[j])
		ya[i]=randrange(2,28);
	}//for j
	if(map[ya[i]][xa[i]]=='#')
	{
	i--;
    continue;
	}//if
}//for i

for(i=0;i<na;i++)
if(map[ya[i]][xa[i]]==' ')
{gotoxy( xa[i], ya[i] ); cout << "A";}

short a[na];
for(i=0;i<na;i++)
a[i]=1;


//C tas->
int nc;
nc=randrangenb(5,15);
short xc[nc],yc[nc];

xc[0]=randrange(3,86);
yc[0]=randrange(2,28);
for(i=1;i<na;i++){
	xc[i]=randrange(3,86);
	yc[i]=randrange(2,28);
	for(j=0;j<i;j++){
		if(xc[i]==xc[j])
		xc[i]=randrange(3,86);
		if(yc[i]==yc[j])
		yc[i]=randrange(2,28);
	}//for j
	if(map[yc[i]][xc[i]]=='#')
	{
	i--;
    continue;
	}//if
}//for i

for(i=0;i<nc;i++)
if(map[yc[i]][xc[i]]==' ')
{gotoxy( xc[i], yc[i] ); cout << "C";}

short c[nc];
for(i=0;i<nc;i++)
c[i]=1;


short xs=95,ys=-1,ns=0;


char ch;
while(running){

ch=getch();
switch(ch)
{
	case 72:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y-1][x] ==' '){
			oldx=x;oldy=y;
			y--;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case1
	case 80:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
		    if(map[y+1][x] ==' '){
		    	oldx=x;oldy=y;
			y++;}
			gotoxy( x,y ); cout << "H";



		break;
	}//case2
	case 77:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y][x+1] ==' '){
			oldx=x;oldy=y;
			x++;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case3
	case 75:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y][x-1] ==' '){
				oldx=x;oldy=y;
			x--;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case4
	case 's':{
	ofstream myfile("save_game.txt");
	if(myfile.is_open()){

		        myfile<<nb<<" "<<na<<" "<<nc<<" "<<x<<" "<<oldx<<" "<<y<<" "<<oldy<<"\n";


		        for(i=0;i<nb;i++)
			    myfile<<xb[i]<<" ";
			    myfile<<"\n";

			    for(i=0;i<nb;i++)
		        myfile<<yb[i]<<" ";
			    myfile<<"\n";

			    for(i=0;i<nb;i++)
			    myfile<<b[i]<<" ";
			    myfile<<"\n";
		//for i nb

			    for(i=0;i<na;i++)
				myfile<<xa[i]<<" ";
				myfile<<"\n";

				for(i=0;i<na;i++)
				myfile<<ya[i]<<" ";
				myfile<<"\n";

				for(i=0;i<na;i++)
				myfile<<a[i]<<" ";
				myfile<<"\n";
		//for i na

			    for(i=0;i<nc;i++)
				myfile<<xc[i]<<" ";
				myfile<<"\n";

				for(i=0;i<nc;i++)
				myfile<<yc[i]<<" ";
				myfile<<"\n";

				for(i=0;i<nc;i++)
				myfile<<c[i]<<" ";
	    //for i nc

		myfile.close();
	}
	else cout<<"unable to open file";

		ys++;
		ns++;
		gotoxy( xs,ys ); printf("Game saved %d",ns);

		break;
	}//case 5 s

}//switch

if(y==28&&x==87)
{
	system("cls");
	printf("####**you win**####");
	break;
}

for(i=0;i<nb;i++){
if((x==xb[i]&&y==yb[i])||(oldx==xb[i]&&oldy==yb[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if
}//for i

for(i=0;i<na;i++){
if((x==xa[i]&&y==ya[i])||(oldx==xa[i]&&oldy==ya[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if
}//for i

for(i=0;i<nc;i++){
if((x==xc[i]&&y==yc[i])||(oldx==xc[i]&&oldy==yc[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if
}//for i

}//while

}//start_and_init


void load_and_init(){

	int x,y,oldx,oldy,i,nb,na,nc;

	string line;

	ifstream myfile("save_game.txt");
	if(myfile.is_open()){


		myfile>>nb>>na>>nc>>x>>oldx>>y>>oldy;

		short xb[nb],yb[nb],b[nb];
		short xa[na],ya[na],a[na];
		short xc[nc],yc[nc],c[nc];

		for(i=0;i<nb;i++)
		myfile>>xb[i];


		for(i=0;i<nb;i++)
		myfile>>yb[i];


		for(i=0;i<nb;i++)
		myfile>>b[i];


		for(i=0;i<na;i++)
		myfile>>xa[i];


		for(i=0;i<na;i++)
		myfile>>ya[i];


		for(i=0;i<na;i++)
		myfile>>a[i];


		for(i=0;i<nc;i++)
		myfile>>xc[i];


		for(i=0;i<nc;i++)
		myfile>>yc[i];


		for(i=0;i<nc;i++)
		myfile>>c[i];

		myfile.close();


	//load_init*************************************************************************************************
	bool running=true;

	system("cls");
    ShowMap();
    gotoxy( x, y ); cout << "H";

	for(i=0;i<nb;i++)
	{gotoxy( xb[i], yb[i] ); cout << "B";}

	for(i=0;i<na;i++)
	{gotoxy( xa[i], ya[i] ); cout << "A";}

	for(i=0;i<nc;i++)
	{gotoxy( xc[i], yc[i] ); cout << "C";}

	short xs=95,ys=-1,ns=0;


char ch;
while(running){

ch=getch();
switch(ch)
{
	case 72:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y-1][x] ==' '){
			oldx=x;oldy=y;
			y--;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case1
	case 80:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
		    if(map[y+1][x] ==' '){
		    	oldx=x;oldy=y;
			y++;}
			gotoxy( x,y ); cout << "H";



		break;
	}//case2
	case 77:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y][x+1] ==' '){
			oldx=x;oldy=y;
			x++;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case3
	case 75:{
		    for(i=0;i<nb;i++)
			move_B(&xb[i],&yb[i],&b[i]);

			for(i=0;i<na;i++)
			move_A(&xa[i],&ya[i],&a[i]);

			for(i=0;i<nc;i++)
			move_C(&xc[i],&yc[i],&c[i]);

		gotoxy( x, y ); cout << " ";
			if(map[y][x-1] ==' '){
				oldx=x;oldy=y;
			x--;}
			gotoxy( x,y ); cout << "H";


		break;
	}//case4
	case 's':{
	ofstream myfile("save_game.txt");
	if(myfile.is_open()){

		        myfile<<nb<<" "<<na<<" "<<nc<<" "<<x<<" "<<oldx<<" "<<y<<" "<<oldy<<"\n";


		        for(i=0;i<nb;i++)
			    myfile<<xb[i]<<" ";
			    myfile<<"\n";

			    for(i=0;i<nb;i++)
		        myfile<<yb[i]<<" ";
			    myfile<<"\n";

			    for(i=0;i<nb;i++)
			    myfile<<b[i]<<" ";
			    myfile<<"\n";
		//for i nb

			    for(i=0;i<na;i++)
				myfile<<xa[i]<<" ";
				myfile<<"\n";

				for(i=0;i<na;i++)
				myfile<<ya[i]<<" ";
				myfile<<"\n";

				for(i=0;i<na;i++)
				myfile<<a[i]<<" ";
				myfile<<"\n";
		//for i na

			    for(i=0;i<nc;i++)
				myfile<<xc[i]<<" ";
				myfile<<"\n";

				for(i=0;i<nc;i++)
				myfile<<yc[i]<<" ";
				myfile<<"\n";

				for(i=0;i<nc;i++)
				myfile<<c[i]<<" ";
	    //for i nc

		myfile.close();
	}
	else cout<<"unable to open file";

		ys++;
		ns++;
		gotoxy( xs,ys ); printf("Game saved %d",ns);

		break;
	}//case 5 s

}//switch

if(y==28&&x==87)
{
	system("cls");
	printf("####**you win**####");
	break;
}

for(i=0;i<nb;i++){
if((x==xb[i]&&y==yb[i])||(oldx==xb[i]&&oldy==yb[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if
}//for i

for(i=0;i<na;i++){
if((x==xa[i]&&y==ya[i])||(oldx==xa[i]&&oldy==ya[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if
}//for i

for(i=0;i<nc;i++){
if((x==xc[i]&&y==yc[i])||(oldx==xc[i]&&oldy==yc[i]))
{
	system("cls");
	printf("####**you lose**####");
	running=false;
}//if

}//for i

}//while

}//if

else cout<<"unable to open file";

}//load_and_init



int main(int argc, char** argv) {
printf("Instructions:\nA.press arrow keys to move your hero\nB.don't get cought by eaters\nC.press s key to save game\n\n");

printf("1.press 1 to start game\n2.press 2 to load saved games\n3.press any other key two times to close the game");

char ch;
ch=getch();

if(ch=='1')
start_and_init();
else if(ch=='2')
load_and_init();


bool close_app=true;
char ca;
cout <<"\n\n\npress q to quit the game.";
while (close_app)
{
	ca=getch();
	if (ca=='q')
	close_app=false;
	}

	return 0;
}
