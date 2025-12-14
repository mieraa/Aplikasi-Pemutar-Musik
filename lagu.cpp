#include "lagu.h"

void createList(List &L) {
    L.admin.firstSong = nullptr;
    L.firstUser = nullptr;
}

adrSong createSong(string id, string title, string artist, string genre) {
    adrSong S = new ElmSong;
    S->info = {id, title, artist, genre};
    S->next = nullptr;
    S->prev = nullptr;
    return S;
}

void insertLastSong(adrSong &head, adrSong S) {
    if (head == nullptr) {
        head = S;
    } else {
        adrSong temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = S;
        S->prev = temp;
    }
}

adrSong searchSongDLL(adrSong head, string key) {
    while (head != nullptr) {
        if (head->info.id == key ||
            head->info.title == key ||
            head->info.artist == key)
            return head;
        head = head->next;
    }
    return nullptr;
}

void deleteSongDLL(adrSong &head, string id) {
    adrSong temp = head;
    while (temp != nullptr && temp->info.id != id)
        temp = temp->next;

    if (temp == nullptr) return;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

void showLibrary(adrSong head) {
    cout << "\n=== LIBRARY LAGU ===\n";
    while (head != nullptr) {
        cout << "[" << head->info.id << "] "
             << head->info.title << " - "
             << head->info.artist << " ("
             << head->info.genre << ")\n";
        head = head->next;
    }
}

adrUser createUser(string name) {
    adrUser U = new ElmUser;
    U->name = name;
    U->firstPlaylist = nullptr;
    U->next = nullptr;
    return U;
}

void insertUser(List &L, adrUser U) {
    L.firstUser = U;
}

void addSongToPlaylist(adrUser U, adrSong S) {
    if (S == nullptr) return;

    // kodingan untuk cek lagu duplikasi
    adrRel cek = U->firstPlaylist;
    while (cek != nullptr) {
        if (cek->song == S) {
            cout << ">> Lagu sudah ditambahkan sebelumnya, silahkan cari lagu yang lain\n";
            return;
        }
        cek = cek->next;
    }

    adrRel R = new ElmRel;
    R->song = S;
    R->next = nullptr;

    if (U->firstPlaylist == nullptr)
        U->firstPlaylist = R;
    else {
        adrRel temp = U->firstPlaylist;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = R;
    }

    cout << ">> Lagu '" << S->info.title
         << "' berhasil ditambahkan ke playlist\n";
}


void showPlaylist(adrUser U) {
    if (U->firstPlaylist == nullptr) {
        cout << "Tidak ada lagu, silahkan tambahkan lagu\n";
        return;
    }

    cout << "\n=== PLAYLIST USER ===\n";
    adrRel R = U->firstPlaylist;
    while (R != nullptr) {
        cout << "- " << R->song->info.title << " - "
             << R->song->info.artist << " ("
             << R->song->info.genre << ")\n";
        R = R->next;
    }
}


adrSong findNextSameArtist(List &L, adrSong current) {
    adrSong temp = L.admin.firstSong;
    while (temp != nullptr) {
        if (temp->info.artist == current->info.artist &&
            temp != current)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void playPlaylist(List &L, adrUser U) {
    if (U->firstPlaylist == nullptr) {
        cout << "Tidak ada lagu, silahkan tambahkan lagu\n";
        return;
    }

    adrRel start = U->firstPlaylist;
    adrRel currentRel = start;
    adrSong currentSong = currentRel->song;

    bool playedRecommendation = false;
    int pilih = -1;

    while (pilih != 0) {
        cout << "\nSEDANG MEMUTAR\n";
        cout << currentSong->info.title << " - "
             << currentSong->info.artist << " ("
             << currentSong->info.genre << ")\n";

        cout << "1. Next\n";
        cout << "2. Prev\n";
        cout << "0. Stop\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            if (currentRel != nullptr && currentRel->next != nullptr) {
                currentRel = currentRel->next;
                currentSong = currentRel->song;
                playedRecommendation = false;
            }
            else if (!playedRecommendation) {
                adrSong same = findNextSameArtist(L, currentSong);
                if (same != nullptr) {
                    currentSong = same;
                    currentRel = nullptr;
                    playedRecommendation = true;
                } else {
                    currentRel = start;
                    currentSong = currentRel->song;
                }
            }
            else {
                currentRel = start;
                currentSong = currentRel->song;
                playedRecommendation = false;
            }
        }
        else if (pilih == 2) {
            if (currentRel != nullptr && currentRel != start) {
                adrRel temp = start;
                adrRel prev = nullptr;
                while (temp != currentRel) {
                    prev = temp;
                    temp = temp->next;
                }
                if (prev != nullptr) {
                    currentRel = prev;
                    currentSong = currentRel->song;
                }
            }
        }
    }
}

void deleteSongFromPlaylist(adrUser U, string id) {
    if (U->firstPlaylist == nullptr) {
        cout << "Playlist kosong\n";
        return;
    }

    adrRel curr = U->firstPlaylist;
    adrRel prev = nullptr;

    while (curr != nullptr) {
        if (curr->song->info.id == id) {
            if (prev == nullptr) {
                U->firstPlaylist = curr->next;
            }
            else {
                prev->next = curr->next;
            }

            cout << ">> Lagu berhasil dihapus dari playlist\n";
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Lagu tidak ditemukan di playlist\n";
}

void editSong(adrSong head, string id) {
    adrSong S = head;

    while (S != nullptr && S->info.id != id) {
        S = S->next;
    }

    if (S == nullptr) {
        cout << "Lagu tidak ditemukan\n";
        return;
    }

    cout << "=== EDIT LAGU ===\n";
    cout << "Judul lama  : " << S->info.title << endl;
    cout << "Artis lama  : " << S->info.artist << endl;
    cout << "Genre lama  : " << S->info.genre << endl;

    cout << "\nJudul baru  : ";
    cin >> S->info.title;
    cout << "Artis baru  : ";
    cin >> S->info.artist;
    cout << "Genre baru  : ";
    cin >> S->info.genre;

    cout << ">> Lagu berhasil diedit\n";
}
