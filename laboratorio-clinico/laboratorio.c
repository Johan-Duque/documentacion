#include <string.h>
#include <conio.h>
#include <stdlib.h>  
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
#define TAM 999

//Laboratorio clinico proyecto. Equipo numero 6
//Angel Nereo Molina Ortiz 30201824
//Johan Omar Duque Pereira 30.920.845
//Arturo Alejandro Carvajalino Vivas 30.889.966

void gotoxy(int,int);
void recuadro(int,int,int,int);
void recuadro_figuras(int,int,int,int);
void centrarTexto(char *, int y);
void margen();
void barra_de_carga();
void asteriscos(char, char *, int, bool, int);
void espacios_vacios(char *, int, int);
void borrar_espacios(int, int);
void tabla(int x, int fila);
HANDLE wHnd;

typedef struct {
    char nombre[TAM];
    float cantidad;
    char fecha[TAM];
    char categoria[TAM];
    int dia;
    int year;
    char mes[TAM];
} Gasto;
Gasto g[TAM];
int num_gastos = 0;
float total_gastos = 0.0;
typedef struct{
	
char nombre[TAM];
char apellido[TAM];
char DNI[TAM];
char tipo_examen[TAM];
float pago;
} clientes;
clientes cliente[TAM];

 typedef struct{
 	
float ingresos;
float nomina;
float costos;
float totalGastos;
float utilidad;
}dinero;
dinero finanzas;

int indice = 0;

float sumarIngresos( clientes* cliente, dinero* finanzas);

typedef struct{
	
char nombre[TAM];
char apellido[TAM];
char DNI[TAM];
char especializacion[TAM];
float sueldo;
} empleados;
empleados empleado[TAM];
total_sueldo=0;
float calcularIngresos() {
    float ingresos = 0.0;
    int i;
    for (i = 0; i < indice; i++) {
        ingresos += cliente[i].pago;
    }
    return ingresos;
}

float calcularGastos() {
    int j;
    float t_gastos = 0.0;
    for (j = 0; j < num_gastos; j++) {
        t_gastos += g[j].cantidad; // sumamos el gasto actual al total
    }
    return t_gastos;
}

float calcularSueldos() {
    float totalSueldos = 0.0;
    int i;
    for (i = 0; i < indice; i++) {
        totalSueldos += empleado[i].sueldo;
    }
    return totalSueldos;
}

float totalganancias=0;


float calcularGanancia(){
		float ingres=calcularIngresos();
	float gasts=calcularGastos()/30;
	float suels=calcularSueldos()/30;
    float ganancia = ingres - gasts- suels;
    return ganancia;
}

