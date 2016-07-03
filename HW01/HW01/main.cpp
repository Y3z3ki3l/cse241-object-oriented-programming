/*		
*       HW01_131044070_Yasin Acikgoz
*		
*           OTHELLO-REVERSI GAME
*
*/
//INCLUDES
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;
//Maximum board buyuklugu
const int MAX_BOARD_SIZE=20;

//Board'daki karakterler
const char user='O';

const char computer='X';

const char emptyCell='.';

//Yapilacak hamlenin bilgilerini tutan struct.
struct MoveCoordinate{
	int max;
	int total;
	int coorY;
	int coorX;
	int alt;
	int ust;
	int sag;
	int sol;
	int sagust;
	int solust;
	int sagalt;
	int solalt;
	bool status;
};
//Yapilacak hamlenin bilgilerini yedekleyen struct.
struct ComputerMoveCoordinate{
	int max;
	int alt;
	int ust;
	int sag;
	int sol;
	int sagust;
	int solust;
	int sagalt;
	int solalt;
};
//Oyununu oynanacagi board'u olusturan fonksiyon
void createBoard(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);
//Board'u ekrana basan fonksiyon
void printBoard(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);
//Kullanicidan hamle alan fonksiyon, kullanıcı gecersiz hamle girdikce almaya devam eder.
bool getMove(int size, int& coorY, int& coorX);
//Kullanicinin girdigi hamleyi kontrol eden fonksiyon
bool checkMove(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, int coorY, int coorX, char p1, char p2, MoveCoordinate& move);
//Kullanici ve bilgisayarin legal hamlesi kalip kalmadigini kontrol eden fonksiyon
bool isThereAnyValidMove(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, char currentplayer, MoveCoordinate& move);
//Kullanicinin girdigi hamleye gore tas yeme fonksiyonunu cagiran fonksiyon
bool checkUserMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX,  int size, MoveCoordinate& move);
//Bilgisayarin en iyi hamlesini tespit edip tas yeme fonksiyonun cagiran fonksiyon
bool checkComputerMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, MoveCoordinate& move, ComputerMoveCoordinate& tempCoor);
//Yonlere gore tas yeme fonksiyonlarini cagiran fonksiyon
int makeUserMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, MoveCoordinate& move);
//Yonlere gore tas yeme fonksiyonlarini cagiran fonksiyon
int makeComputerMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, MoveCoordinate& move);
//Ust tas yeme fonksiyonu
void moveTop(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Alt tas yeme fonksiyonu
void moveDown(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sol tas yeme fonksiyonu
void moveLeft(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sag tas yeme fonksiyonu
void moveRight(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sol ust tas yeme fonksiyonu
void moveCrossLT(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sag alt tas yeme fonksiyonu
void moveCrossRD(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sag ust tas yeme fonksiyonu
void moveCrossRT(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Sol Alt tas yeme fonksiyonu
void moveCrossLD(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell);
//Ekrana skorboard'u basan fonksiyon
void printScoreBoard(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);
//Oyun bittiginde ekrana skor durumunu ve kimin kazandigini yazan fonksiyon
void printGameOver(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size);

int main(void){
	char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
	int size, coorY, coorX;
	int i=0, j=0;
	bool flag=true;
	bool validMove;
	int status;
	MoveCoordinate bestMove;
	ComputerMoveCoordinate tempMove;

	cout << "\033[47;30;1m";
	//Kullanici size degerini dogru girene kadar size al
	do{
		system("clear");
		cout << "Welcome to the GTU-Reversi game!" << endl;
		cout << "Please enter a board size." << endl << "(Between 4-20 and an even size)" << endl;
		cin >> size;
	}while(size > 20 || size < 4 || size%2!=0);


	//Board'u olustur ve ekrana bas	
	createBoard(board, size);
	printBoard(board,size);
	do{ 
		cout<< "\033[47;30;1m" << endl;
		validMove=isThereAnyValidMove(board, size, user, bestMove);//Kullanicinin gecerli hamlesi olup olmadigini kontrol et
		if(validMove!=true)
			cout << "\033[47;30;1mThere is no move for User." << endl; //prompt	
		else{
			while(getMove(size,coorY,coorX)!=true){
				cout << "\033[47;30;1mError: Invalid move attempt." << endl;
				flag=false;
			}
			status=checkUserMove(board, size, coorY, coorX, bestMove);//Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
			if(status!=true && flag==true){
				cout << "\033[47;30;1mError: Invalid move attempt." << endl;
				flag=false;
			}
			else if(status==true){
				flag=true;
				printBoard(board,size);
			}
		}
		if(isThereAnyValidMove(board, size, computer, bestMove)==true && flag==true){	//Bilgisayarin gecerli hamlesi olup olmadigini kontrol et
			status=checkComputerMove(board, size, bestMove, tempMove); //Hamlenin gecerli olup olmadigini kontrol et degilse hata mesaji bas
			printBoard(board,size);
		}
		else if(flag!=false)
			cout << "\033[47;30;1mThere is no move for Computer." << endl;

			//Eger bilgisayar ve kullanicinin ayni anda hamlesi yoksa oyunu bitir
	}while(isThereAnyValidMove(board, size, computer, bestMove) || isThereAnyValidMove(board, size, user, bestMove));

	printGameOver(board, size);
	cout << "\033[0m";
	return 0;
}				
int makeUserMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, MoveCoordinate& move){
	if(move.max>0){	
		if(move.ust>0)
			moveTop(board, coorY, coorX, user, move.ust);
		if(move.alt>0)
			moveDown(board,coorY, coorX, user, move.alt);
		if(move.sag>0)
			moveRight(board,coorY, coorX, user, move.sag);
		if(move.sol>0)
			moveLeft(board, coorY, coorX, user, move.sol);
		if(move.sagust>0)
			moveCrossRT(board,coorY, coorX, user, move.sagust);
		if(move.solust>0)
			moveCrossLT(board,coorY, coorX, user, move.solust);
		if(move.sagalt>0)
			moveCrossRD(board,coorY, coorX, user, move.sagalt);
		if(move.solalt>0)
			moveCrossLD(board,coorY, coorX, user, move.solalt);
	}
}
int makeComputerMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, ComputerMoveCoordinate& tempCoor){
	if(tempCoor.max>0){
		if(tempCoor.ust>0)
			moveTop(board, coorY, coorX, computer, tempCoor.ust);
		if(tempCoor.alt>0)
			moveDown(board,coorY, coorX, computer, tempCoor.alt);
		if(tempCoor.sag>0)
			moveRight(board,coorY, coorX, computer, tempCoor.sag);
		if(tempCoor.sol>0)
			moveLeft(board, coorY, coorX, computer, tempCoor.sol);
		if(tempCoor.sagust>0)
			moveCrossRT(board,coorY, coorX, computer, tempCoor.sagust);
		if(tempCoor.solust>0)
			moveCrossLT(board,coorY, coorX, computer, tempCoor.solust);
		if(tempCoor.sagalt>0)
			moveCrossRD(board,coorY, coorX, computer, tempCoor.sagalt);
		if(tempCoor.solalt>0)
			moveCrossLD(board,coorY, coorX, computer, tempCoor.solalt);
	}
}
bool checkMove(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, int coorY, int coorX, char p1, char p2, MoveCoordinate& move){
	int i=0, j=0;
	int count=0;
	int temp=0;
	int y=0;
	int  ust=0, alt=0, sol=0, sag=0, sagalt=0, solust=0, sagust=0, solalt=0;
	int max=0;
	move.total=0;
	move.status=false;
	if(board[coorY][coorX]!=emptyCell){ //Kontrol edilen hucre bos degilse false return edip cik
		return false;
	}	
	//Bir noktayi ust, alt, sag, sol, sag ust, sag alt, sol alt ve sol ustune bakarak kontrol edip bu yonlerde rakibin tasi varsa sayaca yaz.
	else{
		if(coorY-1>=0 && board[coorY-1][coorX]==p2){//UST 
			while(board[coorY-i][coorX]!=p1){	
				++i;
				if(board[coorY-i][coorX]==p2){
					++count;
					ust=count;
				}
				else if(board[coorY-i][coorX]==emptyCell || coorY-i<0){	
					count=0;
					i=0;			
					ust=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorY+1<size && board[coorY+1][coorX]==p2){//ALT
			while(board[coorY+i][coorX]!=p1){
				++i;
				if(board[coorY+i][coorX]==p2){
					++count;
					alt=count;
				}
				else if(board[coorY+i][coorX]==emptyCell || coorY+i>size-1){
					count=0;
					i=0;
					alt=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorX-1>=0 && board[coorY][coorX-1]==p2){//SOL
			while(board[coorY][coorX-i]!=p1){	
				++i;
				if(board[coorY][coorX-i]==p2){
					++count;
					sol=count;
				}
				else if(board[coorY][coorX-i]==emptyCell || coorX-i<0){
					count=0;
					sol=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		}		
		if(coorX+1<size && board[coorY][coorX+1]==p2){//SAG
			while(board[coorY][coorX+i]!=p1){
				++i;
				if(board[coorY][coorX+i]==p2){
					++count;
					sag=count;
				}
				else if(board[coorY][coorX+i]==emptyCell|| coorX+i>size-1){
					count=0;
					sag=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorY-1>=0 && coorX+1<size && board[coorY-1][coorX+1]==p2){//SAGUST
			while(board[coorY-i][coorX+i]!=p1){	
				++i;
				if(board[coorY-i][coorX+i]==p2){
					++count;
					sagust=count;
				}
				else if(board[coorY-i][coorX+i]==emptyCell || coorY-i<0 || coorX+i>size-1){
					count=0;
					sagust=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorY+1<size && coorX+1<size &&board[coorY+1][coorX+1]==p2){//SAGALT
			while(board[coorY+i][coorX+i]!=p1){	
				++i;	
				if(board[coorY+i][coorX+i]==p2){
					++count;
					sagalt=count;
				}
				else if(board[coorY+i][coorX+i]==emptyCell || coorY+i>size-1 || coorX+i>size-1){
					count=0;
					sagalt=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorY-1>=0 && coorX-1>=0 && board[coorY-1][coorX-1]==p2){//SOLUST
			while(board[coorY-i][coorX-i]!=p1){	
				++i;
				if(board[coorY-i][coorX-i]==p2){
					++count;
					solust=count;
				}
				else if(board[coorY-i][coorX-i]==emptyCell || coorY-i<0 || coorX-i<0){
					count=0;
					solust=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		}
		if(coorY+1<size && coorX-1>=0 && board[coorY+1][coorX-1]==p2){//SOLALT
			while(board[coorY+i][coorX-i]!=p1){	
				++i;
				if(board[coorY+i][coorX-i]==p2){
					++count;
					solalt=count;
				}
				else if(board[coorY+i][coorX-i]==emptyCell || coorY+i>size-1 || coorX-i<0){
					count=0;
					solalt=0;
					i=0;
					break;
				}
			}
			i=0;
			count=0;
		} 
		if(p1==computer){
			move.max=ust+alt+sol+sag+sagalt+solust+sagust+solalt;
			if(move.max>move.total){
				move.total=move.max;
				move.coorX=coorX;
				move.coorY=coorY;
				move.status=true;
				//Her bir hucre icin olusturulan struct'a degerleri yaz
				move.ust=ust, move.alt=alt, move.sag=sag,move.sol=sol;
				move.sagust=sagust, move.solust=solust, move.sagalt=sagalt,move.solalt=solalt;
			}
		}
		if(p1==user){				
			max=ust+alt+sol+sag+sagalt+solust+sagust+solalt;
			if(max){
				move.max=max;
				move.status=true;
				//Her bir hucre icin olusturulan struct'a degerleri yaz
				move.ust=ust,move.alt=alt,move.sag=sag,move.sol=sol,move.sagust=sagust,move.solust=solust,move.sagalt=sagalt,move.solalt=solalt;
			}
		}
	}
	//Hamle yoksa false return et
	if(max<0)
		return false;
	else
		return true;
}
bool checkComputerMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, MoveCoordinate& move, ComputerMoveCoordinate& tempCoor){
	int temp=0;
	int coorY, coorX;
	int xMax, yMax; 
	bool status;	
	//Her bos hucre icin hamle kontrol eden fonksiyonu cagir ve en buyuk hamleyi tesbit edip hamle yaptiran fonksiyona yolla
	for(coorY=0; coorY<size; ++coorY){
		for(coorX=0; coorX<size; ++coorX){
			if(board[coorY][coorX]==emptyCell){
				status=checkMove(board,size, coorY, coorX, computer, user, move);
				if(status==true){
					if(move.max>temp){
						temp=move.max;
						xMax=coorX;
						yMax=coorY;
						tempCoor.ust=move.ust, tempCoor.alt=move.alt, tempCoor.sag=move.sag, tempCoor.sol=move.sol;
						tempCoor.sagust=move.sagust, tempCoor.solust=move.solust, tempCoor.sagalt=move.sagalt, tempCoor.solalt=move.solalt;	
					}
				}
			}
		}
	}
	//Hamle yoksa false return et										
	if(status==false)
		return false;
	else{
		makeComputerMove(board, yMax, xMax, tempCoor);
		//Hamleyi yaptiktan sonra 2 saniye bekle ve ekrani temizle
		sleep(2); 
		system("clear");
		return true;
	}		
}
bool checkUserMove(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, int coorY, int coorX, MoveCoordinate& move){
	bool status;
	status=checkMove(board,size,coorY, coorX, user,computer, move);
	//Hamle yoksa false return et
	if(status==false){
		return false;
	}
	else if(move.status==true){
		system("clear");
		makeUserMove(board, coorY, coorX, move);
		return true;
	}
}
bool isThereAnyValidMove(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size, char currentplayer, MoveCoordinate& move){
	//Kullanici ve bilgisayar icin her hucreyi ayri ayri kontrol ederek gecerli hamle olup olmadigini tespit et
	if(currentplayer==user){
		for(int coorY=0; coorY<size; ++coorY){
			for(int coorX=0; coorX<size; ++coorX){
				if(board[coorY][coorX]==emptyCell){
					checkMove(board,size,coorY, coorX, user,computer, move);
					//Gecerli hamle varsa true dondur
					if(move.status==true)
						return true;
				}
			}
		}
	}		
	else if(currentplayer==computer){
		for(int coorY=0; coorY<size; ++coorY){
			for(int coorX=0; coorX<size; ++coorX){
				if(board[coorY][coorX]==emptyCell){ 
					checkMove(board, size,coorY, coorX, computer, user, move);
					//Gecerli hamle varsa true dondur
					if(move.status==true)
						return true;
				}
			}
		}
	}
	//Gecerli hamle yoksa false dondur
	return false;
}
//Kazanilan tas sayisini alip dongu yardimiyla o kadar sayida tas yiyen fonksiyonlar
void moveTop(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY-i][coorX]=currentplayer;
		++i;
	}
	return ;
}
void moveDown(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY+i][coorX]=currentplayer;
		++i;
	}
	return ;
}
void moveLeft(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY][coorX-i]=currentplayer;
		++i;
	}
	return ;
}
void moveRight(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1; 
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY][coorX+i]=currentplayer;
		++i;
	}
	return ;
}
void moveCrossLT(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){	
	int i=1; 
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY-i][coorX-i]=currentplayer;
		++i;
	}
	return ;
}
void moveCrossRD(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY+i][coorX+i]=currentplayer;
		++i;
	}
	return ;
}
void moveCrossRT(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY-i][coorX+i]=currentplayer;
		++i;
	}
	return ;
}
void moveCrossLD(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int coorY, int coorX, char currentplayer, int numberOfEarnedCell){
	int i=1;
	board[coorY][coorX]=currentplayer;
	while(i<=numberOfEarnedCell){
		board[coorY+i][coorX-i]=currentplayer;
		++i;
	}
	return ;
}
bool getMove(int size, int& coorY, int& coorX){
	char cX;
	int temp;

	cout << "\033[47;30;1m";
	//Kullanicidan gecerli hamle girene kadar hamle iste girilen hamle gecersiz ise buffer'i bosalt
	do{
		cout << "Enter a move." << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}while(!(cin >> coorY)); //Kullanicidan Y koordinatini al
	--coorY; //1 azalt
	cin >> cX; //Kullanicidan X koordinatini karakter olarak al

	cX=toupper(cX); //Buyuk harfe cevir
	temp=static_cast<int>(cX); //harfi integera cevir
	coorX=temp-65;	//integeri tekrar koordinata cevir
	cout << "\033[0m";
	return true;
}
void createBoard(char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size){
	for(int i=0; i<size; ++i)
		for(int j=0; j<size; ++j)
			board[i][j]=emptyCell;
	//Kullanici ve bilgisayarin ilk taslarini ekrana bas
	board[size/2-1][size/2-1]=computer;
	board[size/2][size/2]=computer;
	board[size/2][size/2-1]=user;
	board[size/2-1][size/2]=user;
}
void printBoard(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size){
	int i=0, j=0; 
	char c;
	//Yukaridan asagiya dogru sayi, soldan saga dogru rakam basıp icine board'u basan fonksiyon
	//Kullanicinin taslari mavi, bilgisayarin taslari ise kirmizi renkte temsil edilmistir.
	cout << "\033[47;30;1m";
	cout << "  ";
	for(i=0; i<size; ++i){
		cout << " ";
		c=(char)i+65;
		cout << c;
	}
	cout << endl;	
	for(i=0; i<size; ++i){
		if(i<9)
			cout << "\033[47;30;1m ";;
		cout << "\033[47;30;1m" <<i+1;
		for(j=0; j<size; ++j){
			cout << " ";
			if(board[i][j]==computer){
				cout << "\33[31;1m" <<  board[i][j] << "\33[0m\033[47;1m";
			}
			else if(board[i][j]==user){
				cout << "\33[34;1m" <<  board[i][j] << "\33[0m\033[47;1m";
			}
			else
				cout << "\33[30m" << board[i][j] << "\33[0m\033[47;1m";		
			}
		if(i==size/2-1)
			cout << "\t  \33[4;30;1mScoreboard\33[0m\033[47m";
		if(i==size/2){
			cout << "\t\33[34;471mUser\33[0m\033[47m";
			cout << "\33[31;1m   Computer \33[0m\033[47;1m"; 
			}
		if(i==size/2+1) //board'un yanina skorbord bas
			printScoreBoard(board, size);
		cout << endl;
	cout << "\033[0m";
	}
}
void printScoreBoard(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size){
	int countUser=0, countComputer=0;
	int i=0, j=0;
	//tahtadaki bilgisayar ve kullanici taslarinim sayilarini ekrana bas
	for(j=0; j<size; ++j){
		for(i=0; i<size;++i){
			if(board[i][j]==user)
				++countUser;
			else if(board[i][j]==computer)
				++countComputer;
		}
	}
	cout << "\t \33[34;1m" << countUser << "\33[0m\033[47m";
	cout << "  \t   \33[31;1m" << countComputer << "\33[0m";
}
void printGameOver(const char board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int size){
	int countUser=0, countComputer=0;
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			if(board[i][j]==user)
				++countUser;
			else if(board[i][j]==computer)
				++countComputer;
		}
	}
	cout << "\033[47;30;1m";
	cout << "THE GAME IS OVER" << endl;
	if(countUser > countComputer){
		cout << "\33[34;1mUser\33[0m\033[47;30;1m wins by " << countUser << " - " << countComputer << "!" <<  endl;

	}
	else if(countComputer > countUser){
		cout << "\33[31;1mComputer\33[0m\033[47;30;1m wins by " << countComputer << " - " << countUser << "!" << endl;

	}
	else
		cout << "Draws by " << countComputer << " - " << countUser << "!" <<  endl;
	cout << "\033[0m";
}