#include <iostream>
#include <string>
#include <vector>
using namespace std;

void show(string tablero[][4]){
	string equivalentes = "abcde";
	
	cout << endl << endl << "   ";
	for (int i=0; i<4; i++){
		cout << i+1 << " ";
	}
	cout << endl;
	
	for (int i=0; i<5; i++){   			//i  filas
		cout << equivalentes[i] << " ";
		for (int j=0; j<4; j++){		//j  columnas
			cout << "|" << tablero[i][j];
		}
		cout << "|" << endl;
	}
	cout << endl;
}

//cout << "Ok! " << endl;

bool turno(string tablero[][4]){
	
	int f1,f2,c1,c2;
	string fila1, fila2,temp;
	string equivalentes = "abcde";
	string jugada;
	cout << "Introduzca la jugada: (Blancas en mayuscula, casillas y negras en minuscula)\n"; getline(cin, jugada);
	
	if (jugada.length()<5 || jugada.length()>6){
		cout << "\nJugada invalida...\n";
		return false;
	}
	
	if (jugada.length()==5){	//PEON
		
		//Coordenadas de inicio y fin
		cout << jugada[0] << endl;
		fila1 = jugada[0];
		f1 = jugada.find(fila1);     // ******REVISAR SUBINDICES
		c1 = jugada[1];
		c1-=49;
		
		fila2 = jugada[3];
		f2 = jugada.find(fila2);
		c2 = jugada[4];
		c2-=49;
		
		cout << "Ok1! " << f1 << " " << c1 << endl;
		cout << "Ok2! " << f2 << " " << c2 << endl;
		
		if (jugada[2]=='-'){			//Desplazamiento
			
			if (tablero[f2][c2]!="."){
				
				cout << "\nJugada invalida1...\n";		//Verifica que casilla nueva este vacia
				return false;
			}
			
			else if (c1!=c2 || (f2!=(f1+1) || f2!=(f1-1))){
				
				cout << "\nJugada invalida2...\n";		//Verifica que el movimiento sea una casilla adelante
				return false;
			}
			
			else{
				
				temp = tablero[f1][c1]; 
				tablero[f1][c1] = ".";					//Desplazamiento del peon
				tablero[f2][c2] = temp;
				
			}
			
		}
		
		else if (jugada[2]=='x'){		//Captura
			
		}
		
		else if (jugada[2]=='+'){		//Jaque
			
		}
		
		else if (jugada[2]=='#'){		//Jaque-mate
			
		}
		
	}
	
	else{ //--------------------DEMAS PIEZAS


		
	}
	
}




int main(){
	
	while(true){		//Ciclo para RESET
		
		//*---------Tablero---------*
		string tablero[][4] = 	{{"R","K","Q","R"},  //Tablero inicial del juego  -  [fila][columna]
								{"P","P","P","P"},
								{".",".",".","."},
								{"p","p","p","p"},
								{"r","q","k","r"},};
		
		//*------Presentacion-------*
		cout << "*---Ajedrez ak7 fyah---*" << endl << endl;
		
		
		while (true){		//Ciclo del juego
			//Variables reseteables
			bool condicion;
			
			//Juego
			show(tablero);		//Muestra la condicion actual del tablero
			condicion=turno(tablero);		//Input de la jugada, junto a sus respectivos calculos y restricciones
			if (!condicion){
				continue;
			}
			
			
		}
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
}
/* CHORES
-Ver como forzar el uso de MS Gothic en la consola.
-Ver lo del UTF para caracteres
-Ver lo de los subindices DONE
-Hacer ciclo para validar entradas
-Hacer algoritmo de analisis de string para jugadas
**
*/

