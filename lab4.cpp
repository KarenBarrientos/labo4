#include <iostream>
#include <cstdlib>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

void matriz (int*** m);
void llenado (int*** m);
void jugador (int*** m);
void liberar_Memoria(int*** m,int*** jugador1,int*** jugador2);
void cordenadas(int*** m);
void ataqueNormal (int*** m,int x , int y , int z );
void ataqueExpansive(int*** m,int x , int y , int z );
void ganador(int*** m);

int menu();

int main(int argc, char const *argv[]){

	int*** m = new int**[12];
	int*** jugador1 = new int**[12];
        int*** jugador2 = new int**[12];
/////////////////////////
        matriz (m);
	llenado (m);
        matriz (jugador1);
	llenado (jugador1);
        matriz (jugador2);
	llenado (jugador2);
	jugador (m);
	jugador (jugador1);
	jugador (jugador2);
        cordenadas(m);
 
//////////////////////////

	int menu1;
	int x,y,z;
	int jug = 1;
	while ( (menu1 = menu()) != 6){
           
	   while (true){
		if (menu1 == 1){
			cout<<"Ingrese coordenadas"<<endl;
			cout<<"x: "<<endl;
			cin>>x;
			cout<<"y: "<<endl;
			cin>>y;
			cout<<"z: "<<endl;
			cin>>z;
			if (jug==1){
			    cout << "Jugador 1 :)" <<endl ;
			    cordenadas(jugador1);
			    jug =2;
				ataqueNormal (jugador1,x ,  y , z );
				ganador(jugador1);
				break;
				
                    	    
			}
			if (jug==2){
			    cout << "Jugador 2 :)" <<endl ;
			    cordenadas(jugador2);
			    jug =1;
				ataqueNormal (jugador2,x ,  y , z );
				//ganador (jugador2);
				break;
                                
			}
			
		}else{
			if (menu1 == 2){
				cout<<"Ingrese coordenadas"<<endl;
				cout<<"x: "<<endl;
				cin>>x;
				cout<<"y: "<<endl;
				cin>>y;
				cout<<"z: "<<endl;
				cin>>z;
				//AtaqueWaveXY();
			}else{
				if (menu1 == 3){
					cout<<"Ingrese coordenadas"<<endl;
					cout<<"x: "<<endl;
					cin>>x;
					cout<<"y: "<<endl;
					cin>>y;
					cout<<"z: "<<endl;
					cin>>z;
					//AtaqueWaveXZ();
				}else{
					if (menu1 == 4){
						cout<<"Ingrese coordenadas"<<endl;
						cout<<"x: "<<endl;
						cin>>x;
						cout<<"y: "<<endl;
						cin>>y;
						cout<<"z: "<<endl;
						cin>>z;
						//AtaqueWaveYZ();
					}else{
						if (menu1 == 5){
							cout<<"Ingrese coordenadas"<<endl;
							cout<<"x: "<<endl;
							cin>>x;
							cout<<"y: "<<endl;
							cin>>y;
							cout<<"z: "<<endl;
							cin>>z;
							//AtaqueExpensive();
						}
					}
				}
			}
		}
	   }// fin del jugador
	} // fin while menu

               liberar_Memoria(m,jugador1,jugador2);
	return 0;
}

int menu(){
	cout <<" ------------------- MENU DE ATAQUES -------------------"<<endl;
	cout << "1. Ataque Normal" << endl
		 << "2. Ataque wave en XY"<<endl
		 << "3. Ataque wave en XZ"<<endl
		 << "4. Ataque wave en YZ"<<endl
		 << "5. Ataque Expansive"<<endl
	         << "6. Salir" << endl;
	    // cout<<"WAVE DISPONIBLES: "<<wave<<endl;
	    // cout<<"EXPANSIVE DISPONIBLES: "<<expansiv<<endl;
	int opcion;
	do{
		cin >> opcion;
		if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6)
			cout << "Introduzca el numero correcto" << endl;
	}while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6);

	return opcion;
}

void matriz (int*** m){

	for (int i =0; i<12 ;i++){
		m[i]=new int*[12];
        }
	
	for(int i =0 ; i<12 ; i++){
	      for(int j = 0 ;j<12;j++){
	      	m[i][j]= new int [12];
	      }
	}
}

void llenado (int*** m){
	for(int i =0; i<12;i++){
	    for(int j =0 ;j<12 ;j++){
		for(int k = 0 ; k<12 ;k++){
		m[i][j][k]=0;		
		//cout << m[i][j][k];
		}
	    }
	}	
}
 
void jugador (int*** m){
srand(time(NULL));
double magic=(rand()%10)+1;
int y =0;

	for(int i =0; i<12;i++){
	    for(int j =0 ;j<12 ;j++){
		for(int k = 0 ; k<12 ;k++){
				
		
                   double magic=(rand()%50)+1;
		   if (y <15){
                     if(magic == 20){
                        m[i][j][k]=1;
                        y++;
                     }
		   }
		 cout << m[i][j][k];
		}
	    }
	}

}

void liberar_Memoria(int*** m,int*** jugador1,int*** jugador2){
  
 	for(int i =0 ; i <12 ;i++){
		for(int j =0; j<12 ; j++){
		   delete [] m[i][j];
                   delete [] jugador1[i][j];
		   delete [] jugador2[i][j];
		}
		
	}
		
	for(int i =0 ; i <12 ;i++){
	   delete[] m[i];
	   delete[] jugador1[i];
	   delete[] jugador2[i];
	}

delete[] m;
delete[] jugador1;
delete[] jugador2;
}

void cordenadas(int*** m){

for(int i =0; i<12;i++){
	    for(int j =0 ;j<12 ;j++){
		for(int k = 0 ; k<12 ;k++){
				
		if(m[i][j][k]==1){
                   cout << "x= " <<i << " y= "<<j<<" z= " << k<< endl;
                 
                 }

		}
	    }
	}

}

void ataqueNormal (int*** m,int x , int y , int z ){
	
	if(m[x][y][z]==1){
	   m[x][y][z]=0;
	   cout << "Ataque EXITOSO :)"<<endl;
		  
	}else{
	cout << "No Destruistes nada :("<<endl;
	}

}

void ataqueExpansive(int*** m,int x , int y , int z ){
   if (((x != 1)&&(y!=1)&&(z!=1))||((x != 13)&&(y!=13)&&(z!=13))){ 
      for (int i = x-1; i <x+2;i++){
          for(int j = y-1; j <y+2;j++){
           
	      for(int k = z-1; k <z+2;k++){
	         m[x][y][z]=0;
                 cout << "Ataque EXITOSO :)"<<endl;

	      }
	   }
	}
       
   }else {
    cout << "No destruistes nada :("<<endl;
  }
}

void ganador (int*** m){
int o = 0;
for (int i = 0; i < 12;i++){
          for(int j = 0; j < 12;j++){
           
	      for(int k = 0; k < 12;k++){
	        if (m[i][j][k]==1){
                o=1;
		break;
		}
	        }
	   }
	}
	
	if (o==0){
	cout <<"Ganastes :) ya el otro contricante no tiene submarinos :)"<<endl;
	}

}
