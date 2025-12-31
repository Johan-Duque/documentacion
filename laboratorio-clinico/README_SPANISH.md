# Laboratorio Clínico - Sistema de Gestión por Consola

## Descripción General
Este es un sistema de gestión para un laboratorio clínico desarrollado en C. Permite la administración de clientes, empleados, exámenes, registro de gastos y generación de diversos reportes financieros y operativos. Es una aplicación de consola que simula las operaciones básicas de un laboratorio, diseñada específicamente para entornos Windows debido a las librerías utilizadas.

## Características
*   **Inicio de Sesión:** Sistema de autenticación con un usuario y clave predefinidos (`ADMIN`/`1234`). La aplicación gestiona un ciclo de fecha ficticio que avanza diariamente (aunque la fecha mostrada en el login es fija).
*   **Gestión de Clientes:**
    *   Registro de nuevos clientes con nombre, apellido, DNI, tipo de examen realizado y monto pagado.
    *   Validación del tipo de examen contra una lista predefinida.
*   **Gestión de Empleados:**
    *   Registro de nuevos empleados con nombre, apellido, DNI, especialización y sueldo mensual.
    *   **Nota:** La validación de la especialización se realiza incorrectamente contra la lista de exámenes.
*   **Gestión de Exámenes:**
    *   Visualización de la lista de exámenes disponibles.
    *   Funcionalidad para añadir nuevos exámenes al catálogo del laboratorio, incluyendo validación para evitar duplicados.
*   **Registro de Gastos:**
    *   Permite ingresar múltiples gastos, detallando el nombre del gasto, la cantidad, la fecha (generada automáticamente por el sistema) y la categoría.
*   **Reportes:** Un menú dedicado a la generación de varios informes:
    *   **Reporte de Empleados:** Muestra una tabla con todos los empleados registrados, sus datos personales y su sueldo, además del costo total de la nómina.
    *   **Reporte de Clientes:** Presenta una tabla con todos los clientes, sus datos personales, el pago realizado y el tipo de examen.
    *   **Reporte por Tipo de Examen:** Permite buscar y listar clientes que se realizaron un examen específico.
    *   **Cliente con Mayor Gasto:** Identifica y muestra los detalles del cliente que ha realizado el pago más alto.
    *   **Examen Más Solicitado:** Intenta identificar el tipo de examen más frecuente (la lógica de conteo puede requerir revisión).
    *   **Reporte de Ingresos:** Muestra el total acumulado de los pagos de los clientes.
    *   **Reporte de Gastos:** Lista todos los gastos registrados con sus detalles y el total acumulado de gastos.
    *   **Reporte de Ganancias:** Calcula y muestra la ganancia diaria, restando los gastos y sueldos diarios de los ingresos totales.
*   **Configuración:** Permite a los administradores:
    *   Cambiar el nombre de usuario de acceso.
    *   Cambiar la clave de acceso.
    *   Agregar nuevos tipos de exámenes al catálogo.
*   **Interfaz de Usuario:** Utiliza funciones de la librería `windows.h` y `conio.h` para crear una interfaz de texto interactiva en la consola, incluyendo:
    *   Recuadros y bordes para estructurar la información.
    *   Centrado automático de texto.
    *   Una barra de carga visual para transiciones entre pantallas.
    *   Entrada de datos con ocultamiento de caracteres (asteriscos) para contraseñas.
    *   Validación básica de entrada (campos vacíos, opciones inválidas).

## Estructura del Código

