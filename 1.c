#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct __ll_node {
    int value;
    struct __ll_node* next;
} ll_node;

int head(ll_node* a) {
    return a->value;
}

ll_node* tail(ll_node* a) {
    return a->next;
}


ll_node* copy_ll(ll_node* list) {
    if (list == NULL) return NULL;
    ll_node* newNode = malloc(sizeof(ll_node));
    newNode->value = head(list);
    newNode->next = copy_ll(tail(list));
    return newNode;
}

ll_node* newList(int value, ll_node* rest) {
    ll_node* newHead = malloc(sizeof(ll_node));
    newHead->value = value;
    ll_node* restCopy = copy_ll(rest);
    newHead->next = restCopy;
    return newHead;
}

bool fizz(int a) {
    return a % 3 == 0 || a % 5 == 0;
}

ll_node* filter(ll_node* list, bool (* filter_funct)(int a)) {
    if (list == NULL) {
        return NULL;
    }
    if (filter_funct(list->value)) {
        return newList(list->value, filter(tail(list), filter_funct));
    } else {
        return filter(tail(list), filter_funct);
    }
} 

int sum(ll_node* a) {
    if (a == NULL) return 0;
    return a->value + sum(tail(a));
}


ll_node* range(int i) {
    if (i == 1) { 
        return newList(0, NULL);
    } else {
        return newList(i - 1, range(i - 1));
    }
}

int main() {
    printf("%d\n", sum(filter(range(1000), &fizz)));
    return 0;
}
