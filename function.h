#ifndef ENCODE_H_INCLUDED
#define ENCODE_H_INCLUDED
#include <stdio.h>
typedef struct letter_morse
{
    char letter;
    char morse[7]; // there at most 7 characters in morse alphabet
    int l;
}
Trnslt;


typedef struct btree
{
    char letter;
    struct btree *r,*l;
} btree;

char *read_long_line();

void morse (char *text,Trnslt *s);

void code (Trnslt *s);

btree *insert (btree *root,char c,char *s);

void search (btree *root,char *s);

btree *Allinsert (btree *root,Trnslt *s);

void decode (Trnslt *s);

void statisticEncd();

void statisticDecd (Trnslt *s);

#endif // ENCODE_H_INCLUDED
