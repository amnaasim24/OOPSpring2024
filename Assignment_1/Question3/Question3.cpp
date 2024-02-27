/* Programmer: Amna Asim Khan
   ID: 23K-0859
   OBJECT ORIENTED PROGRAMMING (OOP) [Theory] 
   Assignment 1
   Question 3
   Description:Assume we’re writing a very bare bones program to figure out how we can apply OOP to Chess. Let’s
consider the following classes that will be interacting with each other to play the game.
The ChessPiece class is used for all chess pieces (pawn, rook, knight, etc.). Each piece has attributes such

as name(King, Queen, etc.), color (black or white) and a unique symbol (K/k-for king, Q/q-for queen, N/n-
for knight, etc.) to represent it on the board. Other requirements are as follows:

• Default Constructor: Whenever this constructor is called, it will create a white pawn.
• Parameterized Constructor: Creates a ChessPiece of the type specified by the parameters.
• Appropriate getters and setters for your member variables.
The ChessBoard class represents the chessboard itself. It contains a 2D array of ChessPiece to represent
the 8x8 grid. Each element of the array holds a pointer to a ChessPiece object or is set to null if there is no
piece at that position. The class has methods like display() to print the current state of the board, and aother
method, movePiece(), which is responsible for moving a piece from one position to another.
More details about the functions is given below:
• Default Constructor for the ChessBoard class should initialize the 2D array of chess pieces to an initial
game state (also shown below).
• The display() method should generate an output like this:
a b c d e f g h
8 R N B Q K B N R 8
7 P P P P P P P P 7
6 . . . . . . . . 6
5 . . . . . . . . 5
4 . . . . . . . . 4
3 . . . . . . . . 3
2 p p p p p p p p 2
1 r n b q k b n r 1
a b c d e f g h
White pieces can be represented by small alphabet while black pieces can be capital alphabets.
Note: R: Rook, N: Knight, B: Bishop, Q: Queen, K: King, P: Pawn

• The bool movePiece(string source, string destination) method is used to move the chess piece from
a source to destination. It returns true or false based on whether the move is valid or not. For simplicity’s
sake, let only consider the movements for knight and pawns on the first turn.
Example: Function is called as: movePiece(“b8”, “a6”), so this means we are moving the knight from
b8 to a6, which is a valid first move, so your function should return true. Similarly, if the function is
called as: movePiece(“b8”, “d7”), it should return false, as d7 is already occupied by a pawn.
Notes:
The knight moves in an "L" shape on the chessboard. It can move two squares in one direction (either
horizontally or vertically) and then one square in a perpendicular direction. Alternatively, it can move two
squares in a perpendicular direction and then one square in the original direction.
Meanwhile, during the first move only, a pawn has two possible moves: it can move forward by one or two
steps, only if there is nothing in its path.
Please see the diagrams below for further clarification.
*/



