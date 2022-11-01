#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<time.h>

#define color SetConsoleTextAttribute
using namespace std;

//Declarar funciones
void run_game(char Board[3][3], int Mode);
void fill_matrix(char Board[3][3]);
void draw_board(char Board[3][3]);
void enter_piece(char Board[3][3], int Turn);
void enter_ia_piece(char Board[3][3], int Round);
int end_game(char Board[3][3]);

int main()
{
	//Declarar variables
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int Mode = 0;
	char Board[3][3];
	system("title 3 en linea");
	
	//Seleccionar modo de juego
	while(Mode < 1 or Mode > 2)
	{
		system("cls");
		system("title 3 en linea");
		cout<<"3 EN LINEA"<<endl;
		
		if (Mode != 0)
		{
			color(hConsole, 4);
			cout<<"Error! Opcion no valida."<<endl;
		}
		
		color(hConsole, 7);
		cout<<"Ingresa 1 para un jugador y 2 para multijugador: ";
		cin>>Mode;
	}
	
	run_game(Board,Mode);
	
	color(hConsole, 7);
	system("Pause");
	return 0;	 
}

//Cargar todas las funciones
void run_game(char Board[3][3],int Mode)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int Round, j;
	Round = 0;
	j = 3;
	
	fill_matrix(Board);
	
	do
	{
		system("cls");
		draw_board(Board);
		
		//Modo Solitario
		if (Mode == 1)
		{
			if (Round%2 == 0)
			{
				enter_piece(Board, 1);
			}
			else 
			{
				enter_ia_piece(Board, Round);
			}
		}
		
		//Modo Multijugador
		if (Mode == 2)
		{
			if (Round%2 == 0)
			{
				color(hConsole, 9);
				cout<<"Jugador 1: "<<endl;
				enter_piece(Board, 1);
			}
			else
			{
				color(hConsole,6);
				cout<<"Jugador 2: "<<endl;
				enter_piece(Board, 2);
			}
		}
		
		j = end_game(Board);
		Round++;
	}
	while(Round <= 9 and j == 0);
	
	system("cls");
	draw_board(Board);
	
	//Mostrar resultado del ganador
	if (j == 1)
	{
		if (Mode == 1)
		{
			color(hConsole, 2);
			cout<<"Has Ganado!\n\n";
		}
		
		if (Mode == 2)
		{
			color(hConsole, 9);
			cout<<"Jugador 1 ";
			color(hConsole, 2);
			cout<<"es el ganador!\n\n";
		}
	}
	
	if (j == 2)
	{
		if (Mode == 1)
		{
			color(hConsole, 4);
			cout<<"Has perdido!\n\n";
		}
		
		if (Mode == 2)
		{
			color(hConsole, 6);
			cout<<"Jugador 2 ";
			color(hConsole,2);
			cout<<"es el ganador!\n\n";
		}
	}
	
	if(j == 0)
	{
		color(hConsole,7);
		cout<<"Empate!\n\n";	
	}
}

//Llenar la matriz con numeros
void fill_matrix(char Board[3][3])
{
	int i,j;
	char Counter;
	Counter = '1';
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			Board[i][j] = Counter++;
		}
	}
}

//Dibujar el tablero
void draw_board(char Board[3][3])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, BoardColor, TextColor;
	char Counter;
	BoardColor = 6;
	TextColor = 8;
	
	color(hConsole,7);
	cout<<"3 EN LINEA\n\n";
	
	//Dibujar la el tablero a partir de la matriz
	for(i = 0; i < 3; i++)
	{	
		for(j = 0; j < 3; j++)
		{
			switch(Board[i][j])
			{
				case 'X': color(hConsole, 9); break;
				case 'O': color(hConsole, 6); break;
				default: color(hConsole, TextColor); break;
			}
			
			if (j < 2)
			{
				cout<<" "<<Board[i][j];
				color(hConsole,BoardColor);
				cout<<" |";
			}
			else
			{
				cout<<" "<<Board[i][j];
			}
		}
		
		if (i < 2)
		{
			color(hConsole, BoardColor);
			cout<<"\n-----------\n";
		}
	}
	
	cout<<"\n\n";
}

//Colocar ficha en el tablero
void enter_piece(char Board[3][3], int Turn)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, k;
	char Box, Piece;
	Piece = 'X';
	
	do
	{
		do
		{
			color(hConsole,7);
			cout<<"Coloca una ficha: ";
			fflush(stdin);
			cin>>Box;
			k = 0;
		}
		while(Box < '1' or Box > '9');
		
		switch(Box)
		{
			case '1':
				i = 0;
				j = 0;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '2':
				i = 0;
				j = 1;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '3':
				i = 0;
				j = 2;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '4':
				i = 1;
				j = 0;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '5':
				i = 1;
				j = 1;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '6':
				i = 1;
				j = 2;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '7':
				i = 2;
				j = 0;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '8':
				i = 2;
				j = 1;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
			
			case '9':
				i = 2;
				j = 2;
				
				if (Board[i][j] == 'X' or Board[i][j] == 'O')
				{
					k = 1;
					color(hConsole, 4);
					cout<<"La casilla esta ocupada! Intentalo con otro numero!\n\n";
				}
			break;
		}
	}
	while(k == 1);
	
	if (Turn == 1)
	{
		Board[i][j] = 'X';
	}
	else if (Turn == 2)
	{
		Board[i][j] = 'O';
	}
}

//Inteligencia artifical
void enter_ia_piece(char Board[3][3], int Round)
{
	int i,j,k;
	srand(time(NULL));
	
	if (Round < 9)
	{
	do
	{
		i = rand()%3;
		j = rand()%3;
		k = 0;
		
		if (Board[i][j] == 'X' or Board[i][j] == 'O')
		{
			k = 1;
		}
	}
	while(k == 1);
	}
	
	Board[i][j] = 'O';
}

//Comprobar ganador
int end_game(char Board[3][3])
{
	if (Board[0][0] == 'X' or Board[0][0] == 'O')
	{
		if (Board[0][0] == Board[0][1] and Board[0][0] == Board[0][2])
		{
			if (Board[0][0] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		
		if (Board[0][0] == Board[1][0] and Board[0][0] == Board[2][0])
		{
			if (Board[0][0] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	
	if (Board[0][0] == 'X' or Board[0][0] == 'O')
	{
		if (Board[1][1] == Board[0][0] and Board[1][1] == Board[2][2])	
		{
			if (Board[1][1] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		
		if (Board[1][1] == Board[1][0] and Board[1][1] == Board[1][2])
		{
			if (Board[1][1] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		
		if (Board[1][1] == Board[2][0] and Board[1][1] == Board[0][2])
		{
			if (Board[1][1] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		
		if (Board[1][1] == Board[0][1] and Board[1][1] == Board[2][1])
		{
			if (Board[1][1] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	
	if (Board[2][2] == 'X' or Board[2][2] == 'O')
	{
		if (Board[2][2] == Board[2][0] and Board[2][2] == Board[2][1])	
		{
			if (Board[2][2] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		
		if (Board[2][2] == Board[0][2] and Board[2][2] == Board[1][2])	
		{
			if (Board[2][2] == 'X')
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	
	return 0;
}
