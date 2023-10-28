#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    if (head == nullptr || k == 0) {
        return head;
    }
    Node<char>* tail = head;
    int longitud = 1;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
        longitud++;
    }
    if (longitud <= 500 && longitud >= 0) {
        k = k % longitud;
        Node<char>* nuevoHead = head;
        for (int i = 0; i < longitud - k - 1; i++) {
            nuevoHead = nuevoHead->next;
        }
        tail->next = head;
        head = nuevoHead->next;
        nuevoHead->next = nullptr;
        return head;
    }
    return nullptr;
}
