#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include <string.h>
class Pila;
class Estados;
class FuncionDeTransicion;

struct nodo
		{
			char dato;
			struct nodo *ptrSig;
		};
class Pila{
	public:
		void meterInicio(struct nodo *ptrCab, char entrada)
		{//inicia meterInicio
			struct nodo *ptrNuevo;
			ptrNuevo=NuevoNodo(entrada);
			if(ptrCab->ptrSig==NULL)//condiciÃ³n para saber si la pila esta vacÃ­a
			{
				ptrNuevo->ptrSig=NULL;
				ptrCab->ptrSig=ptrNuevo;
			}//termina if
			else
			{
				ptrNuevo->ptrSig=ptrCab->ptrSig;
				ptrCab->ptrSig=ptrNuevo;
			}//termina else
			printf("\nPush\n");
		}//termina meterInicio

		bool sacarInicio(struct nodo *ptrCab)
		{//inicia eliminarInicio
			struct nodo *ptrTemp;
			ptrTemp=ptrCab->ptrSig;
			if(ptrTemp==NULL)
			{
				//printf("\nLa pila esta vacia\n");
				return false;
			}//termina if
			else if(ptrTemp->ptrSig==NULL)
			{
				printf("\nPop\n");
				ptrCab->ptrSig=NULL;
				free(ptrTemp);
				return true;
			}//termina else
			else
			{
				printf("\nPop\n");
				ptrCab->ptrSig=ptrTemp->ptrSig;
				free(ptrTemp);
				return true;
			}

		}//termina eliminarInicio
	
		char mostrarCabecera(struct nodo *ptrCab){
			char cabecera;
			if(ptrCab->ptrSig!=NULL)
				cabecera=ptrCab->ptrSig->dato;
			else
				cabecera='*';
			return cabecera;
		}
		
		void mostrarElementos(struct nodo *ptrCab)
		{//inicia mostrarElementos
			struct nodo *ptrRec;
			if(ptrCab->ptrSig==NULL)
			{//inicia if
				printf("\nLa pila esta vacia\n");
			}//termina if
			else
			{//inicia else
				ptrRec=ptrCab->ptrSig;
				do
				{
					printf(" %c |",ptrRec->dato);
					ptrRec=ptrRec->ptrSig;
				}while(ptrRec!=NULL);//termina do-while
			}//termina else
		}//termina mostrarElementos

		struct nodo *NuevoNodo(char dato)
		{
			struct nodo *ptrAux;
			ptrAux=(struct nodo*)malloc(sizeof(struct nodo));
			ptrAux->dato=dato;
			ptrAux->ptrSig=NULL;
			return ptrAux;
		}//termina NuevoNodo

};

class FuncionDeTransicion {
	Pila pila;
	Estados* e;
	public:
		bool cambiarDeEstado(char cadena[],int posicion,int estado, int op, struct nodo *ptrCab);
};

class Estados {
	Pila pila;
	FuncionDeTransicion f;
	public:
		bool q0(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'a':
						pila.meterInicio(ptrCab,'I');
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,a)--->q0\n");
						return f.cambiarDeEstado(cadena, posicion, 0, op, ptrCab);
					case 'b':
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->q1\n");
						return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
					default:
						printf("\nd(q0,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case '0':
						pila.meterInicio(ptrCab,'i');
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,0)--->q0\n");
						return f.cambiarDeEstado(cadena, posicion, 0, op, ptrCab);
					case '1':
						if(pila.mostrarCabecera(ptrCab)=='i'){
							pila.sacarInicio(ptrCab);
							pila.mostrarElementos(ptrCab);
							printf("\nd(q0,1)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
						else {
							pila.meterInicio(ptrCab, 'k');
							pila.mostrarElementos(ptrCab);
							printf("\nd(q0,1)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
					case '3':
						printf("\nd(q0,3)--->q4\n");
						return f.cambiarDeEstado(cadena, posicion, 4, op, ptrCab);
					case '2':
						printf("\nd(q0,2)--->M\n");
						return false;
					default:
						printf("\nd(q0,%c)--->M\n",caracter);
						return false;
				}
			}
		}
		bool q1(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'c':
						pila.sacarInicio(ptrCab);
						pila.mostrarElementos(ptrCab);
						printf("\nd(q1,c)--->q2\n");
						return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
					default:
						printf("\nd(q1,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case '1':
						if(pila.mostrarCabecera(ptrCab)=='i'){
							pila.sacarInicio(ptrCab);
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,1)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
						else {
							pila.meterInicio(ptrCab, 'k');
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,1)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
					case '2':
						if(pila.mostrarCabecera(ptrCab)=='k'){
							pila.sacarInicio(ptrCab);
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,2)--->q2\n");
							return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
						}
						else {
							printf("\nq1--->M\n");
							return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);;
						}
					case '3':
						if(pila.mostrarCabecera(ptrCab)=='*'){
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,3)--->q3\n");
							return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
						}
						else {
							printf("\ndq1--->M\n");
							return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
						}
					default:
						printf("\nd(q1,%c)--->M\n",caracter);
						return false;
				}		
			}
		}
		bool q2(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'c':
						if(pila.sacarInicio(ptrCab)==true){
							pila.mostrarElementos(ptrCab);
							printf("\nd(q2,c)--->q2\n");
							return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
						}
						else{
							if(posicion==strlen(cadena)){
								pila.mostrarElementos(ptrCab);
								printf("\nd(q2,c)--->q3\n");
								return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
							}
							else if(posicion<strlen(cadena)){
								pila.mostrarElementos(ptrCab);
								printf("\nd(q2,c)--->q2\n");
								return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
							}
						}
					default:
						printf("\nd(q2,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case '2':
						pila.sacarInicio(ptrCab);
						pila.mostrarElementos(ptrCab);
						printf("\nd(q2,2)--->q2\n");
						return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
					case '3':
						if(pila.mostrarCabecera(ptrCab)=='*'){
							pila.mostrarElementos(ptrCab);
							printf("\nd(q2,3)--->q3\n");
							return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
						}
						else {
							printf("\ndq2--->M\n");
							return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
						}
					default:
							printf("\nd(q2,%c)--->M\n",caracter);
							return false;	
				}
			}
		}
		bool q3(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==2){
				switch(caracter){
					case '3':
						if(pila.sacarInicio(ptrCab)==true){
							pila.mostrarElementos(ptrCab);
							printf("\nd(q3,c)--->q3\n");
							return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
						}
						else{
							if(posicion==strlen(cadena)){
								pila.mostrarElementos(ptrCab);
								printf("\nd(q3,c)--->q4\n");
								return f.cambiarDeEstado(cadena, posicion, 4, op, ptrCab);
							}
							else if(posicion<strlen(cadena)){
								pila.mostrarElementos(ptrCab);
								printf("\nd(q3,c)--->q3\n");
								return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
							}
						}
					default:
							printf("\nd(q3,%c)--->M\n",caracter);
							return false;
				}
			}
		}

};

