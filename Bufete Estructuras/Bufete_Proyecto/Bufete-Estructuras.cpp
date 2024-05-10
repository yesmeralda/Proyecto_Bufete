#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#include <vector>
#define TECLA_ARRIBA 72 
#define TECLA_ABAJO 80 
#define ENTER 13

using namespace std;

//XY
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Funciones MENU
void menu_principal();
void menuPila();
void menuCola();
void munuLista();
int menu(const char* titu, const char* opciones[], int n);

void info();
void bien1();
void bien2();
void bien3();
void color(int);
void bienvenida();

//struct nodo {
//	struct datoABB prodabb;
//	int datoABB;
//	nodo* derABB;
//	nodo* izqABB;
//	nodo* padreABB;
//};




//ESTRUCTURA NODO PARA PILA 
struct Pilas {
	string codigopila;
	string nombreprodpila;
	string tipoprodpila;
	string precio;
	Pilas* dir_codpila;
	Pilas* dir_nombreppila;
	Pilas* dir_tipoppila;
	Pilas* dir_aPrecio;
};

//APUNTADORES PARA PILA
Pilas* Codigo_Pila, * pila_auxcod;
Pilas* NombreP_Pila, * pila_auxnombre;
Pilas* TipoP_pila, * pila_auxTipoP;
Pilas* pila_precio, * pila_auxPrecio;

//FUNCIONES DE LA PILA 
void push();
void pop();
void show();
void search();
void modificarNombre();

//MOSTRAR PILA C
void mostrarColaM();

//PROTOTIPOS DE FUNCIONES
void MenuArbol();
//nodo* crearNodoABB(int, nodo*);
//void agregarNodoABB(nodo*&, int, nodo*);
//void mostrarArbolABB(nodo*, int);
//bool busquedaABB(nodo*, int);
//void eliminarABB(nodo*, int);
//void eliminarNodoABB(nodo*);
//nodo* minimoABB(nodo*);
//void reemplazarABB(nodo*, nodo*);
//void destruirNodoABB(nodo*);

//nodo* arbol = NULL;

//Menu arboles AVL
void MenuArbolAVL();

void grupo();
void buscasCola();


//Main
int main() {
	info();
	grupo();
	menu_principal();
	return 0;
}

void cabeceraDatosPilas() {
	gotoxy(1, 1); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 2); cout << "|CODIGO DEL CASO  |NOMBRE DEL CASO   |TIPO DE CASO    |PRECIO                |";
	gotoxy(1, 3); cout << " -----------------------------------------------------------------------------";
}

void cabeceraDatosCOLA() {
	gotoxy(1, 1); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 2); cout << "|NOMBRE DEL CLIENTE           |MUNICIPIO        |NIT                |DPI      |";
	gotoxy(1, 3); cout << " -----------------------------------------------------------------------------";
}

void mostrarColaM() {
	system("mode con: cols=103 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 110 COLUMNAS Y 25 FILAS
	gotoxy(1, 1); cout << " ---------------------------------------------------------------------------------------------------- ";
	gotoxy(1, 2); cout << "|NOMBRE DEL CLIENTE     |MUNICIPIO        |NIT             |DPI               | DIRECCION DE MEMORIA |";
	gotoxy(1, 3); cout << " ---------------------------------------------------------------------------------------------------- ";
}

void grupo() {
	system("cls");
	system("mode con: cols=120lines=40");
	system("color f0");
	gotoxy(29, 10); cout << "INTEGRANTES DEL GRUPO";
	gotoxy(30, 19); cout << "Rolando Eliseo Gomez Velasquez            CARNET: 2290-22-8306";
	gotoxy(30, 21); cout << "Yasmin Emseralda Alexandra Bulux Chavez   CARNET: 2290-21-6183";
	gotoxy(30, 23); cout << "Bryan Danilo de Leon Ixtan                CARNET: 2290-22-16516";

	_getch();
}

void info() {
	system("cls");

	system("mode con: cols=120 lines=40");

	system("color f0");

	system("cls");
	system("mode con: cols=120 lines=40");
	system("color f0");
	gotoxy(45, 10); cout << "  GGGG    BBBB    L      ";
	gotoxy(45, 11); cout << " G    G   B   B   L      ";
	gotoxy(45, 12); cout << " G        BBBB    L      ";
	gotoxy(45, 13); cout << " G  GGG   B   B   L      ";
	gotoxy(45, 14); cout << "  GGGG    BBBB    LLLLL  ";
	gotoxy(45, 15); cout << "                    ";
	gotoxy(15, 24); cout << "Es un programa que facilita el registro, actualizacion y administracion de los casos";
	gotoxy(45, 26); cout << "de un bufete de abogados ";
	_getch();
}


//CONTADOR
int j = 1;

//INGRESO DE DATOS PARA METODO PILA 
void push() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	cabeceraDatosPilas();
	gotoxy(1, 4); cout << "|";
	gotoxy(78, 4); cout << "|";
	if (Codigo_Pila == NULL) {
		Codigo_Pila = new (Pilas);
		gotoxy(3, 4);  cin >> Codigo_Pila->codigopila;
		getchar();
		Codigo_Pila->dir_codpila = NULL;

		NombreP_Pila = new (Pilas);
		gotoxy(29, 4); cin >> NombreP_Pila->nombreprodpila;
		getchar();
		NombreP_Pila->dir_nombreppila = NULL;
		j = j++;

		TipoP_pila = new(Pilas);
		gotoxy(47, 4); cin >> TipoP_pila->tipoprodpila;
		getchar();
		TipoP_pila->dir_tipoppila = NULL;
		j = j++;

		pila_precio = new(Pilas);
		gotoxy(67, 4); cin >> pila_precio->precio;
		getchar();
		pila_precio->dir_aPrecio = NULL;
		j = j++;

		gotoxy(15, 20); cout << " Se han ingresado " << j << " nodos a la estructura...";
		gotoxy(25, 21); cout << " DATOS CORRECTAMENTE INGRESADOS";
		getchar();
		return;
	}
	else {

		pila_auxcod = new(Pilas);
		gotoxy(3, 4); cin >> pila_auxcod->codigopila;
		getchar();
		pila_auxcod->dir_codpila = Codigo_Pila;
		Codigo_Pila = pila_auxcod;
		j = j++;
		pila_auxnombre = new(Pilas);
		gotoxy(29, 4); cin >> pila_auxnombre->nombreprodpila;
		getchar();
		pila_auxnombre->dir_nombreppila = NombreP_Pila;
		NombreP_Pila = pila_auxnombre;
		j = j++;
		pila_auxTipoP = new(Pilas);
		gotoxy(47, 4); cin >> pila_auxTipoP->tipoprodpila;
		getchar();
		pila_auxTipoP->dir_tipoppila = TipoP_pila;
		TipoP_pila = pila_auxTipoP;
		j = j++;
		pila_auxPrecio = new(Pilas);
		gotoxy(67, 4); cin >> pila_auxPrecio->precio;
		getchar();
		pila_auxPrecio->dir_aPrecio = pila_precio;
		pila_precio = pila_auxPrecio;
		j = j++;
		gotoxy(15, 20); cout << " Se han ingresado " << j << " nodos a la estructura...";
		gotoxy(25, 21); cout << " DATOS CORRECTAMENTE INGRESADOS";
		getchar();
	}
}

