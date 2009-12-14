Simplex School Locator

Requerimientos de software:

Linux
----------------------------------------
- Qt v4.5.2
- lpsolve v5.5 (desarrollo y ejecución)


Windows
----------------------------------------
- Qt v4.5.2


Estructura Directorios:
----------------------------------------------------------
+- data      :  Datos de entrada
+- debug     :  Ejecutable para windows 32
+- include   :  Cabeceras de desarrollo
+- lib       :  Librerías
+- resources :  Archivos de recursos
+- src       :  Código fuente
  +--- app   :  Controlador de aplicación, Archivo main
  +--- bab   :  Implementación Branch and Bound
  +--- gui   :  Interfaz gráfica
  +--- parser:  Lector de archivos, generador de modelos
  +--- utils :  Utilerías varias
+- tmp       :  Archivos temporales


Compilación:
------------------------------------------------------------ 
En el directorio raíz ejecutar los comandos:

$ qmake -makefile
$ make


Ejecución:
------------------------------------------------------------
Ejecutar desde línea de comandos:

En Linux:  Una vez compilado:
------------------------------------------------------------
$ ./app

En Windows: 
------------------------------------------------------------
$ debug\app.exe
