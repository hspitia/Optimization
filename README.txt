Simplex School Locator

Requerimientos de software:

Linux
----------------------------------------
- Qt v4.5.2
- lpsolve v5.5 (desarrollo y ejecuci�n)


Windows
----------------------------------------
- Qt v4.5.2


Estructura Directorios:
----------------------------------------------------------
+- data      :  Datos de entrada
+- debug     :  Ejecutable para windows 32
+- include   :  Cabeceras de desarrollo
+- lib       :  Librer�as
+- resources :  Archivos de recursos
+- src       :  C�digo fuente
  +--- app   :  Controlador de aplicaci�n, Archivo main
  +--- bab   :  Implementaci�n Branch and Bound
  +--- gui   :  Interfaz gr�fica
  +--- parser:  Lector de archivos, generador de modelos
  +--- utils :  Utiler�as varias
+- tmp       :  Archivos temporales


Compilaci�n:
------------------------------------------------------------ 
En el directorio ra�z ejecutar los comandos:

$ qmake -makefile
$ make


Ejecuci�n:
------------------------------------------------------------
Ejecutar desde l�nea de comandos:

En Linux:  Una vez compilado:
------------------------------------------------------------
$ ./app

En Windows: 
------------------------------------------------------------
$ debug\app.exe
