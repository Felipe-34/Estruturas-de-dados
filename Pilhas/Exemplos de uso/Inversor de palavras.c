#include <stdio.h>
#include <string.h>
#define Max 100

typedef struct Pilha{

    char palavra[Max];
    int top;

}Pilha;

void push(Pilha *ptr, char letra);
int isFull(Pilha *ptr);
void Pop(Pilha *ptr);
int isEmpty(Pilha *ptr);

int main(){

    Pilha stack;
    stack.top = -1;
    int letras;

    while(1){

        printf("Digite uma palavra para ser invertida.(Sem espacos.)\n");
        scanf("%s", &stack.palavra);
        letras = strlen(stack.palavra);
    
        for(size_t i = 0; i < letras; i++){

            push(&stack, stack.palavra[i]);
        }
        
        for(size_t j = 0; j < letras; j++){

            Pop(&stack);
        }
        
        printf("\n");
    }
    
    return 0;
}

void push(Pilha *ptr, char letra){

    int valor;
    valor = isFull(ptr);
    
    if(valor == 0){ 

        ptr->palavra[ptr->top + 1] = letra;
        ptr->top++;
    }
    else{
        
        printf("Pilha cheia.\n");
    }

}

int isFull(Pilha *ptr){

    if (ptr->top >= Max - 1){

        return -1;
    }
    else{

        return 0;
    }
    
}

void Pop(Pilha *ptr){

    int valor;
    
    valor = isEmpty(ptr);
    
    if (valor == 0){

        printf("%c", ptr->palavra[ptr->top]);
        ptr->top--;
    }
    else{

        printf("Pilha vazia.\n");
    }        
}

int isEmpty(Pilha *ptr){

    if (ptr->top <= -1){

        return -1;
    }
    else{

        return 0;
    }
    
}