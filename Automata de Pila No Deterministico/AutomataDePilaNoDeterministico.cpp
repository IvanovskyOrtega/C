#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int l=0;
int m=0;
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
		bool nodoq0(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				bool A=false,B=false;
				printf("\nPRIMER CAMINO:\n");
				printf("\nd(q0,a)--->q0\n");
				A = q0AM(cadena, caracter, posicion, 0, op, ptrCab);
				while(true){
					pila.sacarInicio(ptrCab);
					if(pila.mostrarCabecera(ptrCab)=='*')
						break;
				}
				B = q0A2i(cadena, caracter, posicion, 5, op, ptrCab);
				return A || B;
			}
			else{
				bool A=false,B=false;
				printf("\nPRIMER CAMINO:\n");
				printf("\nd(q0,a)--->q0\n");
				A = q0AM(cadena, caracter, posicion, 0, op, ptrCab);
				while(true){
					pila.sacarInicio(ptrCab);
					if(pila.mostrarCabecera(ptrCab)=='*')
						break;
				}
				B = q0A2i(cadena, caracter, posicion, 5, op, ptrCab);
				return A || B;
			}
		}
		bool q0AM(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
			switch(caracter){
				case 'a':
					pila.meterInicio(ptrCab,'m');
					l++;
					pila.mostrarElementos(ptrCab);
					return f.cambiarDeEstado(cadena,posicion,0,op,ptrCab);
				case 'b':
					pila.meterInicio(ptrCab,'p');
					l++;
					pila.mostrarElementos(ptrCab);
					printf("\nd(q0,b)--->q1\n");
					return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
				case 'c':
					if(pila.mostrarCabecera(ptrCab)=='m'){
						pila.sacarInicio(ptrCab);
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->q1\n");
						return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
					}
					else
						printf("\nd(q0,%c)--->M\n",caracter);
				default:
					printf("\nd(q0,%c)--->M\n",caracter);
					return false;
			}	
			}
			else{
				switch(caracter){
				case 'a':
					pila.meterInicio(ptrCab,'m');
					l++;
					pila.mostrarElementos(ptrCab);
					return f.cambiarDeEstado(cadena,posicion,0,op,ptrCab);
				case 'b':
					pila.meterInicio(ptrCab,'p');
					l++;
					pila.mostrarElementos(ptrCab);
					printf("\nd(q0,b)--->q1\n");
					return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
				case 'c':
					if(pila.mostrarCabecera(ptrCab)=='m'){
						pila.sacarInicio(ptrCab);
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->q1\n");
						return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
					}
					else
						printf("\nd(q0,%c)--->M\n",caracter);
				default:
					printf("\nd(q0,%c)--->M\n",caracter);
					return false;
			}
			}
			
		}
		bool q0A2i(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
				case 'a':
					printf("\nSEGUNDO CAMINO:\n");
					pila.meterInicio(ptrCab,'i');
					m++;
					pila.mostrarElementos(ptrCab);
					printf("\nd(q0,a)--->q5\n");
					return f.cambiarDeEstado(cadena,posicion,5,op,ptrCab);
				case 'b':
					printf("\nSEGUNDO CAMINO:\n");
					if(m==0){
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->M\n");
						return false;
					}
					else{
						pila.sacarInicio(ptrCab);
						pila.sacarInicio(ptrCab);
						m-=2;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->q5\n");
						return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
					}
				default:
					printf("\nd(q0,%c)--->M\n",caracter);
					return false;
			}
			}
			else{
				switch(caracter){
				case 'a':
					printf("\nSEGUNDO CAMINO:\n");
					pila.meterInicio(ptrCab,'i');
					pila.meterInicio(ptrCab,'i');
					m+=2;
					pila.mostrarElementos(ptrCab);
					printf("\nd(q0,a)--->q5\n");
					return f.cambiarDeEstado(cadena,posicion,5,op,ptrCab);
				case 'b':
					printf("\nSEGUNDO CAMINO:\n");
					if(m==0){
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->M\n");
						return false;
					}
					else{
						pila.sacarInicio(ptrCab);
						m--;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q0,b)--->q5\n");
						return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
					}
				default:
					printf("\nd(q0,%c)--->M\n",caracter);
					return false;
			}
			}
		}
		bool q1(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'b':
						if(posicion==strlen(cadena)){
							printf("\nd(q1,%c)--->M\n",caracter);
							return false;
						}
						else{
							l++;
							pila.meterInicio(ptrCab,'p');
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,b)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
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
					case 'b':
						if(posicion==strlen(cadena)){
							printf("\nd(q1,%c)--->M\n",caracter);
							return false;
						}
						else{
							l++;
							pila.meterInicio(ptrCab,'p');
							pila.mostrarElementos(ptrCab);
							printf("\nd(q1,b)--->q1\n");
							return f.cambiarDeEstado(cadena, posicion, 1, op, ptrCab);
						}
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
		}
		bool q2(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'c':
						if((pila.mostrarCabecera(ptrCab)=='m'||pila.mostrarCabecera(ptrCab)=='p')&&posicion<strlen(cadena)){
							pila.sacarInicio(ptrCab);
							pila.mostrarElementos(ptrCab);
							printf("\nd(q2,c)--->q2\n");
							return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
						}
						else if(pila.mostrarCabecera(ptrCab)=='m'&&posicion==strlen(cadena)){
								if(pila.sacarInicio(ptrCab->ptrSig)=='*'){
									pila.mostrarElementos(ptrCab);
									printf("\nd(q2,e)--->q3\n");
									return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
								}
								else{
									if(strlen(cadena)==2*l){
										pila.mostrarElementos(ptrCab);
										printf("\nd(q2,e)--->q3\n");
										return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
									}
									else{
										pila.mostrarElementos(ptrCab);
										printf("\nq2--->M\n");
										return false;
									}
								}
								
						}
					default:
						printf("\nd(q2,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case 'c':
						if((pila.mostrarCabecera(ptrCab)=='m'||pila.mostrarCabecera(ptrCab)=='p')&&posicion<strlen(cadena)){
							pila.sacarInicio(ptrCab);
							pila.mostrarElementos(ptrCab);
							printf("\nd(q2,c)--->q2\n");
							return f.cambiarDeEstado(cadena, posicion, 2, op, ptrCab);
						}
						else if(pila.mostrarCabecera(ptrCab)=='m'&&posicion==strlen(cadena)){
								if(pila.sacarInicio(ptrCab->ptrSig)=='*'){
									pila.mostrarElementos(ptrCab);
									printf("\nd(q2,e)--->q3\n");
									return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
								}
								else{
									if(strlen(cadena)==2*l){
										pila.mostrarElementos(ptrCab);
										printf("\nd(q2,e)--->q3\n");
										return f.cambiarDeEstado(cadena, posicion, 3, op, ptrCab);
									}
									else{
										pila.mostrarElementos(ptrCab);
										printf("\nq2--->M\n");
										return false;
									}
								}
								
						}
					default:
						printf("\nd(q2,%c)--->M\n",caracter);
						return false;
				}
			}
		}
		bool q5(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'a':
						pila.meterInicio(ptrCab,'i');
						m++;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q5,%c)--->q5\n",caracter);
						return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
					case 'b':
						pila.sacarInicio(ptrCab);
						pila.sacarInicio(ptrCab);
						m-=2;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q5,%c)--->q6\n",caracter);
						return f.cambiarDeEstado(cadena, posicion, 6, op, ptrCab);
					default:
						printf("\nd(q5,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case 'a':
						pila.meterInicio(ptrCab,'i');
						pila.meterInicio(ptrCab,'i');
						m+=2;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q5,%c)--->q5\n",caracter);
						return f.cambiarDeEstado(cadena, posicion, 5, op, ptrCab);
					case 'b':
						pila.sacarInicio(ptrCab);
						m--;
						pila.mostrarElementos(ptrCab);
						printf("\nd(q5,%c)--->q6\n",caracter);
						return f.cambiarDeEstado(cadena, posicion, 6, op, ptrCab);
					default:
						printf("\nd(q5,%c)--->M\n",caracter);
						return false;
				}
			}
		}
		bool q6(char cadena[], char caracter, int posicion, int estado, int op, struct nodo *ptrCab){
			if(op==1){
				switch(caracter){
					case 'b':
						if(pila.mostrarCabecera(ptrCab)=='*'&&strlen(cadena)==posicion&&m==0){
							pila.mostrarElementos(ptrCab);
							printf("\nd(q6,e)--->q7\n",caracter);
							return f.cambiarDeEstado(cadena, posicion, 7, op, ptrCab);
						}
						else if(m%2==0){
							pila.sacarInicio(ptrCab);
							pila.sacarInicio(ptrCab);
							m-=2;
							pila.mostrarElementos(ptrCab);
							printf("\nd(q6,%c)--->q6\n",caracter);
							return f.cambiarDeEstado(cadena, posicion, 6, op, ptrCab);
						}
						else if(m%2!=0){
								pila.mostrarElementos(ptrCab);
								printf("\nq6--->M\n");
								return false;
						}
						else{
							pila.mostrarElementos(ptrCab);
							printf("\nq6--->M\n");
							return false;
						}
					default:
						printf("\nd(q6,%c)--->M\n",caracter);
						return false;
				}
			}
			else{
				switch(caracter){
					case 'b':
						if(pila.mostrarCabecera(ptrCab)=='*'&&strlen(cadena)==posicion&&m==0){
							printf("\nd(q6,e)--->q7\n",caracter);
							return f.cambiarDeEstado(cadena, posicion, 7, op, ptrCab);
						}
						else if(pila.mostrarCabecera(ptrCab)=='i'&posicion<strlen(cadena)){
							pila.sacarInicio(ptrCab);
							m--;
							pila.mostrarElementos(ptrCab);
							printf("\nd(q6,%c)--->q6\n",caracter);
							return f.cambiarDeEstado(cadena, posicion, 6, op, ptrCab);
						}
						else if(m>0&&posicion==strlen(cadena)){
							if(pila.mostrarCabecera(ptrCab->ptrSig)=='*'){
								pila.sacarInicio(ptrCab);
								m--;
								pila.mostrarElementos(ptrCab);
								printf("\nd(q6,%c)--->q6\n",caracter);
								return f.cambiarDeEstado(cadena, posicion, 6, op, ptrCab);
							}
							else{
								pila.mostrarElementos(ptrCab);
								printf("\nq6--->M\n");
								return false;
							}
						}
						else{
							pila.mostrarElementos(ptrCab);
							printf("\nq6--->M\n");
							return false;
						}
					default:
						printf("\nd(q6,%c)--->M\n",caracter);
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
		printf("(1)	L3 = { a^m b^p c^(p+m) | m, p >= 1} U {a^(2i) b^i | i >= 1}\n");
		printf("(2)	L3 = { a^m b^p c^(p+m) | m, p >= 1} U {a^i b^(2i) | i >= 1}\n");
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
				if(funcion.cambiarDeEstado(cadena,0,-1,op,ptrCab)==true){
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
				l=0;
				m=0;
				system("pause");
				break;

			case 2:
				system("cls");
				printf("\nIngrese la cadena a analizar:\n");
				fflush(stdin);
				scanf("%s",&cadena);
				fflush(stdin);
				if(funcion.cambiarDeEstado(cadena,0,-1,op,ptrCab)==true){
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
				case -1:
					return e.nodoq0(cadena,caracter,posicion,estado,op,ptrCab);
				case 0:
					return e.q0AM(cadena,caracter,posicion,estado,op,ptrCab);
				case 1:
					return e.q1(cadena,caracter,posicion,estado,op,ptrCab);
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return true;
				case 5:
					return e.q5(cadena,caracter,posicion,estado,op,ptrCab);
				case 6:
					return e.q6(cadena,caracter,posicion,estado,op,ptrCab);
			}
		}
		else{
			char caracter = cadena[posicion-1];
			switch(estado){
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 6:
					return e.q6(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return true;
				case 7:
					return true;
				default:
					return false;
			}
		}
	}
	else{
		if(posicion<strlen(cadena)){
			char caracter = cadena[posicion];
			posicion++;
			switch(estado){
				case -1:
					return e.nodoq0(cadena,caracter,posicion,estado,op,ptrCab);
				case 0:
					return e.q0AM(cadena,caracter,posicion,estado,op,ptrCab);
				case 1:
					return e.q1(cadena,caracter,posicion,estado,op,ptrCab);
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 3:
					return true;
				case 5:
					return e.q5(cadena,caracter,posicion,estado,op,ptrCab);
				case 6:
					return e.q6(cadena,caracter,posicion,estado,op,ptrCab);
				case 8:
					return e.q0A2i(cadena,caracter,posicion,estado,op,ptrCab);
			}
		}
		else{
			char caracter = cadena[posicion-1];
			switch(estado){
				case 2:
					return e.q2(cadena,caracter,posicion,estado,op,ptrCab);
				case 6:
					return e.q6(cadena,caracter,posicion,estado,op,ptrCab);
				case 7:
					return true;
				case 3:
					return true;
				default:
					return false;
			}
		}
	}
}
