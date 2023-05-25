#include "function.h"
#include <stdio.h>


/*this function will read input until newline. After use must free it because using dynamic array */
char *read_long_line()
{
    int cnt = 0;
    char *line = (char*) malloc(sizeof(char) * 1);
    line[0] = '\0';
    char newchar;
    while (scanf("%c", &newchar) == 1 && newchar != '\n')
    {
        /* array extension */
        char *newarr = (char*) malloc(sizeof(char) * (cnt+1+1));
        for (int i = 0; i < cnt; ++i)
            newarr[i] = line[i];
        newarr[cnt] = newchar;
        newarr[cnt+1] = '\0';
        free(line);
        line = newarr;
        ++cnt;
    }

    return line;
}

/* this function will print corresponding Morse code for each letter of your text. Every character is separated from each other by a single space
 and every word is separated from each other by a double space. */
void morse (char *text,Trnslt *s)
{
    FILE *f;
    f=fopen("encode.txt","a");
    if (text!=NULL)
    {
        int i,l=strlen(text);
        for (i=0; i!=l; ++i)
        {
            for (int j=0; j!=39; ++j)
            {
                if (tolower(text[i])==s[j].letter)
                {
                    printf("%s ",s[j].morse);
                    fprintf(f,"%s ",s[j].morse);
                }
            }
            if (text[i]==' ')
            {
                printf(" ");
                fprintf(f," ");
            }
            if (i==strlen(text)-1)
                printf("\n");
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

/*this function is just combine of void morse() and char read_long_line() functions. Free array since it's dynamic array*/
void code (Trnslt *s)
{
    char *text=read_long_line();
    morse(text,s);
    free(text);
}

// this function inserts nodes to the binary tree. Left node is . and right one is -
btree *insert (btree *root,char c,char *s)
{
    if (root==NULL)
    {
        root=(btree*)malloc(sizeof(btree));
        root->letter=' ';
        root->l=NULL;
        root->r=NULL;

    }
    if (s[0]!='\0')
    {
        if (s[0]=='-')
            root->r=insert(root->r,c,(s+1));
        if (s[0]=='.')
            root->l=insert(root->l,c,(s+1));
    }
    else if (s[0]=='\0')
        root->letter=c;
    return root;
}

// this function will insert all my alphabet which is in array of Trnslt.
btree *Allinsert (btree *root,Trnslt *s)
{
    for (int i=0; i!=39; ++i)
    {
        root=insert(root,s[i].letter,s[i].morse);
    }
    return root;
}


//this function searches morse code by binary tree and prints corresponding letter for that morse code on the screen and into the file.
void search (btree *root,char *s)
{
    int i=0;
    btree *tmp=root;
    FILE *f;
    f=fopen("decode.txt","a");
    if (s!=NULL)
    {
        while (s[i]!='\0')
        {
            if (s[i]=='.' || s[i]=='-')
            {
                while ( s[i]=='-' || s[i]=='.')
                {
                    if (s[i]=='.')
                        tmp=tmp->l;
                    else if (s[i]=='-')
                        tmp=tmp->r;
                    ++i;
                }
                printf("%c",tmp->letter);
                fprintf(f,"%c",tmp->letter);
            }
            if (s[i]==' ' && s[i+1]==' ')
            {
                printf(" ");
                fprintf(f," ");
            }
            if (i==strlen(s))
                printf("\n");
            ++i;
            tmp=root;
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

// this function combines reading function [read_long_line], printing text into file function [printtxt], inserting function [Allinsert] and printing decode [search]
void decode (Trnslt *s)
{
    btree *root=NULL;
    char *m=read_long_line();
    root=Allinsert(root,s);
    search(root,m);
    free(m);

}

// function will give statistics of letters
void statisticDecd (Trnslt *s)
{
    FILE *f;
    char c;
    f=fopen("decode.txt","r");
    if (f!=NULL)
    {
        while (fscanf(f,"%c",&c)!=EOF)
        {
            for (int i=0; i!=39; ++i)
                if (s[i].letter==c)
                    s[i].l+=1;

        }
        for (int j=0; j!=39; ++j)
            if (s[j].l!=0)// only will print statistics of used letters
            {
                printf("\t'%c' letter is used %d times\n",s[j].letter,s[j].l);
            }
    }
    fclose(f);
    remove("decode.txt");
}

// function will give statistics of dots and dashes.
void statisticEncd()
{
    FILE *f;
    char c;
    int dot=0,dash=0;
    f=fopen("encode.txt","r");
    if (f!=NULL)
    {
        while (fscanf(f,"%c",&c)!=EOF)
        {
            if (c=='.')
                ++dot;
            else if (c=='-')
                ++dash;
        }
        if (dot!=0)//only will print statistics of dashes and dots, if they are used
        {
            printf("\tDot is used %d times\n",dot);
        }
        if (dash!=0)
        {
            printf("\tDash is used %d times\n",dash);
        }
    }
    fclose(f);
    remove("encode.txt");
}

