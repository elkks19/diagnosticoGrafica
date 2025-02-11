/**
 ** Práctica de Diagnóstico - Serie de Números Primos con Scrum y Git
 ** Objetivo:
 ** Evaluar la capacidad de los estudiantes para resolver un problema sencillo de programación
 ** aplicando Scrum y control de versiones con Git.
 ** Instrucciones:
 ** 1. Implementar la serie de números primos
 ** ○ Utilizar cualquier lenguaje de programación.
 ** ○ Aplicar cualquier método para generar los números primos.
 ** 2. Subir la solución a GitHub
 ** ○ Si tienen un repositorio en GitHub, subir el código y copiar el enlace y
 ** captura de la ejecución del programa.
 ** ○ Si no tienen un repositorio, crear un documento con:
 ** ■ El código fuente de la solución.
 ** ■ Una captura de pantalla con la ejecución del programa.
 ** 3. Aplicar metodología Scrum
 ** ○ Identificar qué lograron aplicar de Scrum.
 ** Entrega:
 ** ● Tiempo límite: ⏳ 30 minutos.
 ** ● Subir el enlace del repositorio y la captura de pantalla o el documento con el
 ** código y la captura de pantalla.
 ** 🔹 Nota: La práctica se enfocará en la solución del problema, el uso de GitHub y la
 ** aplicación de Scrum. 
 **/

#include <cmath>
#include <iostream>
#include <list>

using namespace std;
bool isPrimo(int n, list<int>* primos) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}

	return true;
}

int main (int argc, char *argv[]) {
	int cantPrimos;
	cout << "Ingrese la cantidad de números primos a mostrar: ";
	cin >> cantPrimos;

	list<int> primos;

	for (int i = 1, j = 0; j < cantPrimos; i++) {
		if (isPrimo(i)) {
			primos.push_back(i);
			j++;
		}
	}
	cout << "[" << primos.front();

	primos.pop_front();

	for (int i : primos) {
		cout << ", " << i;
	}
	cout << "]" << endl;

	return 0;
}