int main()
{//inicia main
	Pila pila;
	FuncionDeTransicion funcion;
	struct nodo *ptrCab;
	ptrCab=(struct nodo*)malloc(sizeof(struct nodo));
	ptrCab->dato='-';//creacion del nodo desperdiciado
	ptrCab->ptrSig=NULL;//Indica que la pila esta vacia
	int op,op2;
	char valor;
	char cadena[64];
	do
	{//inicia do-while
		system("cls");
		printf("Seleccione el lenguaje que desea trabajar:\n\n");
		printf("(1)	L1 = { a^i b c^k | i, k ? 1 y i < k }\n");
		printf("(2)	L2 = { 0^i  1^(i+k) 2^k 3^(n+1) | i, k, n ? 0 }\n");
		printf("(3)	Ninguno :v (Salir)\n\n");
		scanf("%d",&op);
		switch(op)
		{//inicia switch-case
			case 1:
				system("cls");
				printf("\nIngrese la cadena a analizar:\n");
				fflush(stdin);
				scanf("%s",&cadena);
				fflush(stdin);
				if(funcion.cambiarDeEstado(cadena,0,0,op,ptrCab)==true){
					printf("\nCadena valida :)\n");
				}
				else{
						printf("\nCadena invalida :)\n");
				}
				//for(int i=0 ; i<sizeof(cadena);i++){
				//	printf("%c",&arrayCadena[i]);
				//}
				//printf("%s",arrayCadena);
				while(true){
					pila.sacarInicio(ptrCab);
					if(pila.mostrarCabecera(ptrCab)=='*')
						break;
				}
				system("pause");
				break;

			case 2:
				system("cls");
				printf("\nIngrese la cadena a analizar:\n");
				fflush(stdin);
				scanf("%s",&cadena);
				fflush(stdin);
				if(funcion.cambiarDeEstado(cadena,0,0,op,ptrCab)==true){
					printf("\nCadena valida :)\n");
				}
				else{
						printf("\nCadena invalida :)\n");
				}
				while(true){
					pila.sacarInicio(ptrCab);
					if(pila.mostrarCabecera(ptrCab)=='*')
						break;
				}
				system("pause");
				break;
			case 3:
				break;
			default:
				system("cls");
				printf("\nIngrese una opcion valida!!!:\n");
				system("pause");
				break;
		}//termina switch-case
	}while(op!=3);//termina do-while
}//termina main

bool FuncionDeTransicion::cambiarDeEstado(char cadena[],int posicion,int estado, int op, struct nodo *ptrCab){
	Estados e;
	if(op==1){
		if(posicion<strlen(cadena)){
			char caracter = cadena[posicion];
			posicion++;
			switch(estado){
				case 0:
					return e.q0(cadena,caracter,posicion,estado,op,ptrCab);
				case 1:
					return e.q1(cadena,caracter,posicion,estado,op,ptrCab);
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return true;
			}
		}
		else{
			char caracter = cadena[posicion-1];
			switch(estado){
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return true;
				default:
					printf("\nq%d ---> M",estado);
					return false;
			}
		}
	}
	else{
		if(posicion<strlen(cadena)){
			char caracter = cadena[posicion];
			posicion++;
			switch(estado){
				case 0:
					return e.q0(cadena,caracter,posicion,estado,op,ptrCab);
				case 1:
					return e.q1(cadena,caracter,posicion,estado,op,ptrCab);
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return e.q3(cadena,caracter,posicion,estado,op,ptrCab);
				case 4:
					return true;
			}
		}
		else{
			char caracter = cadena[posicion-1];
			switch(estado){
				case 3:
					return e.q3(cadena,caracter,posicion,estado,op,ptrCab);
				case 4:
					printf("\nd(q%d,c)--->q3\n",estado);
					return true;
				default:
					printf("\nq%d ---> M",estado);
					return false;
			}
		}
	}
}
