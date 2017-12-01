/*
*   Programa: Simulacion pagina web a base de arboles en c.
*   Fecha: 30/noviembre/2017.
*   Autor: Alejandro Santibañez, Richard Ramirez, Sebastian Urbano.
*/

//Librerias
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <cstdlib>
#include<fstream>
#define reservar_memoria (nodo *)malloc(sizeof(nodo))
//Estructura principal del arbol
struct nodo{
    int nro;
    char url[100];
    char titulo[100];
    struct nodo *izq, *der;
    struct nodo *padre;
}pagina[100];
struct Datos{

};
//Estructura Menu de la pagina
struct Menu{
	char opciones[30];
}men[100];
//Estructura pie de pagina
struct Pie{
	char celular[11];
	char correo[100];
	char direccion[100];
}piesito[100];
/*Es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos para mayor facilidad
de creacion de variables*/
nodo *ABB ;
tipoNodo *pNodo;

//prototipos de funciones
ABB crearNodo(int , ABB );
void insertar(ABB &, int , ABB);
void preOrden(ABB );
void enOrden(ABB );
void postOrden(ABB );
void verArbol(ABB , int );
void datos_principales();
void imprimir();
void menu();
void menu_Recorrido();
void menu_Eliminar();
void busqueda(ABB , int );
void eliminar(ABB , int );
ABB minimo(ABB );
void reemplazar(ABB , ABB );
void destruir(ABB );
void gotoxy(int , int );
void marco();
void cargando();
void escribir();
void eliminarNodo(ABB );
void editar(ABB , int &);
//Variables Globales
int cont = 0;
int me;
char opcion, opc;
int posicion;
char creadores[] = "Richard-Sebastian_Alejandro";
int fecha = 2018;
FILE *fd;
//Funcion principal
int main(){
	system("COLOR 70");
	menu();
}
//Menu Principal
void menu(){
	fflush(stdin);
    ABB arbol = NULL;   // creado Arbol
    int n, opcion;

	do{
		printf("----------------------------\n");
		printf("-           MENU           -\n");
		printf("----------------------------\n");
		printf("-                          -\n");
		printf("-  1. Crear Pagina         -\n");
		printf("-  2. Listar Paginas       -\n");
		printf("-  3. Editar Pagina        -\n");
		printf("-  4. Eliminar             -\n");
		printf("-  5. Buscar Pagina        -\n");
		printf("-  6. Mostrar Arbol        -\n");
		printf("-  7. Recorrido Arbol      -\n");
		printf("-  0. Salir                -\n");
		printf("-                          -\n");
		printf("----------------------------\n\n");
		printf("Que deseas hacer: ");
		scanf("%d",&opcion);
		system("cls");

		switch(opcion){
			case 0:exit('0');
				break;
			case 1:printf("//// Datos Principales \\\\\n\n");
				printf("Ingrese ID de la pagina:  ");
    			scanf("%d",&n);
    			insertar(arbol, n, NULL);
    			datos_principales();
    			escribir();
				break;
			case 2:
				imprimir();
				marco();
				break;
			case 3:editar(arbol,n);
				break;
			case 4:	printf("Digite ID de pagina a eliminar: ");
					scanf("%d",&n);
					eliminar(arbol,n);
				break;
			case 5:
				printf("Ingrese ID de pagina a buscar: ");
				scanf("%d",&n);
				busqueda(arbol,n);
				break;
			case 6:verArbol( arbol, 0);
				break;
			case 7:do{
						printf("----------------------\n");
						printf("-       MENU         -\n");
						printf("----------------------\n");
						printf("-                    -\n");
						printf("-  1. InOrden        -\n");
						printf("-  2. PreOrden       -\n");
						printf("-  3. PostOrden      -\n");
						printf("-  0. Salir          -\n");
						printf("-                    -\n");
						printf("----------------------\n\n");
						printf("Que deseas hacer: ");
						scanf("%d",&opcion);
						system("cls");
						switch(opcion){
							case 0:menu();
								break;
							case 1:printf(" Recorrido en InOrden:  ");
								enOrden(arbol);
								printf("\n");
								break;
							case 2:printf(" Recorrido en PreOrden:  ");
								preOrden(arbol);
								printf("\n");
								break;
							case 3:printf(" Recorrido en PostOrden:  ");
								postOrden(arbol);
								printf("\n");
								break;
							default:printf("Numero Equivocado\n");
								break;
						}
						system("pause");
						system("cls");
					}while(opcion != 0);
				break;
			default:printf("Numero Equivocado\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}
void menu_Eliminar(){
	fflush(stdin);
    ABB arbol;   // creado Arbol
    int n, x , opcion;  // numero de nodos del arbol

	do{
		printf("----------------------------\n");
		printf("-           MENU           -\n");
		printf("----------------------------\n");
		printf("-                          -\n");
		printf("-  1. Eliminar Una Pagina  -\n");
		printf("-  //2. Eliminar Todo      -\n");
		printf("-  0. Salir                -\n");
		printf("-                          -\n");
		printf("----------------------------\n\n");
		printf("Que deseas hacer: ");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 0:menu();
				break;
			case 1:
				break;
			case 2:
				break;
			default:printf("Numero Equivocado\n");
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

ABB crearNodo(int x, ABB padre){
    ABB nuevoNodo = reservar_memoria;
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

void insertar(ABB &arbol, int n, ABB padre){
    if(arbol != NULL){
        if(arbol -> nro == n){
            printf("No es un id valido\n");
            system("cls");
            return menu();
            //insertar();
        }
    }
    if(arbol == NULL){
        arbol = crearNodo(n,padre);
	}else if(n < arbol->nro){
		insertar(arbol->izq, n, arbol);
	}else if(n > arbol->nro){
		insertar(arbol->der, n, arbol);
	}
}
void preOrden(ABB arbol){
    if(arbol != NULL){
    	printf("%d   ",arbol->nro) ;
        preOrden(arbol->izq);
		preOrden(arbol->der);
    }
}

void enOrden(ABB arbol){
    if(arbol!=NULL){
        enOrden(arbol->izq);
        printf("%d   ",arbol->nro);
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol){
    if(arbol!=NULL){
        postOrden(arbol->izq);
        postOrden(arbol->der);
        printf("%d   ",arbol->nro);
     }
}

void verArbol(ABB arbol, int contador){
    if(arbol == NULL){
    	return;
	}
    verArbol(arbol->der, contador+1);
	for(int i=0; i<contador; i++){
    	printf("   ");
	}
    printf("%d\n",arbol->nro);
	verArbol(arbol->izq, contador+1);
}

void datos_principales(){
	printf("Ingrese el url: ");
	fflush(stdin);
	fgets(pagina[cont].url,100,stdin);
	printf("Ingrese el titulo de la pagina: ");
	fflush(stdin);
	fgets(pagina[cont].titulo,100,stdin);
	system("cls");
	printf("//// Contenido Pagina \\\\\n\n");
	printf("Decea usted un Menu(s/n): ");
	scanf("%c",&opcion);
	fflush(stdin);
	if(opcion == 's' || opcion == 'S'){
		printf("Digite la cantidad de opciones en el menu: ");
		scanf("%d",&me);
		fflush(stdin);
		for(int i = 0; i < me; i++){
			printf("Digite su %d opcion del menu: ",i+1);
			fflush(stdin);
			fgets(men[i].opciones,100,stdin);
		}
	}else if(opcion == 'n' || opcion == 'N'){
		printf("Presione Enter para continuar\n");
		system("pause");
	}else{
		printf("No es una opcion valida\n");
	}
	printf("\nDeseas imagen principal(s/n): ");
	scanf("%c",&opc);
	if(opc == 's' || opc == 'S'){
		printf("En que posicion quiere la imagen: \n");
		printf("  1. Izquierda.\n");
		printf("  2. Derecha.\n");
		printf("  3. Centrada.\n");
		printf("Que deseas hacer: ");
		scanf("%d",&posicion);
		fflush(stdin);
	}else if(opcion == 'n' || opcion == 'N'){
		printf("Presione Enter para continuar\n");
		system("pause");
	}else{
		printf("No es una opcion valida\n");
	}
	system("cls");
	printf("//// Pie de Pagina \\\\\n\n");
	printf("Digite el numero telefonico: ");
	fflush(stdin);
	fgets(piesito[cont].celular,11,stdin);
	printf("Digite el Correo: ");
	fflush(stdin);
	fgets(piesito[cont].correo,30,stdin);
	printf("Digite la Direccion: ");
	fflush(stdin);
	fgets(piesito[cont].direccion,30,stdin);
	cont++;
}

void imprimir(){
	int opcion;
	fflush(stdin);
	for(int i = 0; i < cont; i++){
		printf("%d. %s \n",i,pagina[i].titulo);
	}
	printf("\nCual deseas ver: ");
	scanf("%d",&opcion);
	fflush(stdin);
	system("cls");
	cargando();
	system("pause");
	system("cls");
	system("COLOR 72");
	gotoxy(2,2);
	printf("%s",pagina[opcion].url);
	gotoxy(25,4);
	printf("\t\t  %s\n\n",pagina[opcion].titulo);
	for (int i = 0; i < me; i++){
            gotoxy(90,9+i);
            printf("%s",men[i].opciones);
	}
	if(opc == 's' || opc == 'S'){
		switch(posicion){
			case 1:
				gotoxy(3,9);printf("****************************  ____________________________________________________\n");
				gotoxy(3,10);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,11);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,12);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,13);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,14);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,15);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,16);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,17);printf("*                          *  ____________________________________________________\n");
				gotoxy(3,18);printf("****************************  ____________________________________________________\n");
				gotoxy(3,19);printf("__________________________________________________________________________________\n");
				gotoxy(3,20);printf("__________________________________________________________________________________\n");
				gotoxy(3,21);printf("__________________________________________________________________________________\n");
				gotoxy(3,22);printf("__________________________________________________________________________________\n");
				gotoxy(3,23);printf("__________________________________________________________________________________\n");
				gotoxy(3,24);printf("__________________________________________________________________________________\n");
				gotoxy(3,25);printf("__________________________________________________________________________________\n");
				gotoxy(3,27);printf("****************************  ----------------------------------------------------\n");
				gotoxy(3,28);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,29);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,30);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,31);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,32);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,33);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,34);printf("*                          *  ----------------------------------------------------\n");
				gotoxy(3,35);printf("****************************  ----------------------------------------------------\n");
				gotoxy(3,36);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,37);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,38);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,39);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,40);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,41);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,42);printf("----------------------------------------------------------------------------------\n");
				break;
			case 2:
				gotoxy(3,9);printf("____________________________________________________  ****************************\n");
				gotoxy(3,10);printf("____________________________________________________  *                          *\n");
				gotoxy(3,11);printf("____________________________________________________  *                          *\n");
				gotoxy(3,12);printf("____________________________________________________  *                          *\n");
				gotoxy(3,13);printf("____________________________________________________  *                          *\n");
				gotoxy(3,14);printf("____________________________________________________  *                          *\n");
				gotoxy(3,15);printf("____________________________________________________  *                          *\n");
				gotoxy(3,16);printf("____________________________________________________  *                          *\n");
				gotoxy(3,17);printf("____________________________________________________  *                          *\n");
				gotoxy(3,18);printf("____________________________________________________  ****************************\n");
				gotoxy(3,19);printf("__________________________________________________________________________________\n");
				gotoxy(3,20);printf("__________________________________________________________________________________\n");
				gotoxy(3,21);printf("__________________________________________________________________________________\n");
				gotoxy(3,22);printf("__________________________________________________________________________________\n");
				gotoxy(3,23);printf("__________________________________________________________________________________\n");
				gotoxy(3,24);printf("__________________________________________________________________________________\n");
				gotoxy(3,25);printf("__________________________________________________________________________________\n");
				gotoxy(3,27);printf("----------------------------------------------------  ****************************\n");
				gotoxy(3,28);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,29);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,30);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,31);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,32);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,33);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,34);printf("----------------------------------------------------  *                          *\n");
				gotoxy(3,35);printf("----------------------------------------------------  ****************************\n");
				gotoxy(3,36);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,37);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,38);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,39);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,40);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,41);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,42);printf("----------------------------------------------------------------------------------\n");
				break;
			case 3:
				gotoxy(3,9);printf("***********************************************************************************\n");
				gotoxy(3,10);printf("*                                                                                 *\n");
				gotoxy(3,11);printf("*                                                                                 *\n");
				gotoxy(3,12);printf("*                                                                                 *\n");
				gotoxy(3,13);printf("*                                                                                 *\n");
				gotoxy(3,14);printf("*                                                                                 *\n");
				gotoxy(3,15);printf("*                                                                                 *\n");
				gotoxy(3,16);printf("*                                                                                 *\n");
				gotoxy(3,17);printf("*                                                                                 *\n");
				gotoxy(3,18);printf("*                                                                                 *\n");
				gotoxy(3,19);printf("*                                                                                 *\n");
				gotoxy(3,20);printf("***********************************************************************************\n");
				gotoxy(3,21);printf("__________________________________________________________________________________\n");
				gotoxy(3,22);printf("__________________________________________________________________________________\n");
				gotoxy(3,23);printf("__________________________________________________________________________________\n");
				gotoxy(3,24);printf("__________________________________________________________________________________\n");
				gotoxy(3,25);printf("__________________________________________________________________________________\n");
				gotoxy(3,27);printf("**********************************************************************************\n");
				gotoxy(3,28);printf("*                                                                                *\n");
				gotoxy(3,29);printf("*                                                                                *\n");
				gotoxy(3,30);printf("*                                                                                *\n");
				gotoxy(3,31);printf("*                                                                                *\n");
				gotoxy(3,32);printf("*                                                                                *\n");
				gotoxy(3,33);printf("*                                                                                *\n");
				gotoxy(3,34);printf("*                                                                                *\n");
				gotoxy(3,35);printf("*                                                                                *\n");
				gotoxy(3,36);printf("*                                                                                *\n");
				gotoxy(3,37);printf("*                                                                                *\n");
				gotoxy(3,38);printf("**********************************************************************************\n");
				gotoxy(3,39);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,40);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,41);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,42);printf("----------------------------------------------------------------------------------\n");
				gotoxy(3,43);printf("----------------------------------------------------------------------------------\n");
				break;
		}
	}
	for(int i = 1 ;i < 100; i++){
		gotoxy(i, 44);
  		printf("%c", 177);
  		gotoxy(i, 50);
  		printf("%c", 177);
	}
	gotoxy(2, 45);
	printf("Contactanos:\t");
	gotoxy(3, 46);
	printf("Celular: %s\t",piesito[opcion].celular);
	gotoxy(3, 48);
	printf("Correo: %s\t",piesito[opcion].correo);
	gotoxy(45, 45);
	printf("\tDireccion: \t");
	gotoxy(46, 46);
	printf("\t%s\t",piesito[opcion].direccion);
	gotoxy(70, 45);
	printf("\t%d\n",fecha);
	gotoxy(70, 46);
	printf("\t%s\n",creadores);
}

