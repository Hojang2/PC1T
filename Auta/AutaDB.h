#pragma once

#define ALBUM_SIZE 20
#define INTERPRET_SIZE 20

struct t_album
{
    char  nazev_alba[ALBUM_SIZE];
    char  interpret[INTERPRET_SIZE];
    int   rok;
    struct t_album* dalsi;
};

void add(char* znacka, int rok, struct t_album** uk_prvni, char* interpret);
void del(int rok, struct t_album** uk_prvni);