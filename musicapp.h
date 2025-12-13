#ifndef MUSICAPP_H_INCLUDED
#define MUSICAPP_H_INCLUDED

#include <string>
using namespace std;

struct Song{
    string title;
    string artist;
};

void adminMenu(Song *arr, int n, int &p);
void userMenu(Song *arr, int n, int &p);
void mainMenu(Song *arr, int n);
void sortSong(Song *arr, int n);
int nextSong(int idx, int n);
int prevSong(int idx, int n);
int sameNextSong(Song *arr, int n, int idx);
int searchSong(Song *arr, int n, string key);
void addSongToPlaylist(ListUser &LU, string idUser, string idLagu, ListLagu master){}
void deleteSongFromPlaylist(ListUser &LU, string idUser, string idLagu){}
void showUserPlaylist(ListUser LU, string idUser){}
void showAllPlaylist(ListUser LU){}


#endif // MUSICAPP_H_INCLUDED
