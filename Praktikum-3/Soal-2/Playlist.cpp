#include "Playlist.hpp"

Playlist::Playlist(string playlistName) : name(playlistName) { }

const string& Playlist::getName() const {
    return name;
}

const vector<Song>& Playlist::getSongs() const {
    return songs;
}

void Playlist::addSong(const Song &song) {
    bool in = false;
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i] == song) {
            in = true;
        }
    }

    if (!in) {
        songs.push_back(song);
    }
}

bool Playlist::removeSong(const Song &songToRemove) {
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i] == songToRemove) {
            songs.erase(songs.begin() + i);
            return true;
        }
    }
    return false;
}

void Playlist::removeSongByIndex(size_t index) {
    try {
        if (index >= songs.size()) {
            throw std::out_of_range("Index out of range");
        }
        songs.erase(songs.begin() + index);
    } catch (std::out_of_range& e) {
        cout << e.what() << endl;
    }
}

size_t Playlist::numberOfSongs() const {
    return songs.size();
}

ostream &operator<<(ostream &os, const Playlist &pl) {
    os << "Playlist: " << pl.getName() << " (" << pl.numberOfSongs() << " lagu)" << endl;
    for (int i = 0; i < pl.numberOfSongs(); i++) {
        os << i + 1 << ". " << pl.getSongs()[i] << endl;
    }
    return os;
}