#include<iostream>
#include<math.h>
using namespace std;
class ChessPiece{
	private: 
		string name;
		string color;
		char symbol;
	public:
		ChessPiece(){
			this->name = "Pawn";
			this->color="White";
			this->symbol = 'p';
		}		
		ChessPiece(string newName, string newColor, char newSymbol){
			this->name = newName;
			this->color=newColor;
			this->symbol =newSymbol;
		}		
		string getPieceName(){
			return name;
		}		
		string getPieceColor(){
			return color;
		}		
		char getPieceSymbol(){
			return symbol;
		}		
		void setName(string name){
			this->name = name;
		}		
		void setColor(string color){
			this->color = color;
		}		
		void setSymbol(char symbol){
			this->symbol = symbol;
		}
};
class ChessBoard{
	public:
	ChessPiece board[8][8];
	ChessBoard(){
		board[0][0]=ChessPiece("Rook","white",'r');
		board[0][1]=ChessPiece("Knight","white",'n');
		board[0][2]=ChessPiece("Bishup","white",'b');
		board[0][3]=ChessPiece("Queen","white",'q');
		board[0][4]=ChessPiece("King","white",'k');
		board[0][5]=ChessPiece("Bishup","white",'b');
		board[0][6]=ChessPiece("Knight","white",'n');
		board[0][7]=ChessPiece("Rook","white",'r');	
		for(int i =0; i<8;i++){
			board[1][i]=ChessPiece("Pawn","white",'p');
		}
		for(int i = 2; i<6; i++){
			for(int j =0; j<8; j++){
				board[i][j]=ChessPiece(" "," ",'.');
			}
		}
		for(int i =0; i<8;i++){
			board[6][i]=ChessPiece("Pawn","black",'P');
		}
		board[7][0]=ChessPiece("Rook","black",'R');
		board[7][1]=ChessPiece("Knight","black",'N');
		board[7][2]=ChessPiece("Bishup","black",'B');
		board[7][3]=ChessPiece("Queen","black",'Q');
		board[7][4]=ChessPiece("King","black",'K');
		board[7][5]=ChessPiece("Bishup","black",'B');
		board[7][6]=ChessPiece("Knight","black",'N');
		board[7][7]=ChessPiece("Rook","black",'R');
	}	
	bool movePiece(string source, string destination){
		int source_c = source[0]-'a';
		int source_r = source[1]-'0'-1;
		int destination_c = destination[0]-'a';
		int destination_r = destination[1]-'0'-1;
		if(board[destination_r][destination_c].getPieceSymbol()=='.'||board[destination_r][destination_c].getPieceColor()!=board[source_r][source_c].getPieceColor()){
			if (board[source_r][source_c].getPieceSymbol() == 'n' || board[source_r][source_c].getPieceSymbol() == 'N') {         
                if ((abs(source_r - destination_r) == 2) && (abs(source_c - destination_c) == 1)) {                
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;
                } 
                else {
                    cout << "Invalid move for " << board[source_r][source_c].getPieceSymbol() << endl;
                    return false;
                }           
            } 
            else if (board[source_r][source_c].getPieceSymbol() == 'p' || board[destination_r][destination_c].getPieceSymbol() == 'P') {              
                if (((destination_r - source_r == 1) && (destination_c - source_c == 0)) || ((destination_r - source_r == 2) && (destination_c - source_c == 0) && source_r == 1)) {               
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;                
                } 
                else if ((abs(destination_r - source_r) == 1) && (abs(source_c - destination_c) == 1)) {V     CF                 
                    board[destination_r][destination_c] = board[source_r][source_c];
                    board[source_r][source_c] = ChessPiece();
                    return true;
                } 
                else {
                    cout << "Invalid move for " << board[destination_r][destination_c].getPieceSymbol() << endl;
                    return false;
                }
            }
        }
        return false;
    }
	void display() {
        cout << " " << "   ";
        for (char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl ;
        int num = 8;
        for (int i = 7; i >= 0; i--) {
            cout << num << "   ";
            for (int j = 0; j < 8; j++) {
                cout << board[i][j].getPieceSymbol() << "   ";
            }
            cout << num-- << endl;
        }
        cout << " " << "   ";
        for (char ch = 'a'; ch <= 'h'; ch++) cout << ch << "   ";
        cout << endl;
    }
};
int main(){
	cout<<"Amna Asim Khan"<<"\t\t"<<"23k-0859"<<endl;
	ChessBoard board1;
	board1.display();
	cout<<"----------------------------------"<<endl;
	if(board1.movePiece("a1","a3")){
		cout<<"valid"<<endl;
	}
	else{
		cout<<"Invalid move"<<endl;
	}
	board1.display();
	cout<<"----------------------------------"<<endl;
	if(board1.movePiece("b1","c3")){
		cout<<"valid"<<endl;
	}
	else{
		cout<<"Invalid move"<<endl;
	}
	board1.display();
}