### Archivos de Cabecera Utilizados
*   `<string.h>`: Para funciones de manipulación de cadenas de caracteres (ej. `strcpy`, `strcmp`, `strcasecmp`).
*   `<conio.h>`: Contiene funciones para entrada/salida de consola, como `_getch()` para lectura de caracteres sin búfer.
*   `<stdlib.h>`: Ofrece funciones de propósito general, incluyendo `system()` para ejecutar comandos del sistema (ej. `cls` para limpiar pantalla).
*   `<stdio.h>`: La biblioteca estándar de entrada y salida (ej. `printf`, `scanf`, `gets`).
*   `<windows.h>`: Esencial para la interacción con la consola en Windows, proporcionando funciones como `SetConsoleCursorPosition` (para `gotoxy`), `GetStdHandle`, y `Sleep` (para pausas).
*   `<stdbool.h>`: Define el tipo booleano `bool` y los valores `true`/`false`.
*   `#pragma GCC diagnostic ignored "-Wwrite-strings"`: Deshabilita una advertencia específica del compilador GCC relacionada con el uso de literales de cadena en contextos de punteros no constantes.

### Estructuras de Datos
*   `Gasto`:
    *   `char nombre[TAM]`: Nombre o descripción del gasto.
    *   `float cantidad`: Cantidad monetaria del gasto.
    *   `char fecha[TAM]`: (No usado directamente, desfasado por `dia`, `mes`, `year`).
    *   `char categoria[TAM]`: Categoría a la que pertenece el gasto.
    *   `int dia`, `int year`: Día y año del gasto.
    *   `char mes[TAM]`: Mes del gasto (como cadena).
*   `clientes`:
    *   `char nombre[TAM]`, `char apellido[TAM]`: Nombre y apellido del cliente.
    *   `char DNI[TAM]`: Documento Nacional de Identidad del cliente.
    *   `char tipo_examen[TAM]`: Tipo de examen que se realizó el cliente.
    *   `float pago`: Monto que pagó el cliente.
*   `empleados`:
    *   `char nombre[TAM]`, `char apellido[TAM]`: Nombre y apellido del empleado.
    *   `char DNI[TAM]`: Documento Nacional de Identidad del empleado.
    *   `char especializacion[TAM]`: Especialización del empleado.
    *   `float sueldo`: Sueldo mensual del empleado.
*   `dinero`:
    *   `float ingresos`, `float nomina`, `float costos`, `float totalGastos`, `float utilidad`: Campos para almacenar diferentes valores financieros. Algunas de estas variables no se utilizan completamente en la implementación actual como parte de esta estructura.

### Variables Globales
*   `Gasto g[TAM]`: Arreglo global para almacenar objetos `Gasto`.
*   `int num_gastos`: Contador de gastos registrados.
*   `float total_gastos`: Suma total de los gastos (podría ser redundante con `calcularGastos()`).
*   `clientes cliente[TAM]`: Arreglo global para almacenar objetos `clientes`.
*   `empleados empleado[TAM]`: Arreglo global para almacenar objetos `empleados`.
*   `dinero finanzas`: Variable global de tipo `dinero` para cálculos financieros.
*   `int indice`: Un contador general que se utiliza para `clientes` y `empleados` (puede llevar a confusión).
*   `int indice_c`: Índice para la inserción de clientes.
*   `int indice_e`: Índice para la inserción de empleados.
*   `int indice_g`: Índice para la inserción de gastos.
*   `char examenes[TAM][TAM]`: Matriz de caracteres que almacena los nombres de los exámenes disponibles.
*   `char usuario1[TAM]`, `char clave1[TAM]`: Credenciales de inicio de sesión (`ADMIN`/`1234`).
*   `HANDLE wHnd`: Manipulador de la ventana de la consola para funciones de `windows.h`.

