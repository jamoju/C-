#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) { }
        ListNode(int x) : val(x), next(nullptr) { }
        ListNode(int x, ListNode *next) : val(x), next(next) { }
    };

    ListNode *achaUltimoNo (ListNode *head) {

        // verifica se a lista está vazia
        if (head == NULL || head->next == NULL) {
            return head;
        }

        return achaUltimoNo (head->next);
    }

    ListNode *insereNovoNoInicio (ListNode *head, int n) {
        ListNode*NovoNo = new ListNode (); // cria o novo nó

        NovoNo->val = n; // atribui o valor informado ao novo nó
        NovoNo->next = head; // o próximo nó é a atual cabeça da lista

        return NovoNo;
    }

    void insereNovoNoFinal (ListNode **head, int n) {

        ListNode *NovoNo = new ListNode (); // cria o novo nó
        ListNode *temp; // cria um ponteiro temporário

        NovoNo->val = n; // atribui o valor informado ao novo nó
        NovoNo->next = NULL; // inicializa o próximo nó com nulo

        // verifica se a lista está vazia
        if (*head == NULL) {
            *head = NovoNo; // atribui o novo nó à cabeça da lista

            return;
        }

        // busca o último elemento da lista
        temp = achaUltimoNo (*head);

        // atribui o novo nó ao fim da lista
        temp->next=NovoNo;

        return;
    }

    void imprime_lista (ListNode*head) {
        
        printf ("%d", head->val);

        if (head->next == NULL) {
            return;
        }
        
        printf (", ");

        imprime_lista (head->next);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = NULL;

        // fetches both lists while they have nodes
        while (list1 != NULL || list2 != NULL) {
            // check if both lists are not null
            if (list1 != NULL && list2 != NULL) {
                // compare the values of the current nodes
                if (list1->val <= list2->val) {
                    insereNovoNoFinal (&list3, list1->val);

                    list1 = list1->next;
                } else {
                    insereNovoNoFinal (&list3, list2->val);

                    list2 = list2->next;
                }
            }
            else if (list1 != NULL) {
                insereNovoNoFinal (&list3, list1->val);

                list1 = list1->next;
            }
            else {
                    insereNovoNoFinal (&list3, list2->val);

                    list2 = list2->next;
            }
        }

        return list3;
    }
};

int main() {
    Solution solucao;
    Solution::ListNode *Lista1 = NULL,
                       *Lista2 = NULL,
                       *Lista3 = NULL;
//    int i;

//    for (i = 1; i < 11; i++)
//    {
//        solucao.insereNovoNoFinal (&cabecaDaLista, i);
//    }

//    for (i = 10; i > 0; i--)
//    {
//        cabecaDaLista = solucao.insereNovoNoInicio (cabecaDaLista, i);
//    }

    // monta a lista 1
    solucao.insereNovoNoFinal (&Lista1, 1);
    solucao.insereNovoNoFinal (&Lista1, 2);
    solucao.insereNovoNoFinal (&Lista1, 4);

    printf ("Lista1: [");

    solucao.imprime_lista (Lista1);

    printf ("]\n\r");

    // monta a lista 2
    solucao.insereNovoNoFinal (&Lista2, 1);
    solucao.insereNovoNoFinal (&Lista2, 3);
    solucao.insereNovoNoFinal (&Lista2, 4);

    printf ("Lista2: [");

    solucao.imprime_lista (Lista2);

    printf ("]\n\r");

    // faz merge das listas 1 e 2
    Lista3 = solucao.mergeTwoLists (Lista1, Lista2);

    printf ("Lista3: [");

    solucao.imprime_lista (Lista3);

    printf ("]\n\r\n\r");

    return 0;
}