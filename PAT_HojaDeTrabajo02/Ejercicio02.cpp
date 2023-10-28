#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    if (l1 == nullptr) {
        return l2;
    }
    else if (l2 == nullptr) {
        return l1;
    }
    int contador1 = 1;
    int contador2 = 1;
    Node<int>* actual1 = l1;
    Node<int>* actual2 = l2;
    while (actual1->next != nullptr) {
        contador1++;
        actual1 = actual1->next;
    }while (actual2->next != nullptr) {
        contador2++;
        actual2 = actual2->next;
    }
    if ((contador1 >= 1 && contador1 <= 360) && (contador2 >= 1 && contador2 <= 360)) {
        Node<int>* dummy = new Node<int>{ 0 };
        Node<int>* temporal = dummy;
        int agregado = 0;
        while (l1 != nullptr || l2 != nullptr || agregado != 0) {
            int d1 = 0;
            int d2 = 0;
            if (l1) {
                d1 = l1->value;
                l1 = l1->next;
            }
            if (l2) {
                d2 = l2->value;
                l2 = l2->next;
            }
            int suma = d1 + d2 + agregado;
            agregado = suma / 10;
            //agregar el nuevo nodo
            Node<int>* nuevo = new Node<int>{ suma % 10 };
            temporal->next = nuevo;
            temporal = temporal->next;
        }
        return dummy->next;
    }
}
