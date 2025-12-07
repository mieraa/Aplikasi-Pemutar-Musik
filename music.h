#ifndef MUSICAPP_H_INCLUDED
#define MUSICAPP_H_INCLUDED

#include <string>
using namespace std;

struct Song{
    string idSong;
    string title;
    string artist;
    string genre;
};

void adminMenu();
void userMenu();
void mainMenu(Song *s, int n);
void sortSong(Song *s, int n);
int nextSong(int idx, int n);
int prevSong(int idx, int n);
int sameNextSong(Song *s, int n, int idx);
int searchSong(Song *s, int n, string song);
void addSongToPlaylist(ListUser &LU, string idUser, string idLagu, ListLagu master){}
void deleteSongFromPlaylist(ListUser &LU, string idUser, string idLagu){}
void showUserPlaylist(ListUser LU, string idUser){}
void showAllPlaylist(ListUser LU){}

#endif // MUSICAPP_H_INCLUDED
