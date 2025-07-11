#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TONOS 0x27
#define DIALITIKA 0x22
#define M 0xCC
#define N 0xCD
#define n 0XED
#define m 0XEC

enum state_machine {State_dflt , State_m , State_M , State_n , State_N} s;

/* Function to fill the map*/
void fill_Map(int charmap[255][3]){
    /* Filling map with lower case */
    charmap[0xE1][0] = 0x61; /* a */
    charmap[0xE2][0] = 0x76; /* v */
    charmap[0xE3][0] = 0x67; /* g */
    charmap[0xE4][0] = 0x64; /* d */
    charmap[0xE5][0] = 0x65; /* e */
    charmap[0xE6][0] = 0x7A; /* z */
    charmap[0xE7][0] = 0x68; /* h */
    charmap[0xE8][0] = 0x38; /* 8 */
    charmap[0xE9][0] = 0x69; /* i */
    charmap[0xEA][0] = 0x6B; /* k */
    charmap[0xEB][0] = 0x6C; /* l */
    charmap[0xEC][0] = 0x6D; /* m */
    charmap[0xED][0] = 0x6E; /* n */
    charmap[0xEE][0] = 0x6b; /* k */
    charmap[0xEE][1] = 0x73; /* s */
    charmap[0xEF][0] = 0x6f; /* o */
    charmap[0xF0][0] = 0x70; /* p */
    charmap[0xF1][0] = 0x72; /* r */
    charmap[0xF2][0] = 0x73; /* s */
    charmap[0xF3][0] = 0x73; /* s */
    charmap[0xF4][0] = 0x74; /* t */
    charmap[0xF5][0] = 0x79; /* y */
    charmap[0xF6][0] = 0x66; /* f */
    charmap[0xF7][0] = 0x78; /* x */
    charmap[0xF8][0] = 0x70; /* p */
    charmap[0xF8][1] = 0x73; /* s */
    charmap[0xF9][0] = 0x77; /* w */

    /* Filling map with upper case */
    charmap[0xC1][0] = 0x41; /* A */
    charmap[0xC2][0] = 0x56; /* V */
    charmap[0xC3][0] = 0x47; /* G */
    charmap[0xC4][0] = 0x44; /* D */
    charmap[0xC5][0] = 0x45; /* E */
    charmap[0xC6][0] = 0x5A; /* Z */
    charmap[0xC7][0] = 0x48; /* H */
    charmap[0xC8][0] = 0x38; /* 8 */
    charmap[0xC9][0] = 0x49; /* I */
    charmap[0xCA][0] = 0x4B; /* K */
    charmap[0xCB][0] = 0x4C; /* L */
    charmap[0xCC][0] = 0x4D; /* M */
    charmap[0xCD][0] = 0x4E; /* N */
    charmap[0xCE][0] = 0x4B; /* K */
    charmap[0xCE][1] = 0x53; /* S */
    charmap[0xCF][0] = 0x4F; /* O */
    charmap[0xD0][0] = 0x50; /* P */
    charmap[0xD1][0] = 0x52; /* R */
    charmap[0xD3][0] = 0x53; /* S */
    charmap[0xD4][0] = 0x54; /* T */
    charmap[0xD5][0] = 0x59; /* Y */
    charmap[0xD6][0] = 0x46; /* F */
    charmap[0xD7][0] = 0x58; /* X */
    charmap[0xD8][0] = 0x50; /* P */
    charmap[0xD8][1] = 0x53; /* S */
    charmap[0xD9][0] = 0x57; /* W */

    /* Filling map with tonos uppercase */
    charmap[0xB6][0] = TONOS;
    charmap[0xB6][1] = 0x41; /* A */
    charmap[0xB8][0] = TONOS;
    charmap[0xB8][1] = 0x45; /* E */
    charmap[0xB9][0] = TONOS;
    charmap[0xB9][1] = 0x48; /* H */
    charmap[0xBA][0] = TONOS;
    charmap[0xBA][1] = 0x49; /* I */
    charmap[0xBC][0] = TONOS;
    charmap[0xBC][1] = 0x4F; /* O */
    charmap[0xBF][0] = TONOS;
    charmap[0xBF][1] = 0x57; /* W */
    charmap[0xBE][0] = TONOS;
    charmap[0xBE][1] = 0x59; /* Y */

    /* Filling map with tonos lowercase */
    charmap[0xDC][0] = 0x61; /* a */
    charmap[0xDC][1] = TONOS;
    charmap[0xDD][0] = 0x65; /* e */
    charmap[0xDD][1] = TONOS;
    charmap[0xDE][0] = 0x68; /* h */
    charmap[0xDE][1] = TONOS;
    charmap[0xDF][0] = 0x69; /* i */
    charmap[0xDF][1] = TONOS;
    charmap[0xFC][0] = 0x6F; /* o */
    charmap[0xFC][1] = TONOS;
    charmap[0xFE][0] = 0x77; /* w */
    charmap[0xFE][1] = TONOS;
    charmap[0xFD][0] = 0x79; /* y */
    charmap[0xFD][1] = TONOS;

    /* Filling map with dialitika lowercase */
    charmap[0xFA][0] = 0x69; /* i */
    charmap[0xFA][1] = DIALITIKA;
    charmap[0xC0][0] = 0x69; /* i */
    charmap[0xC0][1] = DIALITIKA;
    charmap[0xC0][2] = TONOS;
    charmap[0xFB][0] = 0x79; /* y */
    charmap[0xFB][1] = DIALITIKA;
    charmap[0xE0][0] = 0x79; /* y */
    charmap[0xE0][1] = DIALITIKA;
    charmap[0xE0][2] = TONOS;

    /* Filling map with dialitika uppercase */
    charmap[0xDA][0] = 0x49; /* I */
    charmap[0xDA][1] = DIALITIKA;
    charmap[0xDB][0] = 0x59; /* Y */
    charmap[0xDB][1] = DIALITIKA;

}

