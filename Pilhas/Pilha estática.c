#include <stdio.h>
#define Max 20

struct Pilha
{
    int Pilhinha[20];
    int Top;
};

void Start(struct Pilha *ptr);
void push(struct Pilha *ptr, int elemento);
int isFull(struct Pilha *ptr);
void pop(struct Pilha *ptr);
int isEmpty(struct Pilha *ptr);
void Displayingstack(struct Pilha *ptr);


int main(){

    struct Pilha stack;
    int escolha, elemento;

    Start(&stack);

    while (1)
    {
        
        printf("O que voce deseja fazer?\n");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Peek\n");

        scanf("%d", &escolha);
        
        switch (escolha)
        {
        case 1:
            printf("Qual elemento voce quer inserir?\n");
            scanf("%d", &elemento);
            push(&stack, elemento);

            break;
        
        case 2: 
            pop(&stack);
            break;
        
        case 3: 
            Displayingstack(&stack);
            break;

        default:
            printf("Escolha outra opcao.\n");
            break;
        }
    }
    
    return 0;
}

void Start(struct Pilha *ptr){

    ptr->Top = -1;
}

void push(struct Pilha *ptr, int elemento){

    int verificar;

    verificar = isFull(ptr);

    if (verificar == 0)
    {
        ptr->Pilhinha[ptr->Top + 1] = elemento;
        ptr->Top++;
    }
    else{

        printf("A lista esta cheia e nao foi possivel inserir.\n");
    }
        
}

int isFull(struct Pilha *ptr){

    if(ptr->Top >= Max-1){   
        return -1;
    }

    return 0;
}

void pop(struct Pilha *ptr){

    int verificar;

    verificar = isEmpty(ptr);

    if (verificar == 0)
    {
        ptr->Top--;
    }
    else{
        printf("Nao foi possivel excluir.\n");
    }
    
}

int isEmpty(struct Pilha *ptr){

    if (ptr->Top >= 0)
    {
        return 0;
    }
    else{

        return -1;
    }
    
}

void Displayingstack(struct Pilha *ptr){

    for (int i = 0; i <= ptr->Top; i++)
    {
        printf("%d ", ptr->Pilhinha[i]);
    }

    printf("\n");   
}