void busqueda(ABB arbol, int n){
	bool encontrado = false;
	if(arbol == NULL){
		printf("El arbol esta vacio\n");
	}else if(arbol->nro == n){
		printf("El Id %d fue encontrado\n",n);
		encontrado = true;
	}else if(n < arbol->nro){
		return busqueda(arbol->izq,n);
		printf("El Id %d fue encontrado\n",n);
		encontrado = true;
	}else{
		return busqueda(arbol->der,n);
		printf("El Id %d fue encontrado\n",n);
		encontrado = true;
	}
	if(encontrado == false){
		printf("El Id %d no fue encontrado\n",n);
	}
}

void eliminar(ABB arbol,int n){
	if(arbol == NULL){
		return;
	}else if(n < arbol->nro){
		eliminar(arbol->izq,n);
	}else if(n > arbol->nro){
		eliminar(arbol->der,n);
	}else{
		eliminarNodo(arbol);
	}
}
void eliminarNodo(ABB nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		ABB menor = minimo(nodoEliminar->der);
		nodoEliminar->nro = menor->nro;
		eliminarNodo(menor);
	}else if(nodoEliminar->izq){
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruir(nodoEliminar);
	}else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	}else{
		reemplazar(nodoEliminar,NULL);
	}	destruir(nodoEliminar);
}
ABB minimo(ABB arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}else{
		return arbol;
	}
}

