#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void write();
void date();
void menu();
void playfair();
void vigenere();
void trans();

int main() {
    menu();
    return 0;
}
void date(){
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = localtime(&t);
    printf("\t\t\t%02d-%02d-%02d\n", tm->tm_mday, tm->tm_mon, 1900+tm->tm_year);
    printf("\tBaeza Ramirez Luis Gerardo 2012010273\n");
}

void menu(){
    char valref;
    do{
        system("cls");
        date();
        printf("\tSeleccione una Opcion\n");
        printf("1.Introducir texto a cifrar\n2.Cifrado Playfair\n3.Cifrado Vigenere\n4.Transposicion con clave\n5.Salir\n");
        scanf("%d",&valref);

        switch(valref){
            case '1':
                write();
                break;
            case '2':
                playfair();
                break;
            case '3':
                vigenere();
                break;
            case '4':
                trans();
                break;
            case '5':
                printf("Adios");
                break;
            default:
                printf("invalid");
                break;
        }
    }while(valref == '5');

}

void write() {
    FILE *file;
    char phrase[1024];

    file = fopen("Textoacifrar.txt", "w+");
    if (file == NULL){
        printf("No se ha podido abrir el archivo.\n");
        exit(1);
    }
    printf("Introduce el mensaje a cifrar\n");
    fgets(phrase,1024,stdin);

    fprintf(file,"%s", phrase);
    fclose(file);
    system("pause");
}

void playfair(){

}

void vigenere(){

}

void trans(){

}