//ELIMINACION DE DATOS EN METODO PILA
void pop() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	cabeceraDatosPilas();
	cout << endl;
	if (Codigo_Pila == NULL && NombreP_Pila == NULL && TipoP_pila == NULL && pila_precio == NULL) {
		gotoxy(3, 4); cout << "No existen datos para eliminar..." << endl;
		getchar();
		getchar();
		return;
	}
	else {
		pila_auxcod = new(Pilas);
		pila_auxcod = Codigo_Pila;
		gotoxy(3, 4); cout << pila_auxcod->codigopila;
		getchar();
		Codigo_Pila = pila_auxcod->dir_codpila;
		delete(pila_auxcod);
		pila_auxnombre = new(Pilas);
		pila_auxnombre = NombreP_Pila;
		gotoxy(29, 4); cout << pila_auxnombre->nombreprodpila;
		getchar();
		NombreP_Pila = pila_auxnombre->dir_nombreppila;
		delete(pila_auxnombre);
		pila_auxTipoP = new(Pilas);
		pila_auxTipoP = TipoP_pila;
		gotoxy(47, 4); cout << pila_auxTipoP->tipoprodpila;
		getchar();
		TipoP_pila = pila_auxTipoP->dir_tipoppila;
		delete(pila_auxTipoP);
		pila_auxPrecio = new(Pilas);
		pila_auxPrecio = pila_precio;
		gotoxy(67, 4); cout << pila_auxPrecio->precio;
		getchar();
		pila_precio = pila_auxPrecio->dir_aPrecio;
		delete(pila_auxPrecio);
		gotoxy(25, 6); cout << "-----------------------------";
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE.."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE..."; Sleep(500);
		gotoxy(25, 6); cout << "                               "; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE.."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE..."; Sleep(500);
		gotoxy(25, 6); cout << "                               "; Sleep(500);
		gotoxy(25, 6); cout << "DATOS DEL CLIENTE ELIMINADOS"; Sleep(500);
		getchar();
		return;
	}
}

//MOSTRAR DATOS EN METODO PILA 
void show() {
	system("cls");
	system("mode con: cols=80 lines=1000"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 100 COLUMNAS Y 25 FILAS
	gotoxy(26, 2); cout << "DATOS INGRESADOS EN FORMA DE PILA";
	if (Codigo_Pila == NULL) {
		gotoxy(5, 8); cout << "La pila no contiene datos a mostrar" << endl;
		getchar();
	}
	pila_auxcod = Codigo_Pila;
	pila_auxnombre = NombreP_Pila;
	pila_auxTipoP = TipoP_pila;
	pila_auxPrecio = pila_precio;
	int i = 1;
	gotoxy(2, 4);    cout << " -------------------------------------------------------------------------- " << endl;
	gotoxy(2, 5);     cout << "|                                     FIN                                  |" << endl;
	gotoxy(2, 6);     cout << " -------------------------------------------------------------------------- " << endl;
	while (pila_auxcod != NULL && pila_auxnombre != NULL && pila_auxTipoP != NULL && pila_auxPrecio != NULL)
	{
		cout << endl;
		cout << endl;
		gotoxy(2, 6 + i); cout << "|Codigo del caso: " << pila_auxcod->codigopila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxcod = pila_auxcod->dir_codpila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Nombre del caso: " << pila_auxnombre->nombreprodpila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxnombre = pila_auxnombre->dir_nombreppila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Tipo de caso: " << pila_auxTipoP->tipoprodpila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxTipoP = pila_auxTipoP->dir_tipoppila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Precio: Q." << pila_auxPrecio->precio << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxPrecio = pila_auxPrecio->dir_aPrecio;
		i = i++;

		//DIRECCION DE MEMORIA
		gotoxy(2, 6 + i); cout << "|Direccion de Memoria: " << &pila_auxcod->codigopila << endl;
		gotoxy(77, 6 + i); cout << "|";
		i = i++;
		gotoxy(2, 6 + i); cout << " -------------------------------------------------------------------------- " << endl;

		//NUMERO DE REGISTRO
		i = i++;

	}

	gotoxy(2, 6 + i); cout << "|                                    INICIO                                |" << endl;
	i = i++;
	gotoxy(2, 6 + i); cout << " -------------------------------------------------------------------------- " << endl;

	getchar();
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
}

//BUSCAR DATOS EN FORMA DE PILA 
void search() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "BUSQUEDA DE CODIGO DEL CASO";

	//COMPROBACION PARA VER SI EXISTEN DATOS EN LA PILA
	if (Codigo_Pila == NULL) {

		gotoxy(20, 20); cout << "No hay datos ingresados del caso..." << endl;
	}

	//Variables para la busqueda
	string searchDestino;
	string searchBoleto;
	int searchEstadia;
	int searchPrecio;
	bool found = false;
	pila_auxcod = Codigo_Pila;
	gotoxy(5, 7); cout << "Ingrese codigo del caso a buscar:";
	cin >> searchDestino;

	while (pila_auxcod != NULL)
	{
		if (searchDestino == pila_auxcod->codigopila)
		{
			gotoxy(5, 9); cout << "Buscando."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando.."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando..."; Sleep(500);
			gotoxy(5, 9); cout << "                                                              ";
			gotoxy(5, 9); cout << "Buscando."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando.."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando..."; Sleep(500);
			gotoxy(5, 9); cout << "                                                              ";
			gotoxy(5, 9);  cout << "El codigo existe en los registros de los casos:  " << pila_auxcod->codigopila << endl;
			getchar();
			found = true;
			break;
		}
		pila_auxcod = pila_auxcod->dir_codpila;
	}
	if (found == false)
	{
		gotoxy(5, 9); cout << "No se encontro registro del caso" << endl;
		getchar();
	}
	getchar();
}

//MODIFICAR NOMBRE CLIENTE
void modificarNombre() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "MODIFICACION DE CODIGO DEL CASO";

	//COMPROBACION PARA VER SI EXISTEN DATOS EN LA PILA
	if (Codigo_Pila == NULL) {

		gotoxy(20, 20); cout << "No hay datos ingresados del caso..." << endl;
	}
	string searchDestino;
	bool found = false;
	pila_auxcod = Codigo_Pila;
	gotoxy(5, 7); cout << "Ingrese el codigo del caso a modificar: ";
	cin >> searchDestino;
	while (pila_auxcod != NULL)
	{
		if (searchDestino == pila_auxcod->codigopila)
		{
			gotoxy(5, 8);  cout << "El codigo existe en los registros de los casos:  " << pila_auxcod->codigopila << endl;
			gotoxy(5, 9);  cout << "Ingrese el nuevo codigo: ";
			cin >> pila_auxcod->codigopila;
			gotoxy(5, 10); cout << "Modificando."; Sleep(500);
			gotoxy(5, 10); cout << "Modificando.."; Sleep(500);
			gotoxy(5, 10); cout << "Modificando..."; Sleep(500);
			gotoxy(5, 10); cout << "                                                              ";
			gotoxy(5, 11);  cout << "EL CODIGO A SIDO MODIFICADO CORRECTAMENTE";
			getchar();
			found = true;
			break;
		}
		pila_auxcod = pila_auxcod->dir_codpila;
	}
	if (found == false)
	{
		gotoxy(5, 9); cout << "No se encontro registro para modificar..." << endl;
		getchar();
	}
	getchar();
}