void reemplazar(ABB arbol, ABB nuevoNodo){
	if(arbol->padre){
		if(arbol->nro == arbol->padre->izq->nro){
			arbol->padre->izq = nuevoNodo;
		}else if(arbol->nro == arbol->padre->der->nro){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

void destruir(ABB NODO){
	NODO->izq = NULL;
	NODO->der = NULL;
	free(NODO);
}


void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void marco(){
	int i, d;
	for (i = 1; i < 100; i++){
  		gotoxy(i, 1);
  		printf("%c", 177);
  		gotoxy(i, 50);
  		printf("%c", 177);
	}
	for(i = 1;i < 100; i++){
		gotoxy(i, 3);
  		printf("%c", 177);
  		gotoxy(i, 50);
  		printf("%c", 177);
	}
  	for (d = 2; d < 50; d++) {
   		gotoxy(1, d);
   		printf("%c", 178);
   		gotoxy(100, d);
   		printf("%c", 178);
  	}
	gotoxy(1, 1);
  	printf("%c", 02);

  	gotoxy(100, 1);
  	printf("%c", 02);

  	gotoxy(1, 50);
  	printf("%c", 01);

  	gotoxy(100, 50);
  	printf("%c", 01);

  	printf("\n\n");
}

void cargando(){
	bool si = false;
	int x,y,i,z,a;
 	gotoxy(35,10);
 	printf("CARGANDO...");

 	for(i=1; i<60; i++){
  		gotoxy(i,13);
  		printf("%c",177);
 		for(x = 50; x < 70; x++){
   			for(y = 1; y < 70; y++){
    			gotoxy(y,24);
   			}
  		}
 	}
	printf("\n");
}

void escribir(){
	char direccion[] = "C:\\pruebas\\emails.txt";
	char rpt;
	int i = 0;
	fd = fopen(direccion,"wt");

	if(fd == NULL){
		printf("Error al tratar de crear el archivo");
	}
	fprintf(fd,"\n\n: ");
	fwrite(pagina[i].url,1,strlen(pagina[i].url),fd);
	fprintf(fd,"\n: ");
	fwrite(pagina[i].titulo,1,strlen(pagina[i].titulo),fd);
	if(opcion == 's' || opcion == 'S'){
		fflush(stdin);
		for(i = 0; i < me; i++){
			fprintf(fd,"\n: ");
			fwrite(men[i].opciones,1,strlen(men[i].opciones),fd);
		}
	}
	if(opc == 's' || opc == 'S'){
		switch(posicion){
			case 1:
				gotoxy(3,9);fprintf(fd,"****************************  ____________________________________________________\n");
				gotoxy(3,10);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,11);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,12);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,13);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,14);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,15);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,16);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,17);fprintf(fd,"*                          *  ____________________________________________________\n");
				gotoxy(3,18);fprintf(fd,"****************************  ____________________________________________________\n");
				gotoxy(3,19);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,20);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,21);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,22);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,23);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,24);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,25);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,27);fprintf(fd,"****************************  ----------------------------------------------------\n");
				gotoxy(3,28);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,29);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,30);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,31);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,32);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,33);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,34);fprintf(fd,"*                          *  ----------------------------------------------------\n");
				gotoxy(3,35);fprintf(fd,"****************************  ----------------------------------------------------\n");
				gotoxy(3,36);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,37);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,38);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,39);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,40);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,41);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,42);fprintf(fd,"----------------------------------------------------------------------------------\n");
				break;
			case 2:
				gotoxy(3,9);fprintf(fd,"____________________________________________________  ****************************\n");
				gotoxy(3,10);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,11);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,12);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,13);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,14);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,15);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,16);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,17);fprintf(fd,"____________________________________________________  *                          *\n");
				gotoxy(3,18);fprintf(fd,"____________________________________________________  ****************************\n");
				gotoxy(3,19);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,20);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,21);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,22);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,23);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,24);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,25);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,27);fprintf(fd,"----------------------------------------------------  ****************************\n");
				gotoxy(3,28);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,29);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,30);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,31);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,32);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,33);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,34);fprintf(fd,"----------------------------------------------------  *                          *\n");
				gotoxy(3,35);fprintf(fd,"----------------------------------------------------  ****************************\n");
				gotoxy(3,36);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,37);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,38);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,39);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,40);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,41);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,42);fprintf(fd,"----------------------------------------------------------------------------------\n");
				break;
			case 3:
				gotoxy(3,9);fprintf(fd,"***********************************************************************************\n");
				gotoxy(3,10);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,11);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,12);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,13);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,14);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,15);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,16);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,17);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,18);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,19);fprintf(fd,"*                                                                                 *\n");
				gotoxy(3,20);fprintf(fd,"***********************************************************************************\n");
				gotoxy(3,21);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,22);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,23);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,24);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,25);fprintf(fd,"__________________________________________________________________________________\n");
				gotoxy(3,27);fprintf(fd,"**********************************************************************************\n");
				gotoxy(3,28);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,29);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,30);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,31);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,32);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,33);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,34);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,35);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,36);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,37);fprintf(fd,"*                                                                                *\n");
				gotoxy(3,38);fprintf(fd,"**********************************************************************************\n");
				gotoxy(3,39);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,40);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,41);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,42);fprintf(fd,"----------------------------------------------------------------------------------\n");
				gotoxy(3,43);fprintf(fd,"----------------------------------------------------------------------------------\n");
				break;
		}
	}
	fprintf(fd,"\n: ");
	fwrite(piesito[i].celular,1,strlen(piesito[i].celular),fd);
	fprintf(fd,"\n: ");
	fwrite(piesito[i].correo,1,strlen(piesito[i].correo),fd);
	fprintf(fd,"\n: ");
	fwrite(piesito[i].direccion,1,strlen(piesito[i].direccion),fd);
	i++;
	fclose(fd);
}
void editar(ABB arbol, int &n){
	int op,opceditar,nuevaopc;
	bool encontrado = false;
	if(arbol == NULL){
		printf("El arbol esta vacio\n");
	}else if(arbol->nro == n){
		encontrado = true;
	}else if(n < arbol->nro){
		return busqueda(arbol->izq,n);
		encontrado = true;
	}else{
		return busqueda(arbol->der,n);
		encontrado = true;
	}
	if(encontrado == false){
	}
		for(int i = 0; i < cont; i++){
			printf("los Id guardados son: \n\n");
			printf("%d. %s \n",i,pagina[i].titulo);
			fflush(stdin);
		}
		printf("Que pagina quiere editar, ingrese su Id: ");
		scanf("%d",&op);
		system("cls");
		do{
			printf("----------------------------\n");
			printf("-           MENU           -\n");
			printf("----------------------------\n");
			printf("-                          -\n");
			printf("-  1. Url                  -\n");
			printf("-  2. Nombre de la pagina  -\n");
			printf("-  3. Datos del menu       -\n");
			printf("-  4. Imagen               -\n");
			printf("-  5. Pie de pagina        -\n");
			printf("-  0. Salir                -\n");
			printf("-                          -\n");
			printf("----------------------------\n\n");
			printf("Ingrese la opcion que deseas editar: ");
			scanf("%d",&opceditar);
			system("cls");
			switch(opceditar){
				case 0:menu();
					break;
				case 1:printf("Ingrese el nuevo url: ");
					fflush(stdin);
					fgets(pagina[op].url,100,stdin);
					printf("\nElemento modificado con exito");
					printf("\n");
					break;
				case 2:printf("Ingrese el titulo de la pagina: ");
					fflush(stdin);
					fgets(pagina[op].titulo,100,stdin);
					printf("\n");
					break;
				case 3:
				    break;
				case 4:	printf("\nDeseas imagen principal(s/n): ");
					scanf("%c",&opc);
					printf("En que posicion quiere la imagen: \n");
					printf("  1. Izquierda.\n");
					printf("  2. Derecha.\n");
					printf("  3. Centrada.\n");
					printf("Que deseas hacer: ");
					scanf("%d",&posicion);
					break;
				case 5:printf("Digite el nuevo numero telefonico: ");
					fflush(stdin);
					fgets(piesito[op].celular,11,stdin);
					printf("Digite el nuevo Correo: ");
					fflush(stdin);
					fgets(piesito[op].correo,30,stdin);
					printf("Digite la nueva Direccion: ");
					fflush(stdin);
					fgets(piesito[op].direccion,30,stdin);
					break;
				default:printf("Numero Equivocado\n");
					break;
			}
			system("pause");
			system("cls");
		}while(opceditar != 0);
	}

