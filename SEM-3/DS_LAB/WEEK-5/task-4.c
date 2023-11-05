#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int top = -1;
char stack[SIZE];

void push(char ch) {
    if(top <= SIZE-1){stack[++top] = ch;}
    else {printf("\nStack Overflow!!\n");}
}

void display() {
    int temp = top;
    while(temp >= 0){
        printf("%c",stack[temp--]);
    }
    printf("\n");
}

int main() {
    char ch[SIZE];
    fgets(ch, SIZE, stdin);
    int i = 0;
    while(ch[i] != '\0'){
        push(ch[i]);
        i += 1;
    }
    display();
    return 0;
}