/* Function to print the letter*/
void PrintLetter(int c)
{
    int charmap[255][3] = {0};
    fill_Map(charmap);


    if(charmap[c][0] != '\0') /* Den mpainei otan c == 100 */
    {
        printf("%c" , charmap[c][0]);
    }
    if(charmap[c][1] != '\0') /*  Tono || Dialitika */
    {
        printf("%c" , charmap[c][1]);
    }
    if(charmap[c][2] != '\0') /* Tono || Dialitika */
    {
        printf("%c" , charmap[c][2]);
    }
}

int CheckC(int c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c) || ispunct(c) || isspace(c)){
        return 1;
    }
    return 0;
}
/* State machine default */
enum state_machine df(int c)
{
    switch(c)
    {
        case(M): /* greek M */
            c = getchar();
            if(c == EOF){
                PrintLetter(M);
                return State_dflt;
            }
            else if(c == 0xD0){
                printf("B");
                return State_dflt;
            }
            else if(c == M){
                PrintLetter(M);
                PrintLetter(M);
                return State_M;
            }
            else if(c == n){
                PrintLetter(M);
                return State_n;
            }
            else if(c == N){
                PrintLetter(M);
                return State_N;
            }
            else if(c == m){
                PrintLetter(M);
                return State_m;
            }
            else{
                PrintLetter(M);
                PrintLetter(c);
                return State_dflt;
            }
        case(n): /* greek n */
            c = getchar();
            if(c == EOF){
                PrintLetter(n);
                return State_dflt;
            }
            else if(c == 0xf4){
                PrintLetter(0xE4); /* d */
                return State_dflt;
            }
            else if(c == n){
                PrintLetter(n);
                PrintLetter(n);
                return State_n;
            }
            else if(c == N){
                PrintLetter(n);
                return State_N;
            }
            else if(c == m){
                PrintLetter(n);
                return State_m;
            }
            else if(c == M){
                PrintLetter(n);
                return State_M;
            }
            else{
                PrintLetter(n);
                PrintLetter(c);
                return State_dflt;
            }
        case(N): /* greek N */
            c = getchar();
            if(c == EOF){
                PrintLetter(N);
                return State_dflt;
            }
            else if(c == 0xD4){
                PrintLetter(0xC4);
                return State_dflt;
            }
            else if(c == N){
                PrintLetter(N);
                PrintLetter(N);
                return State_N;
            }
            else if(c == n){
                PrintLetter(N);
                return State_n;
            }
            else if(c == m){
                PrintLetter(N);
                return State_m;
            }
            else if(c == M){
                PrintLetter(N);
                return State_M;
            }
            else{
                PrintLetter(N);
                PrintLetter(c);
                return State_dflt;
            }
        case(m): /* greek m */
            c = getchar();
            if(c == EOF){
                PrintLetter(m);
                return State_dflt;
            }
            else if(c == 0xF0){
                printf("b");
                return State_dflt;
            }
            else if(c == m){
                PrintLetter(m);
                PrintLetter(m);
                return State_m;
            }
            else if(c == n){
                PrintLetter(m);
                return State_n;
            }
            else if(c == N){
                PrintLetter(m);
                return State_N;
            }
            else if(c == M){
                PrintLetter(m);
                return State_M;
            }
            else{
                PrintLetter(m);
                PrintLetter(c);
                return State_dflt;
            }
        default:
            PrintLetter(c);
            return State_dflt;
    }
}

