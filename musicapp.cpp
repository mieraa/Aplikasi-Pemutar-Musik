#include "musicapp.h"
#include <iostream>
#include <string>

using namespace std;

// Almira
int searchSong(Song *arr, int n, string key){
    for (int i = 0; i < n; i++){
        if (arr[i].title == key){
            return i;
        }
    }
    return -1;
}

void sortSong(Song *arr, int n){
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j].title > arr[j+1].title){
                Song temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int nextSong(int idx, int n){
    if(idx < n-1){
        return idx + 1;
    }
    return 0;
}

int prevSong(int idx, int n){
    if(idx > 0){
        return idx - 1;
    }
    return n-1;
}

int sameNextSong(Song *arr, int n, int idx){
    string artist = arr[idx].artist;
    for(int i = idx + 1; i< n; i++){
        if (arr[i].artist == artist){
            return i;
        }
        return -1;
    }
    return -1;
}


void adminMenu(Song *arr, int n, int &p){
    int choice;
    do {
        cout << "===== ADMIN MENU =====";
        cout << "1. Add Song";
        cout << "2. View Song";
        cout << "3. Edit Song/Playlist";
        cout << "4. Delete Song";
        cout << "0. Exit";
        cout << "Pilih: ";
        cin >> choice;

        if(choice == 1){
            cout << "Masukkan ID: ";
            cin >> arr[n].id;
            cout << "Masukkan Judul Lagu: ";
            cin >> arr[n].title;
            cout << "Masukkan Artist: ";
            cin >> arr[n].artist;
            
            cout << "Song Added!"; 
        } else if(choice == 2){
            for (int i =0; i<n;i++){
                cout << arr[i].id << " - " << arr[i].title << " - " << arr[i].artist << " ";
            }
        } else if(choice == 3){
            int id;
            cout << "ID yang ingin di edit: ";
            cin >> id;
            int idx = -1;
            for(int i =0; i<n; i++){
                if(arr[i].id == id){
                    idx = i;
                }
                if(idx == -1){
                    cout << "ID Tidak Ditemukan!";
                } else {
                    cout << "Judul baru: ";
                    cin >> arr[idx].title;
                    cout << "Artist baru: ";
                    cin >> arr[idx].artist;

                    cout << "Berhasil Diperbarui!";
                }
            } else if(choice == 4){
                int id; 
                cout << "ID yang mau dihapus: "; 
                cin >> id;
                int idx = -1;
                for(int i=0;i<n;i++) {
                    if(arr[i].id == id) {
                        idx = i;
                        if(idx == -1) {
                            cout << "Tidak ditemukan!";
                        } else{
                            for(int i=idx;i<n-1;i++) {
                                arr[i] = arr[i+1];
                                    n--;
                                    cout << "Berhasil Dihapus!";
                                }
                            }
                        }while(pilih != 5);
                } else if(pilih == 2){ 
                    sortSong(arr,n); 
                    cout << "Disort!"; 
                } else if(pilih == 3){ 
                    string key; 
                    cout<<"Judul: "; 
                    cin>>key; 
                    int idx=searchSong(arr,n,key); 
                    if(idx!=-1) {
                        cout<<"Index: "<< idx <<" "; 
                    } else {
                        cout<<"Tidak ada!";
                    }
                } while(pilih != 4);
            }
        }
    }
}

void userMenu(Song *arr, int n, int &p){
    int choice;
    do{
        cout << "===== USER MENU =====";
        cout << "1. Now Playing Song";
        cout << "2. Next Song";
        cout << "3. Previous Song";
        cout << "4. Create Playlist";
        cout << "0. Exit";
        cout << "Pilih: ";
        cin >> choice;

        if(choice == 1){
            cout << "Now Playing Song: " << arr[p].title << " ";
        } else if(choice == 2){
            p = next(p, n);
            cout << "Next Song: " << arr[p].title << " ";
        } else if(choice == 3){
            p = next(p, n);
            cout << "Previous Song: " << arr[p].title << " ";
        } else if(choice == 4){
            string key;
            cout << "Masukkan judul lagu: ";
            cin >> key;

            SongNode* p = head;
            while(p != NULL){
                if(p->info.title == key){
                    playlistAdd(playlist, p->info);
                    cout << "Ditambah ke playlist.\n";
                    break;
                }
                p = p->next;
            }
        }
    } while (choice != 0);
}

void mainMenu(Song *arr, int n){
    SongNode* head = NULL;
    PlayNode* playlist = NULL;

    int pilih;
    do{
        cout << "===== MAIN MENU =====";
        cout << "1. Admin";
        cout << "2. User";
        cout << "0. Exit";
        cin >> choice;

        if(choice == 1) adminMenu(head);
        else if(choice == 2) userMenu(head, playlist);

    } while(choice != 0);
}

// Viki 
void createListUser(ListUser &LU) {
    LU.first = nullptr;
}

addressPlaylist findUser(ListUser LU, string idUser) {
    addressPlaylist P = LU.first;
    while (P != nullptr && P->idUser != idUser) {
        P = P->next;
    }
    return P;
}

void createPlaylist(UserList &LU, string idUser) {
    if (findUser(LU, idUser) != nullptr) return;

    addressPlaylist baru = new Playlist;
    baru->idUser = idUser;
    baru->firstLagu = nullptr;
    baru->lastLagu = nullptr;
    baru->next = LU.first;
    LU.first = baru;
}

// Arya
void createListSong(ListSong &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrSong createElementSong(string id, string title, string artist, string genre) {
    adrSong P = new elementSong;
    P->info.idSong = id;
    P->info.title = title;
    P->info.artist = artist;
    P->info.genre = genre;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}