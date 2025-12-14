#include "lagu.h"

int main() {
    List L;
    createList(L);

    // Data awal library
    insertLastSong(L.admin.firstSong, createSong("103", "Gigolo", "bbno$", "Santai"));
    insertLastSong(L.admin.firstSong, createSong("101", "Outfit", "LilBaby", "Pop"));
    insertLastSong(L.admin.firstSong, createSong("105", "RememberMe", "d4vd", "Santai"));
    insertLastSong(L.admin.firstSong, createSong("102", "YesIndeed", "LilBaby", "Pop"));
    insertLastSong(L.admin.firstSong, createSong("106", "RomanticHomicide", "d4vd", "Santai"));
    insertLastSong(L.admin.firstSong, createSong("104", "Lalala", "bbno$", "Santai"));


    adrUser user = createUser("USER");
    insertUser(L, user);

    int menu;
    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Admin\n2. User\n0. Exit\nPilih: ";
        cin >> menu;

        if (menu == 1) {
            int a;
            do {
                cout << "\n--- ADMIN ---\n";
                cout << "1. Add Lagu\n2. View Library\n3. Delete Lagu\n0. Back\nPilih: ";
                cin >> a;

                if (a == 1) {
                    string id, t, ar, g;
                    cout << "ID: "; cin >> id;
                    cout << "Judul: "; cin >> t;
                    cout << "Artis: "; cin >> ar;
                    cout << "Genre: "; cin >> g;
                    insertLastSong(L.admin.firstSong, createSong(id, t, ar, g));
                    cout << ">> Lagu berhasil ditambahkan ke library\n";
                }
                else if (a == 2)
                    showLibrary(L.admin.firstSong);
                else if (a == 3) {
                    string id;
                    cout << "ID hapus: "; cin >> id;
                    deleteSongDLL(L.admin.firstSong, id);
                    cout << ">> Lagu berhasil dihapus dari library\n";
                }
            } while (a != 0);
        }
        else if (menu == 2) {
            int u;
            do {
                cout << "\n--- USER ---\n";
                cout << "1. View Library\n";
                cout << "2. Add Lagu ke Playlist\n";
                cout << "3. View Playlist\n";
                cout << "4. Play Lagu dari Playlist\n";
                cout << "0. Back\nPilih: ";
                cin >> u;

                if (u == 1)
                    showLibrary(L.admin.firstSong);
                else if (u == 2) {
                    string key;
                    cout << "Tambah Lagu (ID): ";
                    cin >> key;
                    adrSong S = searchSongDLL(L.admin.firstSong, key);
                    if (S)
                        addSongToPlaylist(user, S);
                    else
                        cout << "Lagu tidak ditemukan\n";
                }
                else if (u == 3)
                    showPlaylist(user);
                else if (u == 4)
                    playPlaylist(L, user);
            } while (u != 0);
        }
    } while (menu != 0);

    return 0;
}