int main(){
	
	int login=0;
	
	system("COLOR B0");
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 80, 25};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    
       // ---- VARIABLES ---- //
    char tempUser, confirmUser;
	char mesNombre[12][TAM] = {"Enero","Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "octubre", "Noviembre","Diciembre"};
    char respuesta_clave[TAM], respuesta_usuario[TAM], usuario1[TAM] = "ADMIN", clave1[TAM] = "1234", caracter, opcion, respuesta_examen_nuevo, respuesta_tipo_de_examen[TAM], respuesta_x[TAM];;
    char examenes[TAM][TAM] = {"hemonograma", "Urinalisis", "Perfil lipidico","acido urico","Perfil renal","coprocultivo","lipograma","Examen de Heces", "Prueba de embarazo", "analisis de hormonas"};
 
    int dia=10, mes=3, year=2023,  validador = 0, indice_1 = 0, indice_c = 0, indice_e = 0, indice_g = 0, reset=1,indiceMax=0, indice_nomina, fila = 0, fila_2 = 0, contador[9], max_contador = 0, tipo_max_contador = 0, i = 0, indice_x = 10;
    bool mostrador = false;
    
    Gasto gastos[100];
  
	do{
    
    // --- INCIO DE SESION --- //
    for (dia = 10; dia < 365; dia++){

		if(mes==2 && dia>28){
			mes+1;
			dia=1;
		}
		if(mes==0||mes==2||mes==4||mes==6||mes==7||mes==9||mes==11){
			if (dia>31)
		{
			mes++;
			dia=1;
		}
		}
		if (dia>30)
		{
			mes++;
			dia=1;
		}
		if (mes>12)
		{
			year++;
			dia=1;
			mes=1;
		}
		
	system("cls"); 
	margen();
    centrarTexto("LABORATORIO CLINICO",2);
    centrarTexto("INICIO DE SESION",9);
    recuadro(21,10,59,14);
	//gotoxy(3,5); printf("%d/%s/%d", dia, mesNombre[mes], year); 
    gotoxy(3,5); printf("11/05/2024"); 	
	gotoxy(23,11); printf("%c ",254); printf("Usuario: "); 
	gotoxy(23,13); printf("%c ",254); printf("Clave: "); 
	gotoxy(17,22); printf("Usuario: ADMIN | Clave: 1234"); 
	
	mostrador = false;
	gotoxy(34,11); asteriscos(caracter, respuesta_usuario, indice_1, mostrador, 23);
	
	while(strcmp(usuario1,respuesta_usuario) != 0){
		printf("\a");	
		recuadro(29,16,50,18);
		centrarTexto("USUARIO NO VALIDO",17);
		gotoxy(34,11); printf("                       ");
		gotoxy(34,11); asteriscos(caracter, respuesta_usuario, indice_1, mostrador, 23);
	}
	
	borrar_espacios(28,15);
	mostrador = true;
	gotoxy(32,13); asteriscos(caracter, respuesta_clave, indice_1, mostrador, 25);
		
	while(strcmp(clave1,respuesta_clave) != 0){
		printf("\a");	
		recuadro(29,16,50,18);
		centrarTexto("CLAVE NO VALIDA",17);
		gotoxy(32,13); printf("                       ");
		gotoxy(32,13); asteriscos(caracter, respuesta_clave, indice_1, mostrador, 25);
	}	
	
	borrar_espacios(28,15);
	
	gotoxy(17,22); printf("                                                         "); 
	gotoxy(22,22); system("pause");
	
	barra_de_carga();
	
	system("cls"); 
	
	do{
	system("cls"); 
	margen();
    centrarTexto("LABORATORIO CLINICO",2);
		
	centrarTexto("MENU DE OPCIONES",5);
	centrarTexto("Registrar clientes        [1]",7);
	centrarTexto("Registrar empleados 	    [2]",8);
	centrarTexto("lista de examenes         [3]",9);
    centrarTexto("Reportes del laboratorio  [4]",10);
    centrarTexto("Registra gastos           [5]",11);
    centrarTexto("Configuracion             [6]",12);
	centrarTexto("Cerrar sesion             [7]",13);
	centrarTexto("Salir del sistema         [8]",14);
	
	gotoxy(26,16); fflush(stdin); scanf("%c",&opcion); fflush(stdin);
	
	while(opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '5' && opcion != '6'  && opcion != '7' && opcion != '8'){
		
	printf("\a");	
	recuadro(29,17,50,19);
	centrarTexto("OPCION NO VALIDA",18);
	gotoxy(26,16); printf("                  ");
	gotoxy(26,16); fflush(stdin); scanf("%c",&opcion); fflush(stdin);	
		
	}
	
	borrar_espacios(28,17);
	barra_de_carga();
		
	//	---  //
		
	if(opcion == '1'){
	
	validador = 0;
		
	margen();
    centrarTexto("REGISTRO DEL LABORATORIO CLINICO",2);
    centrarTexto("REGISTRO DE CLIENTES",5);
    
    gotoxy(3,7); printf("%c ",254); printf("Nombre: ");
    gotoxy(3,9); printf("%c ",254); printf("Apellido: ");
    gotoxy(3,11); printf("%c ",254); printf("Cedula: ");  
    gotoxy(3,13); printf("%c ",254); printf("Consulta: ");
	gotoxy(3,15); printf("%c ",254); printf("Monto a pagar: ");
    
    mostrador = false;
    
    gotoxy(13,7); asteriscos(caracter, cliente[indice_c].nombre, indice_1, false, 10);
    espacios_vacios(cliente[indice_c].nombre,13,7);
    borrar_espacios(55,5);
    
    gotoxy(15,9); asteriscos(caracter, cliente[indice_c].apellido, indice_1, false, 12);
    espacios_vacios(cliente[indice_c].apellido,15,9);
    borrar_espacios(55,5);
    
    gotoxy(13,11); asteriscos(caracter, cliente[indice_c].DNI, indice_1, false, 10);
    espacios_vacios(cliente[indice_c].DNI,13,11);
    borrar_espacios(55,5);
    
    gotoxy(15,13); gets(cliente[indice_c].tipo_examen); fflush(stdin);
    espacios_vacios(cliente[indice_c].tipo_examen,15,13);
	        
	int e = 0;
		
	for(e = 0; e < TAM-1; e++){
		
		if(strcasecmp(cliente[indice_c].tipo_examen,examenes[e]) != 0){			
		validador++;				
		}
		
		if(validador == TAM-1){
			
		validador = 0;
		e = -1;	
		
		printf("\a");
		
		borrar_espacios(55,5);	
		recuadro(55,6,77,8);	
		gotoxy(56,7); printf("ESE EXAMEN NO EXISTE");
				
		gotoxy(15,13); printf("                           ");
		gotoxy(15,13); gets(cliente[indice_c].tipo_examen); fflush(stdin);
		gotoxy(56,7); printf("                     ");
    	espacios_vacios(cliente[indice_c].tipo_examen,15,13);
    	borrar_espacios(50,5);
									
		} 
	}
	
	cliente[indice_c].pago = 0;

	borrar_espacios(55,5);
	gotoxy(20,15); scanf("%f",&cliente[indice_c].pago);
	finanzas.ingresos += cliente[indice].pago; // Actualizar los ingresos
    
    indice++; // Aumentar el ï¿½ndice de clientes
    
	borrar_espacios(50,5);
	    
    indice_c++;
    
    gotoxy(22,22); system("pause");
	
	barra_de_carga();
	
	}
	
	if(opcion == '2'){
	
	validador = 0;
		
	margen();
    centrarTexto("REGISTRO DEL LABORATORIO CLINICO",2);
    centrarTexto("REGISTRO DE EMPLEADOS",5);
    
    gotoxy(3,7); printf("%c ",254); printf("Nombre: ");
    gotoxy(3,9); printf("%c ",254); printf("Apellido: ");
    gotoxy(3,11); printf("%c ",254); printf("Cedula: ");  
    gotoxy(3,13); printf("%c ",254); printf("Especializacion: ");
	gotoxy(3,15); printf("%c ",254); printf("Sueldo Mensual: ");
    
    gotoxy(13,7); asteriscos(caracter, empleado[indice_e].nombre, indice_1, false, 10);
    espacios_vacios(empleado[indice_e].nombre,13,7);
    borrar_espacios(55,5);
    
    gotoxy(15,9); asteriscos(caracter, empleado[indice_e].apellido, indice_1, false, 10);
    espacios_vacios(empleado[indice_e].apellido,15,9);
    borrar_espacios(55,5);
    
    gotoxy(13,11); asteriscos(caracter, empleado[indice_e].DNI, indice_1, false, 10);
    espacios_vacios(empleado[indice_e].DNI,13,11);
    borrar_espacios(55,5);
    
    gotoxy(22,13); gets(empleado[indice_e].especializacion); fflush(stdin);
    espacios_vacios(empleado[indice_e].especializacion,22,13);
    
	int e = 0;
		
	for(e = 0; e < TAM-1; e++){
		
		if(strcasecmp(empleado[indice_e].especializacion,examenes[e]) != 0){			
		validador++;				
		}
		
		if(validador == TAM-1){
			
		validador = 0;
		e = -1;	
		
		printf("\a");
		
		borrar_espacios(55,5);	
		recuadro(55,6,77,8);	
		gotoxy(58,7); printf("NO EXISTE ESA AREA");
				
		gotoxy(22,13); printf("                           ");
    	gotoxy(22,13); gets(empleado[indice_e].especializacion); fflush(stdin);
    	gotoxy(56,7); printf("                     ");
    	espacios_vacios(empleado[indice_e].especializacion,22,13);
    	borrar_espacios(51,5);
									
		} 
	}
	
	borrar_espacios(55,5);
	
	gotoxy(21,15); scanf("%f",&empleado[indice_e].sueldo);
	indice++;
    finanzas.nomina = calcularSueldos();
    indice_e++;
    
    gotoxy(22,22); system("pause");
	
	barra_de_carga();
	
	}
	
	if (opcion == '3'){
						
		fila = 5;
		fila_2 += fila;
		
		system("cls");
		margen();
 		centrarTexto("EXAMENES DEL LABORATORIO CLINICO",2);
				
		for(i = 0; i < indice_x; i++){
					
			if(i >= 8){
			
			if(i == 8){
				fila = 5;
			}
			
			if(i >= 9){
				gotoxy(38,fila); printf("%c ",254); printf("Examen #[%i]: ",i+1);
				gotoxy(54,fila); printf("%s",examenes[i]);
			} else if(i < 9){
				gotoxy(38,fila); printf("%c ",254); printf("Examen #[%i]: ",i+1);
				gotoxy(53,fila); printf("%s",examenes[i]);
			}
							
			} else {
			
			gotoxy(4,fila); printf("%c ",254); printf("Examen #[%i]: ",i+1);
			gotoxy(19,fila); printf("%s",examenes[i]);	
			
			}
				
		fila+=2;
				
		}
		
		gotoxy(22,22); printf("%c ",254); system("pause");
				
	}
	
	if(opcion == '4'){
		
	do{
	system("cls");
	margen();
 	centrarTexto("REPORTES DEL LABORATORIO CLINICO",2);
		
	centrarTexto("MENU DE OPCIONES [REPORTES]",5);	
	centrarTexto("Reporte de empleados                    [1]",7);
	centrarTexto("Reporte de clientes                     [2]",8);
    centrarTexto("Reporte por tipo de Examen              [3]",9);
    centrarTexto("Reporte del Cliente con mayor gasto     [4]",10);
	centrarTexto("Reporte del Examen mas solicitado       [5]",11);
	centrarTexto("Reporte de ingresos                     [6]",12);
	centrarTexto("Reporte de gastos                       [7]",13);
	centrarTexto("Reporte de ganancias                    [8]",14); 
	centrarTexto("Reporte de ganancias                    [8]",14); 
	centrarTexto("Regresar al menu principal              [9]",15);

	gotoxy(19,17); fflush(stdin); scanf("%c",&opcion); fflush(stdin);
	
	while(opcion != '1' && opcion != '2' && opcion != '3' && opcion != '4' && opcion != '5' && opcion != '6' && opcion != '7' && opcion != '8' && opcion != '9'){
		
	printf("\a");	
	recuadro(29,18,50,20);
	centrarTexto("OPCION NO VALIDA",19);
	gotoxy(19,17); printf("                     ");
	gotoxy(19,17); fflush(stdin); scanf("%c",&opcion); fflush(stdin);	
		
	}
	
	borrar_espacios(28,18);
	
	barra_de_carga();	
	
if (opcion=='1'){

	margen();
	centrarTexto("EMPLEADOS REGISTRADOS [NOMINA]",2);
		
	fila = 7;
	fila_2 += fila;

	if(indice_e == 0){
		
		gotoxy(3,5); printf("%c ",254); printf("No hay empleados registrados");	
		gotoxy(3,7); printf("%c ",254); system("pause");	
		
	} else {
		
	gotoxy(6,5); printf("NOMBRE");
	gotoxy(19,5); printf("APELLIDO");
	gotoxy(34,5); printf("CEDULA");
	gotoxy(46,5); printf("SUELDO");
	gotoxy(58,5); printf("ESPECIALIZACION");
	
	indice_nomina = 0;
	i = 0;
	
	for(indice_nomina = 0; indice_nomina < indice_e; indice_nomina++){
		
		gotoxy(4,fila); printf("%s", empleado[indice_nomina].nombre);
		gotoxy(17,fila); printf("%s",empleado[indice_nomina].apellido);
		gotoxy(32,fila); printf("%s",empleado[indice_nomina].DNI);
		gotoxy(45,fila); printf("%2.f",empleado[indice_nomina].sueldo); 	
		gotoxy(56,fila); printf("%s",empleado[indice_nomina].especializacion);
				
		for(i = 2; i <= 76; i++){
		
		gotoxy(i,6); printf("%c",196);
		if(indice_e > 0){
		gotoxy(i,fila+1); printf("%c",196);
			} 
		}
	
	fila+=2;
	
	}
	
	float totalSueldos = calcularSueldos();
	centrarTexto("[total del costo de la nomina: ",fila+1); printf("%.2f",totalSueldos); printf("]");
    //gotoxy(28,fila); printf("total del costo de la nomina: %.2f",totalSueldos);
	
	recuadro(2,4,76,fila-1);
	
	tabla(15,fila);
	tabla(30,fila);
	tabla(43,fila);
	tabla(54,fila);
	fila_2++;
	
	gotoxy(22,22); printf("%c ",254); system("pause");
		
	}

}

if (opcion=='2'){
	
	margen();
	centrarTexto("CLIENTES REGISTRADOS",2);
		
	fila = 7;
	fila_2 += fila;

	if(indice_c == 0){
		
	gotoxy(3,5); printf("%c ",254); printf("No hay clientes registrados");	
	gotoxy(3,7); printf("%c ",254);	system("pause");	
		
	} else {
		
	gotoxy(6,5); printf("NOMBRE");
	gotoxy(19,5); printf("APELLIDO");
	gotoxy(34,5); printf("CEDULA");
	gotoxy(47,5); printf("PAGO");
	gotoxy(62,5); printf("EXAMEN");
	
	indice_nomina = 0;
	i = 0;
	
	for(indice_nomina = 0; indice_nomina < indice_c; indice_nomina++){
		
		gotoxy(4,fila); printf("%s", cliente[indice_nomina].nombre);
		gotoxy(17,fila); printf("%s",cliente[indice_nomina].apellido);
		gotoxy(32,fila); printf("%s",cliente[indice_nomina].DNI); 
		gotoxy(45,fila); printf("%2.f",cliente[indice_nomina].pago);		
		gotoxy(56,fila); printf("%s",cliente[indice_nomina].tipo_examen); 
		
		for(i = 2; i <= 76; i++){
		
		gotoxy(i,6); printf("%c",196);
		if(indice_c > 0){
		gotoxy(i,fila+1); printf("%c",196);
			} 
		}
	
	fila+=2;
	
	}
	
	recuadro(2,4,76,fila-1);
	
	tabla(15,fila);
	tabla(30,fila);
	tabla(43,fila);
	tabla(54,fila);
	fila_2++;
	
	gotoxy(22,22); printf("%c ",254); system("pause");
		
	}
}

if (opcion=='3'){
	
	validador = 0;
	bool k = true;
	int k2 = 0;
	
	margen();
 	centrarTexto("REPORTES POR TIPO DE EXAMEN",2);
 	
 	fila = 7;
	fila_2 += fila;
	
	if(indice_c == 0){
	
	k = false;	
	gotoxy(3,5); printf("%c ",254); printf("No hay clientes registrados");	
	gotoxy(3,7); printf("%c ",254);	system("pause");
	k2 = 1;
		
	} else {
		
	gotoxy(3,5); printf("%c ",254); printf("Informacion del examen que esta buscando: "); gets(respuesta_tipo_de_examen); fflush(stdin);
 	
 	for(i = 0; i < TAM-1; i++){
		
		if(strcasecmp(respuesta_tipo_de_examen,examenes[i]) != 0){			
		validador++;				
		}
		
		if(validador == TAM-1){
			
		validador = 0;
		i = -1;	
		
		printf("\a");
		
		borrar_espacios(55,5);	
		recuadro(55,6,77,8);	
		gotoxy(58,7); printf("NO EXISTE ESA AREA");
				
		gotoxy(45,5); printf("                           ");
    	gotoxy(47,5); fflush(stdin); gets(respuesta_tipo_de_examen); fflush(stdin);
    	borrar_espacios(54,5);
									
		} 
	}
	
	gotoxy(3,5); printf("                                                              ");
			
		int e = 0;
		int j = 0;
		validador = 0;
		
	for(e = 0; e < TAM; e++){
		
		if(strcasecmp(cliente[e].tipo_examen,respuesta_tipo_de_examen) == 0){
			
		if(j == 0){
			gotoxy(6,5); printf("NOMBRE");
			gotoxy(19,5); printf("APELLIDO");
			gotoxy(34,5); printf("CEDULA");
			gotoxy(47,5); printf("PAGO");
			gotoxy(62,5); printf("EXAMEN");
			j++;
		}
					
		gotoxy(4,fila); printf("%s", cliente[e].nombre);
		gotoxy(17,fila); printf("%s",cliente[e].apellido);
		gotoxy(32,fila);  printf("%s",cliente[e].DNI);
		gotoxy(45,fila); printf("%2.f",cliente[e].pago);		
		gotoxy(56,fila); printf("%s",cliente[e].tipo_examen); 
		
		for(i = 2; i <= 76; i++){
		
		gotoxy(i,6); printf("%c",196);
		if(indice_c > 0){
		gotoxy(i,fila+1); printf("%c",196);
			} 
		}
	
		fila+=2;
		
		recuadro(2,4,76,fila-1);
	
		tabla(15,fila);
		tabla(30,fila);
		tabla(43,fila);
		tabla(54,fila);
		fila_2++;
		validador++;
		
		}
						
		}
		
		}
		
		if(validador == 0 && k == true){
			 
			gotoxy(3,5); printf("%c ",254); printf("													");	 			
 			gotoxy(3,5); printf("%c ",254); printf(" No hay clientes registrados para ese tipo de examen");	
			gotoxy(3,7); printf("%c ",254);	system(" pause");

		} else if(k2 != 1){ 
			gotoxy(22,22); printf("%c ",254); system("pause");
		}				
	}			

if (opcion=='4'){
	
	margen();
 	centrarTexto("REPORTES DEL LABORATORIO CLINICO",2);
	float maxGasto=0;
	float tempgasto=0;
	for (i = 0; i < indice_c; i++)
	{
	if (cliente[i].pago>maxGasto)
	{
	  maxGasto=cliente[i].pago;
	  tempgasto=maxGasto;
	  indiceMax=i;
	  max_contador++;
	}
	
	}
	if (max_contador==0){
		gotoxy(3,5);  printf("%c ",254); printf("Registre clientes para poder mostrar el tipo de examen mas solicitado");
	}
	
	if(max_contador>0){
		gotoxy(3,5); printf("%c ",254); printf("El cliente con mayor gasto fue %s %s y fue un monto de %2.f", cliente[indiceMax].nombre, cliente[indiceMax].apellido, cliente[indiceMax].pago);
	}
	
	gotoxy(22,22);system("pause");

}

if (opcion=='5'){
	
	margen();
 	centrarTexto("REPORTES DEL LABORATORIO CLINICO",2);
	
	i=0;
	
	for (i = 0; i < indice_c; i++) {
    if (contador[i] > max_contador) {
        max_contador = contador[i];
        tipo_max_contador = i;
		fflush(stdin);
    }
	}
	
	if (max_contador==0){
		gotoxy(3,5); printf("%c ",254); printf("Registre clientes para poder mostrar el tipo de examen mas solicitado");
		gotoxy(3,7); printf("%c ",254); system("pause"); 
	} else if (max_contador>0){
		fflush(stdin);
		gotoxy(3,5); printf("%c ",254);printf("El tipo de examen mas solicitado fue [%s], solicitado: '%d'.\n", cliente[tipo_max_contador].tipo_examen, max_contador);
		gotoxy(3,7); printf("%c ",254); system("pause"); 
	}

}

if (opcion=='6'){
	
	margen();
    centrarTexto("REPORTES DEL LABORATORIO", 2);
    
    // ...
    gotoxy(3,5); printf("%c ",254); printf("Ingresos: %.2f", calcularIngresos());
    // ...
		
	gotoxy(22,22);system("pause");
    system("cls");

}

if (opcion=='7'){

	margen();
    centrarTexto("REPORTE DE GASTOS", 2);
    
	    fila = 7;
		fila_2 += fila;
	    
    if(num_gastos > 0){
    	
	gotoxy(4,5);  printf("Gasto");
	gotoxy(15,5); printf("NOMBRE");
	gotoxy(29,5); printf("CANTIDAD");
	gotoxy(48,5); printf("FECHA");
	gotoxy(64,5); printf("CATEGORIA");
	
	int indice_G = 0;
	i = 0;
	
	for(indice_G = 0; indice_G < num_gastos; indice_G++){
		
		gotoxy(4,fila); printf("# %d", indice_G+1);
		gotoxy(12,fila); printf("%s", g[indice_G].nombre);
		gotoxy(28,fila); printf("%.2f", g[indice_G].cantidad);
		gotoxy(41,fila); printf("%d/%s/%d", g[indice_G].dia, g[indice_G].mes, g[indice_G].year);		
		gotoxy(62,fila);  printf("%s", g[indice_G].categoria);
		
		for(i = 2; i <= 76; i++){
		
		gotoxy(i,6); printf("%c",196);
		if(num_gastos > 0){
		gotoxy(i,fila+1); printf("%c",196);
			} 
		}
	
	fila+=2;
	
	}
	gotoxy(30,fila+1); printf("[Total de gastos: $%.2f", calcularGastos()); printf("]");
	recuadro(2,4,76,fila-1);
	
	tabla(10,fila);
	tabla(26,fila);
	tabla(39,fila);
	tabla(60,fila);
	fila_2++;
	
	gotoxy(22,22); printf("%c ",254); system("pause");
		
	} else {
		gotoxy(3,5); printf("%c ",254); printf("No hay gastos registrados recientemente");   	
		gotoxy(3,7);system("pause");
	}
    
    // Mostrar el total de gastos //
    //gotoxy(3,17); printf("Categoria: %s", gastos[i].categoria);

}

if (opcion=='8'){
	
	margen();
    centrarTexto("REPORTES DEL LABORATORIO", 2);
    centrarTexto("REPORTE GANANCIAS", 5);
        
    float totalganancias = calcularGanancia();
	gotoxy(3,5); printf("Las ganancias diarias son: %.2f", totalganancias);
	gotoxy(3,7); system("pause");
	
}
	
	system("cls");
		
	} while(opcion != '9');
	
	opcion = ' ';
	
	}	
	   
   if(opcion=='5'){
   	    
    char respuesta[TAM];

    // Ciclo principal para ingresar gastos
    while (1) {
        // Pedir al usuario los detalles del gasto
        
        margen();
 		centrarTexto("REGISTROS DEL LABORATORIO CLINICO",2);
 		centrarTexto("REGISTRO DE GASTOS",5);
        
        //Gasto g;
        
        gotoxy(3,7); printf("%c ",254); printf("Gasto #%d: ", num_gastos+1);
        gotoxy(3,9); printf("%c ",254); printf("Nombre: "); fflush(stdin); gets(g[indice_g].nombre); fflush(stdin);
        espacios_vacios(g[indice_g].nombre,13,9);
        borrar_espacios(54,6);
        
        gotoxy(3,11); printf("%c ",254); printf("Costo: "); scanf("%f", &g[indice_g].cantidad);
        getchar(); // para consumir el salto de lï¿½nea dejado por scanf

 		g[indice_g].dia = dia; g[indice_g].year = year; strcpy(g[indice_g].mes,mesNombre[mes]);

        gotoxy(3,13); printf("%c ",254); printf("Fecha: %d/%s/%d", g[indice_g].dia, g[indice_g].mes, g[indice_g].year); 
        gotoxy(3,15); printf("%c ",254); printf("Categoria: "); gets(g[indice_g].categoria); fflush(stdin);
        espacios_vacios(g[indice_g].categoria,16,15);
        borrar_espacios(54,6);

        // Guardar el gasto en el arreglo
        gastos[num_gastos] = g[indice_g];
        num_gastos++;
        total_gastos += g[indice_g].cantidad;
        
        indice_g++;

        // Preguntar al usuario si desea ingresar otro gasto
        gotoxy(3,17); printf("%c ",254); printf("�Desea ingresar otro gasto? (S/N): "); fgets(respuesta, 10, stdin);
        if (respuesta[0] != 'S' && respuesta[0] != 's') {
            break; // salir del ciclo principal
        } else {
        	system("cls");
		}
    }

	gotoxy(22,22);system("pause");

   }
   
   if (opcion=='6') {
   	
	int userOpcion=0;
	int	flag=0;
		
	do{
	
	system("cls");
		
	margen();
 	centrarTexto("CONFIGURACION DEL LABORATORIO CLINICO",2);
 	centrarTexto("CONFIGURACION",5);
 	
 	centrarTexto("Cambiar usuario           [1]",7);
 	centrarTexto("Cambiar Clave             [2]",8);
 	centrarTexto("Ingresar un nuevo examen  [3]",9);
 	centrarTexto("Volver al menu            [4]",10);
 	
	gotoxy(26,12); scanf("%d", &userOpcion); fflush(stdin);
	
	while(userOpcion != 1 && userOpcion != 2 && userOpcion != 3 && userOpcion != 4){
		
			recuadro(29,14,50,16);
			centrarTexto("OPCION NO VALIDA",15);
			gotoxy(25,12); printf("                     ");
			gotoxy(25,12); scanf("%d", &userOpcion); fflush(stdin);	
		
	}
	
	borrar_espacios(25,12);
		
if (userOpcion == 1){
			flag=0;
			char changeUser;
			do{
			flag=0;
			system("cls");	
			i=0;
			margen();
 			centrarTexto("CONFIGURACION DEL LABORATORIO CLINICO",2);
			gotoxy(3,5); printf("%c ",254); printf("ingrese el nuevo nombre de usuario: "); scanf("%s", &usuario1[i]); fflush(stdin);	
			gotoxy(3,6); printf("%c ",254); printf("estas seguro que quieres cambiar la clave? s/n: "); scanf("%c", &changeUser);
			if (changeUser=='s'||changeUser=='S'){
				flag=1;
			}
		} while (flag==0);
			recuadro(29,8,50,10);
			centrarTexto("CAMBIO EXITOSO",9);
			gotoxy(22,22);system("pause");
			barra_de_carga();
		}

		if (userOpcion== 2){
	
		do{
			
		system("cls");
		margen();
 		centrarTexto("CONFIGURACION DEL LABORATORIO CLINICO",2);
		gotoxy(3,5); printf("%c ",254); printf("Ingrese la nueva clave del usuario: "); scanf("%s", &clave1[0]); fflush(stdin);	
		gotoxy(3,7); printf("%c ",254); printf("Esta seguro que desea que esta sea la clave S/N : "); scanf("%c", &tempUser); fflush(stdin);
		borrar_espacios(28,9);
		
		if (tempUser=='s'||tempUser=='S'){
				flag=1;
		}
		
		}while(flag==0);
		recuadro(29,9,50,11);
		centrarTexto("CAMBIO EXITOSO",10);
		gotoxy(22,22);system("pause");
		barra_de_carga();
		}

		if (userOpcion== 3){
 		do{
 		 		 	
 		system("cls");
		fflush(stdin);	
		 					
		margen();
 		centrarTexto("CONFIGURACION DEL LABORATORIO CLINICO",2);
 		
 		gotoxy(3,5); printf("%c ",254); printf("Ingrese el nuevo examen al laboratorio: "); asteriscos(caracter, respuesta_x, indice_1, false, 19);
		espacios_vacios(respuesta_x,45,5);
		borrar_espacios(55,6);
		
		for(i = 0; i < TAM-1; i++){
		
		if(strcasecmp(respuesta_x,examenes[i]) != 0){			
		validador++;				
		} else if(strcasecmp(respuesta_x,examenes[i]) == 0){
			
			validador = 0;
			i = -1;	
		
			printf("\a");
		
			borrar_espacios(29,7);	
			recuadro(29,7,50,9);
			centrarTexto("ESE EXAMEN YA EXISTE",8);
			
			gotoxy(45,5); printf("                                "); 
			gotoxy(45,5); gets(respuesta_x);
			borrar_espacios(29,7);
			espacios_vacios(respuesta_x,45,5);
    		borrar_espacios(55,6);
    		
		}
		
		if(validador == TAM-1){
			
		strcpy(examenes[indice_x],respuesta_x);
		i = TAM + 1;

		recuadro(29,7,50,9);
		gotoxy(20,8); printf("                                                     ");
		centrarTexto("CAMBIO EXITOSO",8);
		borrar_espacios(29,7);
				 							
		} 
	}
			
		gotoxy(3,7); printf("%c ",254); printf("�Desea ingresar otro examen? [S]/[N]: "); scanf("%c",&respuesta_examen_nuevo);
		gotoxy(3,7); printf("                                                                ");
				
		indice_x++;	
						
		 } while(respuesta_examen_nuevo == 'S' || respuesta_examen_nuevo == 's');
 		
 		barra_de_carga();
		}
		
if(userOpcion==4){
	break;
}
	
	} while(userOpcion != 4);	

}
   
} while(opcion != '7' && opcion != '8');
	
	if(opcion == '8'){
		exit (-1);
	} 
	}
	
} while(opcion != '8'); 

}

    void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
	void recuadro(int xs, int ys, int xi, int yi){
		int i = 0;
		for(i = xs; i <= xi; i++){
			gotoxy(i,ys); printf("%c",196);
			gotoxy(i,yi); printf("%c",196);
		}
	
		for(i = ys; i <= yi; i++){
			gotoxy(xs,i); printf("%c",179);
			gotoxy(xi,i); printf("%c",179);
		}
		
		gotoxy(xs,ys); printf("%c",218);
		gotoxy(xi,yi); printf("%c",217);
		gotoxy(xi,ys); printf("%c",191);
		gotoxy(xs,yi); printf("%c",192);
	}
	
		void centrarTexto(char *texto, int y){
		int longitud = strlen(texto);
		gotoxy(40-(longitud/2),y);printf(texto);
	}
	
	void margen(){
    	recuadro(0,0,79,24);
	    recuadro(1,1,78,3);
  }
    
  	void barra_de_carga(){
		
	int i = 0;	
		
		centrarTexto("CARGANDO...",20);
	for(i = 3; i <= 75; i++){
		gotoxy(i,22); printf("%c",177);
	}
	
		for(i = 3; i <= 75; i++){
		gotoxy(i,22); printf("%c",219);
		Sleep(15);
	}
	
	system("cls");
	
	}
	
	void asteriscos(char caracter, char *respuesta, int indice, bool mostrador, int longitud){
		while(caracter = _getch()){
		if(caracter == 13){
			respuesta[indice] = '\0';
			break;
		} else if(caracter == 8){
			if(indice > 0){
				indice--;
				printf("\b \b");
			}
		} else {
			if(indice < longitud){
				if(mostrador == true){
				printf("*");
				respuesta[indice] = caracter;
				indice++;
			} else{
				printf("%c",caracter);
				respuesta[indice] = caracter;
				indice++;
			}	
		  } 
		}
	  }
	}
	
	void espacios_vacios(char *texto, int x, int y){
		
	while(strcmp(texto," ") == 0 || strcmp(texto,"") == 0){
		printf("\a");
		recuadro(55,6,77,8);	
		gotoxy(58,7); printf("HAY CAMPOS VACIOS");
    	gotoxy(x,y); gets(texto); fflush(stdin);
	}
		
	}
	
	void borrar_espacios(int x, int y){
	gotoxy(x,y);   printf("                        ");
	gotoxy(x,y+1); printf("                        ");
	gotoxy(x,y+2); printf("                        ");
	gotoxy(x,y+3); printf("                        ");
	}
	
	void tabla(int x, int fila){
		
	int i = 0;	
		
	 for(i = 4; i <= fila-1; i++){
		if(i == 4){
		gotoxy(x,i); printf("%c",194);	
		} else if(i == fila-1){
		gotoxy(x,i); printf("%c",193);	
		} else {
		gotoxy(x,i); printf("%c",179);	
		}
	}		
}
