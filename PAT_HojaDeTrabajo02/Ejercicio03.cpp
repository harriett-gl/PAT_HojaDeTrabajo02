#include "Ejercicio03.h"
#include <stack>
using namespace std;

int Ejercicio03::calculate(string s)
{
    if (s.length() == 0) {
        return 0;
    }
    stack<int> pila;
    char operador = '+';
    //leer la cadena
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') {
            continue;
        }
        else if (isdigit(s[i])) {
            string numero = "";
            while (isdigit(s[i])) {
                numero = numero + s[i];
                i++;
            }
            i--;
            int n = stoi(numero);
            if (operador == '+') {
                pila.push(n);
            }
            else if (operador == '-') {
                pila.push(n * -1);
            }
            else if (operador == '*') {
                int n2 = pila.top();
                pila.pop();
                pila.push(n * n2);
            }
            else if (operador == '/') {
                int n2 = pila.top();
                pila.pop();
                pila.push(n2 / n);
            }
        }
        else {
            operador = s[i];
        }
    }
    int suma = 0;
    while (!pila.empty()) {
        suma = suma + pila.top();
        pila.pop();
    }
    return suma;
}
