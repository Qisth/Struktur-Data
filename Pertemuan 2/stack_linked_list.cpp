#include <iostream>
#include <cstdlib>
using namespace std;

// Deklarasi node untuk stack
struct Node {
    int value;
    Node *next;
};
typedef struct Node stack;

void create(stack **top);
void display(stack *top);
void push(stack **top, int e);
int pop(stack **top);

int main() {
    stack *s;
    create(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(s);

    cout << "Nilai " << pop(&s) << " dihapus dari stack\n";
    display(s);

    return 0;
}

// Buat stack
void create(stack **top) {
    *top = NULL;
}

// Tampilkan stack
void display(stack *top) {
    stack *p = top;

    cout << "Isi stack: ";
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << "NULL\n";
}

// Masukkan nilai ke dalam stack
void push(stack **top, int e) {
    stack *new_node = new stack;
    if (new_node == NULL) {
        cout << "Stack tidak berhasil dibuat\n";
        return;
    }
    new_node->value = e;
    new_node->next = *top;
    *top = new_node;
}

// Hapus nilai paling depan dari stack
int pop(stack **top) {
    if (*top == NULL) {
        cout << "Stack kosong\n";
        exit(1);
    }

    int temp = (*top)->value;
    stack *p = *top;
    *top = (*top)->next;
    delete p;
    return temp;
}