//============================================================================
// Name        : Concurso.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

struct caso {
    int nEquipo;
    int resuelto [12];
    int penT [12];
    bool dato;
} a [100];

void reset ()//reset para limpiar la estructura
{
    for ( int i = 0; i < 100; i++ ) {
        a [i].nEquipo = i;
        memset (a [i].resuelto, 0, sizeof (a [i].resuelto));
        memset (a [i].penT, 0, sizeof (a [i].penT));
        a [i].dato = false;
    }
}

void calcular ()
{
    for ( int i = 1; i < 100; i++ ) {
        for ( int j = 1; j <= 9; j++ ) {
            if ( a [i].resuelto [j] ) {
                a [i].resuelto [10]++;
                a [i].penT [10] += a [i].penT [j];
            }
        }
    }
}

bool ordenDComp (caso x, caso y)
{
    if ( x.resuelto [10] > y.resuelto [10] ) return true;
    if ( x.resuelto [10] == y.resuelto [10] && x.penT [10] < y.penT [10] ) return true;
    if ( x.resuelto [10] == y.resuelto [10] && x.penT [10] == y.penT [10] && x.nEquipo < y.nEquipo ) return true;
    return false;
}

int main() {
    int testCase;
    scanf ("%d", &testCase);
    getchar ();

    bool blank = false;
    char input [1000];

    gets (input);

    while ( testCase-- ) {
        reset ();

        while ( gets (input) && strlen (input) ) {
            int c, p, t;
            char l;

            sscanf (input, "%d %d %d %c",&c, &p, &t, &l );

            a [c].dato = true;

            if ( l == 'R' || l == 'U' || l == 'E' ) continue;

            if ( l == 'C' ) {
                if ( !a [c].resuelto [p] ) {
                    a [c].resuelto [p] = 1;
                    a [c].penT [p] += t;
                }
            }
            else {
                if ( !a [c].resuelto [p] )
                    a [c].penT [p] += 20;
            }
        }

        calcular ();

        sort (a, a + 105, ordenDComp);

        if ( blank )
            printf ("\n");
        blank = true;

        for ( int i = 0; i <= 105; i++ ) {
            if ( a [i].dato )
                printf ("%d %d %d\n", a [i].nEquipo, a [i].resuelto [10], a [i].penT [10]);
        }
    }

    return 0;
}