void menu_principal()
{
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("color f0");
	bool repite = true;
	int opc;

	//TITULO Y OPCIONES DEL MENU
	const char* titu = { "" };
	const char* opciones[] = { "MODULO DE DATOS DE CASOS  (PILA)", "MODULO DE DATOS DE CLIENTES  (COLA)", "MODULO DE DATOS DE INGRESOS CASOS  (LISTAS)","MODULO DE DATOS DE ABOGADOS (ABB)","MODULO DE DATOS DE SUCURSALES (AVL)",  "SALIDA" };
	int n = 6; //NUMERO DE OPCIONES
	do
	{
		opc = menu(titu, opciones, n);
		//MENU
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			menuPila();
			break;
		case 2:
			menuCola();
			break;
		case 3:
			munuLista();
			break;
		case 4:
			MenuArbol();
			break;
		case 5:
			MenuArbolAVL();
			break;
		case 6:repite = false;	break;
		}
	} while (repite);
}

void menuPila() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;

	gotoxy(9, 9); const char* titu = "------------------------ INGRESO DE DATOS (METODO PILA) ------------------------";
	const char* opciones[] = { "Ingreso Casos (PILA)", "Ver lista de casos en forma de (PILA)", "Modificar un caso ", "Buscar un caso ", "Eliminar un caso ", "Regresar al Menu Principal" };
	int n = 6;
	do
	{
		opc = menu(titu, opciones, n);
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			push();
			break;
		case 2:
			show();
			break;
		case 3:
			modificarNombre();
			break;
		case 4:
			search();
			break;
		case 5:
			pop();
			break;
		case 6:
			repite = false;
			break;
		}
	} while (repite);
}

int menu(const char* titu, const char* opciones[], int n) {
	int opcionSeleccionada = 1;
	int tecla;

	bool repite = true;

	do
	{
		system("cls");
		gotoxy(14, 10 + opcionSeleccionada); cout << "==>";

		for (int i = 0; i < n; i++)
		{
			gotoxy(18, 11 + i); cout << i + 1 << ") " << opciones[i];
		}

		do
		{
			tecla = _getch();
		} while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch (tecla)
		{
		case TECLA_ARRIBA:
			opcionSeleccionada--;
			if (opcionSeleccionada < 1)
			{
				opcionSeleccionada = n;
			}
			break;

		case TECLA_ABAJO:
			opcionSeleccionada++;
			if (opcionSeleccionada > n)
			{
				opcionSeleccionada = 1;
			}
			break;

		case ENTER:
			repite = false;
			break;
		}

	} while (repite);

	return opcionSeleccionada;
}



//Colas
struct datos
{
	char nombre[30];
	char municipio[30];
	int nit;
	int dpi;
};

struct nodo1 {
	struct datos entrada;
	nodo1* siguientepilap;
}*ultimo = NULL, * cola = NULL, * primero = NULL;

//Segunda cola
struct nodo2 {
	struct datos salida;
	nodo2* destino_sig1;
}*ultimo1 = NULL, * cola1 = NULL, * primero1 = NULL;

//funciones
int cantidad = 2;
int x;

void ingresarCola() {
	system("cls");
	cabeceraDatosCOLA();
	gotoxy(1, 4); cout << "|";
	gotoxy(79, 4); cout << "|";
	cola = new(nodo1);
	gotoxy(3, 4); cin >> cola->entrada.nombre;
	x = x + 1;
	gotoxy(21, 4); cin >> cola->entrada.municipio;
	x = x++;;
	gotoxy(39, 4); cin >> cola->entrada.nit;
	x = x++;
	gotoxy(59, 4); cin >> cola->entrada.dpi;
	x = x++;
	getchar();

	if (ultimo != NULL) {
		ultimo->siguientepilap = cola;
		cola->siguientepilap = NULL;
		ultimo = cola;
		gotoxy(15, 20); cout << "Se han ingresado " << x << " nodos a la estructura...";
		gotoxy(25, 21); cout << "DATO INGRESADO CORRECTAMENTE " << endl;
		getchar();
	}
	else {
		primero = ultimo = cola;
		gotoxy(15, 20); cout << "Se han ingresado " << x << " nodos a la estructura...";
		gotoxy(25, 21); cout << "DATOS INGRESADOS CORRECTAMENTE " << endl;
		getchar();
	}
}

