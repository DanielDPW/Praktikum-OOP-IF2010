#include "Playback.hpp"

void Playback::addToQueue(const Song& song) {
    playbackQueue.push(song);
}

void Playback::addToQueue(const Playlist& playlist) {
    for (int i = 0; i < playlist.getSongs().size(); i++) {
        playbackQueue.push(playlist.getSongs()[i]);
    }
}

void Playback::next() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();
    }
}

void Playback::playAll() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        while (!playbackQueue.empty()) {
            next();
        }
    }
}

void Playback::skip() {
    if (playbackQueue.empty()) {
        cout << "Antrian kosong" << endl;
    } else {
        playbackQueue.pop();
    }
}

void Playback::clearQueue() {
    while (!playbackQueue.empty()) {
        skip();
    }
}

bool Playback::isEmpty() const {
    return playbackQueue.empty();
}

size_t Playback::queueSize() const {
    return playbackQueue.size();
}