### Funciones Auxiliares (Interfaz Gráfica de Consola)
*   `void gotoxy(int x, int y)`: Mueve el cursor a las coordenadas (x, y) de la consola.
*   `void recuadro(int xs, int ys, int xi, int yi)`: Dibuja un recuadro usando caracteres ASCII extendidos entre las coordenadas dadas.
*   `void centrarTexto(char *texto, int y)`: Imprime una cadena de texto centrada horizontalmente en la fila `y`.
*   `void margen()`: Dibuja el margen principal y el encabezado de la aplicación.
*   `void barra_de_carga()`: Muestra una animación de barra de carga.
*   `void asteriscos(char caracter, char *respuesta, int indice, bool mostrador, int longitud)`: Captura la entrada del usuario, mostrando asteriscos si `mostrador` es `true` (para contraseñas) o el caracter real si es `false`.
*   `void espacios_vacios(char *texto, int x, int y)`: Verifica si una cadena de texto está vacía y solicita al usuario que la rellene si es así.
*   `void borrar_espacios(int x, int y)`: Borra un bloque de texto en la consola.
*   `void tabla(int x, int fila)`: Dibuja líneas verticales para las tablas de reportes.

### Funciones de Lógica de Negocio
*   `float calcularIngresos()`: Itera sobre los clientes registrados y suma sus pagos para obtener el total de ingresos.
*   `float calcularGastos()`: Itera sobre los gastos registrados y suma sus cantidades para obtener el total de gastos.
*   `float calcularSueldos()`: Itera sobre los empleados registrados y suma sus sueldos para obtener el costo total de los sueldos.
*   `float calcularGanancia()`: Calcula la ganancia diaria restando la proporción diaria de gastos y sueldos del total de ingresos acumulados.

## Compilación y Ejecución
Para compilar el programa en un sistema Windows con GCC (MinGW, TDM-GCC, etc.), abre una terminal o Símbolo del Sistema y ejecuta el siguiente comando:

```bash
gcc "Proyecto_acabado (1).c" -o laboratorio_clinico.exe -luser32
```
*   `gcc`: El comando del compilador GNU C.
*   `"Proyecto_acabado (1).c"`: El nombre de tu archivo fuente.
*   `-o laboratorio_clinico.exe`: Indica al compilador que genere un archivo ejecutable llamado `laboratorio_clinico.exe`.
*   `-luser32`: Enlaza la librería `user32.lib`, necesaria para algunas funciones de `windows.h`.

Una vez compilado, puedes ejecutar la aplicación desde la misma terminal:

```bash
.\laboratorio_clinico.exe
```

## Notas y Posibles Mejoras
*   **Portabilidad:** El uso extensivo de `windows.h` y `conio.h` hace que la aplicación no sea directamente portable a otros sistemas operativos como Linux o macOS.
*   **Gestión de Fechas:** La fecha mostrada en el login es estática ("11/05/2024") a pesar de que hay un sistema de fecha que avanza internamente. Se podría integrar la fecha dinámica en el display.
*   **Validación de Entrada:** Algunas validaciones son básicas. Se podría mejorar para evitar entradas numéricas en campos de texto y viceversa, así como formatos específicos para DNI o fechas.
*   **Persistencia de Datos:** Los datos se pierden cada vez que se cierra la aplicación, ya que no hay un mecanismo para guardar y cargar la información (por ejemplo, en archivos o una base de datos).
*   **Lógica de Reportes:**
    *   La lógica para el "Examen más solicitado" (`max_contador`, `tipo_max_contador`) parece incompleta o incorrecta, ya que el arreglo `contador` no se inicializa ni se actualiza con la frecuencia de los exámenes.
    *   La validación de la "especialización" del empleado contra la lista de exámenes es un error lógico; debería haber una lista separada de especializaciones o no validar.
*   **Uso de `fflush(stdin)`:** Es una práctica no estándar y puede causar problemas en diferentes compiladores o sistemas. Se recomienda evitar su uso.
*   **Redundancia:** `total_gastos` como variable global y `calcularGastos()` son algo redundantes; se podría confiar más en la función.
*   **Organización:** El código podría beneficiarse de una mayor modularización, dividiendo las funciones en archivos de cabecera (`.h`) y archivos de implementación (`.c`) para una mejor organización.

---
**Proyecto de Equipo:**
*   Angel Nereo Molina Ortiz 30201824
*   Johan Omar Duque Pereira 30.920.845
*   Arturo Alejandro Carvajalino Vivas 30.889.966