void Mostrar1Cola() {
	system("cls");
	mostrarColaM();
	int i = 1;
	if (ultimo == NULL) {
		gotoxy(25, 6); cout << " no se ingresaron nuevos datos " << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
	cola = primero;
	gotoxy(1, 4);     cout << "|                                              INICIO                                                |" << endl;
	gotoxy(1, 5);     cout << " ---------------------------------------------------------------------------------------------------- " << endl;
	while (cola != NULL) {
		if (primero == ultimo) {
			gotoxy(1, 5 + i); cout << "|";
			gotoxy(102, 5 + i); cout << "|";
			gotoxy(3, 5 + i); cout << cola->entrada.nombre;
			gotoxy(20, 5 + i); cout << "|" << cola->entrada.municipio;
			gotoxy(39, 5 + i); cout << "|" << cola->entrada.nit;
			gotoxy(66, 5 + i); cout << "|" << cola->entrada.dpi;
			//DIRECCION DE MEMORIA 
			gotoxy(79, 5 + i); cout << "|" << &cola->entrada.nombre;
			i++;
			gotoxy(1, 5 + i);    cout << " ---------------------------------------------------------------------------------------------------- " << endl;
			cola = NULL;
			_getch();
			menuCola();
		}
		else {
			gotoxy(1, 5 + i); cout << "|";
			gotoxy(102, 5 + i); cout << "|";
			//cout << "Su Destino es: ";
			gotoxy(3, 5 + i); cout << cola->entrada.nombre;

			//cout << "Su tipo de boleto es: " 
			gotoxy(20, 5 + i); cout << "|" << cola->entrada.municipio;

			//cout << "Su tiempo de estadia es: " 
			gotoxy(39, 5 + i); cout << "|" << cola->entrada.nit;

			//cout << "Su monto a pagar es: " 
			gotoxy(65, 5 + i); cout << "|" << cola->entrada.dpi;

			//DIRECCION DE MEMORIA 
			gotoxy(79, 5 + i); cout << "|" << &cola->entrada.nombre;
			i++;
			gotoxy(1, 5 + i);    cout << " ---------------------------------------------------------------------------------------------------- " << endl;
			i++;
			cola = cola->siguientepilap;
			_getch();
		}
	}
	gotoxy(1, 5 + i);     cout << "|                                              FIN                                                   |" << endl;
	i++;
	gotoxy(1, 5 + i);     cout << " ---------------------------------------------------------------------------------------------------- " << endl;
	_getch();
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
}

void eliminarCola() {
	system("cls");
	cola1 = new(nodo2);
	//dibujarCuadro(0, 0, 78, 24); //SE DIBUJA EL CUADRO PRINCIPAL
	//dibujarCuadro(1, 1, 77, 3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(30, 2); cout << "ELIMINACION DE DATOS";
	if (ultimo == NULL) {

		gotoxy(25, 6); cout << "NO HAY DATOS INGRESADOS";
		_getch();
		return;
	}
	else {
		if (primero != NULL) {

			cola = primero; gotoxy(25, 6); cout << "-----------------------------";
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO.."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO..."; Sleep(500);
			gotoxy(25, 6); cout << "                               "; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO.."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO..."; Sleep(500);
			gotoxy(25, 6); cout << "                               "; Sleep(500);
			gotoxy(25, 6); cout << "DATOS DEL DESTINO ELIMINADOS"; Sleep(500);
			gotoxy(25, 7); cout << "Se elimino el cliente en la cola: " << cola->entrada.nombre << endl;
			getchar();

			strcpy_s(cola1->salida.nombre, cola->entrada.nombre);
			strcpy_s(cola1->salida.municipio, cola->entrada.municipio);
			cola1->salida.nit = cola->entrada.nit;
			cola1->salida.dpi = cola->entrada.dpi;
			if (ultimo != NULL) {
				ultimo1 = cola1->destino_sig1;
				cola1->destino_sig1 = NULL;
				ultimo1 = cola1;
			}
			else {
				primero1 = ultimo1 = cola1;
			}
		}
		primero = cola->siguientepilap;
		if (primero == NULL) {
			ultimo = NULL;
			cola = NULL;
		}
		_getch();
	}
}

void buscasCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "BUSQUEDA DE DATOS";

	nodo1* actual = new nodo1();
	actual = primero;
	bool encontrado = false;
	string nodoBuscado;
	gotoxy(20, 8); cout << "INGRESE EL NOMBRE DEL CLIENTE A BUSCAR : ";
	gotoxy(30, 9); cin >> nodoBuscado;
	if (primero != NULL) {
		while (actual != NULL && encontrado != true) {

			if (actual->entrada.nombre == nodoBuscado) {
				gotoxy(30, 10); cout << "Buscando."; Sleep(500);
				gotoxy(30, 10); cout << "Buscando.."; Sleep(500);
				gotoxy(30, 10); cout << "Buscando..."; Sleep(500);
				gotoxy(30, 10); cout << "                                                              ";
				gotoxy(30, 10); cout << "DATOS ENCONTRADOS";
				gotoxy(3, 11); cout << actual->entrada.nombre;
				gotoxy(20, 11); cout << actual->entrada.municipio;
				gotoxy(42, 11); cout << actual->entrada.nit;
				gotoxy(70, 11); cout << actual->entrada.dpi;
				encontrado = true;
				_getch();
				system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
				return;
			}

			actual = actual->siguientepilap;
		}
		if (!encontrado) {
			gotoxy(30, 10); cout << " CLIENTE NO ENCONTRADO";
			_getch();
			system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
			return;
		}
	}
	else {
		gotoxy(30, 10); cout << " NO HAY DATOS INGRESADOS " << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
}

void modificarCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "MODIFICACION DE DATOS";

	nodo1* actual = new nodo1();
	actual = primero;
	bool encontrado = false;
	string nodoBuscado;

	gotoxy(20, 8); cout << "INGRESE NOMBRE A MODIFICAR: ";
	gotoxy(30, 9); cin >> nodoBuscado;

	if (primero != NULL) {
		while (actual != NULL && encontrado != true) {
			if (actual->entrada.nombre == nodoBuscado) {
				gotoxy(30, 10);  cout << "CLIENTE ( " << nodoBuscado << " ) ENCONTRADO";
				gotoxy(30, 11); cout << "INGRESE EL NUEVO NOMBRE DEL CLIENTE ";
				gotoxy(30, 12); cin >> actual->entrada.nombre;
				gotoxy(30, 13); cout << "Modificando."; Sleep(500);
				gotoxy(30, 13); cout << "Modificando.."; Sleep(500);
				gotoxy(30, 13); cout << "Modificando..."; Sleep(500);
				gotoxy(30, 13); cout << "                                                              ";
				gotoxy(30, 13); cout << "DATO MODIFICADO";
				encontrado = true;
				_getch();
				system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
				return;
			}

			actual = actual->siguientepilap;
		}
		if (!encontrado) {
			gotoxy(30, 12); cout << "Buscando."; Sleep(500);
			gotoxy(30, 12); cout << "Buscando.."; Sleep(500);
			gotoxy(30, 12); cout << "Buscando..."; Sleep(500);
			gotoxy(30, 12); cout << "                                                              ";

			gotoxy(30, 10); cout << "DATO NO ENCONTRADO";
			_getch();
			system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
			return;
		}
	}
	else {
		gotoxy(30, 10); cout << endl << "NO HAY DATOS INGRESADOS" << endl << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
}

void menuCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;
	const char* titu = "------------------------ INGRESO DE DATOS (METODO COLA) ------------------------";

	//elnom();
	//gotoxy(25, 2); cout << "TIENDA DE ABARROTERIA DON CABAL";

	const char* opciones[] = { "Ingreso de datos de clientes (COLA)", "Ver datos de clientes (COLA)", "Modificar datos de clientes ", "Buscar un cliente ", "Eliminar cliente ", "Regresar al Menu Principal" };
	int n = 6;

	do
	{
		opc = menu(titu, opciones, n);
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			ingresarCola();
			break;
		case 2:
			Mostrar1Cola();
			break;
		case 3:
			modificarCola();
			break;
		case 4:
			buscasCola();
			break;
		case 5:
			eliminarCola();
			break;

		case 6:
			repite = false;
			break;
		}
	} while (repite);
	system("cls");
}

//Estructuras para listas////////////////////////////////////////////////////////////////////////////////////////////////////////
//funciones de lstas simples
//funciones de lstas simples
void insertarNodoqq();
void eliminarNodoqq();
void desplegarListaqq();

//listas dobles funciones
void insertarNododuo();
void eliminarNododuo();
void desplegarListaPUduo();
void desplegarListaUPduo();

//Listas circulare
void insertarNodocir();
void eliminarNodocir();
void desplegarListacir();

