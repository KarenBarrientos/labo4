#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;


int menu();

int main(int argc, char const *argv[]){

	bool ganador=false;

	int menu1;
	int x,y,z;

	while ( (menu1 = menu()) != 6){

		if (menu1 == 1){
			cout<<"Ingrese coordenadas"<<endl;
			cout<<"x: "<<endl;
			cin>>x;
			cout<<"y: "<<endl;
			cin>>y;
			cout<<"z: "<<endl;
			cin>>z;
			//AtaqueNormal(x,y,z);
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

	} // fin while menu


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