/* State machine for m */
enum state_machine sm(int c)
{
    switch(c)
    {
        case(M): /* greek M */
            PrintLetter(m);
            return State_M;
        case(m): /* greek m */
            c = getchar();
            if(c == EOF){
                PrintLetter(m);
                return State_dflt;
            }
            else if(c == 0xF0){
                printf("b");
                return State_m;
            }
            else if(c == m){
                PrintLetter(m);
                PrintLetter(m);
                return State_m;
            }
            else if(c == n){
                PrintLetter(m);
                return State_n;
            }
            else if(c == N){
                PrintLetter(m);
                return State_N;
            }
            else if(c == M){
                PrintLetter(m);
                return State_M;
            }
            else{
                PrintLetter(m);
                PrintLetter(c);
                return State_m;
            }
        case(n): /* greek n */
            PrintLetter(m);
            return State_n;
        case(N): /* greek N */
            PrintLetter(m);
            return State_N;
        case(0xF0): /* greek p */
            printf("b"); /* b */
            return State_dflt;
        default:
            PrintLetter(c);
            return State_dflt;
    }
}

/* State machine for M */
enum state_machine sM(int c)
{
    switch(c)
    {
        case(M): /* greek M */
            c = getchar();
            if(c == EOF){
                PrintLetter(M);
                return State_dflt;
            }
            else if(c == 0xD0){
                printf("B");
                return State_dflt;
            }
            else if(c == M){
                PrintLetter(M);
                PrintLetter(M);
                return State_M;
            }
            else if(c == n){
                PrintLetter(M);
                return State_n;
            }
            else if(c == N){
                PrintLetter(M);
                return State_N;
            }
            else if(c == m){
                PrintLetter(M);
                return State_m;
            }
            else{
                PrintLetter(M);
                PrintLetter(c);
                return State_dflt;
            }
        case(n): /* greek n */
            PrintLetter(M);
            return State_n;
        case(N): /* greek N */
            PrintLetter(M);
            return State_N;
        case(m): /* greek m */
            PrintLetter(M);
            return State_m;
        case(0xD0): /* greek P */
            printf("B");
            return State_dflt;
        default:
            PrintLetter(M);
            return State_dflt;
    }
}

/* State machine for n */
enum state_machine sn(int c)
{
    switch(c)
    {
        case(M): /* greek M */
            PrintLetter(n);
            return State_M;
        case(N): /* greek N */
            PrintLetter(n);
            return State_N;
        case (n):
            c = getchar();
            if(c == EOF){
                PrintLetter(n);
                return State_dflt;
            }
            else if(c == 0xf4){
                PrintLetter(0xE4); /* d */
                return State_dflt;
            }
            else if(c == n){
                PrintLetter(n);
                PrintLetter(n);
                return State_n;
            }
            else if(c == N){
                PrintLetter(n);
                return State_N;
            }
            else if(c == m){
                PrintLetter(n);
                return State_m;
            }
            else if(c == M){
                PrintLetter(n);
                return State_M;
            }
            else{
                PrintLetter(n);
                PrintLetter(c);
                return State_dflt;
            }
        case(m): /* greek m */
            PrintLetter(n);
            return State_m;
        case (0xf4):
            PrintLetter(0xE4); /* d */
            return State_dflt;
        default:
            PrintLetter(c);
            return State_dflt;
    }
}

/* State machine for N*/
enum state_machine sN(int c)
{
    switch(c)
    {
        case(M): /* greek M */
            PrintLetter(N);
            return State_M;
        case(n): /* greek n */
            PrintLetter(N);
            return State_n;
        case(N): /* greek N */
            c = getchar();
            if(c == EOF){
                PrintLetter(N);
                return State_dflt;
            }
            else if(c == 0xD4){
                PrintLetter(0xC4);
                return State_dflt;
            }
            else if(c == N){
                PrintLetter(N);
                PrintLetter(N);
                return State_N;
            }
            else if(c == n){
                PrintLetter(N);
                return State_n;
            }
            else if(c == m){
                PrintLetter(N);
                return State_m;
            }
            else if(c == M){
                PrintLetter(N);
                return State_M;
            }
            else{
                PrintLetter(N);
                PrintLetter(c);
                return State_dflt;
            }
        case(m): /* greek m */
            PrintLetter(N);
            return State_m;
        case(0xD4): /* greek T */
            PrintLetter(0xC4); /* D */
            return State_dflt;
        default:
            PrintLetter(c);
            return State_dflt;
    }
}

/* State machine functions */
enum state_machine(*action[])(int c) = {df , sm , sM , sn , sN};

int main() {
    int c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if(CheckC(c) == 1){
            printf("%c" , c);
        }
        else{
            if (i == 0) {
                if (c == n) {
                    s = State_n;
                } else if (c == N) {
                    s = State_N;
                } else if (c == m) {
                    s = State_m;
                } else if (c == M) {
                    s = State_M;
                } else {
                    s = State_dflt;
                }
                i++;
            }
            s = (action[s])(c);
        }
    }

    return 0;
}