void munuLista() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;

	const char* titu = "----------------------- INGRESO DE DATOS (METODO LISTAS) -----------------------";
	const char* opciones[] = { "Listas de casos importantes (Simpelemte enlazada)", "Listas de abogados  (doblemenete enlazada)", "Lista de deudores (Circular)","Salir" };
	int n = 4;

	do
	{
		opc = menu(titu, opciones, n);
		int opcion_menu;

		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:

			do
			{
				system("mode con: cols=80 lines=25");
				gotoxy(20, 4); cout << "|-------------------------------------|";
				gotoxy(20, 5); cout << "|           ° LISTA SIMPLE °          |";
				gotoxy(20, 6); cout << "|         ° Casos Importantes °       |";
				gotoxy(20, 7); cout << "|------------------|------------------|";
				gotoxy(20, 8); cout << "| 1. Insertar      | 4. Regresar      |";
				gotoxy(20, 9); cout << "| 2. Desplegar     |                  |";
				gotoxy(20, 10); cout << "| 3. Eliminar      |                  |";
				gotoxy(20, 11); cout << "|------------------|------------------|";
				gotoxy(27, 17); cout << "Escoja una Opcion[ ] ";
				gotoxy(45, 17); cin >> opcion_menu;
				switch (opcion_menu) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNodoqq();
					break;
				case 2:
					cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
					desplegarListaqq();
					break;
				case 3:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNodoqq();
					break;
				case 4:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu != 4);
			break;
		case 2:
			int opcion_menu1111;
			do
			{
				system("mode con: cols=80 lines=25");
				gotoxy(20, 4); cout << "|-------------------------------------|";
				gotoxy(20, 5); cout << "|           ° LISTA DOBLE °           |";
				gotoxy(20, 6); cout << "|             ° Abogados °            |";
				gotoxy(20, 7); cout << "|------------------|------------------|";
				gotoxy(20, 8); cout << "| 1. Insertar      | 5. Regresar      |";
				gotoxy(20, 9); cout << "| 2. Desplegar P.U |                  |";
				gotoxy(20, 10); cout << "| 3. Desplegar U.P |                  |";
				gotoxy(20, 11); cout << "| 4. Eliminar      |                  |";
				gotoxy(20, 12); cout << "|------------------|------------------|";
				gotoxy(27, 17); cout << "Escoja una Opcion [ ]";
				gotoxy(46, 17); cin >> opcion_menu1111;
				switch (opcion_menu1111) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNododuo();
					break;
				case 2:
					cout << "\n\n DESPLEGAR LISTA DE NODOS DEL PRIMERO AL UTLIMO\n\n";
					desplegarListaPUduo();
					break;
				case 3:
					cout << "\n\n DESPLEGAR LISTA DE NODOS DEL UTLIMO AL PRIMERO\n\n";
					desplegarListaUPduo();
					break;
				case 4:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNododuo();
					break;
				case 5:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu1111 != 5);
			//Mostrar1Cola();ingresa el nombre aqui 
			break;
		case 3:
			int opcion_menu33;
			do
			{
				system("mode con: cols=80 lines=25");
				gotoxy(20, 4); cout << "|-------------------------------------|";
				gotoxy(20, 5); cout << "|      ° LISTA CIRCULAR SIMPLE °      |";
				gotoxy(20, 5); cout << "|             ° Deudores  °           |";
				gotoxy(20, 6); cout << "|------------------|------------------|";
				gotoxy(20, 7); cout << "| 1. Insertar      | 4. Regresar      |";
				gotoxy(20, 8); cout << "| 2. Desplegar     |                  |";
				gotoxy(20, 9); cout << "| 3. Eliminar      |                  |";
				gotoxy(20, 10); cout << "|------------------|------------------|";
				gotoxy(27, 17); cout << "Escoja una Opcion [ ]";
				gotoxy(46, 17); cin >> opcion_menu33;
				switch (opcion_menu33) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNodocir();
					break;
				case 2:
					cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
					desplegarListacir();
					system("pause");
					break;
				case 3:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNodocir();
					break;
				case 4:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu33 != 4);
			//modificarCola();ingresa el nombre aqui 
			break;
		case 4:
			repite = false;
			break;
		}
	} while (repite);
	system("cls");
}


//Listas simples
struct prodctLS {
	string codLS;
	string nomLS;
	string cantidadLS;
	string prcioLS;
};

struct nodo8 {
	struct prodctLS datospLS;
	nodo8* siggg;
} *primero11, * ultimo11;

void menuLS() {

	gotoxy(1, 1); cout << " -------------------------    CASOS POR MUNICIPIO    -------------------------";
	gotoxy(1, 2); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 3); cout << "|NOMBRE            |MUNICIPIO        |CASO                |CONSUMO            |";
	gotoxy(1, 4); cout << " -----------------------------------------------------------------------------";
}
void menuLSDire() {
	gotoxy(1, 1); cout << " ------------------------    MOSTRANDO CASOS POR MUNICIPIO    --------------------------";
	gotoxy(1, 2); cout << " ---------------------------------------------------------------------------------------";
	gotoxy(1, 3); cout << "|NOMBRE           |MUNICIPIO      |CASO      |TOTAL   |DR_MEMORIA                       ";
	gotoxy(1, 4); cout << " ---------------------------------------------------------------------------------------";
}

void insertarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* nuevoaa = new (nodo8);
	menuLS();
	gotoxy(1, 5); cin >> nuevoaa->datospLS.codLS;
	//x = x + 1;
	gotoxy(20, 5); cin >> nuevoaa->datospLS.nomLS;
	//x = x++;
	gotoxy(38, 5); cin >> nuevoaa->datospLS.cantidadLS;
	//x = x++;
	gotoxy(59, 5); cin >> nuevoaa->datospLS.prcioLS;
	//x = x++;

	if (primero11 == NULL) {
		primero11 = nuevoaa;
		primero11->siggg = NULL;
		ultimo11 = nuevoaa;
	}
	else {
		ultimo11->siggg = nuevoaa;
		nuevoaa->siggg = NULL;
		ultimo11 = nuevoaa;
	}
	cout << "\n Datos del cliente correctamete ingresados... \n\n";
	_getch();
}

void eliminarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* actualoo = new nodo8();
	actualoo = primero11;
	nodo8* anterioroo = new nodo8();
	anterioroo = NULL;
	bool encontradooo = false;
	string nodoBuscadooo;
	desplegarListaqq();
	cout << " \n\n ------------------------------------------------------- \n\n";
	cout << " \nIngrese el nombre del Caso a Buscar para Eliminar: ";
	cin >> nodoBuscadooo;
	if (primero11 != NULL) {

		while (actualoo != NULL && encontradooo != true) {

			if (actualoo->datospLS.codLS == nodoBuscadooo) {
				cout << "\n EL caso " << nodoBuscadooo << " se encuentra registrado\n\n";

				if (actualoo == primero11) {
					primero11 = primero11->siggg;
				}
				else if (actualoo == ultimo11) {
					anterioroo->siggg = NULL;
					ultimo11 = anterioroo;
				}
				else {
					anterioroo->siggg = actualoo->siggg;
				}

				cout << "\n Caso ELiminado con exito\n\n";

				encontradooo = true;
			}

			anterioroo = actualoo;
			actualoo = actualoo->siggg;
		}
		if (!encontradooo) {
			cout << "\n Caso No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}

void desplegarListaqq() {
	int i = 1;
	system("mode con: cols=100 lines=25");
	menuLSDire();
	nodo8* actualuu = new (nodo8);
	actualuu = primero11;
	if (primero11 != NULL) {
		while (actualuu != NULL) {
			gotoxy(1, 5 + i); cout << actualuu->datospLS.codLS;
			gotoxy(20, 5 + i); cout << actualuu->datospLS.nomLS;
			gotoxy(35, 5 + i); cout << actualuu->datospLS.cantidadLS;
			gotoxy(45, 5 + i); cout << "Q." << actualuu->datospLS.prcioLS;
			//DIRECCION DE MEMORIA 
			gotoxy(56, 5 + i); cout << &actualuu->datospLS.codLS;
			i++;
			cout << " " << actualuu->datospLS.codLS << endl;
			actualuu = actualuu->siggg;

		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}

//Listas Doblemente enlazada
void menuDE() {
	gotoxy(1, 1); cout << " ----------------------------     ABOGADOS           -------------------------";
	gotoxy(1, 2); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 3); cout << "|NOMBRE            |MUNICIPIO        |NIT                |SALARIO            |";
	gotoxy(1, 4); cout << " -----------------------------------------------------------------------------";
}

void menuLSDireDE() {
	gotoxy(1, 1); cout << " ------------------------    MOSTRANDO CASOS IMPORTANTES      --------------------------";
	gotoxy(1, 2); cout << " ---------------------------------------------------------------------------------------";
	gotoxy(1, 3); cout << "|NOMBRE           |MUNICIPIO      |NIT     |CONSUMO   |DR_MEMORIA                       ";
	gotoxy(1, 4); cout << " ---------------------------------------------------------------------------------------";
}

struct productDE {
	string nombreMayorista;
	string municipoMayorista;
	string nitMayorista;
	string consumoMayorista;
};

struct nodo9 {
	struct productDE datLD;
	int dato;
	nodo9* siguientedou;
	nodo9* atrasduo;
} *primero12, * ultimo12;

void insertarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* nuevodd = new (nodo9);
	menuDE();
	gotoxy(1, 5); cin >> nuevodd->datLD.nombreMayorista;
	gotoxy(20, 5); cin >> nuevodd->datLD.municipoMayorista;
	gotoxy(38, 5); cin >> nuevodd->datLD.nitMayorista;
	gotoxy(59, 5); cin >> nuevodd->datLD.consumoMayorista;

	if (primero12 == NULL) {
		primero12 = nuevodd;
		primero12->siguientedou = NULL;
		primero12->atrasduo = NULL;
		ultimo12 = primero12;
	}
	else {
		ultimo12->siguientedou = nuevodd;
		nuevodd->siguientedou = NULL;
		nuevodd->atrasduo = ultimo12;
		ultimo12 = nuevodd;
	}
	cout << "\n Datos del cliente correctamete ingresados... \n\n";
	_getch();
}

void eliminarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualee = new nodo9();
	actualee = primero12;
	nodo9* anterioree = new nodo9();
	anterioree = NULL;
	bool encontradoee = false;
	string nodoBuscadoee;
	desplegarListaPUduo();
	cout << " \n\n ------------------------------------------------------- \n\n";
	cout << " \nIngrese el nombre del cliente a Buscar para Eliminar: ";
	cin >> nodoBuscadoee;
	if (primero12 != NULL) {

		while (actualee != NULL && encontradoee != true) {

			if (actualee->datLD.nombreMayorista == nodoBuscadoee) {
				cout << "\n El cliente  ( " << nodoBuscadoee << " ) se encuentra registrado";

				if (actualee == primero12) {
					primero12 = primero12->siguientedou;
					primero12->atrasduo = NULL;
				}
				else if (actualee == ultimo12) {
					anterioree->siguientedou = NULL;
					ultimo12 = anterioree;
				}
				else {
					anterioree->siguientedou = actualee->siguientedou;
					actualee->siguientedou->atrasduo = anterioree;
				}

				cout << "\n Cliente Eliminado";
				encontradoee = true;
			}
			anterioree = actualee;
			actualee = actualee->siguientedou;
		}

		if (!encontradoee) {
			cout << "\n Cliente no Encontrado\n\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void desplegarListaPUduo() {
	int j = 1;
	system("mode con: cols=100 lines=25");
	menuLSDireDE();
	nodo9* actualdede = new nodo9();
	actualdede = primero12;
	if (primero12 != NULL) {
		while (actualdede != NULL) {
			gotoxy(1, 5 + j); cout << actualdede->datLD.nombreMayorista;
			gotoxy(20, 5 + j); cout << actualdede->datLD.municipoMayorista;
			gotoxy(35, 5 + j); cout << actualdede->datLD.nitMayorista;
			gotoxy(45, 5 + j); cout << "Q." << actualdede->datLD.consumoMayorista;
			actualdede = actualdede->siguientedou;
			gotoxy(56, 5 + j); cout << actualdede;
			j++;
		}
	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////// ingresar solo 5 datos.

void desplegarListaUPduo() {
	int up = 1;
	system("mode con: cols=100 lines=25");
	menuLSDireDE();
	nodo9* actualup = new nodo9();
	actualup = ultimo12;
	if (primero12 != NULL) {

		while (actualup != NULL) {
			gotoxy(1, 10 - up); cout << actualup->datLD.nombreMayorista;
			gotoxy(20, 10 - up); cout << actualup->datLD.municipoMayorista;
			gotoxy(35, 10 - up); cout << actualup->datLD.nitMayorista;
			gotoxy(45, 10 - up); cout << "Q." << actualup->datLD.consumoMayorista;
			actualup = actualup->atrasduo;
			gotoxy(56, 10 - up); cout << actualup;
			up--;
		}
	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}


//Listas Circulares 
void menuDobleM() {
	gotoxy(1, 1); cout << " -----------------------------   CLIENTES DEUDORES   -------------------------";
	gotoxy(1, 2); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 3); cout << " DPI               |NOMBRE           |TEL                |DEUDA               ";
	gotoxy(1, 4); cout << " -----------------------------------------------------------------------------";
}

void menuDobleMdire() {
	gotoxy(1, 1); cout << " ------------------------     MOSTRANDO CLIENTES DEUDORES     --------------------------";
	gotoxy(1, 2); cout << " ---------------------------------------------------------------------------------------";
	gotoxy(1, 3); cout << " DPI              |NOMBRE         |TEL     |DEUDA    |DRIRECCION DE MEMORIA             ";
	gotoxy(1, 4); cout << " ---------------------------------------------------------------------------------------";
}
struct productLC {
	int dpideudor;
	string nombredeudor;
	string telefono;
	string deudadeudor;
};

struct nodo10 {
	struct productLC ProdLC;
	int dato;
	nodo10* siguientecir;
} *primerocir, * ultimocir;

void insertarNodocir() {
	system("mode con: cols=80 lines=25");
	menuDobleM();
	nodo10* nuevoinsert = new nodo10();
	gotoxy(1, 5); cin >> nuevoinsert->ProdLC.dpideudor;
	gotoxy(20, 5); cin >> nuevoinsert->ProdLC.nombredeudor;
	gotoxy(38, 5); cin >> nuevoinsert->ProdLC.telefono;
	gotoxy(59, 5); cin >> nuevoinsert->ProdLC.deudadeudor;


	if (primerocir == NULL) {
		primerocir = nuevoinsert;
		primerocir->siguientecir = primerocir;
		ultimocir = primerocir;
	}
	else {
		ultimocir->siguientecir = nuevoinsert;
		nuevoinsert->siguientecir = primerocir;
		ultimocir = nuevoinsert;
	}
	cout << "\n Datos del cliente correctamete ingresados...\n\n";
	_getch();
}

void eliminarNodocir() {
	system("mode con: cols=80 lines=25");
	nodo10* actualElimin = new nodo10();
	actualElimin = primerocir;
	nodo10* anteriorElimin = new nodo10();
	anteriorElimin = NULL;
	bool encontradoElimin = false;
	int nodoBuscadoElimins = 0;
	desplegarListacir();
	cout << " \n\n ------------------------------------------------------- \n\n";
	cout << "\n Ingrese el nombre del cliente a Buscar para Eliminar: ";
	cin >> nodoBuscadoElimins;
	if (primerocir != NULL) {
		do {

			if (actualElimin->ProdLC.dpideudor == nodoBuscadoElimins) {
				cout << "\n El cliente ( " << nodoBuscadoElimins << " ) se encuentra registrado";

				if (actualElimin == primerocir) {
					primerocir = primerocir->siguientecir;
					ultimocir->siguientecir = primerocir;
				}
				else if (actualElimin == ultimocir) {
					anteriorElimin->siguientecir = primerocir;
					ultimocir = anteriorElimin;
				}
				else {
					anteriorElimin->siguientecir = actualElimin->siguientecir;
				}

				cout << "\n Cliente Eliminado\n\n";
				encontradoElimin = true;
			}
			anteriorElimin = actualElimin;
			actualElimin = actualElimin->siguientecir;
		} while (actualElimin != primerocir && encontradoElimin != true);
		if (!encontradoElimin) {
			cout << "\n Cliente No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}

void desplegarListacir() {
	int k = 0;
	system("mode con: cols=100 lines=25");
	menuDobleMdire();
	nodo10* actualdespleg = new nodo10();
	actualdespleg = primerocir;
	if (primerocir != NULL) {
		do {
			gotoxy(1, 5 + k); cout << actualdespleg->ProdLC.dpideudor;
			gotoxy(20, 5 + k); cout << actualdespleg->ProdLC.nombredeudor;
			gotoxy(35, 5 + k); cout << actualdespleg->ProdLC.telefono;
			gotoxy(45, 5 + k); cout << "Q." << actualdespleg->ProdLC.deudadeudor;
			actualdespleg = actualdespleg->siguientecir;
			gotoxy(56, 5 + k); cout << actualdespleg;
			j++;
		} while (actualdespleg != primerocir);
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}



//Parte de arboles de busqueda binarios
void menuABBasas() {
	gotoxy(1, 1); cout << " ---------------------------  DATOS  DE  ABOGADOS   --------------------------";
	gotoxy(1, 2); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 3); cout << "|CODIGO DEL ABOGADO     |NOMBRE DEL ABOGADO         |TELEFONO                  ";
	gotoxy(1, 4); cout << " -----------------------------------------------------------------------------";
}
void menuABBls() {
	gotoxy(1, 1); cout << " --------------------";
	gotoxy(1, 2); cout << "|                    |";
	gotoxy(1, 3); cout << "|                    |";
	gotoxy(1, 4); cout << "|                    |";
	gotoxy(1, 5); cout << "|                    |";
	gotoxy(1, 6); cout << "|                    |";
	gotoxy(1, 7); cout << " --------------------";

}

struct datosABBes {
	int CodigoProAbb;
	string nombreProabb;
	string telprodabb;
	struct datosABBes* izqabb, * derabb;
};
//prototipos ABB
//void mostrarArbol(odo* miArbol );

typedef struct datosABBes* ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodoabb(int x)
{
	ABB nuevoNodocrearABB = new(struct datosABBes);
	nuevoNodocrearABB->CodigoProAbb = x;
	nuevoNodocrearABB->nombreProabb;
	nuevoNodocrearABB->telprodabb;
	nuevoNodocrearABB->izqabb = NULL;
	nuevoNodocrearABB->derabb = NULL;

	return nuevoNodocrearABB;
}

void insertarabb(ABB& arbolinsabb, int x)
{
	if (arbolinsabb == NULL)
	{
		arbolinsabb = crearNodoabb(x);
	}
	else if (x < arbolinsabb->CodigoProAbb)
		insertarabb(arbolinsabb->izqabb, x);
	else if (x > arbolinsabb->CodigoProAbb)
		insertarabb(arbolinsabb->derabb, x);
	_getch();
}

void preOrden(ABB arbolpreordeabb)
{
	if (arbolpreordeabb != NULL)
	{
		cout << arbolpreordeabb->CodigoProAbb << " ";
		preOrden(arbolpreordeabb->izqabb);
		preOrden(arbolpreordeabb->derabb);
	}
}

void enOrden(ABB arbolenoabb)
{
	if (arbolenoabb != NULL)
	{
		enOrden(arbolenoabb->izqabb);
		cout << arbolenoabb->CodigoProAbb << " ";
		enOrden(arbolenoabb->derabb);
	}
}

void postOrden(ABB arbolpostabb)
{
	if (arbolpostabb != NULL)
	{
		postOrden(arbolpostabb->izqabb);
		postOrden(arbolpostabb->derabb);
		cout << arbolpostabb->CodigoProAbb << " ";
	}
}


int auxXabb = 0;
ABB arbolABB = NULL;
void mostrarArbolabb(ABB arbolmostabb, int auxYabb) {
	if (arbolmostabb == NULL) {//Arbol vacio nada que mostrar

		return;
	}

	auxXabb += 5;//variable que permite posicionarse en el eje X

	mostrarArbolabb(arbolmostabb->izqabb, auxYabb + 2);//Se para hasta el nodo mas a la izquierda del árbol construye primero el subarbol izq porque sus valores en X son menores
	gotoxy(20 + auxXabb - auxYabb, 10 + auxYabb);//posiciona el nodo segun sus variables en X y en Y

	cout << arbolmostabb->CodigoProAbb;// << endl << endl;//Muestra el dato del nodo respectivo

	//auxX = 0;
	mostrarArbolabb(arbolmostabb->derabb, auxYabb + 2);
}

void MenuArbol() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repitevool = true;
	int opcabb;

	const char* tituabb = "--------------------- REGISTRO DE ABOGADOS   (METODO ABB) ---------------------";
	const char* opcionesabb[] = { " Agregar datos de proveedores al arbol", " Mostrar el arbol completo", " Eliminar un nodo del arbol", " Regresar al menu principal" };
	int ndatoabb = 4;
	int datoxabb, contadorabb = 0;

	do {
		// creado Arbol
		int contadorABB = 0;
		int nabb;  // numero de nodos del arbol
		int xabb; // elemento a insertar en cada nodo
		string yabb;
		string zabb;
		opcabb = menu(tituabb, opcionesabb, ndatoabb);
		switch (opcabb) {
		case 1:
			system("cls");
			system("mode con: cols=80 lines=25");
			cout << " Digite cantidad de datos a igresar:  ";
			cin >> nabb;
			cout << endl;
			menuABBasas();
			for (int i = 0; i < nabb; i++)
			{
				//cout << " Numero de comprobante  " << i + 1 << ": ";
				gotoxy(1, i + 5); cin >> xabb;
				//cout << " Nombre del cliente: ";
				gotoxy(27, i + 5); cin >> yabb;
				//cout << " Metodo de pago: ";
				gotoxy(52, i + 5); cin >> zabb;
				//cout << "\n";
				insertarabb(arbolABB, xabb);
			}
			//cin >> datoxabb;
			//agregarNodoABB(arbol, datoxabb, NULL);
			system("pause");
			break;
		case 2:
			system("cls");
			system("mode con: cols=80 lines=25");
			cout << "\nMostrando el arbol completo: \n";

			//verArbol(arbol, 0);

			mostrarArbolabb(arbolABB, contadorABB);
			auxXabb = 0;

			cout << "\n Recorridos del Árbol ABB";
			cout << "\n\n En orden   :  ";   enOrden(arbolABB);
			cout << "\n\n Pre Orden  :  ";   preOrden(arbolABB);
			cout << "\n\n Post Orden :  ";   postOrden(arbolABB);
			cout << endl << endl;
			//mostrarArbolABB(arbol, contadorabb);
			_getch();
			break;
		case 3:
			system("cls");
			break;
		}
		//system("cls");
	} while (opcabb != 3);
}


//Arboles AVL///////////////////////////

struct Nodo13 {
	int dataavl;
	Nodo13* deravl;
	Nodo13* izqavl;
};


//Identificadores
Nodo13* crearRNodoavl(int);
void pushavl(Nodo13*&, int);
void viewavl(Nodo13*, int);
void menuavl();

class arbolAVL {
	int altura(Nodo13*);
	int diferencia(Nodo13*);
	Nodo13* bal(Nodo13*);
	Nodo13* rr(Nodo13*);
	Nodo13* ll(Nodo13*);
	Nodo13* lr(Nodo13*);
	Nodo13* rl(Nodo13*);
};

Nodo13* arbolA = NULL;

int altura(Nodo13* arbolalvs) {
	int h = 0;
	if (arbolalvs != NULL) {
		int lh = altura(arbolalvs->izqavl);
		int rh = altura(arbolalvs->deravl);
		int maxh = max(lh, rh);
		h = maxh + 1;
	}
	return h;
}

int diferencia(Nodo13* arbol) {
	int lh = altura(arbol->izqavl);
	int rh = altura(arbol->deravl);
	int factor = lh - rh;
	return factor;
}

int auxXZ = 0;

void viewavl(Nodo13* arbolviewavl, int auxY) { //arbol vacio nada que mostrar 

	if (arbolviewavl == NULL) {
		return;
	}
	auxXZ += 5;//Variable que permite poscionarse en el eje X

	viewavl(arbolviewavl->izqavl, auxY + 2);//Más a la izquierda, construye primero el subarbol izq
	gotoxy(18 + auxXZ - auxY, 10 + auxY);//posciona el nodo según sus variables en X y en Y
	cout << arbolviewavl->dataavl;//Muestra el el dato del nodo respectivo 

	viewavl(arbolviewavl->deravl, auxY + 2);
}

void MenuArbolAVL() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repitevool = true;
	int opcavls;
	const char* tituavl = "---------------------- REGISTRO DE SUCURSALES (METODO AVL) ----------------------";
	const char* opcionesavl[] = { " Insertar nuevo nodo", " Imprimir arbol AVL", " Regresar al menu principal" };
	int ndatoavl = 3;
	int datoxabb, contadorabb = 0;
	int avlv = 0, opavlss = 0, contavl = 0;
	do {
		opcavls = menu(tituavl, opcionesavl, ndatoavl);
		switch (opcavls) {
		case 1:
			system("cls");
			system("mode con: cols=80 lines=25");
			cout << "1-. Insertar nuevo nodo" << endl;
			cin >> avlv; pushavl(arbolA, avlv);
			cout << "------------------------------" << endl;
			_getch();
			break;
		case 2:
			system("cls");
			system("mode con: cols=80 lines=25");
			cout << "2-. Imprimir arbol AVL" << endl;
			cout << "Arbol AVL actual:" << endl;
			cout << "------------------------------" << endl;
			viewavl(arbolA, contavl);
			_getch();
		case 3:
			system("cls");
			break;
		}
	} while (opcavls != 3);
}

Nodo13* rr(Nodo13* parent) {
	Nodo13* arbolrr;

	arbolrr = parent->deravl;
	parent->deravl = arbolrr->izqavl;
	arbolrr->izqavl = parent;

	cout << "Rotacion RR";
	return arbolrr;
}

Nodo13* ll(Nodo13* parent) {
	Nodo13* arbolll;

	arbolll = parent->izqavl;
	parent->izqavl = arbolll->deravl;
	arbolll->deravl = parent;

	cout << "Rotacion LL";
	return arbolll;
}

Nodo13* lr(Nodo13* parent) {
	Nodo13* arbollr;

	arbollr = parent->izqavl;
	parent->izqavl = rr(arbollr);

	cout << "Rotacion LR";
	return ll(parent);
}

Nodo13* rl(Nodo13* parent) {
	Nodo13* arbolrl;

	arbolrl = parent->deravl;
	parent->deravl = ll(arbolrl);

	cout << "Rotacion RL";
	return rr(parent);
}

Nodo13* bal(Nodo13* arbolball) {
	int factor = diferencia(arbolball);

	if (factor > 1) {
		if (diferencia(arbolball->izqavl) > 0) {
			arbolball = ll(arbolball);
		}
		else {
			arbolball = lr(arbolball);
		}
	}
	else if (factor < -1) {
		if (diferencia(arbolball->deravl) > 0) {
			arbolball = rl(arbolball);
		}
		else {
			arbolball = rr(arbolball);
		}
	}
	return arbolball;
}

void pushavl(Nodo13*& arbolpshusavls, int n) {

	if (arbolpshusavls == NULL) {
		cout << "Nodo vacio.. creando..." << endl;
		system("pause");

		Nodo13* nuevoNodo = crearRNodoavl(n);
		arbolpshusavls = nuevoNodo;
	}
	else {
		int root = arbolpshusavls->dataavl;
		if (n < root) {
			cout << "izquierda.." << endl;
			pushavl(arbolpshusavls->izqavl, n);
			arbolpshusavls = bal(arbolpshusavls);
		}
		else {
			cout << "derecha..." << endl;
			pushavl(arbolpshusavls->deravl, n);
			arbolpshusavls = bal(arbolpshusavls);
		}
	}
}

Nodo13* crearRNodoavl(int n) {
	Nodo13* nuevoNodoavlss = new Nodo13();
	nuevoNodoavlss->dataavl = n;
	nuevoNodoavlss->deravl = NULL;
	nuevoNodoavlss->izqavl = NULL;
	return nuevoNodoavlss;
}