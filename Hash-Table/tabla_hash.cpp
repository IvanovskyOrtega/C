// Tabla hash en C++ utilizando unordered_set
#ifdef _WIN32
#define CLS "cls"
#endif

#include <cstdio>	// getchar(), fflush()
#include <cstdlib>	// exit()
#include <iostream>	// std::cout, std::cin, std::endl
#include <utility>	// std::pair
#include <string>	// std::string
#include <unordered_set>	// std::unordered_set

void menu(std::unordered_set<std::string>* tablaHash);
void lista_de_operaciones();
void agregar(std::unordered_set<std::string>* tablaHash, std::string llave);
void eliminar(std::unordered_set<std::string>* tablaHash, std::string llave);
void consultar(std::unordered_set<std::string> tablaHash, std::string llave);
int numero_de_llaves(std::unordered_set<std::string> tablaHash);
void limpiar_tabla(std::unordered_set<std::string>* tablaHash);


int main(){
	std::unordered_set<std::string> tablaHash; // En este caso los elementos de la tabla son cadenas
	menu(&tablaHash);
	return 0;
}

void menu(std::unordered_set<std::string>* tablaHash){
	char opcion = '0';
	std::string llave;
	char enter;
	while(true){
		enter = '0';
		#ifdef CLS
		system(CLS);
		#else
		system("clear");
		#endif
		std::cout << "TABLA HASH EN C++ UTILIZANDO UNORDERED_SET" << std::endl;
		std::cout << std::endl;
		lista_de_operaciones();
		std::cout << "Ingresa la operacion que desea realizar:" << std::endl;
		std::cin >> opcion;
		switch(opcion){
			case '1':
				std::cout << "Llave: ";
				std::cin >> llave;
				agregar(tablaHash, llave);
				break;
			case '2':
				std::cout << "Llave: ";
				std::cin >> llave;
				eliminar(tablaHash,llave);
				break;
			case '3':
				std::cout << "Llave: ";
				std::cin >> llave;
				consultar(*tablaHash,llave);
				break;
			case '4':
				std::cout << "La tabla tiene: ";
				std::cout << numero_de_llaves(*tablaHash) << std::endl;
				break;
			case '5':
				limpiar_tabla(tablaHash);
				break;
			case '6':
				exit(0);
				break;
			default:
				std::cout << "Opcion invalida." << std::endl;
		}
		fflush(stdin);
		std::cout << "Presiona ENTER para continuar..." << std::endl;
		enter = getchar();
	}
}

void lista_de_operaciones(){
	std::cout << "1) Agregar llave." << std::endl;
	std::cout << "2) Eliminar llave." << std::endl;
	std::cout << "3) Consultar llave." << std::endl;
	std::cout << "4) Consultar numero de llaves." << std::endl;
	std::cout << "5) Limpiar la tabla." << std::endl;
	std::cout << "6) Salir." << std::endl;
}

void agregar(std::unordered_set<std::string>* tablaHash, std::string llave){
	std::unordered_set<std::string>::const_iterator it = tablaHash->find(llave);
	if(it == tablaHash->end()){
		std::pair<std::unordered_set<std::string>::const_iterator, bool> p = tablaHash->insert(llave);
		if(p.second){
			std::cout << "Se agrego la llave exitosamente." << std::endl;	
		}
		else{
			std::cout << "Hubo un error al agregar la llave." << std::endl;
		}
	}
	else{
		std::cout << "La llave que desea agregar ya existe en la tabla." << std::endl;
	}
}

void eliminar(std::unordered_set<std::string>* tablaHash, std::string llave){
	if(tablaHash->count(llave) == 0){
		std::cout << "La llave que desea eliminar no esta en la tabla." << std::endl;
	}
	else{
		if(tablaHash->erase(llave) == 1){
			std::cout << "Se elimino exitosamente la llave." << std::endl;
		}
		else{
			std::cout << "Hubo un problema al eliminar la llave." << std::endl;
		}
	}
}

void consultar(std::unordered_set<std::string> tablaHash, std::string llave){
	std::unordered_set<std::string>::const_iterator it = tablaHash.find(llave);
	if(it == tablaHash.end()){
		std::cout << "No se encontro la llave en la tabla." << std::endl; 
	}
	else{
		std::cout << "La llave esta en la tabla." << std::endl;
	}
}

int numero_de_llaves(std::unordered_set<std::string> tablaHash){
	return tablaHash.size();
}
void limpiar_tabla(std::unordered_set<std::string>* tablaHash){
	tablaHash->clear();
	std::cout << "Se ha limpiado la tabla." << std::endl;
}