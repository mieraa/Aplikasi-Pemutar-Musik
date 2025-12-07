#include "music.h"

void createListUser(User*& head) {
    head = nullptr;
}

void createPlaylist(User*& head, string username) {
    User* newUser = new User{username, nullptr, nullptr};
    if (!head) {
        head = newUser;
    } else {
        User* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
}

void addSongToPlaylist(User* head, string username, string title, string artist) {
    User* temp = head;
    while (temp) {
        if (temp->username == username) {
            insertLagu(temp->playlist, title, artist);
            return;
        }
        temp = temp->next;
    }
}

void deleteSongFromPlaylist(User* head, string username, string title) {
    User* temp = head;
    while (temp) {
        if (temp->username == username) {
            deleteLagu(temp->playlist, title);
            return;
        }
        temp = temp->next;
    }
}

void showUserPlaylist(User* head, string username) {
    User* temp = head;
    while (temp) {
        if (temp->username == username) {
            showAllLagu(temp->playlist);
            return;
        }
        temp = temp->next;
    }
}

void syncPlaylist(User* head, Song* adminPlaylist) {
    User* temp = head;
    while (temp) {
        Song* userPlaylist = temp->playlist;
        while (userPlaylist) {
            Song* adminSong = searchSong(adminPlaylist, userPlaylist->title);
            if (!adminSong) {
                deleteLagu(temp->playlist, userPlaylist->title);
            }
            userPlaylist = userPlaylist->next;
        }
        temp = temp->next;
    }
}

void adminMenu(){

}

void mainPlayerMenu(Song *s, int n){
    int choice;
    int idx = 0;

    cout << "===== MUSIC PLAYER MENU =====";
    cout << "1. Search Song";
    cout << "2. Sort Song";
    cout << "3. Next Song";
    cout << "4. Previous Song";
    cout << "5. Same Next Song";
    cout << "6. Create Playlist";
    cout << "7. View Playlist";
    cout << "8. Add Song";
    cout << "0. Exit";
    cout << "Choice: ";
    cin >> choice;

}

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
