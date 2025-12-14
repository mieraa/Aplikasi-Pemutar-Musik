#ifndef LAGU_H
#define LAGU_H

#include <iostream>
#include <string>
using namespace std;

typedef struct ElmSong* adrSong;
typedef struct ElmUser* adrUser;
typedef struct ElmRel* adrRel;

struct Song {
    string id, title, artist, genre;
};

struct ElmSong {
    Song info;
    adrSong next;
    adrSong prev;
};

struct ElmRel {
    adrSong song;
    adrRel next;
};

struct ElmUser {
    string name;
    adrRel firstPlaylist;
    adrUser next;
};

struct Admin {
    adrSong firstSong;
};

struct List {
    Admin admin;
    adrUser firstUser;
};

void createList(List &L);
adrSong createSong(string id, string title, string artist, string genre);
void insertLastSong(adrSong &head, adrSong S);
adrSong searchSongDLL(adrSong head, string key);
void deleteSongDLL(adrSong &head, string id);
void showLibrary(adrSong head);
adrUser createUser(string name);
void insertUser(List &L, adrUser U);
void addSongToPlaylist(adrUser U, adrSong S);
void showPlaylist(adrUser U);
adrSong findNextSameArtist(List &L, adrSong current);
void playPlaylist(List &L, adrUser U);
void deleteSongFromPlaylist(adrUser U, string id);

#endif
